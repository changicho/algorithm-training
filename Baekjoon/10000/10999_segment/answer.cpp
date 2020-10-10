#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl '\n';

struct SegmentTree {
  int size;
  vector<long long> arr;
  vector<long long> tree;
  vector<long long> lazy;

  SegmentTree(vector<long long> array) {
    size = array.size();

    arr = array;
    tree.resize(size * 4);
    lazy.resize(size * 4);

    init(1, 0, size - 1);
  }

  long long compare(long long x, long long y) {
    return x + y;
  }

  long long init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;

    return tree[node] = compare(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
  }

  void update_lazy(int node, int start, int end) {
    if (lazy[node] == 0) return;

    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) {
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  void update(int node, int left, int right, int start, int end, long long diff) {
    update_lazy(node, start, end);

    if (left > end || right < start) return;
    if (left <= start && end <= right) {
      tree[node] += (end - start + 1) * diff;

      if (start != end) {
        lazy[node * 2] += diff;
        lazy[node * 2 + 1] += diff;
      }
      return;
    }

    int mid = (start + end) / 2;
    update(node * 2, left, right, start, mid, diff);
    update(node * 2 + 1, left, right, mid + 1, end, diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

  void update(int left, int right, long long diff) {
    update(1, left, right, 0, size - 1, diff);
  }

  long long query(int node, int left, int right, int start, int end) {
    update_lazy(node, start, end);

    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return compare(query(node * 2, left, right, start, mid), query(node * 2 + 1, left, right, mid + 1, end));
  }

  long long query(int left, int right) {
    return query(1, left, right, 0, size - 1);
  }
};

void solution() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<long long> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  SegmentTree segment(arr);

  for (int i = 0; i < M + K; i++) {
    long long a, b, c, d;
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;

      segment.update(b - 1, c - 1, d);
    } else {
      cin >> b >> c;

      cout << segment.query(b - 1, c - 1) << endl;
    }
  }
  cout << endl;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}