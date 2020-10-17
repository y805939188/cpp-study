/**
 * @param {TreeNode} root
 * @return {number[]}
 * 
 * 思路:
 *  
 */
var preorderTraversal = function(root) {
  if (!root) return [];
  const res = [];
  const stack = [];
  let currentNode = root;
  wrapper: while(currentNode) {
    res.push(currentNode.val);
    if(currentNode.left) {
      // 上来先把左节点一路入栈
      stack.push(currentNode);
      currentNode = currentNode.left;
      continue wrapper;
    } else if (currentNode.right) {
      // 如果发现某个节点没有右节点了
      // 就看它是否有右节点
      // 如果有右节点
      // 就把右节点当成左节点使 但是不用入栈
      currentNode = currentNode.right;
      continue wrapper;
    } else {
      // 到这里既没有左节点也没有右节点 说明是叶子节点
      // 叶子节点的话 由于上面已经一路把它的父节点入栈了
      // 所以从栈尾取出一个 看是否有右节点
      // 如果没有的就再往上找 直到找到一个有右节点的
      // 然后把这个右节点当成左节点用 不用入栈
      while(!currentNode.right) {
        currentNode = stack.pop();
        if (!currentNode) return res;
        if (currentNode.right) {
          currentNode = currentNode.right;
          continue wrapper;
        }
      }
    }
  }
};

[4,9,10,8,5,2,6,7,3,1]

function TreeNode(val, left, right) {
  this.val = (val===undefined ? 0 : val);
  this.left = (left===undefined ? null : left);
  this.right = (right===undefined ? null : right);
}

const node10 = new TreeNode(10, null, null);
const node9 = new TreeNode(9, null, null);
const node8 = new TreeNode(8, node9, node10);
const node7 = new TreeNode(7, null, null);
const node6 = new TreeNode(6, null, null);
const node5 = new TreeNode(5, null, node8);
const node4 = new TreeNode(4, null, null);
const node3 = new TreeNode(3, node6, node7);
const node2 = new TreeNode(2, node4, node5);
const node1 = new TreeNode(1, node2, node3);

preorderTraversal(node1);


