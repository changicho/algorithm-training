#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution() {
  int answer = 0;
  return answer;
}

struct TestCase {
  int answer;
};

int main() {
  vector<TestCase> tcs = {};

  for (TestCase tc : tcs) {
    int answer = solution();

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}