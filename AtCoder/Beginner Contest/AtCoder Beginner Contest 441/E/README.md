# E - A > B substring

[링크](https://atcoder.jp/contests/abc441/tasks/abc441_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자.

prefix sum을 이용해 왼쪽부터 탐색하며 이전에 방문한 가능한 상태를 합에 저장한다.

이를 위해 세그먼트 트리를 사용할 수 있다.

세그먼트 트리의 크기는 값의 범위에 비례하며 N이 된다.

각 쿼리에 O(log_2(N))의 시간 복잡도를 사용하며 이를 순회 내부에서 진행하므로

총 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

세그먼트 트리에 O(N)의 공간이 필요하다.

### 세그먼트 트리 & prefix

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      99      | O(N \* log_2(N)) |    O(N)     |

왼쪽부터 순회하며 A의 갯수와 B의 갯수를 센다. 이를 각각 a, b라 하자.

a - b 를 diff라 할 수 있다.

만약 이전에 존재하던 a, b의 차이들을 diff'들이라 할때 diff' < diff 인 경우 해당 경우의 수들을 현재 정답에 더할 수 있다.

이는 현재 부분(prefix)에 존재하는 a, b에서 이전에 존재하는 부분(prefix')을 제거했을 때 가능한 a > b의 경우가 되기 때문이다.

```javascript
[A, B, C, D, E] // prefix
[A, B] // prefix'
```

여기서 diff' < diff인 모든 diff'의 경우의 수의 합을 저장해야 한다.

이를 위해 세그먼트 트리를 사용해 diff에 대한 구간합을 갱신한다.

이후 현재 diff를 세그먼트 트리에 갱신한다. (갯수 추가)

```cpp
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
```

## 고생한 점
