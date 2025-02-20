#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int parent[MAX],t[MAX][2]; // to define every vertex v as a single set with parent v // t to store vertex in spanning tree order
int v,i,j,cost[MAX][MAX],count=1,mincost,c,rno,cno,v1,v2,k; // v=no. of vertices , cost = cost of edge btw 2 vertices , edgecount = no. of edge in spanning tree  
int find(int i)                                                       // mincost = to add mincost in every loop , c = to give a 999 value and to store mincost to calculate in each loop
{                                                          // rno,cno is to union 2 sets with them as sets parent ,v1,v2 = 2 vertices od edge
    return parent[i];  //to find whiche set the vertex belong to
} 
  
int uni(int i,int j)
{
    if(i!=j)
    {  
        parent[j]=i; 
        for(k=1;k<=v;++k)  // to see if any othe vertex is in this set j , if  so it will also be merged to set i 
        {
            if(parent[k]==j)
            {
                parent[k]=i;
            }
        }
        return 1; 
    }
    return 0; 
} 

int kruskal()
{
    for(i=1;i<=v;i++)
        parent[i]=i;
    //Get edge weight matrix from user
    for(i=1;i<=v;i++)
    {
        for(j=i+1;j<=v;j++)
        {
            if(i!=j)
            {
                printf("enter the cost[%d][%d]||cost[%d][%d]:",i,j,j,i);
                scanf("%d",&cost[i][j]);
                cost[j][i]=cost[i][j];
                if(cost[i][j]==0)
                {
                    cost[i][j]=999;
                    cost[j][i]=999;
                }
            }
        }
    }
    
    

    while(count <= v-1)
    {
    c=999;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(cost[i][j] < c)
            {
                c = cost[i][j];
                v1 = rno =  i;
                v2 = cno=  j;
            }
        }
    }   
    rno  = find(rno);   // rno = parent(rno)
    cno = find(cno);    // cno = parent(cno)
    if(uni(rno,cno))
    {  
        t[count][0] = v1;
        t[count][1] = v2;
        printf("\nEdge %d is (%d <-> %d) with cost : %d ",count++,v1,v2,c);
        mincost = mincost + c;
    }
    cost[v1][v2] = cost[v2][v1] = 999;  // to not consider already taken
    }  
    return mincost;
}
 
int main(){  
    printf("Total no of v :: ");
    scanf("%d",&v);
    int totalcost = kruskal();
    printf("\n Minimum cost=%d \n",totalcost);  
    return 0;
}
