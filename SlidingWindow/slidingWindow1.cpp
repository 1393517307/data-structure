#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// 数组和最小大于target长度
int minSubArrayLen(int target, vector<int> &nums)
{
    int ans, left, right, size, sum;
    ans = INT_MAX;
    left = 0;
    right = 0;
    size = nums.size();
    sum = 0;
    while (right < size)
    {
        // 入栈
        while (sum < target && right < size)
        {
            right++;
            sum += nums[right - 1];
        }
        if (sum < target)
        {
            break;
        }
        ans = min(ans, right - left);
        // 出栈
        while (sum >= target && left <= right - 1)
        {
            sum -= nums[left];
            left++;
        }
        ans = min(ans, right - left + 1);
    }

    return ans == INT_MAX ? 0 : ans;
}

// 最小无重复字符串
int lengthOfLongestSubstring(string s)
{
    int ans, left, length;
    ans = 0;
    left = 0;
    // 使用数组代替哈希 哈希表需要查找 数组速度比其快
    int char_map[256];
    memset(char_map, -1, sizeof(char_map));
    // 外层循环扩右窗口
    for (int right = 0; right < s.size(); right++)
    {
        unsigned char curChar = s[right];
        // 判断 当前元素在窗口之间是否出现过
        if (char_map[curChar] >= left)
        {
            left = char_map[curChar] + 1; // 直接跳跃左节点跃过相同元素
        }
        ans = max(right - left + 1, ans);
        char_map[curChar] = right;
    }
    return ans;
}

// 找出所有 子串集合
vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> result;
    if (words.empty())
    {
        return result;
    }
    int wordLen = words[0].size();
    int wordNum = words.size();
    int totalLen = wordLen * wordNum;
    int sLen = s.size();
    if (sLen < totalLen)
    {
        return result;
    }
    unordered_map<string, int> targetWordMap;
    for (const auto &word : words)
    {
        targetWordMap[word]++;
    }
    for (int left = 0; left <= sLen - totalLen; left++)
    {
        int right = left;
        // 出现相同子串次数
        int num = 0;
        // 记int 可以记录重复字符
        unordered_map<string, int> currentMap;
        while (num < wordNum)
        {
            string tempWord = s.substr(right, wordLen);
            right += wordLen;
            // 每遍历一个单词 判断一下是否有这个单词，且出现次数是否已经超过子串数量
            if (targetWordMap.find(tempWord) != targetWordMap.end() && currentMap[tempWord] < targetWordMap[tempWord])
            {
                currentMap[tempWord]++;
                num++;
            }
            else
            {
                // 一个不相同就进行下一轮
                break;
            }
        }
        if (num == wordNum)
        {
            result.push_back(left);
        }
    }
    return result;
}

// 找出所有 子串集合 滑动窗口版
// 1:通过对字符串s进行分组，分成wordlen组，每个组起点依次从0～wordlen开始，这样子因为滑动窗口的周期性覆盖加上所有分组 可以覆盖所有情况
// 2:滑动窗口每次向右截取一个单词，不满足条件直接跳过前面单词，每组内以单词长度为步长滑动窗口，避免冗余检查
vector<int> findSubstring2(string s, vector<string> &words)
{
    vector<int> result;
    if (words.empty())
    {
        return result;
    }
    int wordLen = words[0].size();
    int num = words.size();
    int sLen = s.size();
    int totalLen = num * wordLen;
    if (sLen < totalLen)
    {
        return result;
    }
    // 通过表记录出现次数 来代替链表的进出
    unordered_map<string, int> targetmap;
    for (auto word : words)
    {
        targetmap[word]++;
    }
    int left, right;
    for (int i = 0; i < wordLen; i++)
    {
        left = i;
        right = i;
        unordered_map<string, int> curMap;
        while (left + totalLen <= sLen)
        {
            // 右边界 右移 截取单词
            string curWord = s.substr(right, wordLen);
            right += wordLen;
            // 如果这个单词不是目标单词 跳过该单词
            if (targetmap.find(curWord) == targetmap.end())
            {
                curMap.clear();
                left = right;
            }
            else
            {
                // 是目标单词 入栈
                curMap[curWord]++;
                // 去掉重复多余的单词
                while (curMap[curWord] > targetmap[curWord])
                {
                    string leftWord = s.substr(left, wordLen);
                    curMap[leftWord]--;
                    if (curMap[leftWord] == 0)
                    {
                        curMap.erase(leftWord);
                    }
                    left += wordLen;
                }
                // 判断长度是否等于目标子串长度
                if (right - left == totalLen)
                {
                    result.push_back(left);
                }
            }
        }
    }
    return result;
}

string minWindow(string s, string t)
{
    string resultS;
    int sLen = s.size();
    int tLen = t.size();
    if (sLen == 0 || tLen == 0)
    {
        return resultS;
    }
    int mapSize = 0;
    int targetMap[256];
    memset(targetMap, 0, sizeof(targetMap));
    for (auto c : t)
    {
        if (targetMap[c] == 0)
        {
            mapSize++;
        }
        targetMap[c]++;
    }

    int curMap[256];
    memset(curMap, 0, sizeof(curMap));
    int num = 0;
    int left = 0;
    int start = 0;
    int ans = INT32_MAX;
    for (int right = 0; right < sLen; right++)
    {
        char curC = s[right];
        // t有该 字符  加进去
        if (targetMap[curC] > 0)
        {
            curMap[curC]++;
            // 达到目标字数
            if (curMap[curC] == targetMap[curC])
            {
                num++;
                while (num == mapSize)
                {
                    if (right - left + 1 < ans)
                    {
                        ans = right - left + 1;
                        start = left;
                    }
                    char leftC = s[left];
                    // 当左移会导致不满足条件时 出栈 num--
                    if (targetMap[leftC] == targetMap[leftC])
                    {
                        num--;
                    }
                    curMap[leftC]--;
                    left++;
                }
            }
        }
    }
    return s.substr(start, ans);
}

int main()
{
    // vector<int> a = {2, 3, 1, 2, 4, 3};
    // cout << "y:" << minSubArrayLen(7, a);

    // cout << "yy:" << lengthOfLongestSubstring("abcabcbb");
    vector<string> c = {"foo", "bar"};
    findSubstring("barfoothefoobarman", c);
}