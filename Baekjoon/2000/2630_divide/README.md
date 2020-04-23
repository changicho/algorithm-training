# 2630. 색종이 만들기

[링크](https://www.acmicpc.net/problem/2630)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |   72.173    |

## 설계

### 시간복잡도

N은 최대 128이고, 1과 0이 번갈아 나오는 체스판 같은 경우 함수의 호출 횟수는 다음과 같다.

```cpp
1 + 4 + 16 + 64 + 256 ...

1^1 + 2^2 + 4^2 + 8^2 + 16^2 + 32^2 + 64^2 + 128^2

이는 128^2 * 8 보다 작고 이는 2048보다 작다
```

따라서 분할정복으로 brute force 하더라도 제한시간 1초 내에 해결할 수 있다.

### 분할정복

좌표를 나타내는 구조체를 생성한다.

```cpp
struct axis {
  int y, x;
};
```

현재 면에서 분할할 부분이 있는지를 판단하는 함수를 선언한다.

```cpp
bool check(axis from, axis to){
  // 범위의 모든 색이 같은경우 true를 return, 아닌 경우 false return.

  // true를 return 하는 경우, 청색 혹은 백색 count한다.
}
```

범위의 모든 색이 같은지 판단은 범위 내의 모든 항목을 탐색한다.

```cpp
bool target = map[from.y][from.x];

for (int y = from.y; y < to.y; y++) {
  for (int x = from.x; x < to.x; x++) {
    if (map[y][x] != target) {
      return false;
    }
  }
}
```

분할할 부분이 없는 경우 count를 증가시키고, 분할할 부분이 존재하는 경우 에는 divide를 재귀 호출한다.

분할정복의 함수 divide는 다음과 같다

```cpp
// from : UP LEFT
// to : DOWN RIGHT
// N : length of square
void divide(axis from, axis to, int N) {
  if(length == 0){
    return;
  }
  // 1사분면
  // 2사분면
  // 3사분면
  // 4사분면
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

### 전부 하나의 종이일때

초기에 divide를 호출 할 때도, check를 수행하지 않으면
모든 면이 같은 색일때 정답이 1이 출력되지 않는다.
