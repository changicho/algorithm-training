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

string solution(string& x) {
  int count[10] = {
      0,
  };

  for (char c : x) {
    count[c - '0']++;
  }

  int minimum = INT_MAX;
  for (int i = 1; i <= 9; i++) {
    if (count[i] > 0) {
      minimum = i;
      break;
    }
  }

  if (minimum == INT_MAX) {
    return "0";
  }
  string answer = "";
  count[minimum]--;
  answer += to_string(minimum);
  for (int i = 0; i <= 9; i++) {
    while (count[i] > 0) {
      answer += to_string(i);
      count[i]--;
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

  string X;
  cin >> X;

  auto answer = solution(X);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}