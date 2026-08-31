#include <stdio.h>   // 用于标准输入输出（如 printf, scanf）
#include <stdlib.h>  // 用于动态内存分配（如 malloc, free，在创建图的结点时必需）
#include <stdbool.h> // 用于使用 bool 类型（在进行图的遍历如 BFS, DFS 时常用）

/***********7.2 04 递归实现折半查找**************************/
int half_find(int * a,int i,int low,int heigh){
    int mid=(low+heigh)/2;
    if(a[mid]==i){
        return mid;
    }
    if(low>heigh){
        return -1;
    }
    if(a[mid]<i){
        return half_find(a,i,low,mid-1);
    }else{
        return half_find(a,i,mid+1,heigh);
    }
}

/***********7.2 05实现特殊顺序检索算法****************************************** */
//太简单省略

/***********7.2 06 给出特殊矩阵寻找目标值**************************************** */
int find_element(int **a,int k,int n){
    
}