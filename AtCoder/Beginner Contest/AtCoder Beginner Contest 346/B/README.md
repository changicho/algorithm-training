# B - Piano

[링크](https://atcoder.jp/contests/abc346/tasks/abc346_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 두 수의 크기를 W, B라 하자.

주어진 piano 문자열에서 W, B를 충족하는 경우를 구해야 한다.

piano 문자열 패턴은 반복되므로 가능한 시작점에서 모든 경우를 탐색할 경우 O(W + B)의 시간 복잡도를 사용한다.

### 공간 복잡도

직접 index를 이동하며 순회할 경우 별도의 공간 복잡도가 필요하지 않다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |  O(W + B)   |    O(1)     |

피아노 문자열의 패턴은 반복된다.

또한 피아노 문자열의 길이는 12이므로, 12개의 시작하는 경우만 탐색하면 된다.

따라서 각 경우마다 시작점을 이동하며 W + B만큼 탐색하며 W, B의 갯수를 센다.

이 경우 W, B의 갯수가 일치하는 경우가 존재하는지 판별한다.

```cpp
bool solution(int &w, int &b) {
  string piano = "wbwbwwbwbwbw";

  int size = piano.size();

  int length = w + b;
  for (int index = 0; index < size; index++) {
    int wCount = 0, bCount = 0;
    for (int i = 0; i < length; i++) {
      char cur = piano[(index + i) % size];
      if (cur == 'b') {
        bCount++;
      } else if (cur == 'w') {
        wCount++;
      }
    }
    if (wCount == w && bCount == b) return true;
  }

  return false;
}
```

## 고생한 점
