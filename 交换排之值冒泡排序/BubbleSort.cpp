#include <iostream>
#define DataType int
using namespace std;

void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}

DataType* BubbleSort(DataType a[], int n){
	for(int i=1;i<n-1;i++){
		for(int j=0;j<n-i;j++){
			if(a[j]>a[j+1]){
				DataType temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		display(a,n);
	}
	return a;
}

DataType* BubbleSort2(DataType a[], int n){
	int flag=1;
	for(int i=1;i<n-1&&flag==1;i++){
		flag=0;
		for(int j=0;j<n-i;j++){
			if(a[j]>a[j+1]){
				flag=1;
				DataType temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	return a;
}


int main(){
	DataType a[]={8,64,2,20,34,54,23,55,14,98};
	display(a,sizeof(a)/sizeof(DataType));
	DataType* aa= BubbleSort2(a,sizeof(a)/sizeof(int));
	display(aa,sizeof(a)/sizeof(DataType));
}