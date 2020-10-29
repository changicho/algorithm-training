# 1992. 쿼드트리

[링크](https://www.acmicpc.net/problem/1992)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   58.036    |

## 설계

### 시간 복잡도

N은 최대 64개이다. 분할정복 기법을 사용했을 때 최악의 경우 호출되는 횟수는 64^2 번 이므로

이는 제한시간 2초 내에 충분하다.

### 공간 복잡도

배열은 0과 1로만 이루어져있으나 입력이 각 줄별로 공백 없이 주어진다.

따라서 string을 이용해 관리한다.

### 분할 정복

특정 range를 입력받았을 때 그 범위의 요소들이 전부 같은지 검사한다.

압축이 불가능한 경우 4등분해 재귀호출한다.

인자로 넣어주는 시작과 끝의 좌표는 다음과 같이 설정한다.

- from : 시작점
- to : 이 좌표 미만까지만 검사하도록 설정

따라서 범위는 다음과 같이 탐색하면 된다.

```cpp
for (int y = from.y; y < to.y; y++)
  for (int x = from.x; x < to.x; x++)
```

```cpp
string recursive(Axis from, Axis to, vector<string> &board) {
  if (from.y + 1 == to.y && from.x + 1 == to.x) {
    string ret = "";
    return ret + board[from.y][from.x];
  }

  char target = board[from.y][from.x];
  bool canCompact = true;
  for (int y = from.y; y < to.y; y++) {
    for (int x = from.x; x < to.x; x++) {
      if (board[y][x] == target) continue;

      canCompact = false;
      break;
    }
    if (!canCompact) break;
  }

  if (canCompact) {
    string ret = "";
    return ret + board[from.y][from.x];
  }

  int mid = abs(to.y - from.y) / 2;

  string upperLeft = recursive(from, {from.y + mid, from.x + mid}, board);
  string upperRight = recursive({from.y, from.x + mid}, {from.y + mid, to.x}, board);
  string lowerLeft = recursive({from.y + mid, from.x}, {to.y, from.x + mid}, board);
  string lowerRight = recursive({from.y + mid, from.x + mid}, to, board);

  return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
