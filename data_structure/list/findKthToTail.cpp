//标记输入参数的合理性
bool invalidInput=false;

//链表中倒数第k个节点
ListNode* findKthToTail(ListNode *L,int i){
    if(L==nullptr||L->next==nullptr){
        invalidInput=true;
        return nullptr;
    }
    ListNode *p=L->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i){
        invalidInput=true;
        return nullptr;
    }

    ListNode *q=L->next;
    while(p->next!=nullptr){
        q=q->next;
        p=p->next;
    }
    return q;

}

