# 2064. Minimized Maximum of Products Distributed to Any Store

[링크](https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 quantities의 크기를 N, quantities의 최대값을 M이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* M)이므로 제한시간 내에 불가능하다.

배치된 물건의 갯수를 이분 탐색으로 찾을 수 있다. 이 경우 O(N \* log_2(M))의 시간 복잡도가 소요된다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도가 필요하다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      16      | O(N \* log_2(M)) |    O(1)     |

각 물건마다 상점에 배치하는 최대 갯수를 M이라 하자.

M에 대해서 각 물건마다 상점에 배치했을 때 필요한 상점의 수를 구할 수 있다.

해당 상점의 수가 입력받은 n을 넘어서는지 판단한다.

M이 클 수록 필요한 상점의 수는 작아지며 M이 작을 수록 필요한 상점의 수는 커진다.

따라서 이분 탐색을 이용해 최적의 M을 찾을 수 있다.

```cpp
bool calc(int n, vector<int> &quantities, int limit) {
  int count = 0;
  for (int &q : quantities) {
    count += q / limit;
    if (q % limit > 0) count++;
  }
  return count <= n;
}

int minimizedMaximum(int n, vector<int> &quantities) {
  int left = 1,
      right = *max_element(quantities.begin(), quantities.end()) + 1;

  int answer = -1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (calc(n, quantities, mid)) {
      // pick left
      right = mid;
      answer = mid;
    } else {
      // pick right
      left = mid + 1;
    }
  }
  return answer;
}
```

## 고생한 점
