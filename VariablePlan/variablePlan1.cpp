#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
// 和分治很像
// 这个就是将没一个决策都分别计算出来 然后记录
// 由前面的决策计算出后面每一次的最佳决策

// 爬楼梯
// 因为只有两步
// 所以每一步路径数 都等于前两步路径数之和
int climbStairs(int n)
{
    if (n == 1)
    {
        return 1;
    }
    int pre = 1;
    int cur = 1;
    int next = 0;
    for (int i = 2; i <= n; i++) // d[i]=d[i-1]+d[i-2]  pre=d[i-2] cur=d[i-1]
    {
        next = pre + cur;
        pre = cur;
        cur = next;
    }
    return cur;
}

// 偷东西
// 每次最大利益 等于一个房子之前最大利益加目前房子利益
// 连续的两个房子利益 总有一个是最大利益 覆盖了
int rob(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }
    if (nums.size() == 1)
    {
        return nums[0];
    }
    // 1 2 3 4 5
    int pre = nums[0];
    int cur = nums[1];
    int maxInt = nums[0];
    for (int i = 2; i < nums.size(); i++)
    {
        int next = nums[i] + maxInt;
        pre = cur;
        cur = next;
        maxInt = max(maxInt, pre);
    }
    maxInt = max(maxInt, cur);
    return maxInt;
}

// 单词拆分
// 遍历s每一个位置能否被单词组成
// 每一个位置i 分为两部分进行判断前面i-length部分 和后面部分  length即为所有单词的长度，遍历每一个长度进行判断
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
    unordered_set<int> lengthSet;
    for (auto word : wordDict)
    {
        lengthSet.insert(word.size());
    }
    int len = s.length();
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    for (int i = 1; i <= len; i++)
    {
        for (auto length : lengthSet)
        {
            if (i < length)
            {
                continue;
            }

            int j = i - length;
            if (dp[j] && wordSet.count(s.substr(j, length)))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[len];
};

int coinChange(vector<int> &coins, int amount)
{
    // amount+1只是表示一个不可能的极大值，其数量最多为amount张1元
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (auto coin : coins)
        {
            // 只用算大于coin的币值
            if (i >= coin)
            {
                // 只有当i-coin也被算了dp时 才会赋值
                // 这时代表i-coin也大于等于最小币值
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int lengthOfLIS(vector<int> &nums)
{
    vector<int> dp(nums.size(), 1);
    int maxLength=1;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLength=max(maxLength,dp[i]);
            }
        }
    }
    return maxLength;
}

int main()
{
}