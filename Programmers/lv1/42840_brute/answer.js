function solution(answers) {
  var answer = [];

  let checks = [
    [1, 2, 3, 4, 5],
    [2, 1, 2, 3, 2, 4, 2, 5],
    [3, 3, 1, 1, 2, 2, 4, 4, 5, 5],
  ];

  let scores = [0, 0, 0];

  checks.forEach((check, student) => {
    answers.forEach((cur, idx) => {
      let index = idx % checks[student].length;

      if (cur === checks[student][index]) {
        scores[student] += 1;
      }
    });
  });

  if (scores[0] >= scores[1] && scores[0] >= scores[2]) {
    answer.push(1);
  }
  if (scores[1] >= scores[0] && scores[1] >= scores[2]) {
    answer.push(2);
  }
  if (scores[2] >= scores[1] && scores[2] >= scores[0]) {
    answer.push(3);
  }

  return answer;
}
