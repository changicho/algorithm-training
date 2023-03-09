# 1539. Kth Missing Positive Number

[링크](https://leetcode.com/problems/kth-missing-positive-number/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 arr의 크기를 N, 찾고자 하는 번째 수를 K라 하자.

1부터 최대 N + K까지 순회하며 없는 K번째 자연수를 찾을 수 있다. 이 경우 O(N + K)의 시간 복잡도를 사용한다.

배열 arr의 원소를 순회하며 K번째 수를 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

입력받은 배열이 정렬되어 있으므로 이분 탐색을 이용할 수 있다.

이 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

순회, 이분탐색에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(N + K)   |    O(1)     |

자연수를 1부터 증가시키며 없는 K번째 자연수를 찾는다.

```cpp
int findKthPositive(vector<int>& arr, int k) {
  int num = 1;

  int index = 0;
  while (k > 0) {
    if (index < arr.size() && arr[index] == num) {
      num++;
      index++;

      continue;
    }
    num++;
    k--;
  }
  return num - 1;
}
```

### 순회 (배열)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |    O(N)     |    O(1)     |

arr의 원소를 순회하며 각 차이를 구할 수 있다.

해당 차이에 존재하는 수에 K번째 수가 존재하는지 판단한다.

```cpp
int findKthPositive(vector<int>& arr, int k) {
  int size = arr.size();
  if (k < arr[0]) {
    return k;
  }

  k -= arr[0] - 1;
  for (int i = 0; i < size - 1; ++i) {
    int diff = arr[i + 1] - arr[i] - 1;

    if (k <= diff) {
      return arr[i] + k;
    }
    k -= diff;
  }

  return arr[size - 1] + k;
}
```

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(log_2(N))   |    O(1)     |

배열 arr의 원소는 정렬되어 있다.

따라서 이분 탐색을 이용해 K번째 수를 찾을 수 있다.

index에 대해 이분 탐색을 수행하며, 현재 index까지의 빠진 자연수의 갯수를 구할 수 있다.

이 때, 현재 index까지의 빠진 자연수의 갯수가 K보다 작은 경우, K번째 수는 현재 index보다 커야 한다.

반대의 경우는 K번째 수가 포함된다는 의미이므로 현재 index보다 작거나 같아야 한다.

이 과정을 통해 이분 탐색을 수행한다.

```cpp
int findKthPositive(vector<int>& arr, int k) {
  int size = arr.size();
  int left = 0, right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] - mid - 1 < k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return left + k;
}
```

## 고생한 점
