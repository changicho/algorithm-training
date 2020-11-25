#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct DisjointSet {
  vector<int> parents;
  vector<int> levels;

  DisjointSet(int size) {
    parents.resize(size);
    levels.resize(size);

    for (int i = 0; i < size; i++) {
      parents[i] = i;
      levels[i] = 1;
    }
  }

  int find(int index) {
    if (parents[index] == index) return index;

    return parents[index] = find(parents[index]);
  }

  void merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (u != v) parents[v] = u;
  }
};

void solution() {
  int N, M, K;

  cin >> N >> M >> K;

  vector<int> cards(M);

  for (int i = 0; i < M; i++) {
    cin >> cards[i];
  }

  sort(cards.begin(), cards.end());
  DisjointSet ds(N + 1);

  for (int i = 0; i < K; i++) {
    int target;
    cin >> target;

    int index = upper_bound(cards.begin(), cards.end(), target) - cards.begin();
    int dsIndex = ds.find(index);

    cout << cards[dsIndex] << '\n';

    ds.merge(dsIndex + 1, dsIndex);
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}