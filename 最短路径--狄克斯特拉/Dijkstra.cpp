#ifndef DIJKSTRA
#define DIJKSTRA
#include "Dijkstra.h"
#endif

void Dijkstra(AdjMGraph G, int v0, int distance[],int path[]){
	int n=G.Vertices.size();
	int *s=new int[n];
	int minDis,i,j,u;

	// 初始化，distance初始值为与初始点v0相连接的的边值
	for (i=0;i<n;i++)
	{
		distance[i]=G.edge[v0][i];
		s[i]=0;
		if(i!=v0&&distance[i]<MaxWeight)
			path[i]=v0;
		else
			path[i]=-1;
	}
	// 标记结点v0已经从集合T加入到集合S中
	s[v0]=1;

	// 在当前还未找到最短路径的结点集中选取具有最短距离的结点u
	for(i=1;i<n;i++){
		minDis=MaxWeight;
		// 在i时找到对应的最小距离
		for(j=0;j<n;j++){
			if(s[j]==0&&distance[j]<minDis){
				u=j;
				minDis=distance[j];
			}
		}

		if(minDis==MaxWeight)return;
		// 标记u从T加入到S中
		s[u]=1;
		// 修改从v0到其他结点的最短距离和最短路径
		for(j=0;j<n;j++)
			if(s[j]==0&&G.edge[u][j]<MaxWeight&&distance[u]+G.edge[u][j]<distance[j]){
				distance[j]=distance[u]+G.edge[u][j];
				path[j]=u;
			}
	}
}