# 1637. Widest Vertical Area Between Two Points Containing No Points

[링크](https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

점들의 갯수를 N이라 하자.

각 점들을 정렬한 뒤 x좌표들의 간격을 비교할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 STL을 사용할 경우 O(log_2(N))의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     248      | O(N \* log_2(N)) | O(log_2(N)) |

각 좌표들을 x좌표에 대해 정렬한다.

이후 연속된 x좌표들의 간격을 비교해 정답을 갱신한다.

이 간격 중 가장 큰 값이 정답이다.

```cpp
int maxWidthOfVerticalArea(vector<vector<int>>& points) {
  sort(points.begin(), points.end());

  int answer = 0;
  int before = points[0][0];
  for (vector<int>& p : points) {
    int x = p[0];
    if (before != x) {
      answer = max(answer, x - before);
      before = x;
    }
  }
  return answer;
}
```

## 고생한 점
