#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    for(int i=0;i<m;i++){
        nums2.push_back(nums1[i]);
    }
}

int main()
{
    cout<<"Hellow World!"<<endl;
    vector<int> nums2={1,2,7,0,0};
    vector<int> nums1={5,9};
      for(int i=0;i<nums2.capacity();i++){
         cout<<nums2[i]<<"--";
    }
    cout<<endl;
    merge(nums1,3,nums2,2);
    for(int i=0;i<nums2.capacity();i++){
         cout<<nums2[i]<<"--";
    }

}