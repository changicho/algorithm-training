#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int solution(int N, int number) {
  int answer = -1;
  set<long long> s[9];

  string temp = "";
  for (int i = 1; i < 9; i++) {
    temp += to_string(N);

    s[i].insert(stoll(temp));
  }

  for (int i = 1; i < 9; i += 1) {
    for (int j = 1; j < i; j += 1) {
      for (long long op1 : s[j]) {
        for (long long op2 : s[i - j]) {
          s[i].insert(op1 + op2);
          s[i].insert(op1 - op2);
          s[i].insert(op1 * op2);

          if (op2 != 0) {
            s[i].insert(op1 / op2);
          }
        }
      }
    }

    if (s[i].find(number) != s[i].end()) {
      answer = i;
      break;
    }
  }

  return answer;
}

struct TestCase {
  int N;
  int number;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {5, 12, 4},
      {2, 11, 3},
      {5, 31168, -1},
      {5, 5, 1},
      {5, 26, 4},
      {5, 24, 4},
      {5, 3600, 4}

  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.N, tc.number);
    bool isCorrect = answer == tc.answer;

    cout << isCorrect << ", answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}