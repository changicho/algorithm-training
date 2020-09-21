#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define MAX 1000000001

using namespace std;

struct RangeMinimumQuery {
  int size;
  vector<int> arr;
  vector<int> segmentTree;

  RangeMinimumQuery(vector<int> array) {
    size = array.size();

    arr.resize(size + 1);
    arr = array;
    segmentTree.resize(size * 4 + 1);

    init(0, size - 1, 1);
  }

  int compare(int a, int b) {
    return a > b ? b : a;
  }

  int init(int start, int end, int node) {
    if (start == end) return segmentTree[node] = arr[start];

    int mid = (start + end) / 2;
    return segmentTree[node] = compare(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
  }

  int update(int start, int end, int node, int index) {
    if (index < start || index > end || start == end) return segmentTree[node];
    int mid = (start + end) / 2;

    return segmentTree[node] = compare(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
  }

  void changeValue(int index, int value) {
    arr[index] = value;
    update(0, size - 1, 1, index);
  }

  int query(int left, int right, int index, int start, int end) {
    if (right < start || end < left) return MAX;
    if (left <= start && end <= right) return segmentTree[index];

    int mid = (start + end) / 2;

    return compare(query(left, right, index * 2, start, mid), query(left, right, index * 2 + 1, mid + 1, end));
  }
};

void solution() {
  int N, M;

  cin >> N >> M;
  vector<int> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  RangeMinimumQuery segtree(arr);

  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    cout << segtree.query(from - 1, to - 1, 1, 0, N - 1) << "\n";
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