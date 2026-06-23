void separt(Linklist L ,LinkList A,LinkList B){
    LinkNode* pre = L->next;
    B=(LinkNode*)malloc(sizeof(LinkNode));
    B->next=NULL;
    while(pre->next!=NULL){
        LinkNode*p=pre->next;
        pre->next=p->next;
        p-next=B->next;
        B-next=p;
        pre=pre-next;
    }
    A=L;
}

void DeleteSame(LinkList L){
    if(L->next==NULL||L->next->next==NULL) return ;
    LinkNode* pre=L->next;
    LinkNode* p = pre->next;
    while(pre->next!=NULL){
        if(pre->data==p->data){
            LinkNode* del = p;
            p=p->next;
            pre->next=p;
            free(del);
        }
        else{
            pre=p;
            p=p->next;
        }
    }
}


bool Judege(LinkList A,LinkList B){
    LinkNode* index_start = A->next;
    // LinkNode* judge_index = B->next;
    while(index_start!=NULL){
        LinkNode *judge_index_B = B->next;
        LinkNode *judge_index_A = index_start;
        while(judge_index_B!=NULL&&judge_index_A!=NULL){
            if(judge_index_A->data==judge_index_B->data){
                judge_index_A=judge_index_A->next;
                judge_index_B=judge_index_B->next;
            }else{
                break;
            }
            if(judge_index_B==NULL) return true;
        }
        index_start=index_start->next;
    }
    return false;
}
 




bool JudegeSymmetry(LinkList L){
    LinkNode*p =L;
    LinkNode*q =L;
    while(p!=q||p->next!=q->next){
        if(p->data==q->data){
            p=p->next;
            q=q->prior;
        }
        else return false;
    }
    return true;
}

void Connect (LinkList h1 ,LinkList h2){
    LinkNode*rear_h1,rear_h2,p=h1;
    while(p->next!=h1){
        p=p->next;
    }
    rear_h1=p;
    p=h2;
    while(p->next!=h2){
        p=p->next;
    }
    rear_h2 = p;
    rear_h1-next=h2-next;
    rear_h2-next=h1;
}  



LinkNode * Locate(LinkList L,ElemType x){
    LinkNode*p=L->next;
    while(p!=NULL&&p->data!=x){//p->data!=x&&p!=NULL这么写是错的，交换次序
        p=p->next;
    }               //找到这个x值指针
    if(p==NULL) return NULL;
    p->freq++;
    //删除该节点
    if(p->next==NULL){//处理此节点再尾端的情况
        p->pre->next==NULL;
    }
    else{
        p->next->pre=p->pre;
        p->pre->next=p->next;
    }
    LinkNode * N=L->next;
    while(N->next!=NULL){
        if(N->freq>p->freq){
            N=N->next;
        }
        else break;
    }//找到此节点的前置节点
    if(N->next!=NULL){
        p->next=N->next;
        p->pre=N;
        N->next->pre=p;
        N-next=p;
        return p;
    }
    N->next=p;
    p->pre=N;
    p->next=NULL;
    return p;
}j

Locate(LinkList L,ElemType x){
    LinkNode* prar=L;
    while(prar->next!=NULL&&prar->next->data!=x){
        prar=prar->next;
    }
    if(prar->next==NULL)
    return NULL;


    //找到这个节点
    LinkNode* p=prar->next;
    prar->next=p->next;
    if(p->next!=NULL)
        p->next->pre=prar;
    //摘除节点
    p-freq++;

    LinkNode* insert=L;
    while(insert->next!=NULL&&insert->next->freq>p-freq){
        insert=insert->next;
    }
    //找到插入位置
    p->next=insert->next;
    p->pre=insert;
    if(insert->next!=NULL)
        insert->next->pre=p;
    insert->next=p;
    
    return p;
}

void (LinkList L,int n,int k){
    if(n<=k){
        return ;
    }
    LinkNode* B=L;
    LinkNode*B_pre=L;
    for(int i=0;i<n-k;i++){
        B=B->next;
        if(i>=1){
            B_pre=B_pre->next;
        }
    }
    B_pre->next=NULL;
    //将这个要移动子链表的那个抽出来
    for(int i=0;i<k;i++){
        LinkNode* insert=B;
        B=B->next;
        insert->next=L；
        L=insert;
    }
    //头插入
    return
}
//基本思想：把整个完整的数据链，拆成两半，一个长度为k，另一个为n-k
//然后将长度为k的一次头插入这个n-k的链表中；
//时间复杂度O（n）


bool check_circle(LinkList L){（
    LinkNode *  quick =L;
    LinkNode *  slow = L;
    while(quick && slow){
        if(quick->next!=NULL&& quick->next->next!=NULL)
            quick=quick->next->next;
        else
            break;

        slow=slow->next;
        //slow走的慢所以就可以直接移动不用判断

        if(slow==quick){
            return true;
        }
        //这里是这个慢指针追上了这个快指针。
    }
    
    //quick 或者 slow 有人到了末尾
    return false;
}


int  Find_man_RelElmSUb(LinkList L,int n){
    LinkNode * rear_list=L;
    LinkNode * rear=L;
    for (int i=0;i<n/2;i++){
        rear_list=rear_list->next;
        // if (i==n/2-2){
        //     //LinkNode * rear =rear_list;
        //     rear = rear_list;
        // }
    }
    for (int i=0;i<n/2-1;i++){
        rear=rear-next;
    }
    rear->next=NULL;
    //开始逆置
    for (int j=0;j<n/2;j++){
        LinkNode * insert=rear_list;
        rear_list=rear_list->next;
        insert->next=rear->next;
        rear->next=insert;
    }
    rear=rear->next;
    int max=L->data+rear->data;
    LinkNode * pre =L;
    for(int m=0;m<n/2-1;m++){
        pre=pre->next;
        rear= rear->next;
        int current = rear->data+pre->data;
        if(current >max){
            max= current;
        }
    }
    return max; 
}
//首先我们设立两个指正快指针和慢指针，快一次走两步，慢一次走一步。
//我们不停走，如果快指针碰到了NULL则无环，如果慢指针和快指针一样，那就有环

//时间复杂度O（n）,空间复杂度O（1）.


//主要思想：1.首先我们我们将这个单链表分成两半，将后链表进行反转
//        2.在分别从前半链表和后半链表分别遍历此链表，一次将对应元素加起来即可
//        3.在遍历的同时进行这个大小比较即可。




//**************真题2009*************************/

int find_element(LinkList L,int k){
    LinkNode * P=L;
    int length=0;
    //遍历看链表长度
    while(P->next!=NULL){
        length++;
        P=P->next;
    }

    if(length<k){
        return 0;
    }else{
        int time=length-k+1;//目标节点正数位置
        LinkNode*real=L;
        for(int i=0;i<time;i++){
            real=real->next;
        }
        printf("%d",real->data);
    }
    return 1;
}
//（1）：基本思想：首先遍历整个链表查看链表长度，其次再根据导数数字倒推正数位置，再次遍历找到该目标元素
//(2):首先用for循环，再用减法计算出第二次遍历所要移动次数，在用for循环遍历一次找到目标元素。


/****************真题2012*******************************/

int length (LinkList L){
    int i=0;
    while(L->next!=NULL){
        i++;
        L=L->next;
    }
    return i;
}
LinkNode *  find_same_place(LinkList L1,LinkList L2){
    int length1=length(L1);
    int length2= length(L2);
    int same_number=0;
    LinkNode * P1=L1;
    LinkNode * P2=L2;
    //使得他们尾部长度一致
    if(length1>=length2){
        int more=length1-length2;
        for(int i=0;i<more;i++){
            P1=P1->next;
        }
    }else{//
        int more =length2-length1;
        for(int i=0;i<more ;i++){
            P2=P2->next;
        }
    }
    while(P2->next!=NULL){
            P2=P2->next;
            P1=P1->next;
            if(P2->data==P1->data){
                same_number++;
            }else{
                same_number=0;
            }
    }
    //找到相同长度;
    LinkNode* real=L1;
    int time= length1-same_number+1;
    for(int i=0;i<time;i++){
        real=real->next;
    }
    return real;
}

//基本思想：首先计算这个两个链表的长度，再通过遍历长的队列，使得长队列和短队列长度一致。再同时遍历两个队列如果元素相等就number++，如果不同那就number置0，直到遍历到最后
//我们得到相同元素的长度我们再从头遍历找到那个目标位置。
//时间复杂度O（L1+L2）



/********************真题2015********************************/
int abs(int A){
    if (a<0)
        return -a;
    else
        return a;
}
void delete_same_abs_element(LinkList L,int m,int n){
    //int arr1[n]={0};
    int arr1*=(int *)malloc((n+1)*sizeof(int));
    LinkNode * pre = L;
    LinkNode * p = L->link;
    while(p!=NULL){
        int element_abs=abs(p->data);
        if(arr1[element_abs]==0){
            arr1[element_abs]=1;
            p=p->link;
            pre=pre->link;
        }else{
            pre->link=p->link;
            p=pre->link;
        }
    }
    free(arr1);
}

//基本思想:首先准备一个长度和n数字限制大小一致的数组（初始全为0）。紧接着遍历整个数组遇到数字后在这个数组里标记他出没出现过（0为未出现，1为出现）,若出现则删除，若未出现则置1。

typedef struct LinkNode{
    int data;
    LinkNode* link;
}LinkNode,*Linklist;
//时间复杂度O（m）空间复杂度O（n）

/**************************************************************/



/*************************2019真题**************************************/
typedef struct node{
    int data;
    struct node* next;
}NODE;

//主要思想：将这个链表分成两部分一前一后，然后我们将后面的链表逆置，然后一次插入这个第一个链表当中

void reverse (*NODE L){
    *NODE current = L->next;
    L->next=NULL;
    while(current!=NULL){
        * NODE insert = current;
        insert->next=L;
        L=insert;
        current=current->next;
    }
    return L;
}
void take_special_list (* NODE L){
    *NODE p1=L;
    *NODE p2 = L;
    while(p2->next==NULL){
        p1=p1->next;
        p2=p2->next;
        if(p2->next!=NULL)
            p2=p2->next; //p2走两步
    }
    * NODE pre = L;
    while(pre->next!=p1){
        pre=pre->next;
    }
    pre->next=NULL;//断开前后连接


    reverse(p1);
    * NODE p=L->next;
    while(p!=NULL){
        *current = p1;
        p1=p1->next;
        current->next=p->next;
        p=p->next;
        if(p->next!=NULL){//处理特殊情况，奇数队列，后队列会比前长一
            p=p-next;
        }
    }
    
}