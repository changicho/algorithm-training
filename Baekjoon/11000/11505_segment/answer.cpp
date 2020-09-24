#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define DIV 1000000007

using namespace std;

struct SegmentTree {
  int size;
  vector<long long> arr;
  vector<long long> segmentTree;

  long long compute(long long a, long long b) {
    return (a * b) % DIV;
  }

  SegmentTree(vector<long long> array) {
    size = array.size();
    arr = array;
    segmentTree.resize(size * 4);

    init(0, size - 1, 1);
  }

  long long init(int start, int end, int node) {
    if (start == end) return segmentTree[node] = arr[start];

    int mid = (start + end) / 2;
    return segmentTree[node] = compute(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
  }

  long long update(int start, int end, int node, int index) {
    if (index < start || index > end) return segmentTree[node];
    if (start == end) return segmentTree[node] = arr[index];

    int mid = (start + end) / 2;
    return segmentTree[node] = compute(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
  }

  void update(int index, int value) {
    arr[index] = value;
    update(0, size - 1, 1, index);
  }

  long long query(int left, int right, int node, int start, int end) {
    if (right < start || end < left) return 1;
    if (left <= start && end <= right) return segmentTree[node];

    int mid = (start + end) / 2;
    return compute(query(left, right, node * 2, start, mid), query(left, right, node * 2 + 1, mid + 1, end));
  }

  long long query(int left, int right) {
    return query(left, right, 1, 0, size - 1);
  }
};

void solution() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<long long> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  SegmentTree segmentTree(arr);

  for (int i = 0; i < M + K; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == 1) {
      segmentTree.update(b - 1, c);
    } else {
      cout << segmentTree.query(b - 1, c - 1) << "\n";
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