# 1087. 쥐 잡기

[링크](https://www.acmicpc.net/problem/1087)

|   난이도    | 정답률(\_%) |
| :---------: | :---------: |
| Platinum IV |   20.632    |

## 설계

### 시간 복잡도

정사각형의 크기로 탐색을 진행할 경우, 소숫점까지 고려해야 하므로 제한시간 내에 불가능하다.

쥐들의 위치는 시간에 대한 그래프로 표현할 수 있다. 이를 시간에 대한 함수로 표현하고 이를 이용한다.

각 시간의 쥐들 좌표에서, 쥐들을 포함하는 가장 작은 정사각형의 크기에 대한 그래프는 최솟값이 일정한 그래프 형태로 나타난다.

따라서 삼분 탐색을 수행할 수 있다.

삼분 탐색을 수행할 경우 시간은 0초부터 충분히 큰 값 (100,000)까지를 초기 범위로 설정한다.

이 경우 시간 복잡도는 O(log_2(100,000)) 이다.

쥐의 수는 최대 50마리 까지이므로, 각 탐색마다 정사각형의 크기를 구하는 데 걸리는 최악의 시간은 다음과 같다.

```cpp
O(N * log_2(100,000)) = O(50 * 17)
```

이는 제한시간 2초 내에 충분하다.

### 공간 복잡도

좌표, 가속도 모두 실수형으로 표현해야 하므로 double을 이용한다.

### 사각형의 크기를 구하는 함수

시간을 인자로 받아 쥐들의 위치를 계산 후에, 이 좌표들을 이용해 계산한다.

정사각형의 시작점과 끝점의 위치를 계산하고, 이 경우 모든 쥐들을 포함할 수 없는 최대 정사각형의 위치를 계산한다.

```cpp
double calculateCost(double time) {
  double start_x = 1e9, start_y = 1e9, end_x = -1e9, end_y = -1e9;

  for (Mouse mouse : mice) {
    start_x = min(start_x, mouse.axis.x + mouse.move.x * time);
    start_y = min(start_y, mouse.axis.y + mouse.move.y * time);
    end_x = max(end_x, mouse.axis.x + mouse.move.x * time);
    end_y = max(end_y, mouse.axis.y + mouse.move.y * time);
  }

  return max(end_x - start_x, end_y - start_y);
}
```

### 삼분 탐색

시간에 대해 삼분 탐색을 할 때, 시간은 실수형 이므로 다음 방법을 사용한다.

- 탐색 횟수를 고정하고, 이 횟수는 오차범위 이내가 되도록 고려한다.

```cpp
double low = 0, high = 1e5;

for (int i = 0; i < 200 && low < high; i++) {
  double left = (2 * low + high) / 3;
  double right = (low + 2 * high) / 3;

  double costL = calculateCost(left);
  double costR = calculateCost(right);

  if (costL < costR) {
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
