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

int solution(int size, vector<int> &sticks) {
  int answer = 0;
  int temp = -1;

  for (int i = size - 1; i >= 0; i--) {
    if (sticks[i] > temp) {
      answer++;
      temp = sticks[i];
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

  int N;
  cin >> N;

  vector<int> sticks(N);

  for (int i = 0; i < N; i++) {
    cin >> sticks[i];
  }

  int answer = solution(N, sticks);
  cout << answer;
  cout << "\n";

  return 0;
}
