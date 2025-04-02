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

// -200,000 ~ 200,000
struct Axis {
  int y, x;

  Axis operator+(const Axis &a) const { return {y + a.y, x + a.x}; }
  Axis operator-(const Axis &a) const { return {y - a.y, x - a.x}; }

  long long convert() { return (long long)y * 1000000 + x; }

  bool operator==(const Axis &a) const { return y == a.y && x == a.x; }
};

unordered_map<char, Axis> dirMap = {
    {'N', {-1, 0}},
    {'W', {0, -1}},
    {'S', {1, 0}},
    {'E', {0, 1}},
};

string solution(int size, int row, int col, string &s) {
  string answer = "";

  Axis target = {row, col};

  unordered_set<long long> visited;

  visited.insert(0);
  Axis cur = {0, 0};

  for (int i = 0; i < size; i++) {
    Axis dir = dirMap[s[i]];

    cur = cur + dir;

    Axis before = cur - target;

    if (visited.find(before.convert()) != visited.end()) {
      answer += '1';
    } else {
      answer += '0';
    }

    visited.insert(cur.convert());
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, R, C;
  cin >> N >> R >> C;

  string S;
  cin >> S;

  string answer = solution(N, R, C, S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}