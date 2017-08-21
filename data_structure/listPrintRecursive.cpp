
//递归方式实现逆序打印链表元素
void listPrintRecursively(ListNode *head){
    if(head){
        if(head->next){
            listPrintRecursively(head->next);
        }
        cout<<head->data<<" ";
    }
}
