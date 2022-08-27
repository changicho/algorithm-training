# 495. Teemo Attacking

[링크](https://leetcode.com/problems/teemo-attacking/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

timeSeries의 크기를 N이라 하자.

각 time들을 순회하며 이전 interval과 겹치는지 판단해 정답을 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회 후 중독된 시간을 구하는 데 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      76      |    O(N)     |    O(1)     |

현재 시간을 t, 다음 시간을 t`라고 했을 때 다음 2가지 경우가 존재한다.

- t에서 시작하는 interval에 t`가 속하지 않음.
- t에서 시작하는 interval에 t`가 속함.

첫번째 경우 t에서 정답은 duration만큼 증가한다.

두번째 경우 t에서 정답은 t`와 현재 t에서 interval이 끝나는 시간만큼의 차이만큼 증가한다.

이를 구현하면 다음과 같다.

```cpp
int findPoisonedDuration(vector<int>& timeSeries, int duration) {
  int answer = 0;
  int endTime = -1;
  for (int& time : timeSeries) {
    if (time <= endTime) {
      answer -= abs(endTime + 1 - time);
    }

    answer += duration;
    endTime = time + duration - 1;
  }

  return answer;
}
```

## 고생한 점
