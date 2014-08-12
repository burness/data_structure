#include <iostream>
using namespace std;
#define DataType int


void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}
void Merge(DataType a[], int n, DataType swap[], int k){
	int m=0,u1,l2,i,j,u2;
	int l1=0;

	while(l1+k<n-1){
		l2=l1+k;//第二个数组开始
		u1=l2-1;//第一个数组结尾
		u2=(l2+k-1<=n-1)?l2+k-1:n-1;//第二个数组结尾

		for(i=l1,j=l2;i<=u1&&j<=u2;m++){
			if(a[i]<=a[j]){
				swap[m]=a[i];
				i++;
			}
			else{
				swap[m]=a[j];
				j++;
			}
		}
		//子数组2已经归并完，将子数组1中剩余的元素放到数组swap中
		while(i<=u1){
			swap[m]=a[i];
			m++;
			i++;
		}
		//子数组1已经归并完，将子数组2中剩余元素放到数组swap
		while(j<=u2){
			swap[m]=a[j];
			m++;
			j++;
		}
		l1=u2+1;
	}
	for(i=l1;i<n;i++,m++)swap[m]=a[i];
}

void MergeSort(DataType a[], int n){
	int i,k=1;
	DataType *swap;
	swap=new DataType[n];
	while(k<n){
		Merge(a,n,swap,k);
		for(i=0;i<n;i++){
			a[i]=swap[i];
		}
		k=2*k;
	}
	delete [] swap;
}

int main(){
	DataType a[]={8,64,2,20,34,54,23,55,14,98};
	display(a,sizeof(a)/sizeof(DataType));
	MergeSort(a,sizeof(a)/sizeof(int));
	display(a,sizeof(a)/sizeof(DataType));
}