function solution(genres, plays) {
  const answer = [];
  const table = {};

  genres.forEach((genre, index) => {
    table[genre] = { genre, songs: [], count: 0 };
  });

  genres.forEach((genre, index) => {
    const play = plays[index];
    table[genre].songs.push({
      play,
      index,
    });
    table[genre].count += play;
  });

  const array = [];
  for (const [key, value] of Object.entries(table)) {
    array.push(value);
  }

  array.sort((a, b) => {
    if (a.count < b.count) return 1;
    if (a.count > b.count) return -1;
    return 0;
  });

  array.forEach((obj, index) => {
    obj.songs.sort((a, b) => {
      if (a.play < b.play) return 1;
      if (a.play > b.play) return -1;
      return -0;
    });
  });

  array.forEach((genre, index) => {
    for (let i = 0; i < Math.min(genre.songs.length, 2); i++) {
      answer.push(genre.songs[i].index);
    }
  });

  return answer;
}

const testCases = [
  {
    data: {
      genres: ["classic", "pop", "classic", "classic", "pop"],
      plays: [500, 600, 150, 800, 2500],
    },
    answer: [4, 1, 3, 0],
  },
];

testCases.forEach((testCase, index) => {
  console.log(`#${index}`);
  const { genres, plays } = testCase.data;

  const answer = solution(genres, plays);

  console.log(
    answer.toString() === testCase.answer.toString(),
    "answer : ",
    solution(genres, plays),
    "myAnswer : ",
    testCase.answer
  );
});
