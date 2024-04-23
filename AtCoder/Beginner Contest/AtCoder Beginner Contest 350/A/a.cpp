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

bool solution(string &s) {
  int num = (s[3] - '0') * 100 + (s[4] - '0') * 10 + (s[5] - '0');

  return num > 0 && num < 350 && num != 316;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  string S;
  cin >> S;

  bool answer = solution(S);

  cout << (answer ? "Yes" : "No") << endl;

  return 0;
}