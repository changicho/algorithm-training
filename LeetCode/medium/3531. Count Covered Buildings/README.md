# 3531. Count Covered Buildings

[링크](https://leetcode.com/problems/count-covered-buildings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

buildings 좌표의 갯수를 M, 도시의 크기를 N이라 하자.

각 좌표를 X, Y 좌표에 대해 묶고 이를 다시 순회하며 각 좌표에 대해 건물이 커버되는지 확인하는 방식으로 접근할 수 있다.

이 경우 O(M) 의 시간 복잡도를 가진다.

### 공간 복잡도

각 좌표 범위를 저장하는데 O(N) 의 공간 복잡도를 가진다.

### 좌표 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(M)     |    O(N)     |

각 Y, X축에 대해서 존재하는 점들을 묶는다.

- 특정 Y축에 해당하는 X좌표들
- 특정 X축에 해당하는 Y좌표들

해당 점들을 묶은 뒤 최소값과 최대값을 저장한다.

이후 각 점들을 다시 순회하며, 해당 점이 속한 Y, X축에 대해 해당 점을 포함하는 좌표가 있는지 최대, 최소값을 이용해 확인한다.

```cpp
bool isInMiddle(pair<int, int>& p, int val) {
  if (p.first == p.second || p.first == val || p.second == val) return false;
  return true;
}

void change(pair<int, int>& p, int val) {
  p.first = min(p.first, val);
  p.second = max(p.second, val);
}

int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
  vector<pair<int, int>> y2x(n + 1, {INT_MAX, INT_MIN});
  vector<pair<int, int>> x2y(n + 1, {INT_MAX, INT_MIN});

  for (vector<int>& b : buildings) {
    int y = b[0], x = b[1];

    change(y2x[y], x);
    change(x2y[x], y);
  }

  int answer = 0;
  for (vector<int>& b : buildings) {
    int y = b[0], x = b[1];

    if (isInMiddle(y2x[y], x) && isInMiddle(x2y[x], y)) answer++;
  }
  return answer;
}
```

## 고생한 점
