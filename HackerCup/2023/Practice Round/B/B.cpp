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

typedef long long ll;

bool solution(ll rows, ll cols, ll a, ll b) {
  return rows > cols;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./dim_sum_delivery_input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    ll R, C, A, B;
    cin >> R >> C >> A >> B;

    bool answer = solution(R, C, A, B);

    cout << "Case #" << testCase << ": " << (answer ? "YES" : "NO") << "\n";
  }

  return 0;
}