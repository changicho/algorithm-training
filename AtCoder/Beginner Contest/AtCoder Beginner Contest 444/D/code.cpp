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

string solution(int size, vector<long long>& nums) {
  string answer = "";

  int count[200001] = {
      0,
  };

  long long maximum = *max_element(nums.begin(), nums.end());

  int diffs[200001] = {
      0,
  };

  for (long long& num : nums) {
    diffs[0] += 1;

    diffs[num] -= 1;
  }

  for (int i = 0, acc = 0; i < maximum; i++) {
    acc += diffs[i];
    count[i] = acc;
  }

  long long carry = 0;
  for (int i = 0; i < maximum; i++) {
    long long total = count[i] + carry;

    answer += (total % 10) + '0';
    carry = total / 10;
  }
  if (carry > 0) {
    string s = to_string(carry);
    reverse(s.begin(), s.end());
    answer += s;
  }

  reverse(answer.begin(), answer.end());

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

  cout << answer << endl;
  // // reverse print
  // for (int i = (int)answer.size() - 1; i >= 0; i--) {
  //   cout << answer[i];
  // }
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}