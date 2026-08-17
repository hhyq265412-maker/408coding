#include <stdio.h>   // 用于标准输入输出（如 printf, scanf）
#include <stdlib.h>  // 用于动态内存分配（如 malloc, free，在创建图的结点时必需）
#include <stdbool.h> // 用于使用 bool 类型（在进行图的遍历如 BFS, DFS 时常用）
#define MaxVertexNum 100            //图中顶点数目的最大值
typedef struct ArcNode{          //边表结点
    int adjvex;                 //该弧所指向的顶点的位置
    struct ArcNode *nextarc;    //指向下一条弧的指针
    //InfoType info;            //网的边权值
}ArcNode;

typedef struct VNode{            //顶点表结点
    VertexType data;            //顶点信息
    ArcNode *firstarc;          //指向第一条依附该顶点的弧的指针
}VNode, AdjList[MaxVertexNum];

typedef struct{
    AdjList vertices;           //邻接表
    int vexnum, arcnum;         //图的顶点数和弧数
}ALGraph;                       //ALGraph 是以邻接表存储的图类型

void Convert (ALGraph &L,int arcs[M][N] ){
    for(int i=0;i<L.vertices;i++){
        ArcNode * current = (L.vertices[i]).firstarc;
        while(current!=NULL){
            arcs[i][current->adjvex]=1;
            current=current->nextarc;
        }
    }
}



/******************2021年********************************/
typedef struct {                          // 图的定义
    int numVertices, numEdges;            // 图中实际的顶点数和边数
    char VerticesList[MAXV];              // 顶点表。MAXV 为已定义常量
    int Edge[MAXV][MAXV];                 // 邻接矩阵
} MGraph;

int IsExistEL(MGraph G){
    int answer=0 //度数为积数的节点数；
    for(int i=0;i<G.numVertices;i++){
        int current_degree=0;
        for(int j=0;j<G.numVertices;j++){
            current_degree+=G.Edge[i][j];//计算每个节点的度
        }
        if (current_degree%2==1)
            answer++;
    }
    if(answer<=2 && answer%2==0)
        return 1;
    return 0;
}
//（1）：我们直接遍历数组，我们将这个矩阵每一行的有效数字进行相加，就可以得到这个节点的度
//然后在进行比较就行了。
//时间复杂度O（n2）空间复杂度O（1）；




/***************************2023真题*******************************/
typedef struct {                          // 图的定义
    int numVertices, numEdges;            // 图中实际的顶点数和边数
    char VerticesList[MAXV];              // 顶点表。MAXV 为已定义常量
    int Edge[MAXV][MAXV];                 // 邻接矩阵
} MGraph;
int printVertices(MGraph G){
    int answer=0;
    for(int i=0;i<G.numVertices;i++){
        int in_degree=0;
        int out_degree=0;
        for (int j=0;j<G.numVertices;i++){
            out_degree+=G.Edge[i][j];
            in_degree+=G.Edge[j][i];
        }
        if(out_degree>in_degree){
            printf("%c ",G.VerticesList[i]);
            answer++;
        }
    }
    return answer;
}
/*
(2)思想：我们直接遍历这n个节点 我们计算出我们再遍历计算出入度出度，再比较得出是否是k点再输出
    

*/



/*****************2024 判定有无唯一拓扑排序****************************** */

typedef struct {
    int numVertices,numEdges;
    char VerticesList[MAXV];
    int Edge[MaxV][MaxV];
}MGraph;
/*int find(int * a){
    int[]
}
int uniquely(MGraph G){
    int edge_cur[G.numVertices][G.numVertices];
    for(int i=0;i<G.numVertices;i++){
        for(int j=0;j<G.numVertices;j++){
            edge_cur[i][j]=G.Edge[i][j];
        }
    }//复制一份领接矩阵，方便删除边

    int count =G.numVertices;
    for(int i=0;i<G.numVertices;i++){
        int i=find(edge_cur);

    }
}*/
int uniquely(MGraph G){
    int IN_count[G.numEdges]={0};
    for(int i=0;i<G.numVertices;i++){
        for(int j=0;j<numVerticesl;j++){
            if(G.Edge[j][i]>0)
                IN_count[i]++;
        }
    }//将入读表整出来
    for(int i=0;i<G.vertices;i++){
        int j;
        for(;j<G.numVertices;j++){
            if(IN_count[j]==0){
                break;
            }
        }
        if(j==G.vertices){
            return 0;
        }
        IN_count[j]=-1;//完成删除节点
        for(int i=0;i<G.vertices;i++){
            if(G.Edge[j][i]>0)
                IN_count[i]--;
        }//完成删除边
    }
    return 1;
}