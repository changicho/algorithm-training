function solution(heights) {
  let size = heights.length;
  let answer = Array(size);
  answer.fill(0);

  for (let i = size - 1; i >= 0; i -= 1) {
    for (let j = i - 1; j >= 0; j -= 1) {
      if (heights[i] < heights[j]) {
        answer[i] = j + 1;
        break;
      }
    }
  }

  return answer;
}
