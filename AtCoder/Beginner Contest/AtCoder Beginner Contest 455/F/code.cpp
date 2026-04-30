#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

ll MOD = 998244353;

struct Node {
  ll sum = 0;
  ll sq = 0;
};

struct LazySegTree {
  int size;
  vector<Node> tree;
  vector<ll> lazy;

  LazySegTree(vector<ll>& arr) {
    size = arr.size();
    tree.resize(4 * size);
    lazy.resize(4 * size);
    build(arr, 1, 0, size - 1);
  }

  Node merge(const Node& a, const Node& b) {
    return {(a.sum + b.sum) % MOD, (a.sq + b.sq) % MOD};
  }

  void build(vector<ll>& arr, int node, int l, int r) {
    if (l == r) {
      tree[node].sum = arr[l] % MOD;
      tree[node].sq = (arr[l] * arr[l]) % MOD;
      return;
    }
    int mid = (l + r) / 2;
    build(arr, node * 2, l, mid);
    build(arr, node * 2 + 1, mid + 1, r);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  void propagate(int node, int l, int r) {
    if (lazy[node] == 0) return;

    ll x = lazy[node];
    ll len = (r - l + 1);

    tree[node].sq = (tree[node].sq + (2 * x % MOD) * tree[node].sum % MOD +
                     len % MOD * x % MOD * x % MOD) %
                    MOD;

    tree[node].sum = (tree[node].sum + len % MOD * x % MOD) % MOD;

    if (l != r) {
      lazy[node * 2] = (lazy[node * 2] + x) % MOD;
      lazy[node * 2 + 1] = (lazy[node * 2 + 1] + x) % MOD;
    }

    lazy[node] = 0;
  }

  void update(int l, int r, ll val) { _update(1, 0, size - 1, l, r, val); }

  void _update(int node, int l, int r, int ql, int qr, ll val) {
    propagate(node, l, r);

    if (r < ql || l > qr) return;

    if (ql <= l && r <= qr) {
      lazy[node] = (lazy[node] + val) % MOD;
      propagate(node, l, r);
      return;
    }

    int mid = (l + r) / 2;
    _update(node * 2, l, mid, ql, qr, val);
    _update(node * 2 + 1, mid + 1, r, ql, qr, val);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  Node query(int l, int r) { return _query(1, 0, size - 1, l, r); }

  Node _query(int node, int l, int r, int ql, int qr) {
    propagate(node, l, r);

    if (r < ql || l > qr) return Node();

    if (ql <= l && r <= qr) return tree[node];

    int mid = (l + r) / 2;
    return merge(_query(node * 2, l, mid, ql, qr),
                 _query(node * 2 + 1, mid + 1, r, ql, qr));
  }
};

ll getAnswer(ll sum, ll sq) {
  ll inv2 = (MOD + 1) / 2;

  ll res = (sum * sum) % MOD;
  res = (res - sq + MOD) % MOD;
  res = (res * inv2) % MOD;

  return res;
}

vector<ll> solution(int n, int qSize, vector<vector<int>>& queries) {
  vector<ll> nums(n + 1);

  LazySegTree seg(nums);

  vector<ll> answer;

  for (vector<int>& q : queries) {
    int l = q[0], r = q[1];
    long long num = q[2];

    seg.update(l, r, num);

    Node ret = seg.query(l, r);

    ll sum = ret.sum;
    ll sq = ret.sq;

    // sum^2 - sqSum / 2
    answer.push_back(getAnswer(sum, sq));
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> queries(Q, vector<int>(3));
  for (int i = 0; i < Q; i++) {
    cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
  }

  auto answer = solution(N, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}