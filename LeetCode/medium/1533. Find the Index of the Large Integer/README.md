# 1533. Find the Index of the Large Integer

[링크](https://leetcode.com/problems/find-the-index-of-the-large-integer/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 ArrayReader의 array의 크기를 N이라 하자.

모든에 대해 각각 검색할 경우 O(N)의 시간 복잡도를 사용한다.

이분 탐색을 사용할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

탐색에 상수만큼의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     161      | O(log_2(N)) |    O(1)     |

각 범위에 대해서 다음과 같이 비교할 수 있다.

현재 범위에 속한 원소의 수가 다음과 같다고 하자.

- 짝수인 경우
  - 절반을 나누고 탐색한 뒤 큰쪽으로 이동
- 홀수인 경우
  - 중앙값을 제외한 절반을 나누고 탐색한 뒤 큰쪽으로 이동
  - 두 구간의 값이 같은 경우 중앙점이 정답

이를 이용해 각 경우마다 이분탐색을 수행한다.

```cpp
int getIndex(ArrayReader &reader) {
  int left = 0, right = reader.length() - 1;

  int answer = -1;

  while (left <= right) {
    int size = right - left + 1;

    if (size == 1) {
      answer = left;
      break;
    }
    int mid = left + (right - left) / 2;

    if (size % 2 == 0) {
      int ret = reader.compareSub(left, mid, mid + 1, right);
      if (ret == 1) {
        // pick left
        right = mid;
      } else if (ret == -1) {
        // pick right
        left = mid + 1;
      }
    } else {
      int ret = reader.compareSub(left, mid - 1, mid + 1, right);
      if (ret == 1) {
        // pick left;
        right = mid - 1;
      } else if (ret == -1) {
        // pick right
        left = mid + 1;
      } else if (ret == 0) {
        answer = mid;
        break;
      }
    }
  }
  return answer;
}
```

## 고생한 점
