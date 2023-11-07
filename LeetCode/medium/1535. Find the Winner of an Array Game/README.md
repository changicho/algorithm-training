# 1535. Find the Winner of an Array Game

[링크](https://leetcode.com/problems/find-the-winner-of-an-array-game/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 배열의 길이를 N, 수를 K라 하자. (N <= 10^5, K <= 10^9)

시뮬레이션을 직접 수행할 경우 K번 비교해야 하므로 O(N + K)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

따라서 K번 비교가 아닌 현재 순회할 수 있는 범위에서 최대값을 찾아 이를 비교한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

데크를 이용해 현재 최대값을 시뮬레이션 할 경우 O(N)의 공간 복잡도를 사용한다.

현재 순회할 수 있는 범위에서 최대값을 찾아 이를 비교할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      91      |    O(N)     |    O(1)     |

배열의 최대값을 max라 하자.

만약 값을 비교하는 도중에 max를 찾은 경우 배열의 다른 원소들과 비교했을 때 max가 크므로 K번을 모두 비교하지 않아도 된다.

왼쪽부터 순회하며 각 경우마다의 최대값 max'를 갱신한다. 이 때 해당 max'가 K번 이긴 경우는 현재까지의 max'가 정답이 된다.

그 외에 배열안의 max를 찾은 경우는 max가 정답이 된다.

```cpp
int getWinner(vector<int>& arr, int k) {
  int size = arr.size();

  int beforeMax = arr[0];
  int countLeft = k;
  for (int i = 1; i < size; i++) {
    if (arr[i] > beforeMax) {
      beforeMax = arr[i];
      countLeft = k;
    }
    countLeft--;

    if (countLeft == 0) return beforeMax;
  }

  return beforeMax;
}
```

## 고생한 점
