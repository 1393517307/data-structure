#include<iostream>
#include<vector>
#include<string>
using namespace std;

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
} ;

int arr[]={1,2,3};
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





//左节点连右节点
Node* connect(Node* root)
{
    if(root==nullptr)
       return nullptr;
    queue<Node*> nodes;
    nodes.push(root);
    while (!nodes.empty())//wfs
    { 
       int size=nodes.size();
       while (size>0)
       {  
          Node* tempNode=nodes.front();nodes.pop();size--;
          if(tempNode->left!=nullptr)
             nodes.push(tempNode->left);
          if(tempNode->right!=nullptr)
             nodes.push(tempNode->right);
          if(size>=1)
            tempNode->next=nodes.front();
       }
    }
    return root;
}



//树变链表
//队列：广度优先    栈：深度优先
void flatten(TreeNode* root)  
{
    if(!root)
      return;
    stack<TreeNode*> nodes;
    nodes.push(root);
    TreeNode* preNode=nullptr;
    while (!nodes.empty())
    {
        TreeNode*node=nodes.top();nodes.pop();
        if(node->right)
        {
            nodes.push(node->right);node->right=nullptr;
        }
        if(node->left)
        {
            nodes.push(node->left);node->left=nullptr;
        }
        if(preNode)
        {
            preNode->right=node;
        }
        preNode=node;
    }
}
//1:递归调用内存大 要记录函数调用时状态 调用一次函数压入栈中  是函数的后进先出
//2:循环的遍历相对复杂 是对数据显式的压入栈，是数据的后进先出

   
    int sumNumbers(TreeNode* root) 
    {
       stack<TreeNode*> nodes;
       stack<int> parentStatus;
       int totalNum=0;
       nodes.push(root);
       parentStatus.push(0);
       while (!nodes.empty())
       {
           int parentNum=parentStatus.top();parentStatus.pop();
           TreeNode* node=nodes.top();nodes.pop();
           int Num=parentNum*10+(node->val);
           if(node->right)
           {
              nodes.push(node->right);
              parentStatus.push(Num);
           }
           if(node->left)
           {
               nodes.push(node->left);
               parentStatus.push(Num);
           }
           if(!node->right&&!node->left)//叶子结点
           {
              totalNum+=Num;
           }
       }
       return totalNum;
    }

int main()
{
   TreeNode* root;
   PreCreatTree(root);
   cout<<sumNumbers(root);
   
}