class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
  }
}

/**
 * 思路:
 *  这个思路很妙啊, 如果是回文的话
 *  从头加到尾和从尾加到头 虽然是反着加
 *  但是最后的结果是相同的
 */

function isPalindrome(head: ListNode | null): boolean {
  if (!head) return true;
  let val1 = `${head.val}`;
  let str1: string = val1, str2: string = val1;
  let currentNode: ListNode | null = head;
  while(currentNode = currentNode.next) {
    str1 = str1 + currentNode.val;
    str2 = currentNode.val + str2;
  }
  return str1 === str2;
};

