#include<iostream>
#include<string>
using namespace std;
 
 #pragma region STRUCT
 struct Books
 {
    string bookType;
    string bookName;
    float bookPrice;
 }myBook;

using Computer= struct Computer
{
   string name;
   string cpuType;
   float price;
   Computer(string name,string type,float price):name(name),cpuType(type),price(100000)
   {}
};
#pragma endregion
int arr[3] ={1,23};
vector<int> mVecto={1,2,3,4,5,6,7,8,9,10};

int b=1;
int main()
{
   vector<string> mapa{
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
   };
   
   cout<<arr[2];
   // Books books;
   // books.bookName="sss";
   // cout<<books.bookName;
   // Computer mComputer("inter","Xiaomi",0.1f);
  // cout<<b<<"--"<<mComputer.cpuType<<"--"<<mComputer.price;
   
   for(int i=0;i<mVecto.size();i++)
   {
        mVecto[i]=i;
        cout<<mVecto[i];
   }
   // for(int i:mVecto)
   // {
   //   cout<<"-"<<i<<endl;
   //   mVecto[i];
   // }
}