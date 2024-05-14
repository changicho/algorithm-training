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

pair<int, int> solution(vector<string> &a, vector<string> &b) {
  int size = a.size();

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (a[y][x] != b[y][x]) {
        return {y + 1, x + 1};
      }
    }
  }

  return {-1, -1};
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<string> A(N), B(N);

  for (int y = 0; y < N; y++) {
    cin >> A[y];
  }
  for (int y = 0; y < N; y++) {
    cin >> B[y];
  }

  pair<int, int> answer = solution(A, B);

  cout << answer.first << " " << answer.second << "\n";

  return 0;
}