# 10868. 최솟값

[링크](https://www.acmicpc.net/problem/10868)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   46.374    |

## 설계

### 시간 복잡도

세그먼트 트리를 이용해 풀어야 하는 문제

수의 개수 N은 최대 100,000, 쿼리의 개수 M은 최대 100,000 까지이다.

시간 복잡도는 NlogM 이다.

### 공간 복잡도

수의 최대 값은 10^9이다.

### Range minimum query

최소 구간 비교 쿼리

```cpp
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
    return a > b ? b : a; // 이부분 직접 구현
  }

  int init(int start, int end, int node) {
    if (start == end) return segmentTree[node] = arr[start];  // 이부분 기존 코드에서 수정

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
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      80      |       12       |

## 고생한 점
