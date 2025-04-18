#include<iostream>
 using namespace std;

struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//dfs
int maxDepth(TreeNode* root) 
{
    if(root==nullptr)
    {
        return 0;
    }
    int height=1;
    int leftHeight=maxDepth(root->left);
    int rightHeight=maxDepth(root->right);
    int childHeight=leftHeight>rightHeight?leftHeight:rightHeight;
    return childHeight+height;
}

//wfs
int maxDepth2(TreeNode*root) 
{
    int height=0;
    queue<TreeNode*> nodeMap;
    nodeMap.push(root);
    while ((!nodeMap.empty()))
    {
        int Qz=nodeMap.size();
        while ((Qz>0))
        {
            TreeNode* node=nodeMap.front();nodeMap.pop();
            nodeMap.push(node);
            if(node->left!=nullptr)nodeMap.push(node->left);
            if(node->right!=nullptr)nodeMap.push(node->right);
            Qz--;
        }
        height++;  
    }  
    return height;
}




// int maxDepth(TreeNode* root) 
// {
//         if (root == nullptr) return 0;
//         queue<TreeNode*> Q;
//         Q.push(root);
//         int ans = 0;
//         while (!Q.empty()) {
//             int sz = Q.size();
//             while (sz > 0) {
//                 TreeNode* node = Q.front();Q.pop();
//                 if (node->left) Q.push(node->left);
//                 if (node->right) Q.push(node->right);
//                 sz -= 1;
//             }
//             ans += 1;
//         } 
//         return ans;
//  }


int main()
{
   //vector<int> v={1,2,3,null}
   vector<vector<int>> v={{0,1,2,0},{2,1,2,1},{1,2,1,2}};
  //setZeroes(v);
}