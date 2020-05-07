#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N;
  cin >> N;

  int size = (1 << N) - 1;
  vector<int> arr(size);
  vector<bool> visited(size, false);

  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> answers;

  for (int level = 0; level < N; level++) {
    int div = 1 << (level + 1);
    int index = size / div;
    int diff = index + 1;
    vector<int> answer;

    for (; index < size; index += diff) {
      if (visited[index]) {
        continue;
      }

      answer.push_back(arr[index]);
      visited[index] = true;
    }

    answers.push_back(answer);
  }

  for (vector<int> v : answers) {
    for (int n : v) {
      cout << n << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}