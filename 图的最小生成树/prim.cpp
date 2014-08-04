/************************************************************************/
/* Prim函数原理：	
1，初始时，集合U={A},集合V/U={B,C,D,E,F,G}，T={}，然后寻找U中点与V/U中点相
连接的最小权值的边，然后将点加入到U中,如该点为B，则U={A,B},V/U={C,D,E,F,G}
T={(A,B)}
2,依次直到V/U为NULL*/
/************************************************************************/

#ifndef PRIM
#define PRIM
#include "prim.h"
#endif

// 临时数组lowCost[v]保存了集合U中节点u_i与集合V/U中节点v_j的所有边中当前具有最小权值的边<u,v>
void prim(AdjMGraph G, MinSpanTree closeVertex[]){
	ItemType x;
	list<ItemType> temp=G.Vertices;
	int n=G.Vertices.size(),minCost;
	int *lowCost=new int[n];
	// 节点0做为初始时U的点
	for(int i=0;i<n;i++)
		lowCost[i]=G.edge[0][i];
	x=G.Vertices.front();
	G.Vertices.pop_front();
	closeVertex[0].vertex=x;
	lowCost[0]=-1;
	int k;
	
	for(int i=1;i<n;i++){
		minCost=MaxWeight;
		//寻找U与V/U中,与节点i相连接的边权值最小的点
		for(int j=1;j<n;j++){
			if(lowCost[j]<minCost&&lowCost[j]>0){
				minCost=lowCost[j];
				k=j;
			}
		}
		//取出第k个元素
		list<ItemType>::iterator index=temp.begin();
		for(int ii=0;ii<k&&index!=temp.end();ii++,index++){

		}
		x=*index;
		G.Vertices.remove(*index);
		closeVertex[i].vertex=x;
		closeVertex[i].weight=minCost;
		lowCost[k]=-1;
		// 更新lowCost为节点k相连的权值集合
		for(int i=1;i<n;i++){
			// 这里判断是否小于lowCost[i]的原因在于之前已经加入U的点与此次点可能有连接，之前我们已经将连接置于-1了，所以要排除这种情况
			// 如按上述实验第一个U中点为A，但是第二个点B与A连接同样有50，但是这里因为是U中点与V/U中点的最小权值，因此这里不能考虑（B,A）
			// 所以要进行一下判断
			if(G.edge[k][i]<lowCost[i])
				lowCost[i]=G.edge[k][i];
		}

	}
}