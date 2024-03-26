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

long long solution(string &s) {
  long long answer = 0;

  int size = s.size();
  unordered_map<char, int> counts;

  for (char &c : s) {
    counts[c]++;

    if (counts[c] >= 2) answer = 1;
  }

  for (char from = 'a'; from <= 'z'; from++) {
    for (char to = from + 1; to <= 'z'; to++) {
      long long cur = counts[from] * counts[to];

      answer += cur;
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

  long long answer = solution(S);
  cout << answer << endl;

  return 0;
}