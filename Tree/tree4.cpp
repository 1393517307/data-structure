#include<iostream>
#include<vector>
#include<string>
 using namespace std;
 //搜索树

 class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

struct TreeNode{
  int val;
  TreeNode*left;
  TreeNode*right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

int arr[]={1,2,4,-1,-1,-1,3,-1,5};
int length = sizeof(arr) / sizeof(arr[0]);
int*p=arr;
int* endArr=arr+length;//地址相加减只能进行指针偏移
void PreCreatTree(TreeNode *&bitTree)//指针只是一个变量，和引用还是有差别的，引用是直接改变传进来的变量，指针做参数不会对指针变量进行更新赋值
{
   if(p==endArr)//最后一个元素不
   {
     return;
   }
   if(*p==-1)//空元素
   {
    bitTree=nullptr;
    p++;
     return;
   }
   int num=*p;
   p++;
   bitTree=new TreeNode(num);
   PreCreatTree(bitTree->left);
   PreCreatTree(bitTree->right);
}


int getMinimumDifference(TreeNode* root) 
{
    stack<TreeNode*> nodes;
    nodes.push(root);
    while (!nodes.empty())
    {
        TreeNode* tempNode=nodes.top();nodes.pop();
        if(tempNode->left)
        {
            nodes.push(tempNode->left);
        }
        if(tempNode->right)
        {
            nodes.push(tempNode->right);
        }
    }
    
}

int main()
{

}