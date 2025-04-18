#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    if (ransomNote.size() > magazine.size())
        return false;
    vector<int> charMap(26);
    // 统计magazine中每个字符的出现次数
    for (char c : magazine)
    {
        charMap[c - 'a']++; // 如果c已经存在，则增加计数；如果不存在，则插入并初始化为1，然后增加到2
    }

    // 检查ransomNote中的字符是否都能在magazine中找到足够的数量
    for (char c : ransomNote)
    {
        charMap[c - 'a']--;
        if (charMap[c - 'a'] < 0)
            return false;
    }
    return true;
}

bool isIsomorphic(string s, string t)
{
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;
    int len = s.length();
    for (int i = 0; i < len; ++i)
    {
        char x = s[i], y = t[i];
        if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
        {
            return false;
        }
        s2t[x] = y;
        t2s[y] = x;
    }
    return true;
}

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;
    istringstream istr(s);
    string out;
    int len = pattern.length();
    int i = 0;
    while (istr >> out)
    {
        char x = pattern[i++];
        string y = out;
        if (c2s.count(x) && c2s[x] != y || s2c.count(y) && s2c[y] != x)
        {
            return false;
        }
        else
        {
            c2s[x] = y;
            s2c[y] = x;
        }
    }
    if (i != len)
    {
        return false;
    }
    return true;
}

bool isAnagram(string s, string t)
{
    unordered_map<char, int> charNum;
    if (s.size() != t.size())
    {
        return false;
    }
    for (auto i : s)
    {
        charNum[i]++;
    }
    for (auto i : t)
    {
        if (!charNum.count(i) || charNum[i] == 0)
        {
            return false;
        }
        charNum[i]--;
    }
    return true;
}

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// 定义数字到字母的映射
unordered_map<char, string> digitToLetters = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}};
vector<string> letterCombinations(string digits)
{
    vector<string> numberMap;
    stack<char> stacks;

    stacks.push(digitToLetters[digits[0]][0]);
    while (!stacks.empty())
    {
    }
}

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numToIndex;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        int leftNum = target - nums[i];
        if (numToIndex.find(leftNum) == numToIndex.end())
        {
            numToIndex[nums[i]] = i;
        }
        else
        {
            return vector<int>{
                i, numToIndex[leftNum]};
        }
    }
    return vector<int>{};
}

bool isHappy(int n)
{
    unordered_set<int> numberSet;
    int result = n;
    while (result != 1)
    {
        // 求和
        int sum = 0;
        while (result >= 10)
        {
            int b = result % 10;
            result /= 10;
            sum += b * b;
        }
        sum += result * result;
        // 存在循环
        if (numberSet.find(sum) != numberSet.end())
        {
            return false;
        }
        // 没有出结果
        else
        {
            numberSet.insert(sum);
            result = sum;
        }
    }
    return true;
}

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> numsToIndex;
    for (int i = 0; i < nums.size(); i++)
    {
        if (numsToIndex.find(nums[i]) == numsToIndex.end())
        {
            numsToIndex[nums[i]] = i;
        }
        else
        {
            if (i - numsToIndex[nums[i]] <= k)
            {
                return true;
            }
            else
            {
                numsToIndex[nums[i]] = i;
            }
        }
    }
    return false;
}

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> nums_set(nums.begin(),nums.end());
    for(int i:nums_set)
    {
        int curNum=i;
        int length=1;
        //if(nums_set.)
    }
}

int main()
{
    cout << wordPattern("jquery", "jquery");
}