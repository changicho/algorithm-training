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

vector<int> solution(int size, vector<int> &nums) {
  vector<int> answer;

  vector<bool> visited(size + 1, false);
  for (int &num : nums) {
    if (num == -1) continue;

    if (visited[num]) return {};

    visited[num] = true;
  }

  int target = 1;
  while (target < size && visited[target]) target++;

  for (int i = 0; i < size && target <= size; i++) {
    if (nums[i] == -1) {
      nums[i] = target;
      target++;
      while (target < size && visited[target]) target++;
    }
  }

  return nums;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, A);

  // cout << answer << endl;
  cout << (answer.size() > 0 ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line << " ";
  }
  cout << endl;

  return 0;
}