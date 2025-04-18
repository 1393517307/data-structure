#include<iostream>
#include<vector>
#include<string>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    if(m>0)
    {
        for(int i=0;i<n;i++)
        {
            int tempA=nums2[i];
            int p=0;
            for(int j=m+i-1;j>=0;j--)
            {
                if(tempA<nums1[j])
                {
                    nums1[j+1]=nums1[j];
                }
                else{
                    p=j+1;
                    break;
                }
            }
            nums1[p]=tempA;
        }
    }
    else
    {
        nums1=nums2;
    }
}

//0,1,2,2,3,0,4,2
int removeElement(vector<int>& nums, int val)
{
    int p=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]!=val)
        {
            nums[p++]=nums[i];
        }
    }
    return p;
}

int removeDuplicates(vector<int>& nums) {
    int p=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[p])
           nums[++p]=nums[i];
    }
    return p+1;
}

int removeDuplicates(vector<int>& nums,int count) 
{
    int p=0;
    int num=1;//标记已经记录了连续几个相同的数
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[p]){
            nums[++p]=nums[i];
            num=1; //不同说明只有一个相同
        }else if(num<count){
            nums[++p]=nums[i];
            num++;
        }
    }
    return p+1;
}

//1,1,1,2,2,3,3
int majorityElement(vector<int>& nums) 
{
    int count=0;
    int majorData=0;
    for(int num:nums){
        if(count==0){
            majorData=num;
            count++;
        }else if (num==majorData)
        {
            count++;
        }else
        {
            count--;
        }
    }
    return majorData;
}

void Sort(vector<int>& nums,bool (*Func)(int a,int b))
{
    for(int i=0;i<nums.capacity();i++){
        int tempNumber=nums[0];
        int p=-1;
        for(int j=1;j<nums.capacity()-i;j++){
            if(Func(tempNumber,nums[j]))
            {
                nums[j-1]=nums[j];
                nums[j]=tempNumber;
                p=0;
            }else{
                tempNumber=nums[j];
            }
        }
        if(p==-1)
          break;
    }
}

void rotate(vector<int>& nums, int k) {
    k=k%nums.size();
    int p=nums.size()-k;
    vector<int> v=nums;
    for(int i=0;i<nums.size();i++){
       if(p>=nums.size())
       {
         p=0;
       }
        nums[i]=v[p++];
    }
}

//vector<int> e={1,1,1,100,2,6,5,0,3};
int maxProfit(vector<int>& prices) {
    int maxProfit=0;
    int miniPrices=prices[0];
    for(int i=0;i<prices.size();i++){
        if(prices[i]<miniPrices)
            miniPrices=prices[i];
        int tempProfit=prices[i]-miniPrices;
        if(maxProfit<tempProfit)
           maxProfit=tempProfit;
    }
    return maxProfit;
}

int maxProfit_(vector<int>& prices) {
    int maxProfit=0;
    int tadayPrices=prices[0];
    for(int i=0;i<prices.size();i++){
        if(prices[i]>tadayPrices)
            maxProfit+=(prices[i]-tadayPrices);
        tadayPrices=prices[i];
    }
    return maxProfit;
}

//2 0 0
bool canJump(vector<int>& nums) 
{
    int maxDistance=0;
    for(int i=0;i<nums.size();i++){

        if(maxDistance>=i)
           maxDistance=(maxDistance>(i+nums[i]))?maxDistance:i+nums[i];
    }
    return maxDistance>=nums.size()-1;     
}

int jump(vector<int>& nums) 
{
    int target=nums.size()-1;
    int tempTarget=target;
    int step=0;
    while (tempTarget>0)
    {
        for(int i=target;i>=0;i--)
        {
            if(nums[i]+i>=target)
            tempTarget=i;
        }
        target=tempTarget;
        step++;
    }    
    return step;
}

//3 0 6 1 5
int hIndex(vector<int>& citations) {
   for(int i=1;i<citations.size();i++)
   {
       int p=citations[i];
       int index=i;
       for(int j=i-1;j>=0;j--)
       {
          if(p>citations[j])
          {
             citations[j+1]=citations[j];
             index=j;
          }
          else
            break;
       }
       citations[index]=p;
   }
   int h;
   for (h=0;h<citations.size();h++){
      if(citations[h]<h+1)
         break;
   }
   return h;
}

int main(){
    bool Compare(int a,int b);
    void PrintVector(string describe,vector<int>& v);
    cout<<"Hellow World!"<<endl;

    cout<<"****1:merge****"<<endl;
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    merge(nums1,3,nums2,3);
   // Sort(nums2,Compare);
     PrintVector("Merge:",nums1);


    cout<<"****2:removeElement****"<<endl;
    vector<int> v={1,1,2};
    int p=removeElement(v,0);
    PrintVector("Remove:",v);
    
    cout<<"****3:removeDuplicates：****"<<endl;
    removeDuplicates(v);
    PrintVector("removeDuplicates：",v);
    vector<int> c={1,1,1,2,3,3};
    cout<<majorityElement(c)<<endl;
    removeDuplicates(c,2);
    PrintVector("removeDuplicates||:",c);
    
    vector<int> d={1,2,3,4,5,6,7};
    rotate(d,3);
    PrintVector("Rotate:",d);

    vector<int> e={3, 6,5,0,3};
    cout<<maxProfit(e)<<endl;

    vector<int> f={3,0,6,1,5};
    cout<<hIndex(f);

}


bool Compare(int a,int b){
    if(a<b)
      return true;
    else
      return false;
}

void PrintVector(string describe,vector<int> & v){
    cout<<describe;
    for(int i=0;i<v.capacity(); i++){
        cout<<v[i]<<"--";
    }
    cout<<endl;
}