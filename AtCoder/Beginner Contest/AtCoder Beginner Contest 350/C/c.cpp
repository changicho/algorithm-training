#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<pair<int, int>> solution(int size, vector<int> &nums) {
  vector<pair<int, int>> answer;

  int indexes[200001] = {
      0,
  };

  for (int i = 0; i < size; i++) {
    indexes[nums[i]] = i + 1;
  }

  for (int n = 1; n <= size; n++) {
    if (indexes[n] == n) continue;

    int curNum = nums[n - 1];

    int targetI = indexes[n];

    // target -> n
    // n -> target

    answer.push_back({n, targetI});

    nums[n - 1] = n;
    nums[targetI - 1] = curNum;

    indexes[n] = n;
    indexes[curNum] = targetI;
  }

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

  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<pair<int, int>> answer = solution(N, A);

  cout << answer.size() << "\n";

  for (auto &ans : answer) {
    cout << ans.first << " " << ans.second << "\n";
  }
  cout << endl;

  return 0;
}