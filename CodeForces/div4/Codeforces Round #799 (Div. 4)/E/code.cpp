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

int solution(vector<int> &nums, int s) {
  int size = nums.size();
  vector<int> prefixes(size + 1, 0);
  for (int i = 0; i < size; i++) {
    int n = nums[i];

    prefixes[i + 1] = prefixes[i] + n;
  }

  if (prefixes.back() < s) return -1;
  if (prefixes.back() == s) return 0;

  int answer = size;

  for (int left = 0; left <= size; left++) {
    // prefixes[size] - prefixes[i] = s
    int target = s + prefixes[left];

    // (left + 1) ~ right
    int right = upper_bound(prefixes.begin(), prefixes.end(), target) -
                prefixes.begin() - 1;

    int length = right - (left + 1) + 1;
    answer = min(answer, size - length);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int testCase = 1; testCase <= T; testCase++) {
    int N, S;
    cin >> N >> S;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    int ret = solution(arr, S);

    cout << ret << "\n";
  }

  return 0;
}