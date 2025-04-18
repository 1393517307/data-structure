#include<iostream>
#include<unordered_map>
 using namespace std;
int main()
{
    unordered_map<int,int> valToIndex;
    valToIndex[1]=20;
    valToIndex[2]=30;
    valToIndex[3]=40;
     for(const auto& key_value: valToIndex) {
    int key = key_value.first;
    int value = key_value.second;
    
    cout << key << " - " << value << endl;
    }
 
}

