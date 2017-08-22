#include<iostream>
#include<string>

//以下分别展示浅拷贝、深拷贝

//行为像指针的类
class TreeNode{
private:
    std::string value;
    int *cnt;
    TreeNode *left;
    TreeNode *right;
public:
    TreeNode():value(std::string()),cnt(new int(1)),left(nullptr),right(nullptr){}
    TreeNode(const TreeNode& rhs):value(rhs.value),cnt(rhs.cnt),left(rhs.left),right(rhs.right) {++*cnt;}
    TreeNode& operator=(const TreeNode &rhs){
        ++*rhs.cnt;
        if(--*cnt==0){
            delete cnt;
            delete left;
            delete right;
        }
        value=rhs.value;
        cnt=rhs.cnt;
        left=rhs.left;
        right=rhs.right;
        return *this;
    }
    ~TreeNode(){
        if(--*cnt==0){
            delete cnt;
            delete left;
            delete right;
        }
    }
};

//行为像值的类
class BinStrTree{
private:
    TreeNode *root;
public:
    BinStrTree():root(new TreeNode){}
    BinStrTree(const BinStrTree& rhs):root(new TreeNode(*rhs.root)){}
    BinStrTree& operator=(const BinStrTree& rhs){
        
	//先进行内存申请，再释放原有内存，可以保证异常安全性，防止因为内存不足申请内存失败，自身状态又发生了改变.
	TreeNode *tmp=new TreeNode(*rhs.root);
        delete root;
        root=tmp;
        return *this;
    }
    ~BinStrTree(){
        delete root;
    }
};
