# 1176. Diet Plan Performance

[링크](https://leetcode.com/problems/diet-plan-performance/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 길이를 N, 윈도우의 크기를 K라 하자.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

슬라이딩 윈도우를 사용할 경우 O(1)의 공간 복잡도를 가진다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

슬라이딩 윈도우를 사용해 윈도우의 크기가 K인 구간의 합을 계산한다.

각 구간의 합이 lower 미만일 경우 -1, upper 초과일 경우 +1을 더해준다.

```cpp
int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
  int size = calories.size();
  int sum = 0;

  for (int i = 0; i < k - 1; i++) {
    sum += calories[i];
  }

  int answer = 0;
  for (int i = k - 1; i < size; i++) {
    sum += calories[i];

    if (i - k >= 0) {
      sum -= calories[i - k];
    }

    if (sum < lower) {
      answer--;
    } else if (sum > upper) {
      answer++;
    }
  }
  return answer;
}
```

## 고생한 점
