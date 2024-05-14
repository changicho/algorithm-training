# B - Spot the Difference

[링크](https://atcoder.jp/contests/abc351/tasks/abc351_b)

| 난이도 |
| :----: |
|  150   |

## 설계

### 시간 복잡도

2차원 정사각 배열의 한 변의 길이를 N이라 하자.

이 경우 모든 배열을 순회하며 다른 값이 나오는 경우를 찾아야 한다.

이 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

값이 다른 좌표만 찾으면 되므로 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^2)    |   O(N^2)    |

```cpp
pair<int, int> solution(vector<string> &a, vector<string> &b) {
  int size = a.size();

  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      if (a[y][x] != b[y][x]) {
        return {y + 1, x + 1};
      }
    }
  }

  return {-1, -1};
}
```

## 고생한 점
