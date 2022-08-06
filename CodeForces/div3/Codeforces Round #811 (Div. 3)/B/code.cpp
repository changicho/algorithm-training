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
int solution(int n, vector<int> &a) {
  int answer = 0;

  unordered_map<int, int> counts;
  unordered_set<int> needToErase;
  for (int &num : a) {
    counts[num]++;

    if (counts[num] >= 2) needToErase.insert(num);
  }

  for (int left = 0; left < n && !needToErase.empty(); left++) {
    int num = a[left];
    counts[num]--;

    if (counts[num] == 1) needToErase.erase(num);

    if (needToErase.empty()) {
      answer = left + 1;
      break;
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    int answer = solution(N, A);
    cout << answer << "\n";
  }

  return 0;
}