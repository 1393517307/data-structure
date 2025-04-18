#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *sortList(ListNode *head)
{
    ListNode* dummy=new ListNode();
    dummy->next=head;
    ListNode* cur=head->next;
    while (cur)
    {
        ListNode*ptr;
        while (true)
        {
            /* code */
            
        }
        
    }
    
}

int main()
{
}