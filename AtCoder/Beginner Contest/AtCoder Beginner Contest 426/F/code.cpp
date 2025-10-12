#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

const ll INF = 4e18;

struct SegTree {
  const int NULL_VALUE = 0;
  int size;
  vector<int> tree;

  SegTree(vector<int> arr) {
    size = arr.size();
    tree.resize(size * 4);
    build(1, 0, size - 1, arr);
  }

  // initialize part
  void build(int node, int start, int end, vector<int>& arr) {
    if (start == end) {
      tree[node] = arr[start];
      return;
    }

    int mid = (start + end) / 2;
    build(node * 2, start, mid, arr);
    build(node * 2 + 1, mid + 1, end, arr);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

  // query part
  int query(int left, int right) { return query(1, 0, size - 1, left, right); }

  int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
      return NULL_VALUE;
    }
    if (ql <= l && r <= qr) {
      return tree[node];
    }

    int mid = (l + r) / 2;
    ll leftPart = query(node * 2, l, mid, ql, qr);
    ll rightPart = query(node * 2 + 1, mid + 1, r, ql, qr);
    return leftPart + rightPart;
  }

  // update part
  void update(int i, ll diff) { update(1, 0, size - 1, i, i, diff); }

  void update(int node, int l, int r, int ql, int qr, ll diff) {
    if (l > r || qr < l || r < ql) {
      return;
    }
    if (l == r) {
      tree[node] += diff;
      return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, ql, qr, diff);
    update(node * 2 + 1, mid + 1, r, ql, qr, diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
};

struct LazySegTree {
  const ll NULL_VALUE = LLONG_MAX / 2;
  int size;
  vector<pair<ll, int>> tree;
  vector<ll> lazy;

  LazySegTree(vector<ll> arr) {
    size = arr.size();
    tree.resize(4 * size);
    lazy.resize(4 * size);

    build(arr, 1, 0, size - 1);
  }

  void build(vector<ll>& arr, int node, int l, int r) {
    if (l == r) {
      tree[node] = {arr[l], l};
      return;
    }

    int mid = (l + r) / 2;
    build(arr, node * 2, l, mid);
    build(arr, node * 2 + 1, mid + 1, r);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }

  void propagate(int node, int l, int r) {
    if (lazy[node] == 0) return;

    tree[node].first += lazy[node];
    if (l != r) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  void update(int left, int right, ll val) {
    update(1, 0, size - 1, left, right, val);
  }

  void update(int node, int l, int r, int ql, int qr, ll val) {
    propagate(node, l, r);

    if (l > r || l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
      lazy[node] += val;
      propagate(node, l, r);
      return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, r, ql, qr, val);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }

  pair<ll, int> query(int left, int right) {
    return query(1, 0, size - 1, left, right);
  }

  pair<ll, int> query(int node, int l, int r, int ql, int qr) {
    propagate(node, l, r);
    if (l > r || qr < l || ql > r) return {NULL_VALUE, -1};
    if (ql <= l && r <= qr) return tree[node];

    int mid = (l + r) / 2;
    return min(query(node * 2, l, mid, ql, qr),
               query(node * 2 + 1, mid + 1, r, ql, qr));
  }
};

auto solution(int size, vector<ll>& nums, int qSize,
              vector<vector<ll>>& queries) {
  SegTree countSegTree(vector<int>(size, 1));
  LazySegTree minSegTree(nums);

  vector<ll> answer;
  for (vector<ll>& q : queries) {
    int left = q[0] - 1, right = q[1] - 1;
    ll diff = q[2];

    ll count = countSegTree.query(left, right) * diff;
    minSegTree.update(left, right, -diff);

    pair<ll, int> minimum = minSegTree.query(left, right);
    while (minimum.first < 0 && minimum.second != -1) {
      ll val = minimum.first;
      int index = minimum.second;

      count -= abs(val);

      minSegTree.update(index, index, INF - val);
      countSegTree.update(index, -1LL);

      minimum = minSegTree.query(left, right);
    }

    answer.push_back(count);
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  vector<ll> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int Q;
  cin >> Q;

  vector<vector<ll>> queries(Q, vector<ll>(3));
  for (int i = 0; i < Q; i++) {
    cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
  }

  auto answer = solution(N, A, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}
