# 14499. 주사위 굴리기

[링크](https://www.acmicpc.net/problem/14499)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold V |   40.874    |

## 설계

### 시간 복잡도

명령의 갯수 만큼 연산을 수행하면 된다. K는 1,000 까지 이므로 최악의 경우 O(1,000) 이므로 제한 시간 내에 충분하다.

### 공간 복잡도

지도와 주사위의 크기는 10 이하이므로 int 형으로 선언한다.

지도의 크기는 최대 20^2 이므로 [20][20] 크기의 배열을 선언한다.

주사위의 움직임을 구현하기 위해 6면체를 가지는 구조체를 선언한다.

### 주사위의 움직임 구현

주사위를 전역변수로 선언하고 각 이동마다 면이 뒤바뀌는것을 함수로 구현해 사용한다.

```cpp
void move_right() {
  // FRONT, BACK 은 움직이지 않음
  // top > right > bottom > left > top
}

void move_left() {
  // FRONT, BACK 은 움직이지 않음
  // top > left > bottom > right > top
}

void move_up() {
  // LEFT, RIGHT 는 움직이지 않음
  // top > back > bottom > front > top
}

void move_down() {
  // LEFT, RIGHT 는 움직이지 않음
  // top > front > bottom > back > top
}
```

이동할 좌표가 올바르지 않은 경우를 판단하기 위해 check 함수를 이용한다.

```cpp
bool limitCheck(axis cur, axis limit) {
  if (cur.x < 0 || cur.x >= limit.x) return false;
  if (cur.y < 0 || cur.y >= limit.y) return false;

  return true;
}
```

또한 각 방향으로 이동 마다 유효하지 않은 이동의 경우는 무시한다.

```cpp
for (int i = 0; i < K; i++) {
  cin >> dir;
  axis cur = dice_axis;
  cur.x += dirs[dir].x;
  cur.y += dirs[dir].y;

  if (!limitCheck(cur, limit)) {
    continue;
  }
  dice_axis = cur;

  // 주사위 이동 구현
}
```

이동 후 주사위의 BOTTOM이 0인 경우에 바닥의 숫자가 면으로 옮겨가고, 반대의 경우는 면의 숫자가 바닥으로 옮겨감에 유의한다.

```cpp
if (map[cur.y][cur.x] == 0) {
  map[cur.y][cur.x] = dice.BOTTOM;
} else {
  dice.BOTTOM = map[cur.y][cur.x];
  map[cur.y][cur.x] = 0;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

문제에서 x, y가 반대로 설명되어 있었다.

x는 N의 영향을 받는, 즉 세로 축의 위치이고 y는 M의 영향을 받는 가로축의 위치이다.

숫자가 각각 면과 바닥으로 옮겨감에 주의한다.
