#include<iostream>
#include<vector>
#include<string>
 using namespace std;
//层级遍历
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

//右边视角
//[1,2,3,4,null,null,5]
//  1
// 2 3
//4    5

vector<int> rightSideView(TreeNode* root)
{
    queue<TreeNode*> nodes;
    vector<int> allNums;
    if(!root)
      return allNums;
    nodes.push(root);                       
    while (!nodes.empty())
    {
        int size=nodes.size();
        while (size>1)//遍历每一层 留下最右边一个
        {
            TreeNode* node=nodes.front();nodes.pop();
            size--;
            if(node->left)
            {
                nodes.push(node->left);
            }
            if(node->right)
            {
                nodes.push(node->right);
            }
        }

        TreeNode* node=nodes.front();nodes.pop();
        if(node->left)
        {
            nodes.push(node->left);
        }
        if(node->right)
        {
            nodes.push(node->right);
        }
        allNums.push_back(node->val);
    }
    return allNums;
}

//层级平均数
vector<double> averageOfLevels(TreeNode* root) 
{
    queue<TreeNode*> nodes;
    vector<double> allNums;
    if(!root)
      return allNums;
    nodes.push(root);
    int size;
    int tempSize;
    double levelNum;
    while (!nodes.empty())
    {
        size=nodes.size();
        tempSize=size;
        levelNum=0;
        while (size>0)//遍历每一层 留下最右边一个
        {
            TreeNode* node=nodes.front();nodes.pop();
            levelNum+=node->val;
            size--;
            if(node->left)
            {
                nodes.push(node->left);
            }
            if(node->right)
            {
                nodes.push(node->right);
            }
        }
        allNums.push_back(levelNum/tempSize);
    }
    return allNums;
}

//来回层级遍历
vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
    deque<TreeNode*> deNodes;
    vector<vector<int>> levelOrder;
    if(!root)
      return levelOrder;
    deNodes.push_back(root);
    bool isReversal=false;
    while (!deNodes.empty())
    {
        int  size=deNodes.size();
        vector<int> levelNum;
        while (size>0)
        {
            TreeNode* node;
            if(!isReversal)//顺着读 插尾
            {
                node=deNodes.front();deNodes.pop_front();
                if(node->left)
                {
                    deNodes.push_back(node->left);
                }
                if(node->right)
                {
                    deNodes.push_back(node->right);
                }
            }else//逆着读 插首
            {
                node=deNodes.back();deNodes.pop_back();
                if(node->right)
                {
                    deNodes.push_front(node->right);
                }
                if(node->left)
                {
                    deNodes.push_front(node->left);
                }
            }
            levelNum.push_back(node->val);
            size--;
        }
        isReversal=!isReversal;//反转下次顺序
        levelOrder.push_back(levelNum);//添加一层的顺序
    }
    return levelOrder;
}


int main()
{
   TreeNode* root;
   PreCreatTree(root);
   zigzagLevelOrder(root);
}