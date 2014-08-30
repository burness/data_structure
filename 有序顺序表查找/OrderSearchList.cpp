#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
typedef int DataType;

DataType* ShellSort(DataType a[],int n){
	for(int gap=n/2;gap>0;gap=gap/2){
		for(int i=0;i!=gap;i++){
			for(int j=i+gap;j<n;j+=gap){
				if(a[j]<a[j-gap]){
					int k=j-gap;
					DataType temp=a[j];
				while(k>-1&&temp<a[k]){
					a[k+gap]=a[k];
					k-=gap;
				}
				a[k+gap]=temp;
				}
			}
		}
	}
	return a;
}


void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}

int OrderSearchList(DataType* head,DataType data,int start,int end){
	int mid=(start+end)/2;
	if(start>=end){
		return -1;
	}
	if(head[mid]==data){
		cout<<"所查元素位置："<<endl;
		for(int i=mid;head[i]==data;i++){
		cout<<i<<"	";
		}
		for(int i=mid-1;head[i]==data;i--){
			cout<<i<<"	";
		}
		return 1;
	}
	if(head[mid]<data){
		start=mid;
		OrderSearchList(head,data,start,end);
	}
	else{
		end=mid;
		OrderSearchList(head,data,start,end);
	}
}

int main(){
	const int length=100000;
	DataType a[length];
	srand((unsigned)time(NULL));
	for(int i=0;i<length;i++){
		a[i]=rand()%length;
	}

	DataType* aa= ShellSort(a,sizeof(a)/sizeof(int));
	DataType data;
	cout<<"输入要查找的数:"<<endl;
	cin>>data;
	OrderSearchList(aa,data,0,length-1);
	return 1;

}