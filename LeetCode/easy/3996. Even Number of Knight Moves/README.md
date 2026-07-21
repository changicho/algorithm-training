# 3996. Even Number of Knight Moves

[링크](https://leetcode.com/problems/even-number-of-knight-moves/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 시작 좌표를 토대로 이동할 수 있는 좌표를 구분할 수 있다.

이후 도달 좌표를 계산하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표 계산에 O(1)의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

나이트의 이동을 시뮬레이션했을 때 현재 위치 y,x의 합이 짝수, 홀수인지에 따라 이동횟수가 짝수, 홀수번째인지가 다르다.

이는 나이트의 이동이 각각의 좌표의 변하는값이 한쪽은 짝수 (-+2), 한쪽은 홀수 (-+1)이기 때문이다 (총 홀수만큼 크기가 변함)

이를 이용해 정답을 구한다.

```cpp
bool canReach(vector<int>& start, vector<int>& target) {
  return ((start[0] + start[1]) % 2) == ((target[0] + target[1]) % 2);
}
```

## 고생한 점
