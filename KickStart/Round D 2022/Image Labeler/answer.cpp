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

// time : 20min (debug)
double solution(int n, int m, vector<int>& arr) {
  sort(arr.begin(), arr.end());

  double answer = 0;

  for (int i = 0; i < m - 1; i++) {
    answer += arr.back();
    arr.pop_back();
  }

  int size = arr.size();
  int center = size / 2;
  if (size % 2 == 0) {
    answer += ((double)arr[center - 1] + arr[center]) / 2;
  } else {
    answer += (arr[center]);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(6);
  cout << fixed;

  // freopen("./input.txt", "r", stdin);

  int T;
  cin >> T;
  for (int testCase = 1; testCase <= T; testCase++) {
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    double answer = solution(N, M, arr);
    cout << "Case #" << testCase << ": " << answer << "\n";
  }

  return 0;
}