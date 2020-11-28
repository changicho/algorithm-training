# 11662. 민호와 강호

[링크](https://www.acmicpc.net/problem/11662)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   42.568    |

## 설계

### 시간 복잡도

민호와 강호의 거리를 시간(퍼센트)에 대한 그래프로 나타낼 경우, 이는 최솟값이 존재하는 그래프가 된다.

이를 삼분탐색 해 문제를 풀이할 수 있다.

입력으로 주어지는 모든 좌표는 10,000 이하의 양의 정수이다.

절대 상대오차는 10^-6 까지 허용하므로, 시간에 대해 log_2(10^6)번 정도 삼분탐색을 수행하면 오차 내에 충분한 값을 얻을 수 있다.

따라서 최악의 경우도 시간 복잡도는 O(21) 정도이다.

### 공간 복잡도

실수 형태로 표현해야 하므로 모든 값은 double로 선언한다.

### 삼분탐색

cost를 구하는 함수 (거리를 계산하는 함수)는 다음과 같이 설정한다.

```cpp
double calculateCost(double percentage) {
  Axis new_minsu, new_gangho;

  new_minsu.y = minsu.start.y + (minsu.end.y - minsu.start.y) * percentage / 100;
  new_minsu.x = minsu.start.x + (minsu.end.x - minsu.start.x) * percentage / 100;

  new_gangho.y = gangho.start.y + (gangho.end.y - gangho.start.y) * percentage / 100;
  new_gangho.x = gangho.start.x + (gangho.end.x - gangho.start.x) * percentage / 100;

  double y = (new_minsu.y - new_gangho.y) * (new_minsu.y - new_gangho.y);
  double x = (new_minsu.x - new_gangho.x) * (new_minsu.x - new_gangho.x);

  return sqrt(y + x);
}
```

여기서 percentage를 인자로 받음에 유의하자.

문제에서는 시작점과 끝점만 주어지고, 민호와 강호는 둘다 동시에 도착점에 도착하므로 얼마만큼 진행되고 있는지만 알면 된다.

따라서 percentage의 범위는 0 ~ 100까지 설정해 탐색을 진행한다.

```cpp
double low = 0;
double high = 100;

while (high - low >= 1e-6) {
  double left = (2 * low + high) / 3;
  double right = (low + 2 * high) / 3;

  double leftCost = calculateCost(left);
  double rightCost = calculateCost(right);

  if (leftCost < rightCost) {
    high = right;
  } else {
    low = left;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
