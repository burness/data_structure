#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
#define DataType int

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

DataType* InsertSort(DataType a[], int n){
	for(int i=0;i<n-1;i++){
		DataType temp;
		temp=a[i+1];
		int j=i;
		// 将temp插入到前面有序的数组中合适的位置
		/*for(j=i;j>-1&&temp<a[j];){
			a[j+1]=a[j];
			j--;
		}*/
		while(j>-1&&temp<a[j]){
			a[j+1]=a[j];
			j--;
		}

		a[j+1]=temp;
	}

	return a;
}


int main(){
	clock_t start,start2,finish,finish2;
	//ofstream outfile("./out.txt");
	ofstream outfile("./out2.txt");
	//DataType a[]={8,64,2,20,34,54,23,54,14,98};
	DataType a[100000],b[100000];
	srand((unsigned)time(NULL));
	for(int i=0;i<100000;i++){
		a[i]=100000-i;
		b[i]=100000-i;
		outfile<<a[i]<<" ";
	}

	start=clock();
	DataType* aa= ShellSort(a,sizeof(a)/sizeof(int));
	finish=clock();
	double shell_time=(double)(finish-start)/CLOCKS_PER_SEC;
	start2=clock();
	DataType* bb=InsertSort(b,sizeof(b)/sizeof(int));
	finish2=clock();
	double Insert_time=(double)(finish2-start2)/CLOCKS_PER_SEC;
	display(aa,100);
	display(bb,100);

	cout<<"Shell time:"<< shell_time<<endl;
	cout<<"Insert time:"<<Insert_time<<endl;
	cout<<"Shell time < Insert time ?"<<shell_time-Insert_time<<endl;

}