#include <studio.h>
# define ManSize 1000;
/**********03 二叉树用二叉链表储存 用非递归计算高度***************************/
int Btdeoth(BiTree T){
    if (T==NULL){
        return 0;
    }
    int front = 0;
    int rear = 0;
    BiTree queue[ManSize];
    int height=0;
    int account=1;
    queue[rear++]=T;
    while(front!=rear){
        int current_account=0;
        for(int i=0;i<account;i++){
            if(queue[front]->lchild){
                queue[rear++]=queue[front]->lchild;
                current_account++
            }
            if(queue[front]->rchild){
                queue[rear++]=queue[front]->rchild;
                current_account++
            }
            front++;//头部移出
        }
        height++
        account=current_account;
    }
    return height;
} 


/************ 04  判断是否是完全二叉树*****************************************/
/*层次遍历我们每次判断每个节点的有节点是否存在，若两种情况子树为空不存在且我们的队列无内容则为完全二叉*/
bool Judge_tree(BiTree T){
    BiTree Q[ManSize];
    int front=0;
    int rear=0;
    Q[rear++]=T;
    bool flag=true;
    while(front!=rear){
        if(Q[front]->rchild!=NULL){
            //右不为空
            if(Q[front]->lchild!=NULL&&flag){
                //左不为空
                Q[rear++]=Q->lchild;
                Q[rear++]=Q->rchild;
            }
            else
                return false;
        }
        else{
            //右为空
            if(Q[front -> lchild ==NULL]){
                //左也为空
                flag=false;
                continue;
            }
            else{
                //左不为空
                if(!flag){
                    return false;
                }
                Q[rear++]=Q->lchild;
            }
        }
        front++;//头结点移出
    }
    return true;
}

/*想法十分丑陋不行啊。错误百出啊不好的*/

bool Judge_tree(BiTree T){
    if(!T){
        return true;
    }

    BiTree Q[ManSize];
    int front =0;
    int rear = 0;
    Q[rear++]=T;
    while(front!=rear){
        if (Q[front]==NULL){
            break;
        }
        Q[rear++]=Q[front]->lchild;
        Q[rear++]=Q[front]->rchild;
        front++
    }
    while (front!=rear){
        if(Q[front++]!=NULL){
            return false;
        }
    }
    return true;
}

/***************** 05 判断双儿子的节点个数**********/
int two_branches(BiTree T) {
    if (T == NULL) {
        return 0;
    }
    BiTree Q[MaxSize];
    int front = 0;
    int rear = 0;
    int answer = 0;
    // 根节点入队
    Q[rear++] = T;

    while (front != rear) {
        // 出队当前节点
        BiTree p = Q[front++];
        if (p->lchild != NULL && p->rchild != NULL) {
            answer++;
        }
        if (p->lchild != NULL) {
            Q[rear++] = p->lchild;
        }
        if (p->rchild != NULL) {
            Q[rear++] = p->rchild;
        }
    }

    return answer;
}


/***************06 交换左右子树*******************************/
void change_lr(BiTree &T){
    if(T==NULL){
        return;
    }
    change_lr(T->lchild);
    change_lr(T->rchild);
    BiTree current_Tree=T->lchild;
    T->lchild=T->rchild;
    T->rchild=current_Tree;
}j