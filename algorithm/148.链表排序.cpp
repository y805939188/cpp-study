#include "iostream"
#include "string"
#include "vector"
#include "map"
using namespace std;

/**
 * 思路:
 *  遍历两遍 把所有节点给insert到multimap中
 *  multimap允许存在相同的key
 *  第二遍再遍历 把前一个的 next 指向后一个
 * 除此之外也可以使用快排 归并之类的算法
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
  ListNode* sortList(ListNode* head) {
    multimap<int, ListNode*> m;
    ListNode* currentNode;
    currentNode = head;
    m.insert(make_pair(head -> val, head));
    while(currentNode = currentNode -> next) {
      m.insert(make_pair(currentNode -> val, currentNode));
    }
  
    multimap<int, ListNode*>::const_iterator iter;
    iter = m.begin();
    ListNode* prevtNode = iter -> second;
    iter++;
    for (; iter != m.end(); iter++)  {
      prevtNode -> next = iter -> second;
      prevtNode = iter -> second;
    }
    iter--;
    iter -> second -> next = nullptr;
    return m.begin() -> second;
  }
};

int main(void) {
  ListNode* node1 = new ListNode(4);
  ListNode* node2 = new ListNode(2);
  node1 -> next = node2;
  ListNode* node3 = new ListNode(1);
  node2 -> next = node3;
  ListNode* node4 = new ListNode(3);
  node3 -> next = node4;
  ListNode* node5 = new ListNode(2);
  node4 -> next = node5;

  Solution* test = new Solution();

  test -> sortList(node1);
  return 0;
}
