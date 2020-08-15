#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Tree {
  int parent;
  vector<int> links;
};

int answer = 0;
int target;
Tree trees[51];
bool visited[51];

void search(int index) {
  if (visited[index]) return;
  if (index == target) return;
  visited[index] = true;

  if (trees[index].links.size() == 0) {
    answer += 1;
    return;
  }

  if (trees[index].links.size() == 1) {
    if (trees[index].links[0] == target) {
      answer += 1;
      return;
    }
  }

  for (int link : trees[index].links) {
    if (link != target && !visited[link]) {
      search(link);
    }
  }
}

void solution() {
  int N;
  int root;
  cin >> N;

  for (int i = 0; i < N; i++) {
    trees[i].parent = -1;
  }

  for (int i = 0; i < N; i++) {
    cin >> trees[i].parent;

    if (trees[i].parent == -1) {
      root = i;
    } else {
      int parent = trees[i].parent;
      trees[parent].links.push_back(i);
    }
  }

  cin >> target;

  search(root);

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}