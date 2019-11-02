#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;

void dfs(int depth, vector<int> combination) {
  if (depth == M) {
    for (int number : combination) {
      cout << number << " ";
    }
    cout << "\n";
    return;
  }

  for (int n : numbers) {
    combination.push_back(n);
    dfs(depth + 1, combination);
    combination.pop_back();
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> combination;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    numbers.push_back(i + 1);
  }

  dfs(0, combination);

  return 0;
}