function solution(n, arr1, arr2) {
  var answer = [];
  let lines = [];

  for (let y = 0; y < n; y++) {
    lines.push(arr1[y] | arr2[y]);
  }

  lines.forEach((line) => {
    let cur = line.toString(2);

    cur = "0000000000000000" + cur;
    cur = cur.slice(-n);

    cur = cur.replace(/0/gi, " ");
    cur = cur.replace(/1/gi, "#");

    answer.push(cur);
  });

  return answer;
}
