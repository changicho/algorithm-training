#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;
vector<int> answer;
int N, M;

bool visited[8] = {
    false,
};

void dfs(int index) {
  if (index == M) {
    for (int i : answer) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }

  int prev = -1;
  for (int i = 0; i < N; i++) {
    if (visited[i] || prev == arr[i]) continue;

    visited[i] = true;
    prev = arr[i];
    answer[index] = arr[i];

    dfs(index + 1);

    visited[i] = false;
  }
}

void solution() {
  cin >> N >> M;
  arr.resize(N);
  answer.resize(M);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  stable_sort(arr.begin(), arr.end());

  dfs(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}