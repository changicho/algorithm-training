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
  int size = s.size();

  if (s.front() != '<' || s.back() != '>') return false;
  for (int i = 1; i < size - 1; i++) {
    if (s[i] != '=') return false;
  }

  return true;
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