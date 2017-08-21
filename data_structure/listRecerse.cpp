
//用头插法实现单链表逆置
void listReverse(LinkList L){
    if(!L||!L->next){
        return ;
    }
    LinkList p=L->next;
    LinkList q=nullptr;
    L->next=nullptr;
    for(;p;){
        q=p->next;
        p->next=L->next;
        L->next=p;
        p=q;
    }
}

void listReverse1(ListNode **head){
    if(*head==nullptr)
        return ;
    ListNode *pre=nullptr;
    ListNode *curr=*head;
    ListNode *pnext=nullptr;
    while(curr){
        pnext=curr->next;
        if(!pnext)
            *head=curr;
        curr->next=pre;
        pre=curr;
        curr=pnext;
    }
}
