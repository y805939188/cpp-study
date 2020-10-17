/**
 * @param {TreeNode} root
 * @return {number[]}
 * 
 * 思路:
 *  
 */
var postorderTraversal = function(root) {
  const stack = [];
  const res = [];
  if (!root) return res;
  let prevNode = null;
  let currentNode = root;
  while(true) {
    if (currentNode.left) {
      stack.push(currentNode);
      currentNode = currentNode.left;
    } else if (currentNode.right) {
      stack.push(currentNode);
      currentNode = currentNode.right;
    } else {
      res.push(currentNode.val);
      prevNode = currentNode;
      currentNode = stack[stack.length - 1];
      if (!currentNode) return res;
      while (!currentNode.right || (currentNode.right && currentNode.right === prevNode)) {
        res.push(stack.pop().val);
        prevNode = currentNode;
        currentNode = stack[stack.length - 1];
        if (!currentNode) return res;
      }
      currentNode = currentNode.right;
    }
  }
};

// [1,2,3,4,5,6,7,null,null,null,8,null,null,null,null,9,10]
// [4,9,10,8,5,2,6,7,3,1]

function TreeNode(val, left, right) {
  this.val = (val===undefined ? 0 : val);
  this.left = (left===undefined ? null : left);
  this.right = (right===undefined ? null : right);
}

// const node10 = new TreeNode(10, null, null);
// const node9 = new TreeNode(9, null, null);
// const node8 = new TreeNode(8, node9, node10);
// const node7 = new TreeNode(7, null, null);
// const node6 = new TreeNode(6, null, null);
// const node5 = new TreeNode(5, null, node8);
// const node4 = new TreeNode(4, null, null);
// const node3 = new TreeNode(3, node6, node7);
// const node2 = new TreeNode(2, node4, node5);
// const node1 = new TreeNode(1, node2, node3);
const node1 = new TreeNode(1, null, null);
postorderTraversal(node1);


