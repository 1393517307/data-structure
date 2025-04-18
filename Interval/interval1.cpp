#include<iostream>
#include<vector>
#include<string>
using namespace std;


vector<string> summaryRanges(vector<int>& nums) 
{    
    vector<string> s;
    if(nums.size()==0)
    {
        return  s;
    }
    int size=nums.size();
    int mini=nums[0],max=nums[0];

    for(int i=1;i<size;i++)
    {
       if(nums[i-1]+1!=nums[i])
        {
           max=nums[i-1];
           string tempS=mini==max?to_string(mini):(to_string(mini)+"->"+to_string(max));
           s.push_back(tempS);
           mini=nums[i];
        }
    }
    max=nums[size-1];
    string tempS=mini==max?to_string(mini):(to_string(mini)+"->"+to_string(max));
    s.push_back(tempS);
    return s;
}


vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    if(intervals.size()<=1)
    {
        return intervals;
    }
    // int length=intervals.size();
    // for(int i=1;i<length;i++)
    // {
    //     vector<int> tempV=intervals[i];
    //     int index=i;
    //     for(int j=i-1;j>=0;j--)
    //     {
    //         if(tempV.front()<intervals[j].front())
    //         {
    //             intervals[j+1]=intervals[j];
    //             index=j;
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //      intervals[index]=tempV;
    // }
    sort(intervals.begin(),intervals.end());
    int start=intervals[0].front() ,end=intervals[0].back();
    vector<vector<int>> v;
    bool isEnd=true; //是否结束了一个区间

    for(auto item:intervals)
    {
       if(item.front()<=end) //相同就窜起来
       {
          if(end<item.back())
          {
            end=item.back();
          }
       }
       else//不相同就把之前的存起来，并记录当前区间
       {   
            vector<int> tempV{start,end};
            v.push_back(tempV);

            start=item.front();
            end=item.back();
       }
    }
    vector<int> tempV{start,end};
    v.push_back(tempV);

    return v;
}



//  vector<vector<int>> merge(vector<vector<int>>& intervals)
// {
//     if (intervals.size() == 0) {
//         return {};
//     }
//     sort(intervals.begin(), intervals.end());
//     vector<vector<int>> merged;
//     for (int i = 0; i < intervals.size(); ++i) {
//         int L = intervals[i][0], R = intervals[i][1];
//         if (!merged.size() || merged.back()[1] < L) {
//             merged.push_back({L, R});
//         }
//         else {
//             merged.back()[1] = max(merged.back()[1], R);
//         }
//     }
//     return merged;
// }
int main()
{ 
    // vector<int> v{1,2,3,5,7,8,10};
    // vector<string> s=summaryRanges(v);
    // for(auto item:s)
    // {
    //     cout<<item<<"--";
    // }
   
    vector<vector<int>> v{{1,4},{0,4}};
     merge(v);
}