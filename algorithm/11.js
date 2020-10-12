var maxArea = function(height) {

  let left = 0, right = height.length - 1;

  let maxArea = 0;
  while(left < right) {
    const min = Math.min(height[left], height[right]);
    const area = min * (right - left);
    maxArea = Math.max(maxArea, area);
    if (min === height[left]) {
      left++;
    } else {
      right--;
    }
  }

  return maxArea;

};

// maxArea([3,6,3,5,8,5,3,2,6,7,9,0,5,2,1,2]);
console.log(maxArea([1,8,6,2,5,4,8,3,7]));
