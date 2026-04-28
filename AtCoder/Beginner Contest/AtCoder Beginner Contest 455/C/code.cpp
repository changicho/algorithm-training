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

long long solution(int size, int k, vector<int>& nums) {
  long long answer = 0;

  unordered_map<int, int> count;
  for (int& num : nums) {
    count[num]++;
  }

  vector<long long> arr;
  for (auto& [key, val] : count) {
    arr.push_back(1LL * key * val);
  }
  sort(arr.begin(), arr.end());

  while (k > 0 && !arr.empty()) {
    arr.pop_back();
    k--;
  }

  for (long long& sum : arr) {
    answer += sum;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto answer = solution(N, K, A);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}