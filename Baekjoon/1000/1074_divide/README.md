# 1074. Z

[링크](https://www.acmicpc.net/problem/1074)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   41.381    |

## 설계

### 시간 복잡도

모든 경우를 순서대로 탐색하는 경우 입력의 최대 값 (2^15)^2 만큼 탐색하면 된다.

이는 1,073,741,824 번 이므로 제한시간 내에 불가능하다.

재귀 호출로 구현하는 경우 log_4((2^15)^2) 만큼의 시간이 소요된다.

이는 15 이며 제한시간 1초 내에 충분하다.

### 공간 복잡도

15^2 사이즈의 배열을 선언한다. 배열에 들어갈 수 있는 최대 값은 15^2 이므로 int형으로 선언한다.

### 재귀

각 구역을 4가지로 나눈다.

입력받은 좌표 R,C가 어느 위치에 포함되어있는지 여부를 판단하고 total을 갱신해야 한다.

현재 크기를 4등분 했을 때, 나눈 사각형의 한 변의 길이를 L 이라 하자

하나의 사각형에는 L^2개의 숫자가 포함된다.

현재 사각형의 시작점 axis 를 기준으로 total은

- R이 axis.y + L 보다 크면 L^2 + L^2 만큼 증가
- C이 axis.x + L 보다 크면 L^2 만큼 증가

이는 Z모양으로 순회하는 성질에 따르기 때문이다

```sh
0 1
2 3

# 위 숫자의 갯수만큼 범위 덩어리 추가
```

따라서 재귀함수는 다음과 같이 구현된다.

```cpp
void recusive(Axis from, Axis to, int total){
  if(from.y == to.y && from.x == to.x){
    // 정답에 도달함
    return;
  }

  int length = (to.y - from.y) / 2;
  int size = (length + 1) * (length + 1);

  if(from.x + length < C) {
    from.x += length + 1;
    total += size;
  }
  if(from.y + length < R) {
    from.y += length + 1;
    total += size * 2;
  }

  recusive(from, {from.y + length, from.x + length}, total);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
