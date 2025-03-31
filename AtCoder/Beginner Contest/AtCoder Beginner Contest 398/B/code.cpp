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

bool solution(vector<int> &cards) {
  vector<int> count(15, 0);
  for (int &num : cards) {
    count[num]++;
  }

  sort(count.begin(), count.end(), greater<int>());

  if (count[0] >= 3 && count[1] >= 2) return true;
  return false;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  vector<int> A(7);
  for (int i = 0; i < 7; i++) {
    cin >> A[i];
  }

  bool answer = solution(A);

  // cout << answer << endl;
  cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}