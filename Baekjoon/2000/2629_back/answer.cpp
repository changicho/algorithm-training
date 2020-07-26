#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> weights;
bool visited[31][30 * 500 + 1];

int absolute(int number) {
  return number < 0 ? -number : number;
}

void dfs(int index, int total) {
  if (index > weights.size() || visited[index][total]) {
    return;
  }

  visited[index][total] = true;

  int plus = total + weights[index];
  int minus = absolute(total - weights[index]);

  dfs(index + 1, total);
  dfs(index + 1, plus);
  dfs(index + 1, minus);
}

void solution() {
  int N;
  cin >> N;
  weights.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> weights[i];
  }
  dfs(0, 0);

  int C;
  cin >> C;
  for (int i = 0; i < C; i++) {
    int ball;
    cin >> ball;

    if (500 * 30 >= ball && visited[weights.size()][ball]) {
      cout << "Y ";
    } else {
      cout << "N ";
    }
  }

  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}