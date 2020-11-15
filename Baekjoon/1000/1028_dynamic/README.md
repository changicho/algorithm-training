# 1028. 다이아몬드 광산

[링크](https://www.acmicpc.net/problem/1028)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   27.126    |

## 설계

### 시간 복잡도

전체 광산의 크기는 최대 750^2 이다.

각 광산의 좌표 별로 모든 좌표를 검사할 경우 시간 복잡도는 (N/2)^2 정도 소요된다.

따라서 브루트 포스 방법을 사용하는 경우 시간 복잡도는 750^4 정도이며, 이는 제한시간 2초 내에 불가능하다.

따라서 동적 계획법을 이용해 N^2 이내로 시간복잡도를 줄인다.

### 공간 복잡도

지도에서 나타내야 하는 데이터의 종류는 0, 1 두가지이다.

입력이 붙어 들어오므로 string 형태로 관리한다.

정답의 경우 최대 2N 이내로 가질 수 있으며, 이는 1500 미만이므로 int형으로 선언한다.

### 동적 계획법

두 종류의 2차원 배열을 만들어 관리한다.

```cpp
int leftDown[LIMIT][LIMIT]; // 왼쪽 아래에서부터 연속된 line의 최대 수
int rightDown[LIMIT][LIMIT]; // 오른쪽 아래에서부터 연속된 line의 최대 수
```

다음과 같은 예시를 보자

```text
00100
01010
10001
01010
00100
```

위와 같은 경우 각 배열의 수는 다음과 같을것이다.

```text
leftDown  rightDown
00300     00300
02010     01020
10003     30001
01020     02010
00100     00100
```

여기서 우리가 이용할 것은, 해당 좌표에서 특정 길이의 다이아몬드 광산을 찾을 수 있는지 여부이다.

좌표 (y,x)와 특정 길이 (length)가 주어졌을 때 다음 조건이 만족하는 경우 다이아몬드 광산이 존재한다.

```cpp
int length = min(leftDown[y][x], rightDown[y][x]);

int leftDownLength = isFine(y + (length - 1), x + (length - 1)) ? leftDown[y + (length - 1)][x + (length - 1)] : 0;
int rightDownLength = isFine(y + (length - 1), x - (length - 1)) ? rightDown[y + (length - 1)][x - (length - 1)] : 0;

if (leftDownLength >= length && rightDownLength >= length) {
  answer = max(answer, length);
  break;
}
```

즉 이전에 구해놓은 각 대각선 별로 다이아몬드가 연속된 길이를 이용하는 방법이며, 다이아몬드의 4변중 2변끼리 묶어 생각할 수 있음을 이용한다.

상 하 좌 우 의 꼭지점에서, 각 dp 배열의 좌표값들이 길이 이상인 경우 이를 판단한다.

또한 각 좌표별로 length를 변경 (줄여가며) 이를 탐색한다.

```cpp
for (int y = 0; y < limit.y; y++) {
  for (int x = 0; x < limit.x; x++) {
    int startLength = min(leftDown[y][x], rightDown[y][x]);

    for (int length = startLength; length > answer; length--) {
      int leftDownLength = isFine(y + (length - 1), x + (length - 1)) ? leftDown[y + (length - 1)][x + (length - 1)] : 0;
      int rightDownLength = isFine(y + (length - 1), x - (length - 1)) ? rightDown[y + (length - 1)][x - (length - 1)] : 0;

      if (leftDownLength >= length && rightDownLength >= length) {
        answer = max(answer, length);
        break;
      }
    }
  }
}
```

dp배열의 초기화는 다음과 같다.

```cpp
for (int y = limit.y - 1; y >= 0; y--) {
  for (int x = 0; x < limit.x; x++) {
    if (board[y][x] == '1') {
      leftDown[y][x] = isFine(y + 1, x - 1) ? leftDown[y + 1][x - 1] + 1 : 1;
      rightDown[y][x] = isFine(y + 1, x + 1) ? rightDown[y + 1][x + 1] + 1 : 1;
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       8        |

## 고생한 점
