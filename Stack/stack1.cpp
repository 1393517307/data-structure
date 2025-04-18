#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 有效括号
unordered_map<char, char> matchingParentheses = {
    {')', '('},
    {'}', '{'},
    {']', '['}};

bool isValid(string s)
{
    stack<char> charactMap;
    for (auto item : s)
    {
        if (charactMap.empty())
        {
            charactMap.push(item);
        }
        else if (matchingParentheses[item] == charactMap.top())
        {
            charactMap.pop();
        }
        else
        {
            charactMap.push(item);
        }
    }
    return charactMap.empty();
}

// 简化目录
string simplifyPath(string path)
{
    deque<string> pathStack;
    string s = "";
    int dot = 0;
    for (auto c : path)
    {
        if (c != '/') // 没有结束一个路径点就加
        {
            s += c;
        }
        else
        {
            if (s == "")
            {
                continue;
            }
            if (s == ".")
            {
            }
            else if (s == "..") // 上一级目录
            {
                if (!pathStack.empty())
                    pathStack.pop_back();
            }
            else
            {
                pathStack.push_back(s);
            }
            s = "";
        }
    }
    if (s == ".")
    {
    }
    else if (s == "..") // 上一级目录
    {
        if (!pathStack.empty())
            pathStack.pop_back();
    }
    else if (!s.empty())
    {
        pathStack.push_back(s);
    }
    path = "";
    for (auto item : pathStack)
    {
        path += ("/" + item);
        cout << item << endl;
    }
    if (path == "")
        path += "/";
    return path;
}

class MinStack
{
public:
    stack<int> s;
    stack<int> miniStack;
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        if (miniStack.empty() || val <= miniStack.top()) // 上面有小值机记录
        {
            miniStack.push(val);
        }
    }

    void pop()
    {
        if (miniStack.top() == s.top()) // 拿出一个目前最小值就弹一个
        {
            miniStack.pop();
        }
        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return miniStack.top();
    }
};

int evalRPN(vector<string> &tokens) // 从左往右，先遇到先计算
{
    stack<int> numStack;
    int result = 0;
    for (auto c : tokens)
    {
        if (c == "+" || c == "-" || c == "*" || c == "/") // 读到符号就进行计算
        {
            int num2 = numStack.top();
            numStack.pop();
            int num1 = numStack.top();
            numStack.pop();
            if (c == "+")
            {
                result = num1 + num2;
            }
            else if (c == "-")
            {
                result = num1 - num2;
            }
            else if (c == "*")
            {
                result = num1 * num2;
            }
            else if (c == "/")
            {
                result = num1 / num2;
            }
            numStack.push(result);
        }
        else
        {
            numStack.push(stoi(c));
        }
    }
    return numStack.top();
}

// int calculate(string s)
// {
//     stack<string> cStack;
//     int lastNum;
//     int value = 1;
//     for (auto c : s)
//     {
//         if (c == '(')
//         {
//             if (cStack.top() == "-")
//             {
//                 value = -value;
//         }
//         else if (c == ')')
//         {
//             value = -value;
//         }
//         else
//         {
//             if (!(c == '+' || c == '-'))
//             {
//                 int p = (c-'0')* value;
//                 cStack.push(p+"");
//             }
//             else
//             {
//                 cStack.push(c+"");
//             }
//         }
//     }
//     int Result = 0;
//     while (!cStack.empty())
//     {
//         int num1 =stoi(cStack.top()); 
//         cStack.pop();
//         char symbol = cStack.top();
//         cStack.pop();
//         int num2 = stoi(cStack.top()); 
//         cStack.pop();
//         int result = 0;
//         if (symbol == '+')
//         {
//             result = num2 + num1;
//         }
//         else
//         {
//             result = num2 - num1;
//         }
//         if (!cStack.empty())
//             cStack.push(result);
//         else
//             Result = result;
//     }
//     return Result;
// }

int main()
{
    // cout << simplifyPath("/../");

    // vector<string> tokens{"2", "1", "+", "3", "*"};
    // cout << evalRPN(tokens);

   // cout << calculate("1+1+(3-4)");
}