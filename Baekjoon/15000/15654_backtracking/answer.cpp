#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int N, M;
vector<int> arr;
bool visited[8];

void recursive(vector<int> answer) {
  if (answer.size() == M) {
    for (int a : answer) {
      cout << a << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    if (visited[i]) continue;
    vector<int> new_answer = answer;
    new_answer.push_back(arr[i]);

    visited[i] = true;
    recursive(new_answer);
    visited[i] = false;
  }
}

void solution() {
  cin >> N >> M;
  arr.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());

  recursive({});
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}