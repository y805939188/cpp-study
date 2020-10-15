/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */

/**
 * 我发现大部分链表题都可以从头到尾扫一遍给干成数组
 * 然后难度就会下降一大截儿
 * 
 * 思路:
 *  使用双指针, 双指针的长度就为 k
 *  先扫描 k 长度 让第一个 指针指向第 k 位
 *  之后俩指针一块儿往后走 当第一个指针指到 null
 *  就可以把这俩指针中间的都挪到前头了
 *  另外如果 k 大于链表长度了 只需要把第一个指针指回头部就可以了
 */
// var rotateRight = function(head, k) {
//   if (!head) return null;
//     if (!k) return head;
//   const vhead = { next: head };
//   let a = vhead, b = head;
//   for (let i = 0; i < k; i++) {
//     if (!b.next) {
//       b = head;
//     } else {
//       b = b.next;
//     }
//   }
//   if (b === head) return head;
//   let lastNode = null;
//   while(b) {
//     a = a.next;
//     if (!b.next) {
//       lastNode = b;
//     }
//     b = b.next;
//   }
//   lastNode.next = head;
//   let temp = a.next;
//   a.next = null;
//   return temp;
// };
