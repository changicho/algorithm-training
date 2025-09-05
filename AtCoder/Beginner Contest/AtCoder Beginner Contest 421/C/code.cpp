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

long long calc(string s, string &target) {
  int size = s.size();

  vector<int> aIs, tIs;

  for (int i = 0; i < size; i++) {
    if (s[i] == 'A') {
      aIs.push_back(i);
    }
    if (target[i] == 'A') {
      tIs.push_back(i);
    }
  }

  long long ret = 0;
  for (int i = 0; i < size / 2; i++) {
    ret += abs(aIs[i] - tIs[i]);
  }

  return ret;
}

auto solution(int n, string &s) {
  long long answer = 0;

  int size = n * 2;

  string target = "";
  for (int i = 0; i < size; i++) {
    target += (i % 2) ? 'A' : 'B';
  }

  answer = calc(s, target);

  target = "";
  for (int i = 0; i < size; i++) {
    target += (i % 2) ? 'B' : 'A';
  }

  answer = min(answer, calc(s, target));

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  string S;
  cin >> S;

  auto answer = solution(N, S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}