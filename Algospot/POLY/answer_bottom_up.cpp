#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

const int MOD = 1e7;

int solution(int totalSize) {
  // [totalSize][curLength]
  int dp[101][101] = {
      0,
  };

  // initialize
  for (int length = 0; length <= totalSize; length++) {
    dp[length][length] = 1;
  }

  // update
  for (int size = 1; size <= totalSize; size++) {
    for (int curLength = 1; curLength <= size; curLength++) {
      for (int nextLength = 1; nextLength <= size - curLength; nextLength++) {
        int curCount = nextLength + curLength - 1;

        curCount *= dp[size - curLength][nextLength];
        curCount %= MOD;

        dp[size][curLength] += curCount;
        dp[size][curLength] %= MOD;
      }
    }
  }

  int answer = 0;
  for (int curLength = 1; curLength <= totalSize; curLength++) {
    answer += dp[totalSize][curLength];
    answer %= MOD;
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N;
    cin >> N;

    int answer = solution(N);

    cout << answer << "\n";
  }

  return 0;
}
