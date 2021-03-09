#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct SegmentTree {
  int size;
  vector<long long> arr;
  vector<int> tree;

  SegmentTree(vector<long long> array) {
    arr = array;
    size = array.size();

    arr.push_back(1e9 + 1);
    tree.resize(4 * size + 1);
    init(1, 0, size - 1);
  }

  inline int operation(int x, int y) {
    return arr[x] <= arr[y] ? x : y;
  }

  int init(int node, int start, int end) {
    if (start == end) {
      return tree[node] = start;
    }
    int mid = (start + end) / 2;

    return tree[node] = operation(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
  }

  void update(int node, int start, int end, int index) {
    if (index < start || index > end) {
      return;
    }
    tree[node] = operation(tree[node], index);

    if (start != end) {
      update(node * 2, start, (start + end) / 2, index);
      update(node * 2 + 1, (start + end) / 2 + 1, end, index);

      tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
    }
  }

  void update(int index, int value) {
    arr[index] = value;
    update(1, 0, size - 1, index);
  }

  int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return size;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return operation(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
  }

  int query(int left, int right) {
    return query(1, 0, size - 1, left, right);
  }
};

void solution() {
  int N, M;
  cin >> N;
  vector<long long> array(N);

  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  SegmentTree segment(array);

  cin >> M;
  int command, from, to, index, value;
  for (int i = 0; i < M; i++) {
    cin >> command;
    if (command == 2) {
      cin >> from >> to;

      cout << segment.query(from - 1, to - 1) + 1 << "\n";
    } else {
      cin >> index >> value;

      segment.update(index - 1, value);
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