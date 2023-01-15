#include <algorithm>
#include <climits>
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

const int MAX = 1e9 + 1;

// use monotonic queue
// time : O(N)
// space : O(N)
int solution(int size, int k, string &line) {
  int answer = 0;

  queue<int> hamburgers, peoples;
  for (int i = 0; i < size; i++) {
    while (!hamburgers.empty() && hamburgers.front() < i - k) {
      hamburgers.pop();
    }
    while (!peoples.empty() && peoples.front() < i - k) {
      peoples.pop();
    }

    if (line[i] == 'H') {
      if (!peoples.empty() && peoples.front() + k >= i) {
        answer++;
        peoples.pop();
        continue;
      }

      hamburgers.push(i);
    } else if (line[i] == 'P') {
      if (!hamburgers.empty() && hamburgers.front() + k >= i) {
        answer++;
        hamburgers.pop();
        continue;
      }

      peoples.push(i);
    }
  }

  return answer;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  string line;
  cin >> line;

  int answer = solution(N, K, line);
  cout << answer;
  cout << "\n";

  return 0;
}
