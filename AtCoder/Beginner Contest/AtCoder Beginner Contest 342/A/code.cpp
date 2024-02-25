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

int solution(string &s) {
  int size = s.size();
  int counts[26] = {
      0,
  };

  for (char &c : s) {
    counts[c - 'a']++;
  }

  for (int i = 0; i < size; i++) {
    if (counts[s[i] - 'a'] == 1) return i + 1;
  }

  return size;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  string S;
  cin >> S;

  int answer = solution(S);

  cout << answer << "\n";

  return 0;
}