using namespace std;

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define LIMIT 200000001

using namespace std;

bool check(vector<int> stones, int k, int m) {
  int count = 0;

  for (int i = 0; i < stones.size(); i++) {
    if (stones[i] < m) {
      count++;

      if (count == k) {
        return false;
      }
    } else {
      count = 0;
    }
  }
  return true;
}

int solution(vector<int> stones, int k) {
  int answer = 0;
  int left = 0, right = LIMIT;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (check(stones, k, mid)) {
      answer = max(answer, mid);

      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return answer;
}

struct TestCase {
  vector<int> stones;
  int k;
  int answer;
};

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> arr;
  for (int i = 1; i <= 200000; i++) {
    arr.push_back(i);
  }

  vector<int> arr2;
  for (int i = 1; i <= 200000; i++) {
    arr2.push_back(1);
  }

  vector<int> arr3;
  for (int i = 1; i <= 200000; i++) {
    arr3.push_back(i % 20);
  }

  vector<TestCase> testCases = {{{2, 4, 5, 3, 2, 1, 4, 2, 5, 1}, 3, 3},
                                {arr, 200000, 200000},
                                {arr2, 1, 1},
                                {arr3, 20, 19}};

  for (TestCase testCase : testCases) {
    int answer = solution(testCase.stones, testCase.k);

    cout << "myAnswer : " << answer << ", " << testCase.answer << "\n";
  }

  return 0;
}