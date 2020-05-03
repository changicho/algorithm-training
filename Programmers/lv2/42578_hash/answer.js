function solution(clothes) {
  var answer = 1;

  let m = new Map();

  clothes.forEach((cur) => {
    if (m.get(cur[1]) === undefined) {
      m.set(cur[1], 1);
    } else {
      let count = m.get(cur[1]);
      m.set(cur[1], count + 1);
    }
  });

  m.forEach((cur) => {
    answer *= cur + 1;
  });

  answer -= 1;

  return answer;
}
