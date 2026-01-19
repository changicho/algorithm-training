# A - Black Square

[링크](https://atcoder.jp/contests/abc441/tasks/abc441_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 각 수들에 대해 좌표를 비교하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

O(1)의 공간 복잡도를 사용한다.

### 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

시작 위치를 포함해 100칸까지 범위 안에 입력받은 좌표가 존재하는지 판단한다.

이를 각 축에 대해 판단한다.

```cpp
bool solution(int p, int q, int x, int y) {
  bool xOverlapped = p <= x && x < p + 100;
  bool yOverlapped = q <= y && y < q + 100;

  return xOverlapped && yOverlapped;
}
```

## 고생한 점
