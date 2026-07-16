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


