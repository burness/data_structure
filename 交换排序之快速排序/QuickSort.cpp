#include <iostream>
using namespace std;

#define DataType int

void display(DataType* a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<"	";
	}
}

void QSort(DataType a[], int low, int high){
	int first=low,last=high;
	DataType temp=a[low];
	if (low>=high)
	{
		return ;
	}
	// 接下来就是要将所有大于temp的放到右边，所有小于temp的放到左边
	while (first<last)
	{
		while(first<last&&a[last]>=temp)
			--last;
		a[first]=a[last];
		while(first<last&&a[first]<=temp)
			++first;
		a[last]=a[first];
	}
	
	a[first]=temp;
	display(a,10);
	QSort(a,low, first-1);
	QSort(a,last+1,high);

}

int main(){
	DataType a[]={8,64,2,20,34,54,23,55,14,98};
	display(a,sizeof(a)/sizeof(DataType));
	QSort(a,0,sizeof(a)/sizeof(DataType)-1);
	display(a,sizeof(a)/sizeof(DataType));
}