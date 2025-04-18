#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


Node *copyRandomList(Node *head)
{
    Node root(0);
    Node* current=&root;
    unordered_map<Node*,Node*> originalToNew;
    Node* headRoot=head;
    while (head)
    {
        current->next=new Node(head->val);
        current=current->next;
        originalToNew[head]=current;//储存映射信息
        head=head->next;
    }
    while (headRoot)//刷新random
    {
        if(originalToNew[headRoot])
        {
            originalToNew[headRoot]->random=originalToNew[headRoot->random];
        }
        headRoot=headRoot->next;
    }
    return root.next;
}



int main()
{
    printf("s");
    cout<<"秩序了"<<endl;
}