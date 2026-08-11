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
//主要思想找到这个p和这个q的这个两个祖先，再从后开始遍历找到公共节点再返回
void ANCESTORY (BiTree ROOT,BiTree p,BiTree q,BiTree *r){
    BiTree Q[2][ManSize];
    BiTree p=ROOT;
    BiTree r =NULL;
    BiTree Object[2]={p,q};
    int Front[2]={0,0};
    int Rear[2]={0,0};

    for (int i=0;i<2;i++){
        p=ROOT;
        r=NULL;
        while(p!=NULL || Front[i]!=Rear[i]){
            if(p!=NULL){
                Q[i][Rear[i]++]=p;
                p=p->LLINK;
            }else{
                p=Q[i][Rear[i]-1];
                if(p->RLINK!=NULL && p->RLINK!=r){
                    p=p->RLINK;
                }else{
                    Rear[i]--;
                    if(p==Object[i]){
                        break;
                    }
                    r=p;
                    p=NULL;
                }
            }
        }
    }
    int j=0;
    while(j<Rear[0]&&j<Rear[1]&&Q[0][j]==Q[1][j]){
        j++;
    }
    *(r)=Q[0][j-1];
}

/********************11 求这个二叉树的宽度******************************* */
int Width(Bitree T){
    BiTree Q[ManSize];
    int front=0;
    int rear=0;
    Q[rear++]=T;
    int width=1;
    int answer=1;
    while(front!=rear){
        int current_width=0;
        for(int i=0;i<width;i++){
            p=Q[front++];
            if(p->lchild!=NULL){
                Q[rear++]=p->lchild;
                current_width++;
            }
            if(p->rchild!=NULL){
                Q[rear++]=p->rchild;
                current_width++;
            }
        }
        width=current_width;
        if(width>answer){
            answer=width
        }
    }
    return answer;
}

/***********************12********************************************/
void change (int * pre,int pre_start,int * post ,int post_start,int length ){
    if(length==0){
        return;
    }
    post[post_start+length-1]=pre[pre_start];
    if(length<=1){
        return ;
    }
    sub_length=(length-1)/2;
    change(pre,pre_start+1,post,post_start,sub_length);
    change(pre,pre_start+1+sub_length,post,post_start+sub_length,sub_length);

}
/*************************13 通过递归 中序递归查找确定叶子节点连接起来**************************************** */
BiTree  * Linkhead=NULL;
BiTree * Linkrear=NULL;
void Link_leaf(BiTree T){
    if(T==NULL){
        return ;
    }
    Link_leaf(T->lchild);
    if(T->rchild==NULL&&T->rchild==NULL){
        if(Linkhead==NULL){
            Linkhead=T;
            Linkrear=T;
        }
        else{
            Linkrear->next=T;
            Linkrear=T;
        }

    }
    Link_leaf(T->rchild);
}
/*************************14 判断相似，利用递归判断************************************ */
bool simmilar_BiTree(BiTree T1,BiTree T2){
    if(T1==NULL&&T2==NULL){
        return true;
    }else if((!T1->lchild )&& (!T1->rchild)&&(!T2->rchild)&&(!T2->lchild)){
        return true;
    }else if(T1->lchild&&t1->lchild&&T2->rchild&&T2->rchild){
        return simmilar_BiTree(T1->rchild,T2->rchild)&&simmilar_BiTree(T1->lchild,T2->lchild);
    }else{
        return false;
    }
}

/************************2014真题***************************************** */
//基本思想：我们通过这个层次 遍历我们的这个颗数我们的遍历层数乘上叶子节点的权值全部相加得到wpl
typedef struct{
    BiTree * left;
    BiTree * right;
    int weight;
}BiTree;

int WPL(Bitree *  T){
    BiTree * Q[MaxSize];
    int front =0;
    int rear =0;
    Q[rear++]=T;
    int satge=1;  //标记层数
    int wpl=0;    //最后的wpl
    int count =1;
    //利用层次遍历
    while(front!=rear){
        int current_account=0;//记录每层的个数
        for(int i=0;i<count;i++){
            Bitree current = Q[front++]
            if(current->left!=NULL){
                Q[rear++]=current->left;
                current_account++;
            }
            if(current->right!=NULL){
                Q[rear++]=current->right;
                current_account++;
            }
            if(current->left==NULL&&current->right==NULL){
                wpl+=(stage-1)*current->weight;//计算节点的路径权值
            }
        }
        account=current_account;
        satge++;
    }
    return wpl;
}





/*************************2017真题********************************* */
typedef struct node{
    char data[10];
    struct node *left,*right;
}BTree;
String True_answer(BTree * T){
    if(T==NULL){
        return "";
    }
    if(T->right==NULL&&T->left==NULL){
        return T->data[0];
    }
    return "("+True_answer(T->left)+T->data[0]+True_answer(T->right)+")";
} 





