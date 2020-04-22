function solution(priorities, location) {
  var answer = 0;

  let q = Array();
  priorities.reduce((pre, cur, idx) => {
    q.push({
      priorities: cur,
      isAnswer: idx === location ? true : false,
    });
  }, []);

  priorities.sort((a, b) => {
    return b - a;
  });

  while (true) {
    let cur = q[0];
    q.shift();

    if (cur.priorities === priorities[0]) {
      answer += 1;
      if (cur.isAnswer) {
        break;
      }
      priorities.shift();
      continue;
    } else {
      q.push(cur);
    }
  }
  return answer;
}
