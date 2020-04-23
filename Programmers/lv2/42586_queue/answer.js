function solution(progresses, speeds) {
  let N = progresses.length;

  let answer = [];
  let counts = 0;
  let check = Array(N);
  check.fill(false);

  while (counts < N) {
    for (let i = 0; i < N; i++) {
      if (progresses[i] === false) {
        continue;
      }
      progresses[i] += speeds[i];

      if (progresses[i] >= 100) {
        speeds[i] = 0;
        check[i] = true;
      }
    }

    let count = 0;
    for (let i = 0; i < N; i++) {
      if (progresses[i] === false) {
        continue;
      }
      if (check[counts] === true) {
        counts += 1;
        count += 1;
        progresses[i] = false;
      } else {
        break;
      }
    }

    if (count !== 0) {
      answer.push(count);
    }
  }

  return answer;
}
