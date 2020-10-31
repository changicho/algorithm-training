# 1780. 종이의 개수

[링크](https://www.acmicpc.net/problem/1780)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   58.782    |

## 설계

### 시간 복잡도

지도의 크기는 최대 2,187^2 이다.

log_3(2,187) = 7이다.

각 경우별로 모두 같은 종이인지 세는데 N^2번의 시간이 소요되고, 최악의 경우 모든 종이가 연속해서 다른 경우이다.

이 때 각 경우별로 호출의 깊이는 7번 까지 가능하다.

따라서 최악의 경우 시간 복잡도는

```cpp
7 * 2,187^2 = 33,480,783
```

이고 제한시간 2초 내에 충분하다.

### 공간 복잡도

종이는 3가지를 나타내야한다. 따라서 행렬은 int형으로 선언한다.

최악의 경우 정답의 크기는 4,782,969 이내이다. 따라서 정답은 int로 선언한다.

### 9분할 재귀

각 경우별로 시작점과 끝점을 입력받아 특정 경우에 재귀호출을 돌린다.

이 때 재귀호출을 수행하는 경우 규칙에 따라 반복문을 적용한다.

```cpp
void recursive(Axis from, Axis to) {
  if (from.y + 1 == to.y && from.x + 1 == to.x) {
    answers[board[from.y][from.x] + 1] += 1;
    return;
  }

  int target = board[from.y][from.x];
  bool isSame = true;
  for (int y = from.y; y < to.y; y++) {
    for (int x = from.x; x < to.x; x++) {
      if (target == board[y][x]) continue;
      isSame = false;
      break;
    }
    if (!isSame) break;
  }

  if (isSame) {
    answers[target + 1] += 1;
    return;
  }

  int size = (to.y - from.y) / 3;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      recursive({from.y + size * i, from.x + size * j}, {from.y + size * (i + 1), from.x + size * (j + 1)});
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      44      |      380       |

## 고생한 점
