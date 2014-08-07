#include <iostream>
using namespace std;
#define  DataType int

void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}
DataType* SelectSort(DataType a[],int n){
	// 遍历待排序，选择其中最小值
	for(int i=0;i<n-1;i++){
		int min_index=i;
		
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min_index])
				min_index=j;
		}
		// 当min_index!=i时。与已排序的最后一个数也就是下标为i的数交换
		if(min_index!=i){
			int temp=a[i];
			a[i]=a[min_index];
			a[min_index]=temp;
		}
		display(a,n);
	}
	return a;
}




int main(){
	DataType a[]={8,64,2,20,34,54,23,54,14,98};
	DataType* aa= SelectSort(a,sizeof(a)/sizeof(int));
	display(aa,sizeof(a)/sizeof(DataType));
}