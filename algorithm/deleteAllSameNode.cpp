#include <iostream>

using namespace std;

typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode,*LinkList;

void deleteAllSameNode(ListNode **head,int data){
    if(head==NULL||*head==NULL)
        return ;
    ListNode *pre=NULL;
    ListNode *curr=*head;
    ListNode *pnext=NULL;
    while(curr&&curr->val==data){
        pnext=curr->next;
        delete curr;
    }
    if(curr==NULL){
        *head=NULL;
        return ;
    }
    else{
        *head=curr;
        pre=curr;
        curr=curr->next;
    }
    while(curr){
        if(curr->val==data){
            pnext=curr->next;
            pre->next=pnext;
            delete curr;
            curr=pnext;
        }
        else{
            pre=curr;
            curr=curr->next;
        }
    }
}
