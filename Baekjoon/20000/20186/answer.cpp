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

int solution(int size, vector<int> &array, int k) {
  int answer = 0;

  sort(array.begin(), array.end(), greater<int>());

  for (int i = 0; i < k; i++) {
    answer += array[i];
    answer -= i;
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

  vector<int> array(N);

  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  int answer = solution(N, array, K);

  cout << answer << "\n";

  return 0;
}
