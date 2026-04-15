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

int answer = 0;

bool isToggled(double a, double b) {
  if (a < 0 && b > 0) return true;
  if (a > 0 && b < 0) return true;
  return false;
}

void recursive(int i, vector<int>& nums, double cur, int count) {
  if (i == nums.size()) {
    answer = max(answer, count);
    return;
  }

  double length = nums[i];

  double left = cur - length;
  double right = cur + length;

  recursive(i + 1, nums, left, count + isToggled(cur, left));
  recursive(i + 1, nums, right, count + isToggled(cur, right));
}

int solution(int size, vector<int>& nums) {
  recursive(0, nums, 0.5, 0);

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

  vector<int> L(N);

  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  auto answer = solution(N, L);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}