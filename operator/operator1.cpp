#include <iostream>
#include <vector>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string result;
    while (i > 0 || j > 0 || carry > 0)
    {
        int digiA = i > 0 ? a[i]-'0' : 0;
        int digiB = j> 0 ?  b[i]-'0': 0;
        int sum = digiA + digiB + carry;
        carry = 0;
        if (sum > 1)
        {
            sum -= 2;
            carry++;
        }
        result.push_back(sum+'0');
        i--;
        j--;
    }
    reverse(result.begin(),result.end());
    return result;
}

int main()
{
}