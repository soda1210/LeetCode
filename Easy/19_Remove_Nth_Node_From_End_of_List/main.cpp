#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void printList(ListNode* head) {
  while (head) {
    cout << head->val;
    if (head->next) cout << " -> ";
    head = head->next;
  }
  cout << endl;
}

ListNode* createList(const vector<int>& vals) {
  ListNode dummy(0);
  ListNode* cur = &dummy;
  for (int val : vals) {
    cur->next = new ListNode(val);
    cur = cur->next;
  }
  return dummy.next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* dummyHead = new ListNode(0);
  dummyHead->next = head;

  ListNode* cur = dummyHead;
  ListNode* fastCur = dummyHead;
  int index = 0;

  while (fastCur->next != nullptr) {
    fastCur = fastCur->next;
    index++;
    if (index > n) {
      cur = cur->next;
    }
  }

  ListNode* temp = cur->next;
  cur->next = cur->next->next;
  delete temp;

  return dummyHead->next;
}
