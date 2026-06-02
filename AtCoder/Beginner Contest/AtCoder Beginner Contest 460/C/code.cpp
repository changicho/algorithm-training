#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

int solution(vector<int>& shari, vector<int>& neta) {
  int sSize = shari.size();
  int nSize = neta.size();

  int answer = 0;

  // the weight of the neta must be at most twice the weight of the shari
  sort(shari.begin(), shari.end());
  sort(neta.begin(), neta.end());

  int index = 0;
  for (int& s : shari) {
    if (s * 2 >= neta[index]) {
      index++;
      answer++;
    }

    if (index == nSize) break;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  vector<int> A(N), B(M);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  auto answer = solution(A, B);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}