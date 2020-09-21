#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct SegmentTree {
  int size;
  vector<int> arr;
  vector<int> tree;

  SegmentTree(vector<int> array) {
    size = array.size();

    arr.resize(size + 1);
    arr = array;
    tree.resize(size * 4 + 1);

    init(0, size - 1, 1);
  }

  int compare(int x, int y) {
    if (arr[x] == arr[y]) return x < y ? x : y;
    return arr[x] < arr[y] ? x : y;
  }

  int init(int start, int end, int node) {
    if (start == end) return tree[node] = start;
    int mid = (start + end) / 2;

    return tree[node] = compare(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
  }

  int update(int start, int end, int node, int index) {
    if (index < start || index > end || start == end) return tree[node];
    int mid = (start + end) / 2;

    return tree[node] = compare(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
  }

  void changeValue(int index, int value) {
    arr[index] = value;
    update(0, size - 1, 1, index);
  }

  int query(int left, int right, int index, int start, int end) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[index];

    int mid = (start + end) / 2;

    return compare(query(left, right, index * 2, start, mid), query(left, right, index * 2 + 1, mid + 1, end));
  }
};

void solution() {
  int N, M;
  cin >> N;

  vector<int> array(N);
  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }

  SegmentTree segment(array);

  cin >> M;

  for (int i = 0; i < M; i++) {
    int command;
    cin >> command;

    if (command == 2) {
      cout << segment.query(0, N - 1, 1, 0, N - 1) + 1 << "\n";
      // cout << segment.getTop() + 1 << "\n";
    } else {
      int index, value;
      cin >> index >> value;

      segment.changeValue(index - 1, value);
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