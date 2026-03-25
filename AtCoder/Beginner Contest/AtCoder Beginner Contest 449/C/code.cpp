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

long long solution(int size, int left, int right, string& s) {
  long long answer = 0;

  vector<vector<int>> index(26);

  for (int i = 0; i < size; i++) {
    int target = s[i] - 'a';

    // i - right ~ i - left
    int count =
        upper_bound(index[target].begin(), index[target].end(), i - left) -
        lower_bound(index[target].begin(), index[target].end(), i - right);

    answer += count;
    index[target].push_back(i);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, L, R;
  cin >> N >> L >> R;

  string S;
  cin >> S;

  auto answer = solution(N, L, R, S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}