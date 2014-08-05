#include <iostream>
#include <string>   
#include <stdio.h>   
using namespace std;   

#define MaxVertexNum 100   
#define INF 32767   
typedef struct  
{   
	char vertex[MaxVertexNum];   
	int edges[MaxVertexNum][MaxVertexNum];   
	int n,e;   
}MGraph;   

void CreateMGraph(MGraph &G)   
{   
	int i,j,k,p;   
	cout<<"请输入顶点数和边数:";   
	cin>>G.n>>G.e;   
	cout<<"请输入顶点元素:";   
	for (i=0;i<G.n;i++)   
	{   
		cin>>G.vertex[i];   
	}   
	for (i=0;i<G.n;i++)   
	{   
		for (j=0;j<G.n;j++)   
		{   
			G.edges[i][j]=INF;   
			if (i==j)   
			{   
				G.edges[i][j]=0;   
			}   
		}   
	}      
	for (k=0;k<G.e;k++)   
	{   
		cout<<"请输入第"<<k+1<<"条弧头弧尾序号和相应的权值:";   
		cin>>i>>j>>p;   
		G.edges[i][j]=p;   
	}   
}   
void Dispath(int A[][MaxVertexNum],int path[][MaxVertexNum],int n);

void Floyd(MGraph G)
{
	int A[MaxVertexNum][MaxVertexNum],path[MaxVertexNum][MaxVertexNum];
	int i,j,k;
	for (i=0;i<G.n;i++)
	{
		for (j=0;j<G.n;j++)
		{
			A[i][j]=G.edges[i][j];
			path[i][j]=-1;
		}
	}
	for (k=0;k<G.n;k++)
	{
		for (i=0;i<G.n;i++)
		{
			for (j=0;j<G.n;j++)
			{
				if (A[i][j]>A[i][k]+A[k][j])
				{
					A[i][j]=A[i][k]+A[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	Dispath(A,path,G.n);
}

void Ppath(int path[][MaxVertexNum],int i,int j)
{
	int k;
	k=path[i][j];
	if (k==-1)
	{
		return;
	}
	Ppath(path,i,k);//path[i][j]是i表示从vi到vj的最短路径中，vj的前一个结点序号为k，因此，这里用递归一次到path=-1即到初始结点，由递归性质这里就可以输出最短路径各个结点
	printf("%d,",k);
	Ppath(path,k,j);
}

void Dispath(int A[][MaxVertexNum],int path[][MaxVertexNum],int n)
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (A[i][j]==INF)
			{
				if (i!=j)
				{
					printf("从%d到%d没有路径\n",i,j);
				}
			}
			else
			{
				printf("  从%d到%d=>路径长度:%d路径:",i,j,A[i][j]);
				printf("%d,",i);
				Ppath(path,i,j);
				printf("%d\n",j);
			}
		}
	}
}

int main()
{
	//freopen("input2.txt", "r", stdin);
	MGraph G;
	CreateMGraph(G);
	Floyd(G);
	return 0;
}