# 1051. 숫자 정사각형

[링크](https://www.acmicpc.net/problem/1051)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |   37.140    |

## 설계

### 시간 복잡도

N과 M은 50보다 작은 수이다.

모든 경우를 비교한다고 했을 때, 경우의 수는

```cpp
1 + 4 + 9 + 16 + ... + 2500 < 2500 * 50
// 12,500 보다 작음
```

이는 최악의 경우도 12,500 보다 작으므로 제한시간 내에 충분하다.

### 공간 복잡도

각 칸은 한자리 수가 적혀있으므로 int형으로 충분하다.

### 경우 비교

정사각형의 길이가 N이고 좌표가 y,x라고 할 때 비교해야 하는 좌표는 다음 4개이다

- (y, x)
- (y + N - 1, x)
- (y, x + N - 1)
- (y + N - 1, x + N - 1)

4개의 좌표를 비교해서 하나라도 다른 경우 정답이 될 수 없으므로 비교는 다음과 같다.

```cpp
bool isSame(int y, int x, int length) {
  if (map[y][x] != map[y + length - 1][x]) return false;
  if (map[y][x] != map[y][x + length - 1]) return false;
  if (map[y][x] != map[y + length - 1][x + length - 1]) return false;

  return true;
}
```

그리고 좌표를 탐색하는 반복문은 다음과 같다.

```cpp
for (int y = 0; y < N - length + 1; y++) {
  for (int x = 0; x < M - length + 1; x++) {
    if (isSame(y, x, length)) {
      int newAnswer = (length) * (length);
      answer = max(newAnswer, answer);
      return;
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
