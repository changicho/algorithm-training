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

double solution(string &s) {
  int size = s.size();

  double answer = 0.0;
  for (int left = 0; left < size; left++) {
    if (s[left] != 't') continue;

    double count = 0;
    for (int right = left; right < size; right++) {
      int length = right - left + 1;

      count += s[right] == 't';

      if (s[right] != 't') continue;
      if (length < 3) continue;
      double cur = (count - 2) / (length - 2);

      answer = max(answer, cur);
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

  string S;
  cin >> S;
  auto answer = solution(S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}