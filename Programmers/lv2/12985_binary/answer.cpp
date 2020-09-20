#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int a, int b) {
  int answer = 0;

  while (a != b) {
    answer += 1;
    a = (a + 1) / 2;
    b = (b + 1) / 2;
  }

  return answer;
}

struct TestCase {
  int N;
  int A;
  int B;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {8, 4, 7, 3}

  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.N, tc.A, tc.B);
    bool isCorrect = answer == tc.answer;
    cout << isCorrect << ", answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}