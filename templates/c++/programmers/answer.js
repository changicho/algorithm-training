function solution() {}

const testCases = [
  {
    data: {},
    answer: true,
  },
];

testCases.forEach((testCase, index) => {
  console.log(`#${index}`);
  const {} = testCase.data;

  const answer = solution();

  console.log(
    answer.toString() === testCase.answer.toString(),
    "answer : ",
    solution(genres, plays),
    "myAnswer : ",
    testCase.answer
  );
});
