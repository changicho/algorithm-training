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

string solution(string &s) {
  int size = s.size();

  bool find = true;
  string answer = "";

  for (int i = 0; i < size; i++) {
    if (s[i] == '#') {
      find = true;
      answer += '#';
      continue;
    } else {
      if (find) {
        answer += 'o';
        find = false;
      } else {
        answer += '.';
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

  string S;
  cin >> S;

  string answer = solution(S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}