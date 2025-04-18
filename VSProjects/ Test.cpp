#include<iostream>
#include<vector>
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

int main(){
    cout<<"Hellow World!"<<endl;
    vector<int> nums1={1,2,7,0,0};
    vector<int> nums2={5,9};
      for(int i=0;i<nums2.capacity();i++){
         cout<<nums2[i]<<"--";
    }
    cout<<endl;
    merge(nums1,3,nums2,2);
    for(int i=0;i<nums2.capacity();i++){
         cout<<nums2[i]<<"--";
    }

}