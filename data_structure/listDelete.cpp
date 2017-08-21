//常量时间O(1)内删除指定节点
void listDelete(ListNode **head,ListNode *pToBeDeleted){
    if(!head||!*head||!pToBeDeleted)
        return ;
    if(pToBeDeleted->next!=nullptr){
        ListNode *pnext=pToBeDeleted->next;
        pToBeDeleted->data=pnext->data;
        pToBeDeleted->next=pnext->next;
        delete pnext;
        pnext=nullptr;
    }else if(*head==pToBeDeleted){
        *head=nullptr;
    }else{
        ListNode *p=*head;
        while(p&&p->next!=pToBeDeleted)
            p=p->next;
        p->next=nullptr;
        delete pToBeDeleted;
        pToBeDeleted=nullptr;
    }
}
