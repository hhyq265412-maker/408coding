#include <stdio.h>   // 用于标准输入输出（如 printf, scanf）
#include <stdlib.h>  // 用于动态内存分配（如 malloc, free，在创建图的结点时必需）
#include <stdbool.h> // 用于使用 bool 类型（在进行图的遍历如 BFS, DFS 时常用）

/****************7.3 05 判断二叉树是不是二叉排序树*****************************/
//作法1中序遍历升序
int pre=INT-MIN; 
bool Judge_tree(BiTree * T){
    if(T==NULL){
        return true;
    }
    if(!Judge_tree(T->left)){
        return false;
    }
    if(T->data<=pre){
        return false;
    }
    pre=T->data;
    return Judge_tree(T->right);
 }

 //做法二 通过限定这个左右子树的值判定，递归层次
 bool Judge_tree_2(Bitree * T,int max,int min ){
    if(T==NULL){
        return true;
    }
    if(T->data<max && T->data> min){
        max1=min(max,T->data);
        //这个没必要max=t_datat
        bool flag1=Judge_tree_2(T->left,max1,min);
        min1=max(min,T->data);
        bool flag2=Judge_tree_2(T->right,max,min1);
        return flag1&&flag2;
    }
    return false;
 }
//问题：这里的max和min不用更新了，直接用就好了（T->lrft，T->data,min）；就行了


/*************7.3.5 06 给定节点判断在指定二叉树的参差****************************/
int storey(Bitree * T,int i){
    Bitree * current = T;
    int answer=0;
    while(T!=NULL&&current!=current->data){
        if(i<current->data){
            current=current->left;
        }
        if(i>current->data){
            current=current->right;
        }
        answer++;
    }
    if(current==NULL){
        return -1;
    }
    return answer;
}

/*************7.3.5 07 查看二叉树是不是平衡二叉树*************************************************** */
int  check_AVG(Bitree T){
    if(T==NULL){
        return 0;
    }
    int height_left=check_AVG(T->left);
    int height_right=check_AVG(T->right);
    if(abs(height_left-height_right)<=1){
        return max(height_left,height_right)+1;
    }else{
        return -1;
    }
}