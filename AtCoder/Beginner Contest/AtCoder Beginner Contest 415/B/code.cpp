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

vector<pair<int, int>> solution(string &s) {
  vector<pair<int, int>> answer;

  int size = s.size();
  vector<int> nums;
  for (int i = 0; i < size; i++) {
    if (s[i] == '#') {
      nums.push_back(i + 1);
    }
  }

  for (int i = 0; i < nums.size(); i += 2) {
    answer.push_back({nums[i], nums[i + 1]});
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

  vector<pair<int, int>> answer = solution(S);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto &line : answer) {
    cout << line.first << "," << line.second << "\n";
  }
  // cout << endl;

  return 0;
}