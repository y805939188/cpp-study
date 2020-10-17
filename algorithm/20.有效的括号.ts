function isValid(s: string): boolean {
  if (s.length === 1) return false;
  const stack = [];
  const m: { [key: string]: string } = {
    ')': '(',
    '}': '{',
    ']': '[',
  }
  let len = s.length;
  for (let i = 0; i < len; i++) {
    if (!m[s[i]]) {
      stack.push(s[i]);
    } else {
      if (!(stack[stack.length - 1] === m[s[i]])) {
        return false;
      } else {
        stack.length = stack.length - 1;
      }
    }
  }
  if (stack.length) return false;
  return true;
};

const test = "";

console.log(isValid(test));

