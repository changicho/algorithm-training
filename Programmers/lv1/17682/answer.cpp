#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 다트 게임은 총 3번의 기회로 구성된다.
// 각 기회마다 얻을 수 있는 점수는 0점에서 10점까지이다.
// 점수와 함께 Single(S), Double(D), Triple(T) 영역이 존재하고 각 영역 당첨 시 점수에서 1제곱, 2제곱, 3제곱 (점수1 , 점수2 , 점수3 )으로 계산된다.
// 옵션으로 스타상(*) , 아차상(#)이 존재하며 스타상(*) 당첨 시 해당 점수와 바로 전에 얻은 점수를 각 2배로 만든다. 아차상(#) 당첨 시 해당 점수는 마이너스된다.
// 스타상(*)은 첫 번째 기회에서도 나올 수 있다. 이 경우 첫 번째 스타상(*)의 점수만 2배가 된다. (예제 4번 참고)
// 스타상(*)의 효과는 다른 스타상(*)의 효과와 중첩될 수 있다. 이 경우 중첩된 스타상(*) 점수는 4배가 된다. (예제 4번 참고)
// 스타상(*)의 효과는 아차상(#)의 효과와 중첩될 수 있다. 이 경우 중첩된 아차상(#)의 점수는 -2배가 된다. (예제 5번 참고)
// Single(S), Double(D), Triple(T)은 점수마다 하나씩 존재한다.
// 스타상(*), 아차상(#)은 점수마다 둘 중 하나만 존재할 수 있으며, 존재하지 않을 수도 있다.
// 0~10의 정수와 문자 S, D, T, *, #로 구성된 문자열이 입력될 시 총점수를 반환하는 함수를 작성하라.

struct Score {
  int score;
  int square;
  int option;
};

int pow(int number, int square) {
  int result = 1;
  for (int i = 0; i < square; i++) {
    result *= number;
  }
  return result;
}

vector<Score> parse(string dartResult) {
  vector<Score> result = {{0, 1, 1}, {0, 1, 1}, {0, 1, 1}};
  int index = 0, temp = 0;
  bool isNumberCount = false;

  index = 0;
  for (char c : dartResult) {
    if (c >= '0' && c <= '9') {
      isNumberCount = true;
      temp *= 10;
      temp += c - '0';
    } else {
      if (!isNumberCount) continue;

      result[index].score = temp;
      temp = 0;
      index++;
      isNumberCount = false;
    }
  }

  index = 0;
  for (char c : dartResult) {
    if (c == 'S') {
      result[index].square = 1;
      index += 1;
    } else if (c == 'D') {
      result[index].square = 2;
      index += 1;
    } else if (c == 'T') {
      result[index].square = 3;
      index += 1;
    }
  }

  index = -1;
  for (char c : dartResult) {
    if (c == 'S' || c == 'D' || c == 'T') {
      index += 1;
    } else if (c == '*' || c == '#') {
      if (c == '*') {
        result[index].option *= 2;
        if (index - 1 >= 0) result[index - 1].option *= 2;
      } else if (c == '#') {
        result[index].option *= -1;
      }
    }
  }

  return result;
}

int solution(string dartResult) {
  int answer = 0;

  vector<Score> scores = parse(dartResult);

  for (Score score : scores) {
    answer += pow(score.score, score.square) * score.option;
  }

  return answer;
}

struct testCase {
  string dartResult;
  int result;
};

int main() {
  vector<testCase> testCases = {
      {"1S2D*3T", 37}, {"1D2S#10S", 9}, {"1D2S0T", 3}, {"1S*2T*3S", 23}, {"1D#2S*3S", 5}, {"1T2D3D#", -4}, {"1D2S3T*", 59}};

  for (testCase testCase : testCases) {
    int answer = solution(testCase.dartResult);

    cout << "answer : " << answer << ", myAnswer " << testCase.result << "\n";
  }

  return 0;
}