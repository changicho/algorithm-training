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

// time : 5min
int solution(string &s) {
  unordered_set<char> us;
  int days = 1;
  for (char &c : s) {
    us.insert(c);
    if (us.size() > 3) {
      days++;
      us.clear();
      us.insert(c);
    }
  }
  return days;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    string S;
    cin >> S;

    int answer = solution(S);
    cout << answer << "\n";
  }

  return 0;
}