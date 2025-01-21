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

vector<int> solution(int n) {
  vector<int> answer(n, 1);
  for (int i = 0; i < n; i++) {
    answer[i] = i + 1;
  }
  answer[n - 1] = 1;
  answer[n - 2] = 1;

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

  for (int testCase = 1; testCase <= T; testCase++) {
    int N;
    cin >> N;

    vector<int> answer = solution(N);

    for (int &a : answer) {
      cout << a << " ";
    }
    cout << endl;
  }

  return 0;
}