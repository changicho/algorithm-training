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

using ll = long long;

long long solution(int n) {
  long long answer = 0;

  int left = 1, right = 2;

  while (right <= n) {
    string ret;

    cout << "? " << left << " " << right << endl;
    cout.flush();

    cin >> ret;

    if (ret == "Yes") {
      long long cur = right - left;
      answer += cur;

      right++;
    } else {
      left++;
      if (left == right) {
        right++;
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

  int N;
  cin >> N;

  auto answer = solution(N);

  cout << "! " << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}