# 68645. 삼각 달팽이

[링크](https://programmers.co.kr/learn/courses/30/lessons/68645)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv2   |   1116    |

## 설계

### 시간 복잡도

n은 최대 1000 이다.

각 n에 따라서 마지막에 채워지는 숫자는 합공식에 따라 (n+1)n/2 가 되므로 최악의 경우 500,500이 된다.

수를 순서대로 채워넣는것이므로 시간 복잡도는 마지막에 채워지는 수가 된다.

따라서 시간 복잡도는 O(500,500) 이고 제한시간 내에 충분하다.

### 공간 복잡도

순서대로 채워넣기 위해 1000^2 크기의 2차원 배열이 필요하다.

각 수는 최악의 경우 500,500까지의 양의 정수를 가질 수 있으므로 int형으로 선언한다.

### 채우는 순서

채우는 순서는 아래와 같다.

- 아래 방향
- 오른쪽 방향
- 대각선 방향

하나의 좌표를 선언하고, 그 좌표를 이동시키며 작업을 수행한다.

아래로 이동

```cpp
while (board[axis.y][axis.x] == 0 && axis.y < n) {
  board[axis.y][axis.x] = number;
  number += 1;
  axis.y += 1;
}

axis.y -= 1;
axis.x += 1;
```

오른쪽으로 이동

```cpp
while (board[axis.y][axis.x] == 0 && axis.x < n) {
  board[axis.y][axis.x] = number;
  number += 1;
  axis.x += 1;
}

axis.y -= 1;
axis.x -= 2;
```

대각선으로 이동

```cpp
for (int i = 0; i < n - 1; i++) {
  if (board[axis.y][axis.x] != 0) break;
  board[axis.y][axis.x] = number;
  axis.y -= 1;
  axis.x -= 1;
  number += 1;
}

axis.y += 2;
axis.x += 1;
```

## 고생한 점
