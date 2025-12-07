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

auto solution(int a, int b) {
  vector<int> answer;

  int temp = a;

  for (int i = 0; i <= 31; i++) {
    int digit = 1 << i;
    if (digit > a) break;

    if ((a & digit) == (b & digit)) continue;

    int cur = 0;
    cur += digit;

    answer.push_back(cur);
    temp ^= cur;
  }

  if (temp != b) {
    return vector<int>{-1};
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

  for (int testCase = 1; testCase <= T; testCase++) {
    int A, B;
    cin >> A >> B;

    auto answer = solution(A, B);

    // cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;

    if (answer.size() == 1 && answer[0] == -1) {
      cout << -1 << endl;
      continue;
    }

    cout << answer.size() << endl;
    for (auto& line : answer) {
      cout << line << " ";
    }
    cout << endl;
  }

  return 0;
}