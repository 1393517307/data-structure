#include<iostream>
#include<vector>
 using namespace std;

 class RandomizedSet {
    private vector<int> nums;
    private unordered_map<int,int> valueToIndex;
public:
    RandomizedSet() {
        nums=new vector<int>();
        valueToIndex=new unordered_map<int,int>();
    }
    
    bool insert(int val) {
        if(valueToIndex[val]!=null)
        {
            return false;
        }
        nums.push_back(val);
        valueToIndex.insert(value,nums.size()-1);
    }
    
    bool remove(int val) {
        
    }
    
    int getRandom() {
        
    }
};
 int main()
 {
     
 }