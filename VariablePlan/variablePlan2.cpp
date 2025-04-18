#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 初步判断求最短路径问题 动态规划与寻路算法的区别

// 三角形最短路径
int minimumTotal(vector<vector<int>> &triangle)
{
    if (triangle.empty())
    {
        return 0;
    }
    int n = triangle.size();
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            // 每次加上一层的 左右最小路径
            if (j == 0)
            {
                // 只能从正上方转移
                triangle[i][j] += triangle[i - 1][j];
            }
            else if (j == i)
            {
                // 只能从左上方转移
                triangle[i][j] += triangle[i - 1][j - 1];
            }
            else
            {
                // 从正上方或左上方转移
                triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
        }
    }
    // 返回最后一行的最小值
    return *min_element(triangle[n - 1].begin(), triangle[n - 1].end());
}

// 矩形最短路径
int minPathSum(vector<vector<int>> &grid)
{
    // 检查 grid 是否为空
    if (grid.empty() || grid[0].empty())
    {
        return 0; // 如果 grid 为空，返回 0
    }

    int xLen, yLen;
    yLen = grid.size();
    xLen = grid[0].size();
    vector<vector<int>> dp(yLen, vector<int>(xLen, -1));
    dp[0][0] = grid[0][0];
    // 初始化第一行
    for (int y = 1; y < xLen; y++)
    {
        dp[0][y] = dp[0][y - 1] + grid[0][y];
    }

    // 初始化第一列
    for (int x = 1; x < yLen; x++)
    {
        dp[x][0] = dp[x - 1][0] + grid[x][0];
    }

    // 填充 dp 数组
    for (int x = 1; x < yLen; x++)
    {
        for (int y = 1; y < xLen; y++)
        {
            dp[x][y] = grid[x][y] + min(dp[x - 1][y], dp[x][y - 1]);
        }
    }

    return dp[yLen - 1][xLen - 1];
}

// 带障碍物的矩形路径
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    // 检查 grid 是否为空
    if (obstacleGrid.empty() || obstacleGrid[0].empty())
    {
        return 0; // 如果 grid 为空，返回 0
    }
    if (obstacleGrid[0][0] == 1)
    {
        return 0;
    }
    // 行
    int m = obstacleGrid.size();
    // 列
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    // 初始化第一行
    for (int y = 1; y < n; y++)
    {
        if (obstacleGrid[0][y] == 1)
        {
            break;
        }
        dp[0][y] = 1;
    }

    // 初始化第一列
    for (int x = 1; x < m; x++)
    {
        if (obstacleGrid[x][0] == 1)
        {
            break;
        }
        dp[x][0] = 1;
    }

    // 填充 dp 数组
    for (int x = 1; x < m; x++)
    {
        for (int y = 1; y < n; y++)
        {
            if (obstacleGrid[x][y] == 1)
            {
                continue;
            }
            dp[x][y] = dp[x - 1][y] + dp[x][y - 1];
            // if(obstacleGrid[x-1][y]!=1)
            // {

            // }
            // if(obstacleGrid[x][y-1]!=1)
            // {

            // }
        }
    }
    return dp[m - 1][n - 1];
}

// dp记录为每个子串是否为回文串
// dp[i][j]为i～j位置是否为回文串
// 长度从短到长 起点从左到右 逐段记录
string longestPalindrome(string s)
{
    if (s.empty())
    {
        return "";
    }
    if (s.size() == 1)
    {
        return s;
    }
    int start = 0;
    int maxLen = 1;

    int sLen = s.size();
    vector<vector<bool>> dp(sLen, vector<bool>(sLen, false));
    for (int i = 0; i < sLen; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 0; i < sLen - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = s[i] == s[i + 1];
            start = i;
            maxLen = 2;
        }
    }
    for (int len = 3; len <= sLen; len++)
    {
        for (int i = 0; i <= sLen - len; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                start = i;
                maxLen = len;
            }
        }
    }
    return s.substr(start, maxLen);
}

// dp[i][j]为s1前i个字符  和s2前j个字符是否能组成s3前i+j字符是否匹配
// s1第一个字符与s3所有可能字符进行组合
// s2前两个字符与s3所有可能字符进行组合直到记录完所有组合 dp方程为  dp[i][j]=dp[i-1][j]&&s1[i-1]==s3[s3Index];或dp[i][j]=dp[i][j]||dp[i][j-1]&&s2[j-1]==s3[s3Index];
bool isInterleave(string s1, string s2, string s3)
{
    int s1Len = s1.size();
    int s2Len = s2.size();
    if (s1Len + s2Len != s3.size())
    {
        return false;
    }
    vector<vector<bool>> dp(s1Len + 1, vector<bool>(s2Len + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= s1Len; i++)
    {
        for (int j = 0; j <= s2Len + 1; j++)
        {
            int s3Index = i + j - 1;
            if (i > 0) // s1[i-1]在后
            {
                dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[s3Index];
            }
            if (j > 0) // s2[j-1]在后
            {
                dp[i][j] = dp[i][j] || dp[i][j - 1] && s2[j - 1] == s3[s3Index];
            }
        }
    }
    return dp[s1Len][s2Len];
}

// 记录子串的编程距离
// dp[i][j] 从word1前i个字符转化成word2前j个字符的最小编程距离
// 1:删除 dp[i-1][j]+1
// 2:插入 dp[i-1][j-1]+1
// 3:修改 dp[i][j-1]+1
//  最小编程次数 abc bcd
int minDistance(string word1, string word2)
{
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    // 上边界 一直插入
    for (int i = 0; i <= len2; i++)
    {
        dp[0][i] = i;
    }
    // 左边界 一直删除
    for (int i = 1; i <= len1; i++)
    {
        dp[i][0] = i;
    }
    // 处理中间
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (word1[i - 1] != word2[j - 1])
            {
                // 计算三种操作的最小值
                int replace = dp[i - 1][j - 1] + 1; // 替换操作
                int del = dp[i - 1][j] + 1;         // 删除操作
                int insert = dp[i][j - 1] + 1;      // 插入操作
                // 修改 删除 插入
                dp[i][j] = min({replace, del, insert});
            }
            else
            {
                // 不修改
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    return dp[len1][len2];
}

// 最大利益
int maxProfit(vector<int> &prices)
{
    int cash = 0;
    int hold = -prices[0];
    int size = prices.size();
    for (int i = 1; i < size; i++)
    {
        // 虽然表面是贪心 每次只基于前一天行为理论进行决策，但其实
        int tayDayCash = max(cash, hold + prices[i]);
        int tayDayHold = max(cash - prices[i], hold);
        cash = tayDayCash;
        hold = tayDayHold;
    }
    return cash;
}

// 最大正方形边长
int maximalSquare(vector<vector<char>> &matrix)
{
    if(matrix.empty()||matrix[0].empty())
    {
        return 0;
    }
    int h = matrix.size();
    int w = matrix[0].size();
    int max = 0;
    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++)
    {
        dp[i][0] = matrix[i][0] - '0';
        if (dp[i][0] > max)
            max = dp[i][0];
    }
    for (int j = 0; j < w; j++)
    {
        dp[0][j] = matrix[0][j] - '0';
        if (dp[0][j] > max)
            max = dp[0][j];
    }
    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            if(matrix[i][j]!='1')
            {
                continue;
            }
            int leftLen = dp[i][j - 1];
            int topLen = dp[i - 1][j];
            int ltLen = dp[i - 1][j - 1];
            dp[i][j] = min({leftLen, topLen, ltLen}) + 1;
            if (dp[i][j] > max)
            {
                max = dp[i][j];
            }
        }
    }
    return max*max;
}

int main()
{
    vector<vector<char>> matrix{{'0', '1'}, {'1', '0'}};
    maximalSquare(matrix);
}