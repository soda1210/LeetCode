#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 建立無環 Linked List
ListNode* createList(vector<int> vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int val : vals) {
        ListNode* node = new ListNode(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// 建立有環 Linked List，並返回 head
ListNode* createCycleList(vector<int> vals, int pos) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    ListNode* cycleStart = nullptr;

    for (int i = 0; i < vals.size(); i++) {
        ListNode* node = new ListNode(vals[i]);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        if (i == pos) {
            cycleStart = node;
        }
    }

    if (tail && cycleStart) {
        tail->next = cycleStart;
    }

    return head;
}
