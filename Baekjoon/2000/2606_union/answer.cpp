#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int links[101];
int level[101];

int union_find(int index) {
  if (links[index] == index) {
    return index;
  }
  return links[index] = union_find(links[index]);
}

void union_merge(int first, int second) {
  if (first > second) {
    swap(first, second);
  }

  first = union_find(first);
  second = union_find(second);

  if (first == second) {
    return;
  }

  if (level[first] < level[second]) {
    swap(first, second);
  }

  links[second] = first;
  level[first] += level[second];
  level[second] = 0;
}

void solution() {
  int N, M;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    links[i] = i;
    level[i] = 1;
  }

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    union_merge(to, from);
  }

  cout << level[links[1]] - 1 << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}