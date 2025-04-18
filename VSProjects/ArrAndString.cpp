#include<iostream>
#include<string>
 using namespace std;
#pragma region  ROMANSTRING
 int RomanCharToInt(char c)
{
    int num;
    if(c=='I')
    {
        num= 1;
    }
    else if (c=='V')
    {
        num=5;
    }
    else if (c=='X')
    {
       num=10;
    }
    else if (c=='L')
    {
       num=50;
    }
    else if (c=='C')
    {
       num=100;
    }
    else if (c=='D')
    {
       num=500;
    }
    else if (c=='M')
    {
       num=1000;
    }
    return num;
}

int RomanToInt(string s)
{   
    int totalNumber=0;
    int lastNum=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        int tempNum=RomanCharToInt(s[i]);
        totalNumber+=(tempNum<lastNum)&&(lastNum/tempNum<=10)?-tempNum:tempNum;
        lastNum=tempNum;
    }
    return totalNumber;
}
#pragma endregion

int LengthOfLastWord(string s) {
    int length=s.length();
    while (length>0&&s[length-1]==' ')
    {
        length--;
    }
    if(length==0)
    {
        return 0;
    }
    int start=length;
     while (length>0&&s[length-1]!=' ')
     {
        length--;
     }
     return start-length;
}

string reverseWords(string s) 
{
    //"sky is blue"
    int start=0;
    int end=s.length()-1;
    while (end)
    {
        /* code */
    }
    
    while (end>start)
    {
        std::swap(s[start],s[end]);
        start++;
        end--;
        /* code */
    }
  //  cout<<"fa";
    return s;
}

int main()
{
    //cout<<RomanToInt("CMLIV");
    // /cout<<LengthOfLastWord("sky is blue");
    cout<<reverseWords("skyisblue");
}