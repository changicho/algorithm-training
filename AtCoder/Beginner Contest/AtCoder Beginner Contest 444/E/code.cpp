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

long long solution(int size, const vector<long long>& nums, long long limit) {
  long long answer = 0;

  multiset<long long> window;

  auto check = [&](long long newVal) -> bool {
    if (window.empty()) return true;
    if (window.count(newVal) > 0) return false;

    auto nextEl = window.upper_bound(newVal);
    if (nextEl != window.end()) {
      if (abs(*nextEl - newVal) < limit) {
        return false;
      }
    }

    if (nextEl == window.begin()) {
      return true;
    }
    // Check previous element
    auto prevEl = prev(nextEl);

    if (abs(*prevEl - newVal) < limit) {
      return false;
    }

    return true;
  };

  for (int left = 0, right = 0; right < size; right++) {
    while (left < right && check(nums[right]) == false) {
      window.erase(window.find(nums[left]));
      left++;
    }
    window.insert(nums[right]);

    answer += right - left + 1;
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
  long long D;
  cin >> N >> D;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long answer = solution(N, A, D);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}