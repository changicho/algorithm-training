#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
  string answer = "";

  int numSize = number.size() - k;
  int start = 0;

  for (int index = 0; index < numSize; index++) {
    char maxValue = number[start];
    int maxIndex = start;

    for (int i = start; i <= k + index; i++) {
      if (maxValue < number[i]) {
        maxValue = number[i];
        maxIndex = i;
      }
    }
    start = maxIndex + 1;
    answer += maxValue;
  }

  return answer;
}

struct TestCase {
  string number;
  int k;
  string answer;
};

int main() {
  vector<TestCase> tcs = {
      {"1924", 2, "94"},
      {"1231234", 3, "3234"},
      {"4177252841", 4, "775841"},
      {"43277111", 3, "77111"}};

  for (TestCase tc : tcs) {
    string answer = solution(tc.number, tc.k);

    cout << answer << ", " << tc.answer << "\n";
  }

  return 0;
}