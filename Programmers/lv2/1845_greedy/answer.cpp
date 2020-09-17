#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> nums) {
  int answer = 0;
  map<int, int> m;

  for (int num : nums) {
    m[num] += 1;
  }

  answer = min(nums.size() / 2, m.size());

  return answer;
}

struct TestCase {
  vector<int> nums;
  int result;
};

int main() {
  vector<TestCase> tcs = {
      {{3, 1, 2, 3}, 2},
      {{3, 3, 3, 2, 2, 4}, 3},
      {{3, 3, 3, 2, 2, 2}, 2}

  };

  for (TestCase tc : tcs) {
    int result = solution(tc.nums);

    bool isCorrect = result == tc.result;

    cout << isCorrect << ", answer : " << tc.result << ", myAnswer : " << result << "\n";
  }

  return 0;
}