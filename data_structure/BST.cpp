#include <iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<functional>
#include<map>
#include<utility>
#include<stack>
using namespace std;
typedef struct BiTNode{
    int val;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

const BiTNode* searchBST(const BiTNode *root,int val){
    while(root){
        if(root->val==val)
            return root;
        else if(root->val>val)
            root=root->lchild;
        else root=root->rchild;
    }
    return nullptr;
}

bool searchBST(BiTNode *root,int val,BiTNode* (&p)){
    if(root==nullptr){
        p=nullptr;
        return false;
    }
    while(root){
        p=root;
        if(root->val==val)
            return true;
        else if(root->val>val)
            root=root->lchild;
        else root=root->rchild;
    }
    return false;
}
bool insertBST(BiTree &root,int val){
    BiTNode *p;
    if(!searchBST(root,val,p)){
        BiTNode *s=new BiTNode;
        s->lchild=s->rchild=nullptr;
        s->val=val;
        if(p==nullptr)
            root=s;
        else if(p->val>val)
            p->lchild=s;
        else p->rchild=s;
        return true;
    }
    return false;
}

void deleteBSTCore(BiTree &p){
    BiTree q=nullptr,s=nullptr;
    if(p->lchild==nullptr){
        q=p;
        p=p->rchild;
        delete q;
    }else if(p->rchild==nullptr){
        q=p;
        p=p->lchild;
        delete q;
    }else{
        q=p;
        s=p->rchild;
        while(s->lchild){
            q=s;
            s=s->lchild;
        }
        p->val=s->val;
        if(p==q)
            q->rchild=s->rchild;
        else q->lchild=s->rchild;
        delete s;
    }
}

bool deleteBST(BiTree root,int val){
    BiTree p=root;
    while(p){
        if(p->val==val){
            deleteBSTCore(p);
            return true;
        }
        else if(p->val>val)
            p=p->lchild;
        else p=p->rchild;
    }
    return false;
}

void inTraverse(BiTNode *root){
    if(root){
        inTraverse(root->lchild);
        cout<<root->val<<" ";
        inTraverse(root->rchild);
    }


}
int main()
{
    BiTNode *root=nullptr;
    vector<int> src{49,38,65,97,76,13,27,49,-1,100};
    for(auto ele:src){
        insertBST(root,ele);
    }
    inTraverse(root);
    cout<<endl;

    deleteBST(root,13);
    inTraverse(root);
    cout<<endl;

}




