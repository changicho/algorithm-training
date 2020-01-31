#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#define MAXSIZE 1000000  // taste : 1 ~ 1000000

using namespace std;

vector<long long> tree;

void update(int node, int left, int right, int target, long long diff) {
  if (target < left || right < target) return;

  // update current node
  tree[node] += diff;

  if (left == right) return;

  int mid = (left + right) / 2;
  update(node * 2, left, mid, target, diff);
  update(node * 2 + 1, mid + 1, right, target, diff);
}

long long query(int node, int left, int right, int target) {
  if (left == right) return left;

  int mid = (left + right) / 2;

  // left side query
  if (node * 2 <= tree.size() && tree[node * 2] >= target)
    return query(node * 2, left, mid, target);

  // update target (remove left side)
  target -= tree[node * 2];

  // right side query
  if (node * 2 + 1 <= tree.size() && tree[node * 2 + 1] >= target)
    return query(node * 2 + 1, mid + 1, right, target);
}

void solution() {
  int height = (int)ceil(log2(MAXSIZE));
  int treeSize = 1 << (height + 1);
  tree.resize(treeSize);

  vector<int> answers;
  int N;
  cin >> N;

  while (N--) {
    int command;
    cin >> command;

    switch (command) {
      case 1: {
        int rank;
        cin >> rank;

        int index = query(1, 0, MAXSIZE - 1, rank);
        update(1, 0, MAXSIZE - 1, index, -1);

        answers.push_back(index);
        break;
      }
      case 2: {
        int taste;
        long long diff;
        cin >> taste >> diff;

        update(1, 0, MAXSIZE - 1, taste, diff);
        break;
      }
    }
  }

  // print answers
  for (int answer : answers) {
    cout << answer << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}