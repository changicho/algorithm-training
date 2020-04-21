function solution(participant, completion) {
  var answer = "";
  let m = new Map();

  participant.reduce((pre, cur) => {
    let count = m.get(cur);

    if (count === undefined) {
      m.set(cur, 1);
    } else {
      m.set(cur, count + 1);
    }
  }, []);

  completion.reduce((pre, cur) => {
    let count = m.get(cur);

    if (count === 1) {
      m.delete(cur);
    } else {
      m.set(cur, count - 1);
    }
  }, []);

  participant.reduce((pre, cur) => {
    if (m.has(cur)) {
      answer = cur;
    }
  }, []);

  return answer;
}
