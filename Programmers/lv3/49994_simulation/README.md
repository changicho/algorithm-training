# 49994. 방문 길이

[링크](https://programmers.co.kr/learn/courses/30/lessons/49994)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv3   |   1511    |

## 설계

### 시간 복잡도

이동의 총 크기는 500 이다.

각 이동별로 시뮬레이션을 돌린다고 했을 때 시간 복잡도는 최대 O(500) 이다.

### 공간 복잡도

경로를 체크해야 하므로, 좌표 a 에서 좌표 b 까지 이동했음을 나타내는 boolean 4차원 배열을 선언한다.

```cpp
bool visitied[from.x][from.y][to.x][to.y];
```

이 때 지도의 총 크기는 -5 ~ 5 까지의 정수이므로 총 11개 이다.

따라서 4차원 배열의 크기는 11^4 이다.

### 방문 경로

이동이 일어날 때마다 4차원 배열에 체크한다.

이 때 체크되지 않은 이동의 경우 정답을 증가시킨다.

(from.x, from.y) > (to.x, to.y)

이 때 반대의 경우도 체크해야 함에 유의한다.

(to.x, to.y) > (from.x, from.y)

```cpp
for (char dir : dirs) {
  Axis next = cur;
  // next 좌표 이동시킴

  if (isSafe(next)) {
    if (!map[cur.y][cur.x][next.y][next.x]) answer += 1;

    map[cur.y][cur.x][next.y][next.x] = true;
    map[next.y][next.x][cur.y][cur.x] = true;
    cur = next;
  }
}
```

## 고생한 점

이동한 경로의 반대의 경우도 체크해줘야함

이는 방문 경로를 체크할 때 방향을 체크하지 않기 때문
