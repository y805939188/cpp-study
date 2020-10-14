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

var reverseKGroup = function(head, k) {
  const res = [];
  const current = head;
  let index = 0;
  let tempList = [];
  while(true) {
      tempList.push(current);
      if (++index === k) {
          res.push(tempList);
          tempList = [];
          index = 0;
      }
      if (!current.next) {
          res.push(tempList);
          break;
      }
      current = current.next;
  }
};

reverseBetween(node1, 2, 4);
