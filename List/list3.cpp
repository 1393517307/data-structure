#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode
{
    int key;
    int value;
    ListNode *prev;
    ListNode *next;
    ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    unordered_map<int, ListNode *> listMap;
    ListNode *head;
    ListNode *tail;
    int capacity;
    int c;
    void MoveToHead(ListNode *node)
    {
        // 断开
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 重连
        node->prev = head;
        node->next = head->next;
        head->next = node;
    }

    void MoveToTail(ListNode *node)
    {
        // 断开
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // 重连
        tail->prev->next = node;
        node->next = tail;
        tail->prev = node;
    }

    void CreatNewNode(int k, int v)
    {
        ListNode *newNode = new ListNode(k, v);
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
        listMap[k] = newNode;
    }

    // 删除链表尾部节点
    void removeTail()
    {
        ListNode *node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        listMap.erase(node->key);
        delete node;            // 释放内存
    }

public:
    LRUCache(int capacity) : capacity(capacity)
    {
        head = new ListNode(-1, -1);
        tail = new ListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (listMap.find(key) != listMap.end())
        {
            ListNode *node = listMap[key];
            MoveToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (listMap.find(key) != listMap.end())
        {
            listMap[key]->value = value;
        }
        else
        {
            CreatNewNode(key, value);
            if (listMap.size() >= capacity)
            {
                removeTail();
            }
        }
    }
};

int main()
{
}