#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
typedef struct LinkNode{
    int val;
    struct LinkNode *next;
}LinkNode,*LinkList;

LinkList createList(){
    LinkList L=new LinkNode;
    L->next=NULL;
    int value=0;
    while(cin>>value){
        LinkNode *node=new LinkNode;
        node->val=value;
        node->next=L->next;
        L->next=node;
    }
    return L->next;
}
void moveOddBeforeEven(LinkNode **head){
    LinkNode *L1=new LinkNode;
    L1->next=NULL;
    LinkNode *L2=new LinkNode;
    L2->next=NULL;
    LinkNode *odd=L1,*even=L2;
    for(LinkNode *curr=*head;curr!=NULL;curr=curr->next){
        if(curr->val&0x01){
            odd->next=curr;
            odd=curr;
        }
        else{
            even->next=curr;
            even=curr;
        }
    }
    even->next=NULL;
    odd->next=L2->next;
    *head=L1->next;
}
int main()
{
   LinkNode *head=createList();
   moveOddBeforeEven(&head);
   for(LinkNode *curr=head;curr!=NULL;curr=curr->next)
        cout<<curr->val<<" ";
   cout<<endl;
   return 0;
}
