#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
} TreeNode;

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    stack<vector<int>> vStack;
    vStack.push(nums);
    while (vStack.empty())
    {
        vector<int> tempV = vStack.top();vStack.pop();
        int size = tempV.size();
        // 既是左右个数，也是中间索引
        int middle = size / 2;
        vector<int> lV(tempV.begin(), tempV.begin() + middle);
        vector<int> rV(tempV.begin() + middle + 1, tempV.end());
        vStack.push(lV);
        vStack.push(rV);
        TreeNode *node = new TreeNode(tempV[middle]);
    }

    int size = nums.size();
    // 既是左右个数，也是中间索引
    int middle = size / 2;
    vector<int> lV(nums.begin(), nums.begin() + middle);
    vector<int> rV(nums.begin() + middle + 1, nums.end());
    TreeNode *node = new TreeNode(nums[middle]);
    if (lV.size() != 0)
    {
        node->left = sortedArrayToBST(lV);
    }
    if (rV.size() != 0)
    {
        node->right = sortedArrayToBST(rV);
    }
    return node;
}
int main()
{
    vector<int> a{-10, -3, 0, 5, 9};
    sortedArrayToBST(a);
    cout << "ss";
}