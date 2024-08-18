# 3248. Snake in Matrix

[링크](https://leetcode.com/problems/snake-in-matrix/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 commands의 크기를 M이라 하자.

시뮬레이션을 이용해 뱀의 이동을 구현할 경우, 뱀의 이동은 O(M)의 시간 복잡도가 소요된다.

### 공간 복잡도

뱀의 위치를 변수로 관리하므로 O(1)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |    O(M)     |    O(1)     |

각 움직임마다 뱀의 위치를 갱신한다.

이 때 위치를 2차원 배열에서 index로 변환해야 하며 다음 수식에 따라 변환한다.

- y \* n + x

```cpp
int finalPositionOfSnake(int n, vector<string>& commands) {
  int cur = 0;

  for (string& c : commands) {
    if (c == "UP") {
      cur -= n;
    } else if (c == "RIGHT") {
      cur += 1;
    } else if (c == "DOWN") {
      cur += n;
    } else if (c == "LEFT") {
      cur -= 1;
    }
  }

  return cur;
}
```

## 고생한 점
