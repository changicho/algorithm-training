#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;

void dfs(int depth, int start, vector<int> arr) {
  if (depth == M) {
    for (int n : arr) {
      cout << n << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = start; i <= N; i++) {
    vector<int> newArr = arr;

    newArr.push_back(i);
    dfs(depth + 1, i, newArr);
  }
}

void solution() {
  cin >> N >> M;

  vector<int> arr;

  dfs(0, 1, arr);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}