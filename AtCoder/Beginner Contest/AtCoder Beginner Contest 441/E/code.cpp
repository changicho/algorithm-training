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

const int DIFF = 5 * 1e5;

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
  int query(int left, int right) { return _query(1, 0, size - 1, left, right); }

  int _query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
      return NULL_VALUE;
    }
    if (ql <= l && r <= qr) {
      return tree[node];
    }

    int mid = (l + r) / 2;
    int leftPart = _query(node * 2, l, mid, ql, qr);
    int rightPart = _query(node * 2 + 1, mid + 1, r, ql, qr);
    return leftPart + rightPart;
  }

  // update part
  void update(int i, int diff) { _update(1, 0, size - 1, i, i, diff); }

  void _update(int node, int l, int r, int ql, int qr, int diff) {
    if (l > r || qr < l || r < ql) {
      return;
    }
    if (l == r) {
      tree[node] += diff;
      return;
    }

    int mid = (l + r) / 2;
    _update(node * 2, l, mid, ql, qr, diff);
    _update(node * 2 + 1, mid + 1, r, ql, qr, diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
};

long long solution(int size, string& s) {
  long long answer = 0;

  vector<int> arr(1e6 + 1, 0);
  arr[DIFF] = 1;

  SegTree segTree(arr);

  int countA = 0;
  int countB = 0;

  // count case countA > countB
  for (int left = 0, right = 0; right < size; right++) {
    char c = s[right];

    if (c == 'A') {
      countA++;
    } else if (c == 'B') {
      countB++;
    }

    int diff = countA - countB;
    long long cur = segTree.query(0, DIFF + diff - 1);
    answer += cur;

    segTree.update(DIFF + diff, 1);
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
  string S;
  cin >> S;

  auto answer = solution(N, S);

  cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  // for (auto &line : answer) {
  //   cout << line << "\n";
  // }
  // cout << endl;

  return 0;
}