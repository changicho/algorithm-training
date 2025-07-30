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

long long solution(int n, int m, vector<int> &a, vector<int> &b) {
  long long answer = 0;

  multiset<int> ms(a.begin(), a.end());

  for (int &second : b) {
    long long target = ((second - m) % m) * -1;

    auto it = ms.lower_bound(target);
    if (it == ms.end()) {
      it = ms.begin();
    }

    answer += (second + *it) % m;
    ms.erase(it);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;

  for (int test = 0; test < T; test++) {
    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }

    long long answer = solution(N, M, A, B);

    cout << answer << endl;
    // cout << (answer ? "Yes" : "No") << endl;
    // for (auto &line : answer) {
    //   cout << line << "\n";
    // }
    // cout << endl;
  }

  return 0;
}