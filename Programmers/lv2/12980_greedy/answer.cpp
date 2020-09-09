#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
  int answer = 1;

  while (n != 1) {
    if (n % 2 == 1) {
      n -= 1;
      answer += 1;
    } else {
      n /= 2;
    }
  }

  return answer;
}

struct TestCase {
  int n;
  int answer;
};

int main() {
  vector<TestCase> tcs = {{5, 2}, {6, 2}, {5000, 5}};

  for (TestCase tc : tcs) {
    int answer = solution(tc.n);

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}