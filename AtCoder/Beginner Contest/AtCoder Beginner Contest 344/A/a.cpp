#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

string solution(string &s) {
  string answer = "";
  int size = s.size();

  bool toggle = false;

  for (char &c : s) {
    if (c == '|') {
      toggle = !toggle;
    } else {
      if (toggle) {
        continue;
      } else {
        answer += c;
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

  return 0;
}