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

struct Status {
  long long value;
  int index;
  int before;
  int current;

  bool operator<(const Status& other) const { return value < other.value; }
};

vector<long long> solution(int size, vector<long long>& nums, int k, int x) {
  vector<long long> answer;

  sort(nums.begin(), nums.end(), greater<long long>());

  priority_queue<Status> q;
  q.push({nums[0] * k, 0, 0, k});

  while (!q.empty() && answer.size() < x) {
    auto [value, index, before, current] = q.top();
    q.pop();

    answer.push_back(value);

    if (before) {
      q.push({value - nums[index - 1] + nums[index], index, before - 1,
              current + 1});
    }
    if (index != size - 1) {
      q.push(
          {value - nums[index] + nums[index + 1], index + 1, current - 1, 1});
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, K, X;
  cin >> N >> K >> X;

  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, A, K, X);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}