/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */

class ListNode {
  constructor(number) {
    this.number = number;
  }
  setNext = (next) => {
    this.next = next;
  }
}
const node1 = new ListNode(1);
const node2 = new ListNode(2);
node1.setNext(node2);
const node3 = new ListNode(3);
node2.setNext(node3);
const node4 = new ListNode(4);
node3.setNext(node4);
const node5 = new ListNode(5);
node4.setNext(node5);
node5.setNext(null);

console.log(node1);

var reverseBetween = function(head, m, n) {
  // m - 1、m、 n + 1、prevNode 这四个需要记录下来
  let index = 0;
  let prevNode = { next: head };
  let currentNode = head;
  let minusOneNode = null;
  let firstNode = null;
  let lastNode = null;
  let tempNode = null;
  while ( ++index <= n ) {
      if ( index <= m ) {
          currentNode = prevNode.next;
          if (index === m) {
              firstNode = currentNode;
              currentNode = currentNode.next;
          } else if (index === m - 1) {
              minusOneNode = currentNode;
          }
          prevNode = currentNode;
          continue;
      } else if (index > m && index < n) {
          tempNode = currentNode.next;
          currentNode.next = prevNode;
          prevNode = currentNode;
          currentNode = tempNode;
      } else if (index === n) {
          lastNode = currentNode.next;
          minusOneNode.next = currentNode;
          currentNode.next = prevNode;
          firstNode.next = lastNode;
      }
  }
  return head;
};

reverseBetween(node1, 2, 4);
