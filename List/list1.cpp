#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
} ListNode;

ListNode *CreateList(int arr[], int length, int pos)
{
    bool isCycle = pos >= 0 && pos < length;
    ListNode *root = nullptr;
    ListNode *current = nullptr;
    ListNode *markerNode = nullptr; // 用于在 pos 位置插入的特殊节点
    bool markerInserted = false;

    for (int i = 0; i < length; i++)
    {
        ListNode *tempNode = new ListNode(arr[i]);
        // 初始化标记节点
        if (isCycle && i == pos)
        {
            markerNode = tempNode;
        }
        // 初始化根节点
        if (root == nullptr)
        {
            root = tempNode;
            current = tempNode;
        }
        else
        {
            current->next = tempNode;
            current = current->next;
        }
    }
    if (isCycle) // 环连接
    {
        current->next = markerNode;
    }
    return root;
}

// 是否有环
bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// 链表相加
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int remainder = 0; // 余数
    ListNode dummy(0); // 哑节点
    ListNode *current = &dummy;
    while (l1 || l2 || remainder)
    {
        int sum = remainder;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        remainder = 0;
        if (sum > 9)
        {
            sum -= 10;
            remainder++;
        }
        current->next = new ListNode(sum);
        current = current->next;
    }
    return dummy.next;
}

// 合并有序链表
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode root(0);
    ListNode *current = &root;
    while (list1 || list2)
    {
        if (!list1)
        {
            cout << "t";
        }
        if (!list2 || list1 && list1->val <= list2->val)
        {
            current->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            current->next = new ListNode(list2->val);
            list2 = list2->next;
        }
        current = current->next;
    }
    return root.next;
}

// 反转目标区间链表
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (!head || !(head->next))
        return head;
    ListNode *resultNode = new ListNode(0); // 结果链表
    resultNode->next = head;
    ListNode *preNode = resultNode; // 前段节点
    ListNode *leftNode = nullptr;   // 左节点
    ListNode *rightNode = nullptr;  // 右节点
    ListNode *curNode = nullptr;    // 当前节点
    ListNode *nextNode = nullptr;   // 后段节点
    // 设置前节点
    for (int i = 0; i < left - 1; i++)
    {
        preNode = preNode->next;
    }
    // 设置左节点
    leftNode = preNode->next;
    // 设置右节点
    rightNode = leftNode;
    for (int i = left; i < right; i++)
    {
        rightNode = rightNode->next;
    }
    // 设置后节点
    nextNode = rightNode->next;
    // 设置当前节点
    curNode = leftNode;

    // 第一步
    //  切断链表
    preNode->next = nullptr;
    rightNode->next = nullptr;

    // 第二步
    //  反转目标链表
    ListNode *tempPreNode = nullptr;
    ListNode *tempNextNode = nullptr;
    while (curNode)
    {
        // 提前标记下一个节点
        tempNextNode = curNode->next;
        // 改变当前节点指向
        curNode->next = tempPreNode;
        // 标记节点后移
        tempPreNode = curNode;
        curNode = tempNextNode;
    }

    // 第三步
    // 连接新链表
    preNode->next = rightNode;
    leftNode->next = nextNode;

    return resultNode->next;
}

// 连续反转
ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *curNode = nullptr;
    ListNode *preNode = nullptr;
    ListNode *endNode = nullptr;
    ListNode *leftNode = nullptr;
    ListNode *rightNode = nullptr;

    // 设置节点
    preNode = dummyNode;
    while (preNode)
    {
        // 设置左节点
        leftNode = preNode->next;
        if (!leftNode)
        {
            break;
        }
        // 右节点
        rightNode = leftNode;
        for (int i = 1; i < k; i++)
        {
            rightNode = rightNode->next;
            if (!rightNode)
            {
                break;
            }
        }
        if (!rightNode)
        {
            break;
        }
        // 后节点
        endNode = rightNode->next;

        // 断开节点
        preNode->next = nullptr;
        rightNode->next = nullptr;
        // 开始反转
        ListNode *tempNextNode = nullptr;
        ListNode *tempPreNode = nullptr;
        curNode = leftNode;
        while (curNode)
        {
            tempNextNode = curNode->next;
            curNode->next = tempPreNode;
            tempPreNode = curNode;
            curNode = tempNextNode;
        }
        // 连接
        preNode->next = rightNode;
        leftNode->next = endNode;

        // 重新设置前节点
        preNode = leftNode;
    }
    return dummyNode->next;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    if (head == nullptr)
    {
        return head;
    }
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *fastNode = dummyNode;
    ListNode *slowNode = dummyNode;
    // fast与slow拉开n+1个距离
    for (int i = 0; i < n + 1; i++)
    {
        fastNode = fastNode->next;
    }
    // 快慢一起后移
    while (fastNode)
    {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }
    // 删除节点
    ListNode *tempNode = slowNode->next->next;
    slowNode->next = tempNode;
    return dummyNode->next;
}

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *slowNode = dummyNode;
    ListNode *fastNode = head->next;
    while (fastNode)
    {
        if (slowNode->next->val != fastNode->val)
        {
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }
        else
        {
            int value = fastNode->val;
            // 删除节点
            while (slowNode->next && slowNode->next->val == value)
            {
                slowNode->next = slowNode->next->next;
            }
            // 重置快节点
            if (slowNode->next)
            {
                fastNode = slowNode->next->next;
            }
            else
            {
                fastNode = nullptr;
            }
        }
    }
    return dummyNode->next;
}

// a->b->c->d
ListNode *rotateRight(ListNode *head, int k)
{
    // 1:通过快慢指针找到需要断开和重新连接的节点
    // 2:断开重新连接(当轮转和原来相同时 不用断开重连)
    if (!head || !head->next || k == 0)
    {
        return head;
    }
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *fastPtr = dummyNode;
    ListNode *slowPtr = dummyNode;
    int cout = 0;
    // 快指针 提前走k步
    for (int i = 1; i <= k; i++)
    {
        if (!(fastPtr->next))
        {
            break;
        }
        cout++;
        fastPtr = fastPtr->next;
    }
    // 快慢指针同时向后移，直到末尾
    while (fastPtr->next)
    {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }
    // 当轮转步数大于链表长度 调整慢指针位置
    if (cout < k)
    {
        k %= cout;
        if (k != 0)
        {
            k = cout - k;
        }
        for (int i = 1; i <= k; i++)
        {
            slowPtr = slowPtr->next;
        }
    }
    // 指定新的头指针
    dummyNode->next = slowPtr->next;
    // 慢指针等于哑节点 则说明轮转后 结果不变
    if (slowPtr != dummyNode)
    {
        // 此时慢指针表示需要断开的前节点 重新连接
        slowPtr->next = nullptr;
        fastPtr->next = head;
    }
    return dummyNode->next;
}

ListNode *partition(ListNode *head, int x)
{
    if (!head)
    {
        return head;
    }
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *separateNode = nullptr;
    ListNode *ptr = dummyNode;
    while (ptr->next)
    {
        // 找到第一个大于等于x的节点的前一个节点 作为分隔节点
        if (!separateNode)
        {
            if (ptr->next->val >= x)
            {
                separateNode = ptr;
            }
            ptr = ptr->next;
            continue;
        }
        // 如果下一个节点小于目标值 则将改节点移到分隔节点前面
        if (ptr->next->val < x)
        {
            ListNode *tempNode = ptr->next;
            ptr->next = ptr->next->next;
            tempNode->next = separateNode->next;
            separateNode->next = tempNode;
            separateNode = tempNode;
        }
        else
        {
            // 后移
            ptr = ptr->next;
        }
    }
    // 最后一个节点的特殊处理
    if (ptr->val < x)
    {
        if (separateNode)
        {
            ptr->next = separateNode->next;
            separateNode->next = ptr;
        }
    }
    return dummyNode->next;
}


int main()
{
    int a3[] = {1};
    ListNode *root3 = CreateList(a3, 1, -1);
    partition(root3, 2);
}