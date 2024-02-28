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

string solution(string &s, vector<vector<char>> &queries) {
  string table = "";
  for (char c = 'a'; c <= 'z'; c++) {
    table += c;
  }

  for (vector<char> &q : queries) {
    char from = q[0], to = q[1];

    for (int i = 0; i < table.size(); i++) {
      if (table[i] == from) {
        table[i] = to;
      }
    }
  }

  for (char &c : s) {
    c = table[c - 'a'];
  }

  return s;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  string S;
  cin >> N;
  cin >> S;

  int Q;
  cin >> Q;
  vector<vector<char>> queries(Q, vector<char>(2));

  for (int i = 0; i < Q; i++) {
    cin >> queries[i][0] >> queries[i][1];
  }

  string ret = solution(S, queries);

  cout << ret << "\n";

  return 0;
}