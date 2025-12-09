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

auto solution(int size, int k, vector<int>& nums) {
  vector<int> priority(size + 1, -1);
  for (int i = 0; i < size; i++) {
    priority[nums[i]] = i;
  }

  vector<vector<int>> candidates(size + 1);
  for (int num = 1; num <= size; num++) {
    candidates[priority[num] + 1].push_back(num);
  }

  vector<int> answer;
  for (int i = 0; i <= size && answer.size() < k; i++) {
    for (int& candidate : candidates[i]) {
      answer.push_back(candidate);
      if (answer.size() == k) {
        break;
      }
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

  int T;
  cin >> T;

  for (int test = 1; test <= T; test++) {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    auto answer = solution(N, K, A);

    // cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    for (auto& line : answer) {
      cout << line << " ";
    }
    cout << endl;
  }

  return 0;
}