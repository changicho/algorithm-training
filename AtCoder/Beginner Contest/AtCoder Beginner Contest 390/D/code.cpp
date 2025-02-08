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

int solution(int size, vector<long long> &nums) {
  unordered_set<long long> us;

  long long result = 0;
  function<void(int)> recursive = [&](int index) {
    if (index == size) {
      us.insert(result);
      return;
    }

    result ^= nums[index];
    recursive(index + 1);
    result ^= nums[index];

    for (int i = 0; i < index; i++) {
      if (nums[i] == 0) {
        continue;
      }

      long long val = nums[i];

      result ^= val;
      nums[i] = 0;
      nums[index] += val;
      result ^= nums[index];

      recursive(index + 1);

      result ^= nums[index];
      nums[i] = val;
      nums[index] -= val;
      result ^= val;
    }
  };

  recursive(0);

  return us.size();
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<long long> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int answer = solution(N, A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}