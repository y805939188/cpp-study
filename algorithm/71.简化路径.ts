function simplifyPath(path: string): string {
  if (!path) return "";
  const temp = path.split('/');
  const temp2 = [];
  const len = temp.length;
  for(let i = 0; i < len; i++) {
    const dir = temp[i];
    if (dir === '.') continue
    else if (dir === '..') temp2.pop()
    else if (dir !== "") temp2.push(dir);
  }
  temp2.unshift("");
  return temp2.join('/');
};