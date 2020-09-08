#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int answer = 0;

bool isNotPrime[50001];

void init() {
  answer = 0;
  isNotPrime[1] = isNotPrime[0] = true;

  for (int i = 2; i < 50001; i++) {
    if (isNotPrime[i]) continue;

    for (int j = i + i; j < 50001; j += i) {
      isNotPrime[j] = true;
    }
  }
}

void dfs(int index, int count, int num, vector<int> arr) {
  if (count == 3) {
    if (!isNotPrime[num]) {
      answer += 1;
    }
    return;
  }
  if (index == arr.size()) return;

  dfs(index + 1, count + 1, num + arr[index], arr);
  dfs(index + 1, count, num, arr);
}

int solution(vector<int> nums) {
  init();

  dfs(0, 0, 0, nums);

  return answer;
}

struct TestCase {
  vector<int> nums;
  int result;
};

int main() {
  vector<TestCase> testCases = {{{1, 2, 3, 4}, 1}, {{1, 2, 7, 6, 4}, 4}};

  for (TestCase tc : testCases) {
    int myAnswer = solution(tc.nums);

    cout << "answer : " << tc.result << ", myAnswer : " << myAnswer << "\n";
  }
}