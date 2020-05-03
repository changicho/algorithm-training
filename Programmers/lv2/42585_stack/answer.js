function solution(arrangement) {
  let answer = 0;
  let s = new Array();

  for (let i = 0; i < arrangement.length; i++) {
    let cur = arrangement.charAt(i);

    if (cur === "(") {
      s.push(cur);
    } else {
      s.pop();
      if (arrangement.charAt(i - 1) === "(") {
        answer += s.length;
      } else {
        answer += 1;
      }
    }
  }

  return answer;
}
