# 11505. 구간 곱 구하기

[링크](https://www.acmicpc.net/problem/11505)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   34.639    |

## 설계

### 시간 복잡도

N은 최대 1,000,000 까지이며, 구간의 값이 변하는 경우는 10,000번 까지이다.

구간 곱을 구하는 경우 또한 최대 10,000번 가지이다.

세그먼트 트리를 이용해 구간의 값을 가져오는 경우를 logN으로 줄일 수 있으므로

시간 복잡도는 최악의 경우 10,000log(1,000,000) 이므로 제한시간 내에 충분하다.

### 공간 복잡도

원소의 값은 1,000,000 까지이다. 나눠야 하는 수는 1,000,000,007 이다.

최악의 경우 연산 중 곱이 int형을 벗어날 수 있으므로 (1,000,000,006^2) 모든 수는 long long형으로 선언한다.

### 세그먼트 트리

update 부분에서 분기 처리가 필요하다

```cpp
long long update(int start, int end, int node, int index) {
  if (index < start || index > end) return segmentTree[node];
  if (start == end) return segmentTree[node] = arr[index];

  int mid = (start + end) / 2;
  return segmentTree[node] = compute(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
}
```

start == end 인 경우 끝에 도달했다는 의미 이므로 (arr[index]를 나타내는 노드) 해당 노드를 업데이트한다.

그 외의 경우는 세그먼트 트리의 기존 값을 반환한다.

```cpp
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
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     164      |       20       |

## 고생한 점
