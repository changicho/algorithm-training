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

string convert(string& s) {
  string ret = "";

  for (char& c : s) {
    int size = ret.size();
    if (size >= 3) {
      if (c == ')' && ret[size - 1] == 'x' && ret[size - 2] == 'x' &&
          ret[size - 3] == '(') {
        ret.pop_back();
        ret.pop_back();
        ret.pop_back();
        ret.push_back('x');
        ret.push_back('x');

        continue;
      }
    }

    ret.push_back(c);
  }
  return ret;
}

bool solution(string& a, string& b) {
  string ac = convert(a);
  string bc = convert(b);

  bool answer = ac == bc;

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

  for (int tc = 1; tc <= T; tc++) {
    string A, B;
    cin >> A >> B;

    auto answer = solution(A, B);

    // cout << answer << endl;
    cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}