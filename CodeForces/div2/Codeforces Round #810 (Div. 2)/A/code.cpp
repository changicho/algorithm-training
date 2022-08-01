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

// time : 10 min
vector<int> solution(int &n) {
  vector<int> answer(n);

  for (int i = 0; i < n; i++) {
    int target = (i + 1) % n;

    answer[target] = (i + 1);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> answer = solution(N);

    for (int &num : answer) {
      cout << num << " ";
    }
    cout << "\n";
    // cout << answer << "\n";
  }

  return 0;
}