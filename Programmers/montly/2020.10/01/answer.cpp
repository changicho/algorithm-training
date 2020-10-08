#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string changeToThree(int n) {
  string ret = "";

  while (n != 0) {
    ret += to_string(n % 3);
    n /= 3;
  }

  return ret;
}

int changeToInt(string s) {
  int ret = 0;
  int temp = 1;
  for (int i = 0; i < s.length(); i++) {
    char cur = s[i];
    ret += (cur - '0') * temp;
    temp *= 3;
  }
  return ret;
}

int solution(int n) {
  int answer = 0;

  string change = changeToThree(n);

  reverse(change.begin(), change.end());
  answer = changeToInt(change);

  return answer;
}

struct TestCase {
  int n;
  int answer;
};

int main() {
  vector<TestCase> tcs = {
      {45, 7},
      {125, 229}

  };

  for (TestCase tc : tcs) {
    int answer = solution(tc.n);

    cout << "answer : " << tc.answer << ", myAnswer : " << answer << "\n";
  }

  return 0;
}