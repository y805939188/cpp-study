/**
 * @param {string} s
 * @return {string}
 */
var frequencySort = function(s) {
  const len = s.length;
  const m1 = {};
  for (let i = 0; i < len; i++) {
    m1[s[i]] = m1[s[i]] ? (m1[s[i]] + 1) : 1;
  }
  // console.log(m1)
  const m2 = {};
  for (val in m1) {
    const temp = m1[val];
    if (m2[temp]) {
      if (typeof m2[temp] === 'object') {
        m2[temp].push(val.padEnd(temp, val));
      } else {
        m2[temp] = [m2[temp], val.padEnd(temp, val)];
      }
    } else {
      m2[temp] = val.padEnd(temp, val);
    }
  }
  // console.log(m2)
  let res = "";
  for (key in m2) {
    const tempVal = m2[key];
    if (typeof tempVal !== 'string') {
      res = tempVal.join('') + res;
    } else {
      res = m2[key] + res;
    }
  }
  return res;
};

console.log(frequencySort('aabbdsa'));
