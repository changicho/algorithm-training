# 3075. Maximize Happiness of Selected Children

[링크](https://leetcode.com/problems/maximize-happiness-of-selected-children/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 happiness의 길이를 N이라 하자.

각 경우마다 가장 높은 값을 선택할 수 있다. 이에 정렬을 사용할 경우 O(N * log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     164      | O(N * log_2(N)) |    O(N)     |

happiness를 정렬 후 가장 큰 순서대로 k개를 선택한다.

이 때 이후에 선택하는 값은 이전에 선택한 갯수만큼 값이 감소한다.

```cpp
long long maximumHappinessSum(vector<int>& happiness, int k) {
  long long answer = 0;

  sort(happiness.begin(), happiness.end(), greater<int>());

  for (int turn = 0; turn < k; turn++) {
    answer += max(0, happiness[turn] - turn);
  }
  return answer;
}
```

## 고생한 점
