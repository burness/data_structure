#include <iostream>
using namespace std;

#define DataType int
/*创建堆从数据下标i=(n-1)/2，即最后一个有叶子节点的点，从这个点开始进行子树的
更新，更新完成后i--，进行下一个子树的更新，一次直到i=0,即可创建一个最大（最小）堆*/
void CreateHeap(DataType a[],int n, int h){
	int i,j,flag;
	DataType temp;

	i=h;
	j=2*i+1;
	temp=a[i];
	flag=0;
	while(j<n&&flag!=1){
		if(j<n-1&&a[j]<a[j+1])
			j++;
		if(temp>a[j])
			flag=1;
		else{
			a[i]=a[j];
			i=j;
			j=2*i+1;
		}
	}
	a[i]=temp;
}

void InitCreateHeap(DataType a[], int n){
	for(int i=(n-1)/2;i>=0;i--)
		CreateHeap(a,n,i);
}

void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}


DataType* HeapSort(DataType a[], int n){
	int i;
	DataType temp;
	InitCreateHeap(a,n);
	for(i=n-1;i>0;i--){
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		// 每次取出最大值后，将堆更新为最大堆
		display(a,n);
		//比如取出第一个堆顶元素，在数组中，即与数组最后元素交换；
		//但是之后0～n-1被破坏了最大堆结构，但是很显然不需要再从最
		//后一个有叶子节点的节点开始更新来创建堆，因为此时，只是堆
		//顶元素被取出，后面基本的结果完全可以保持不变，故，只需更
		//新一次，更新时，起始点为0即可
		CreateHeap(a,i,0);
	}
	return a;
}


int main(){
	DataType a[]={8,64,2,20,34,54,23,54,14,98};
	DataType* aa= HeapSort(a,sizeof(a)/sizeof(int));
	display(aa,sizeof(a)/sizeof(DataType));
}