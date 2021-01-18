# 2357. 최솟값과 최댓값

[링크](https://www.acmicpc.net/problem/2357)

| 난이도 | 정답률(\_%) | 제한 시간 |
| :----: | :---------: | :-------: |
| Gold I |   49.799    |    2초    |

## 설계

### 시간 복잡도

정수의 개수 N은 최대 100,000개 까지이다. 질의이 개수 M또한 최대 100,000개 까지이다.

만약 모든 경우에 최소, 최대값을 직접 구할 경우 시간 복잡도는 100,000^2가 되어 제한시간 내에 불가능하다.

따라서 세그먼트 트리를 이용한다.

### 공간 복잡도

입력되는 수의 범위는 1 ~ 1,000,000,000 까지이다.

또한 세그먼트 트리의 비교 과정에서 범위가 int형을 초과하지 않는다.

따라서 int형으로 충분하다.

### 세그먼트 트리

구간의 값들을 미리 계한새놓고, 이분탐색으로 구간의 연산 결과를 빨리 찾아내는 방법이다.

트리를 만들 때 트리의 크기는 원본 배열의 크기에 4를 곱한다.

이 문제에서 트리의 갱신(update)는 일어나지 않으므로 단순 query만 하는 트리를 이용한다.

```cpp
struct SegmentTree {
  int size;
  vector<long long> arr;
  vector<long long> tree;

  SegmentTree(vector<long long> array) {
    size = array.size();

    arr = array;
    tree.resize(size * 4); // min 트리를 원하는 경우 최대값으로 초기화

    init(1, 0, size - 1);
  }

  long long operation(long long x, long long y) {
    return max(x, y); // min 트리를 원하는 경우 min으로 변경
  }

  long long init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;

    return tree[node] = operation(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
  }

  long long query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return operation(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
  }

  long long query(int left, int right) {
    return query(1, 0, size - 1, left, right);
  }
};
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     128      |       20       |

## 고생한 점
