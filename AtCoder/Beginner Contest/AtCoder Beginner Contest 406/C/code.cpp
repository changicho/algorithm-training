#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

long long solution(int size, vector<int> &nums) {
  long long answer = 0;

  long long beforeCount = 0;
  long long curCount = 0;
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] < nums[i + 1]) {
      curCount++;
    } else if (nums[i] > nums[i + 1]) {
      answer += curCount * beforeCount;

      if (curCount > 0) {
        beforeCount = curCount;
      }
      curCount = 0;
    }
  }

  answer += curCount * beforeCount;

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }

  long long answer = solution(N, P);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}