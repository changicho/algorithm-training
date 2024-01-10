# 3000. Maximum Area of Longest Diagonal Rectangle

[링크](https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 dimensions의 크기를 N이라 하자.

각 좌표를 순회하며 대각선의 길이와 넓이를 구해 정답을 갱신한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

최대값만을 저장하는 데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

각 좌표마다 대각선 제곱의 길이를 구하고, 이 값이 최대값인 경우에만 넓이를 갱신한다.

```cpp
int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
  int area = 0;
  int diagonal = 0;

  for (vector<int>& d : dimensions) {
    int a = d[0], b = d[1];
    int cur = a * a + b * b;

    if (diagonal < cur) {
      area = a * b;
      diagonal = cur;
    } else if (diagonal == cur) {
      area = max(area, a * b);
    }
  }

  return area;
}
```

## 고생한 점
