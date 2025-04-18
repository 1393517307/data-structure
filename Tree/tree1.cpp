#include<iostream>
#include<struct.h>
using namespace std;

struct TreeNode{
  int val;
  TreeNode*left;
  TreeNode*right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {};
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
} ;

int arr[]={5,4,8,11,-1,13,4,7,2,-1,-1,-1,1};
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

  //[3,9,20,15,7]   in:[9,3,15,20,7]
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
   int size=inorder.size();
   if(size==0)
   {
      return nullptr;
   }
   int rootData=preorder[0];
   TreeNode* root=new TreeNode(rootData);
   int pos;
   for(int i=0;i<size;i++)
   {
      if(inorder[i]==rootData)
        pos=i;
   }
   if(size==1)
     return root;
   vector<int> lftInOrder(inorder.begin(),inorder.begin()+pos);
   int number=lftInOrder.size();
   vector<int> leftPreOrder(preorder.begin()+1,preorder.begin()+1+number);

   vector<int> rgtInOrder(inorder.begin()+1+pos,inorder.end());
   vector<int> rgtPreOrder(preorder.begin()+1+number,preorder.end());
   root->left=buildTree(leftPreOrder,lftInOrder);
   root->right=buildTree(rgtPreOrder,rgtInOrder);
   return root;
}






// unordered_map<int, int> indx;
// TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart) {
//     if (inorder.empty() || postorder.empty()) return nullptr;
//     int rootData = postorder.back();
//     TreeNode* node = new TreeNode(rootData);
//     postorder.pop_back();  // Remove the root element from postorder for next recursion
//     int pos = indx[rootData];
//     if (pos > inStart) {
//         vector<int> lInOrder(inorder.begin() + inStart, inorder.begin() + pos);
//         vector<int> lPsOrder(postorder.begin(), postorder.begin() + lInOrder.size());
//         node->left = build(lInOrder, lPsOrder, inStart);
//     }
//     if (pos < inorder.size() - 1) {
//         vector<int> rInOrder(inorder.begin() + pos + 1, inorder.end());
//         vector<int> rPsOrder(postorder.begin() + lInOrder.size(), postorder.end());
//         node->right = build(rInOrder, rPsOrder, pos + 1);
//     }
//     return node;
// }

// TreeNode* buildTreePost(vector<int>& inorder, vector<int>& postorder) 
// {
//     int size=inorder.size();
//     for(int i=0;i<size;i++)
//     {
//        indx[inorder[i]]=i;
//     }
//     return build(inorder,postorder,0);
// }

// /：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]


//前序遍历树
void PrePrintTree(TreeNode *treeNode)
{
   if(treeNode==nullptr)
    return;
  cout<<(treeNode->val)<<"--";
  PrePrintTree(treeNode->left);
  PrePrintTree(treeNode->right);
}


//相同树
bool isSameTree(TreeNode* p, TreeNode* q)
{
  if(p==nullptr&&q==nullptr)//都为空
  {
     return true;
  }
  if(p==nullptr||q==nullptr||p->val!=q->val)//两边不同
  {
    return false;
  }
  return  isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);//当前层相同，比较下一层
}

//对称树
bool isSymmetric(TreeNode* root)
{
  if (root == nullptr) {
      return true; // 空树是对称的
  }
  queue<TreeNode*> leftNodes;
  queue<TreeNode*> rightNodes;
  leftNodes.push(root->left);
  rightNodes.push(root->right);
  while (!leftNodes.empty()&&!rightNodes.empty())
  {
      TreeNode* tempLNode=leftNodes.front();
      TreeNode* tempRNode=rightNodes.front();
            leftNodes.pop();rightNodes.pop();
      if(tempLNode==nullptr&&tempRNode==nullptr)
      {
        continue;
      }
      if(tempLNode==nullptr||tempRNode==nullptr||tempLNode->val!=tempRNode->val)
      {
        return false;
      }
      leftNodes.push(tempLNode->left);leftNodes.push(tempLNode->right);
      rightNodes.push(tempRNode->right);rightNodes.push(tempRNode->left);
  }
  return leftNodes.empty()&&rightNodes.empty();
}

//反转树 dfs 
TreeNode* invertTree(TreeNode* root) {
      if(root==nullptr)
        return nullptr;
      TreeNode* tempNode=root->left;
      root->left=root->right;
      root->right=tempNode;
      if(root->left!=nullptr)
        invertTree(root->left);
      if(root->right!=nullptr)
        invertTree(root->right);
      return root;
}

//目标路径和 wfs
bool hasPathSum(TreeNode* root, int targetSum) {
    if(root==nullptr)
      return false;
    queue<TreeNode*> nodes;
    queue<int> targets;
    nodes.push(root);
    targets.push(root->val);
    while ((!nodes.empty()))
    {
       int size=nodes.size();
       while (size>0)
       {
          TreeNode* tempNode=nodes.front();nodes.pop();
          int parentNum=targets.front();targets.pop();
          if(tempNode->left==nullptr&&tempNode->right==nullptr&&parentNum==targetSum)//获得目标深度的 叶子结点 返回true
            return true;
          if(tempNode->left!=nullptr)
          {
            nodes.push(tempNode->left);
            targets.push(parentNum+(tempNode->left->val));
          }
          if(tempNode->right!=nullptr)
          {
            nodes.push(tempNode->right);
            targets.push(parentNum+(tempNode->right->val));
          }
       }
    }
    return false; 
}
//[5,4,8,11,null,13,4,7,2,null,null,null,1]




int main()
{
  // TreeNode* root;
  // PreCreatTree(root);
  // PrePrintTree(root);

  //inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
  // vector<int> v{9,3,15,20,7};
  // vector<int> v2{9,15,7,20,3};
  // TreeNode* root=buildTreePost(v,v2);
  // PrePrintTree(root);
}