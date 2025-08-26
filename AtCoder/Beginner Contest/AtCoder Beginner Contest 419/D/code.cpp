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

struct Swap {
  int left, right;
};

auto solution(int length, int size, string &s, string &t, vector<Swap> &swaps) {
  vector<int> diffs(length + 1);

  for (Swap &swap : swaps) {
    diffs[swap.left]++;

    diffs[swap.right + 1]--;
  }

  string answer = "";
  for (int i = 0, temp = 0; i < length; i++) {
    temp += diffs[i];
    if (temp % 2 == 1) {
      answer += t[i];
    } else {
      answer += s[i];
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

  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;

  vector<Swap> swaps(M);
  for (int i = 0; i < M; i++) {
    cin >> swaps[i].left >> swaps[i].right;
    swaps[i].left--;
    swaps[i].right--;
  }

  // for (int i = 0; i < M; i++) {
  //   cout << swaps[i].left << " " << swaps[i].right << endl;
  // }

  auto answer = solution(N, M, S, T, swaps);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}