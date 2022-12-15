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
// [totalSize][curLength]
int cache[101][101];

int recursive(int size, int curLength) {
  if (size == curLength) return 1;

  if (cache[size][curLength] != -1) return cache[size][curLength];
  cache[size][curLength] = 0;

  int ret = 0;
  for (int nextLength = 1; nextLength <= size - curLength; nextLength++) {
    int curCount = nextLength + curLength - 1;

    curCount *= recursive(size - curLength, nextLength);
    curCount %= MOD;

    ret += curCount;
    ret %= MOD;
  }

  return cache[size][curLength] = ret;
}

int solution(int size) {
  memset(cache, -1, sizeof(cache));

  int answer = 0;
  for (int curLength = 1; curLength <= size; curLength++) {
    answer += recursive(size, curLength);
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
