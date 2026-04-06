#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

long long solution(long long n) {
  const long long LIMIT = 1e9;

  int lengths[31] = {
      0,
  };
  for (int i = 0; i < 31; i++) {
    lengths[i] = to_string(1LL << i).length();
  }

  int pows[10] = {
      1,
  };
  for (int i = 1; i < 10; i++) {
    pows[i] = pows[i - 1] * 10;
  }

  vector<long long> nums;
  unordered_set<long long> visited;

  function<void(long long)> dfs = [&](long long num) {
    for (int i = 0; i < 31; i++) {
      long long cur = (1LL << i);

      int length = lengths[i];
      long long next = num * pows[length] + cur;

      if (next > LIMIT) continue;

      if (visited.count(next)) continue;
      visited.insert(next);
      nums.push_back(next);

      dfs(next);
    }
  };

  dfs(0);

  sort(nums.begin(), nums.end());

  return nums[n - 1];
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  long long N;
  cin >> N;

  auto answer = solution(N);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}