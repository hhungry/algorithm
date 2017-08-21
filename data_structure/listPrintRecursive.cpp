
//递归方式实现逆序打印链表元素
void listPrintRecursively(ListNode *head){
    if(head){
        if(head->next){
            listPrintRecursively(head->next);
        }
        cout<<head->data<<" ";
    }
}

//递归方式实现正序打印链表元素
void listPrintRecursively(ListNode *head){
    if(head){
        cout<<head->data<<" ";
        if(head->next){
            listPrintRecursively(head->next);
        }
    }
}
