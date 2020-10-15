/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} node
 * @return {void} Do not return anything, modify node in-place instead.
 */

 /**
  * 思路:
  *   由于没有给出head所以无法拿到上一个节点‘
  *   所以只能通过直接改变node的val来删除
  *   每次让当前节点的val指向下一个节点的val就行了
  */
var deleteNode = function(node) {
  let currentNode = node;
  while(true) {
      currentNode.val = currentNode.next.val;
      if (!currentNode.next.next) {
          currentNode.next = null;
          break;
      }
      currentNode = currentNode.next;
  }
};