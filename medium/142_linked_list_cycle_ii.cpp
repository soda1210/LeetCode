#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};

// Helper function to print result
void testCycleDetection(ListNode* head, const string& testName) {
    Solution solution;
    ListNode* entry = solution.detectCycle(head);
    cout << testName << ": ";
    if (entry) {
        cout << "Cycle detected at node with value " << entry->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
}

int main() {
    // Test case 1: Empty list
    testCycleDetection(NULL, "Test 1");

    // Test case 2: One node, no cycle
    ListNode* t2 = new ListNode(1);
    testCycleDetection(t2, "Test 2");

    // Test case 3: Two nodes, no cycle
    ListNode* t3a = new ListNode(1);
    ListNode* t3b = new ListNode(2);
    t3a->next = t3b;
    testCycleDetection(t3a, "Test 3");

    // Test case 4: Three nodes, cycle starting at head
    ListNode* t4a = new ListNode(1);
    ListNode* t4b = new ListNode(2);
    ListNode* t4c = new ListNode(3);
    t4a->next = t4b;
    t4b->next = t4c;
    t4c->next = t4a; // cycle here
    testCycleDetection(t4a, "Test 4");

    // Test case 5: Five nodes, cycle starting at node with value 2
    ListNode* t5a = new ListNode(1);
    ListNode* t5b = new ListNode(2);
    ListNode* t5c = new ListNode(3);
    ListNode* t5d = new ListNode(4);
    ListNode* t5e = new ListNode(5);
    t5a->next = t5b;
    t5b->next = t5c;
    t5c->next = t5d;
    t5d->next = t5e;
    t5e->next = t5b; // cycle here
    testCycleDetection(t5a, "Test 5");

    // Test case 6: Ten nodes, cycle starting at node with value 5
    ListNode* nodes[10];
    for (int i = 0; i < 10; i++) {
        nodes[i] = new ListNode(i + 1);
    }
    for (int i = 0; i < 9; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    nodes[9]->next = nodes[4]; // cycle here
    testCycleDetection(nodes[0], "Test 6");

    return 0;
}
