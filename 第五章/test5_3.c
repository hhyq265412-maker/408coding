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
}


/***************07先序遍历第k个节点的值************************************ */
int count = 0;     
Elemtype ans;      

void search(BiTree T, int k) {
    if (T == NULL) return; 

    count++;
    if (count == k) {
        ans = T->data; 
        return;
    }

    search(T->lchild, k); 
    search(T->rchild, k); 
}
/*****************08 删除元素值为x的所有子树**************************************** */
void delete(BiTree T){
    if(T==NULL){
        return ;
    }
    delete(T->lchild);
    delete(T->rchild);
    free(T);
}//我们要删除他的后续节点就必须递归解放掉所有的节点

void Del_Element(BiTree T,int data){
    if(T->data==data){
        delete(T);
        return;
    }
    BiTree Q[MaxSize];
    int front=0;
    int rear=0;
    Q[rear++]=T;
    while(T!=NULL||rear!=front){
        if(T!=NULL){
            if(T->lchild!=NULL&&T->lchild->data==data){
                delete(T->lchild);
                T->lchild=NULL;
            }else{
                Q[rear++]=T->lchild;
                T=T->lchild;
            }
        }else{
            T=Q[--rear];
            if(T->rchild!=NULL&&T->rchild->data==data){
                delete(T->rchild);
                T->rchild=NULL
                //注意下一行这个要记上
                T=NULL
            }else{
                Q[rear++]=T->rchild;
                T=T-rchild;
            }
        }
    }
    return ;
}
void DeleteElemt(BiTree T,int data){
    if (T->data==data){
        delete(T);
        return;
    }
    BiTree Q[MaxSize];
    int font=0;
    int rear=0;
    Q[rear++]=T;
    while(rear!=front){
        BiTree cut=Q[font++];
        if(cut->lchild!=NULL){
            if(cut->lchild->data==data){
                delete(cut->lchild);
                cut->lchild=NULL;
            }else
                Q[rear++]=cut->lchild;
        }
        if(cut->rchild!=NULL){
            if(cut->rchild->data==data){
                delete(cut->rchild);
                cut->rchild=NULL;
            }else
                Q[rear++]=cut->rchild;
        }
    }
    return ;
}



/***************09 找到x 并且打印所有祖先************************/
/*核心思想就是我们后续访问再遇到x直接打印我们栈的内容*/
void Ancestory (BiTree T ,int x){
    BiTree Q[MaxSize];
    int front=0;
    int rear =0;
    BiTree p=T;
    BiTree r=NULL;

    while(p!=NULL || font!=rear){ 
        if(p!=NULL){
            Q[rear++]=p;
            p=p->lchild;
        }else{
            p=Q[rear-1];
            if(p->rchild!=NULL && p->rchild!=r){
                p=p->rchild;
            }else{
                rear--;
                if(p->data==x){
                    for(int i=front;i<rear;i++){
                        printf("%d/n",Q[i]->data);
                    }
                }
                r=p;
                p=NULL;
            }
        }
    }
}

//以下是第一遍写的
void Ancestory(BiTree T,int x){
    BiTree Q[ManSize];
    int front=0;
    int rear=0;
    BiTree P=T;//我们当前访问的节点
    BiTree R=NULL;//我们上一个节点用来判断拐弯的时机
    //Q[rear++]=T;

    while(rear!=front){
        if(p!=NULL){
            //Q[rear++]=p->lchild;
            Q[rear++]=p;
            p=p->lchild;
        }else{
            p=Q[rear-1];
            if(p->rchild!=NULL&&p->lchild==r){
                //Q[rear++]=p->rchild;
                p=p->rchild;
            }else{
                rear--;
                vist();
                r=p;
                p=NULL;
            }
        }
    }
}

/******************非递归版遍历**********************/
//先序
void first_visit(BiTree T){
    BiTree Q[MaxSize];
    int front=0;
    int rear=0;
    BiTree p=T;
    //while(p!=NULL&&rear!=front){
    while(p!=NULL || rear != front){
        if(p!=NULL){
            visit();
            Q[rear++]=p;
            p=p->lchild;
        }else{
            //p=Q[rear-1];
            p=Q[--rear]
            /*if(p->rchild!=NULL){//问题如果是rchild的是空我们会一直循环
                p=p->rchild;
            }*/
            p=p->rchild;
        }
    }
}

//中序
void Middle_visit(BiTree T){
    BiTree Q[MaxSize];
    int front=0;
    int rear=0;
    BiTree p=T;
    //while(p!=NULL&&front!=rear){
    while(p!=NULL || front !=rear){
        if(p!=NULL){
            Q[rear++]=p;
            p=p->rchild;
        }else{
            p=Q[--rear]
            visit();
            /*if(p->rchild!=NULL){
                p=p->rchild;
            }*/
            p=p->rchild;
        }
    }
}

//后序
void last_visit(BiTree T){
    int front =0;
    int rear=0;
    BiTree Q[MaxSize];
    BiTree p=T;
    Bitree r = NULL;
    //while(p!=NULL&&front!=rear){
    while(p!=NULL || front!=rear){
        if(p!=NULL){
            Q[rear++]=p;
            p=p->lchild;
        }else{
            p=Q[rear-1];
            //if(p->rchild!=NULL&&p->lchild==r){
            if(p->rchild!=NULL&&p->rchild!=r){
                p=p->rchild;
            }else{
                rear--;
                visit();
                r=p;
                p=NULL;//很重要我们此节点已经弹出来，我们要下一个节点
                        //要置空直接找到下一个节点
            }
        }
    }
}


/****************10找到两个节点的公共祖先节点************************************ */
typedef struct BiTree{
    BiTree * LLINK;
    BiTree * RLINK;
    int INFO;
}*BiTree;
