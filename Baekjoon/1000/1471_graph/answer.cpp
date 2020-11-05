#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int steps[200001];
int counts[200001];
bool visited[200001];
int N;

int recursive(int index) {
  if (counts[index] != -1) return counts[index];

  visited[index] = true;
  int next = index;

  for (char c : to_string(index)) {
    next += c - '0';
  }

  if (next > N) next -= N;
  steps[index] = next;

  if (visited[next]) {
    if (counts[next] != -1) return counts[index] = counts[next] + 1;
    counts[index] = 1;

    int count = next;
    while (count != index) {
      counts[index]++;
      count = steps[count];
    }

    count = next;
    while (count != index) {
      counts[count] = counts[index];
      count = steps[count];
    }

    return counts[index];
  }

  recursive(next);

  if (counts[index] == -1) return counts[index] = recursive(next) + 1;

  return counts[index];
}

void solution() {
  cin >> N;

  fill(counts, counts + N + 1, -1);
  int answer = 0;

  for (int i = 1; i <= N; i++) {
    answer = max(answer, recursive(i));
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}