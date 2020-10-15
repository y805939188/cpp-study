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

var removeNthFromEnd = function(head, n) {
  const res = [head];
  let currentNode = head;
  while(currentNode = currentNode.next) {
      res.push(currentNode);
  }
  res[res.length - n + 1].next = res[res.length - n - 1];
  return res[0];
};


