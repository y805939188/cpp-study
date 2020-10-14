#include "iostream"
#include "string"
#include "vector"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (!head) return nullptr;
    int index = 0;
    ListNode* oddNumberNode = nullptr;
    ListNode* currentNode = head;
    ListNode* nextNode = nullptr;
    ListNode* nextNextNode = nullptr;
    ListNode* res = nullptr;
    if (head -> next) {
      res = head -> next;
    } else {
      res = head;
    }
    while(currentNode) {
      nextNode = currentNode -> next;
      if (!nextNode) {
        if (oddNumberNode) oddNumberNode -> next = currentNode;
        currentNode -> next = nullptr;
        break;
      };
      nextNextNode = nextNode -> next;
      nextNode -> next = currentNode;
      if (oddNumberNode) oddNumberNode -> next = nextNode;
      if (nextNode && !nextNextNode) {
        currentNode -> next = nullptr;
        break;
      };
      oddNumberNode = currentNode;
      currentNode = nextNextNode;
    }
    return res;
  }
};

int main(void) {
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(2);
  node1 -> next = node2;
  ListNode* node3 = new ListNode(3);
  node2 -> next = node3;
  ListNode* node4 = new ListNode(4);
  node3 -> next = node4;

  Solution* test = new Solution();
  ListNode* res = test -> swapPairs(node1);

  while(res) {
    cout << res -> val << endl;
    res = res -> next;
  }
  return 0;
}
