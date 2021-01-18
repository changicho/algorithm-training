#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define LIMIT 1000000001

using namespace std;

struct MaxSegmentTree {
  int size;
  vector<int> arr;
  vector<int> tree;

  MaxSegmentTree(vector<int> array) {
    size = array.size();

    arr = array;
    tree.resize(size * 4);

    init(1, 0, size - 1);
  }

  int operation(int x, int y) {
    return max(x, y);
  }

  int init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;

    return tree[node] = operation(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
  }

  int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return operation(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
  }

  int query(int left, int right) {
    return query(1, 0, size - 1, left, right);
  }
};

struct MinSegmentTree {
  int size;
  vector<int> arr;
  vector<int> tree;

  MinSegmentTree(vector<int> array) {
    size = array.size();

    arr = array;
    tree.resize(size * 4, LIMIT);

    init(1, 0, size - 1);
  }

  int operation(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return x;

    return min(x, y);
  }

  int init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;

    return tree[node] = operation(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
  }

  int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
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
  cin >> N >> M;

  vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  MaxSegmentTree maxSegmentTree(arr);
  MinSegmentTree minSegmentTree(arr);

  int from, to;
  for (int i = 0; i < M; i++) {
    cin >> from >> to;

    cout << minSegmentTree.query(from - 1, to - 1) << " " << maxSegmentTree.query(from - 1, to - 1) << "\n";
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