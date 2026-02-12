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

bool check(long long val, vector<long long>& nums) {
  unordered_map<long long, int> count;

  for (long long& num : nums) {
    if (num > val) return false;

    if (num == val) continue;
    long long diff = val - num;

    if (count.count(diff) > 0) {
      count[diff]--;
      if (count[diff] == 0) count.erase(diff);
    } else {
      count[num]++;
    }
  }

  if (count.size() == 0) return true;
  return false;
}

vector<long long> solution(int size, vector<long long>& nums) {
  vector<long long> answer;

  long long minimum = *min_element(nums.begin(), nums.end());
  long long maximum = *max_element(nums.begin(), nums.end());

  // remain or broke two cases
  if (check(maximum, nums)) {
    answer.push_back(maximum);
  }

  if (check(minimum + maximum, nums)) {
    answer.push_back(minimum + maximum);
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

  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, A);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << " ";
  }
  cout << endl;

  return 0;
}