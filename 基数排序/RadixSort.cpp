#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// 因为我们代码中需要用到随机访问，故我们这里使用vector
typedef vector< deque<int> > LinQueue; 
#define DataType int
// n为排序数个数，m为数中最大数数位，d为进制类型与桶数一致
DataType* RadixSort(DataType a[], int n, int m, const int d){
	int i,j,k,power=1;
	LinQueue tub(d);

	for(i=0;i<m;i++){
		if(i==0)
			power=1;
		else
			power=power*d;
		//
		for (j=0;j<n;j++)
		{
			//计算第j个数的第i位
			k=a[j]/power%d;
			tub.at(k).push_back(a[j]);
		}
		k=0;
		for(j=0;j<d;j++){
			while(!tub[j].empty()){
				
				a[k]=tub.at(j).front();
				tub[j].pop_front();
				k++;
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


int main(){
	DataType a[]={8,64,2,20,34,54,23,54,14,98};
	DataType* aa=RadixSort(a,sizeof(a)/sizeof(int),2,10);
	display(a,sizeof(a)/sizeof(DataType));
}