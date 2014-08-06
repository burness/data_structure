#include <iostream>
using namespace std;
#define DataType int
DataType* InsertSort(DataType* a, int n){
	for(int i=0;i<n-1;i++){
		DataType temp;
		temp=a[i+1];
		int j;
		// 将temp插入到前面有序的数组中合适的位置
		for(j=i;j>-1&&temp<a[j];){
				a[j+1]=a[j];
				j--;
		}

		a[j+1]=temp;
	}

	return a;
}

void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}

int main(){
	DataType a[]={8,64,2,20,34,54,23,54,14,98};
	DataType* aa= InsertSort(a,sizeof(a)/sizeof(int));
	display(aa,sizeof(a)/sizeof(DataType));
}