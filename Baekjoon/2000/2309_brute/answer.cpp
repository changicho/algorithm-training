#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  vector<int> arr(9);

  for (int i = 0; i < 9; i++) {
    cin >> arr[i];
  }

  sort(arr.begin(), arr.end());

  vector<bool> visited = {0, 0, 1, 1, 1, 1, 1, 1, 1};
  sort(visited.begin(), visited.end());

  do {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
      if (!visited[i]) continue;
      sum += arr[i];
    }

    if (sum == 100) {
      for (int i = 0; i < 9; i++) {
        if (!visited[i]) continue;
        cout << arr[i] << "\n";
      }
      break;
    }
  } while (next_permutation(visited.begin(), visited.end()));

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}