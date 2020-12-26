#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

void recursive(vector<int> combination) {
  if (combination.size() == M) {
    for (int number : combination) {
      cout << number << " ";
    }
    cout << "\n";
    return;
  }

  combination.push_back(-1);
  int size = combination.size();
  int before = size == 1 ? 0 : combination[size - 2];

  for (int number : arr) {
    if (before > number) continue;
    combination[size - 1] = number;
    recursive(combination);
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

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}