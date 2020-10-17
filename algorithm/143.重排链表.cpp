#include "iostream"
#include "string"
#include "vector"
#include "map"
// #include "algorithm"
using namespace std;

/**
 * 思路:
 *  可以使用快慢指针, 一个走到中间一个走到尾巴
 *  然后相当于拆成了俩链表, 之后归并
 *  重点在于后面那半串儿链表的反转
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//   void reorderList(ListNode* head) {
//     if (!head) return;
//     if (!head -> next) return;
//     if (!head -> next -> next) return;
//     ListNode *vhead = new ListNode(-1, head);
//     ListNode *a = vhead, *b = vhead;
//     // ListNode *tempNode;
//     // // ListNode *originBNext;
//     // ListNode *prevB;
//     map<ListNode*, ListNode*> m;
//     // ListNode *currentNext;
//     while(currentNext -> next) {
//       // tempNode = b;
//       // prevB = b;
//       // currentNext = b -> next;
//       if (!b -> next -> next) {
//         b = b -> next;
//         a -> next -> next = nullptr;
//         b -> next = prevB -> next;
//       } else {
//         b = b -> next -> next;
//         b -> next = prevB -> next;
//       }
//       a = a -> next;
//     }
//     ListNode *currentNode;
//     currentNode = head;
//     ListNode *tempNode2;
//     while(!currentNode || currentNode -> next != b) {
//       tempNode = currentNode -> next;
//       tempNode2 = b -> next;
//       currentNode -> next = b;
//       b -> next = tempNode;
//       currentNode = tempNode;
//       b = tempNode2;
//     }
//   }
// };

class Solution {
private:
    ListNode *reverse(ListNode *head){
        ListNode *p1 = NULL;
        ListNode *p2 = head;
        ListNode *p3 = p2;
        
        while(p2){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;            
        }
        return p1;
    }
public:
  void reorderList(ListNode* head) {
    if (!head) return;
    if (!head -> next) return;
    if (!head -> next -> next) return;
    ListNode *vhead = new ListNode(-1, head);
    ListNode *a = vhead, *b = vhead;
    ListNode *tempNode;
    while(b -> next) {
      if (!b -> next -> next) {
        b = b -> next;
      } else {
        b = b -> next -> next;
      }
      a = a -> next;
    }

    b = a -> next;
    a -> next = nullptr;
    b = reverse(b);
    
    ListNode *currentNode;
    ListNode *tempNode2;
    currentNode = head;
    while(b) {
      tempNode = currentNode -> next;
      currentNode -> next = b;
      tempNode2 = b -> next;
      b -> next = tempNode;
      currentNode = tempNode;
      b = tempNode2;
    }
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
  ListNode* node5 = new ListNode(5);
  node4 -> next = node5;

  Solution* test = new Solution();

  test -> reorderList(node1);
  return 0;
}
