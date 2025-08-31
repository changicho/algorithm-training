# 1182. Shortest Distance to Target Color

[링크](https://leetcode.com/problems/shortest-distance-to-target-color/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 colors의 크기를 N, 쿼리의 수를 Q라 하자.

이분 탐색을 이용해 구할 경우 O(Q \* log_2(N) + N)의 시간 복잡도를 사용한다.

미리 순회하며 정답을 구해놓을 경우 O(N + Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열에 O(Q)의 공간 복잡도를 사용한다.

이분 탐색에 O(N)의 공간 복잡도를 사용한다.

미리 정답을 구해놓을 경우 O(N)의 공간 복잡도를 사용한다.

### 미리 계산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      64      |  O(N + Q)   |  O(N + Q)   |

colors를 순회하며 현재 color에 해당하는 직전 index부터 현재 index까지 정답을 갱신한다.

이후 해당 color에 대한 직전 index를 갱신한다.

이를 정방향, 역방향으로 수행하며 각 index마다 특정 color에 대한 최단 거리를 계산한다.

이 때 특정 index에서 color에 접근 불가능한 경우를 처리하기 위해 초기값은 모두 접근 불가능으로 설정한다.

```cpp
vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
  int size = colors.size();
  int lefts[3] = {0, 0, 0};
  int rights[3] = {size - 1, size - 1, size - 1};

  vector<vector<int>> dists(size, vector<int>(3, INT_MAX));

  for (int i = 0; i < size; i++) {
    int rI = size - 1 - i;

    int c = colors[i] - 1;

    for (int before = lefts[c]; before <= i; before++) {
      dists[before][c] = min(dists[before][c], i - before);
    }
    lefts[c] = i + 1;

    int rc = colors[rI] - 1;

    for (int before = rights[rc]; before >= rI; before--) {
      dists[before][rc] = min(dists[before][rc], before - rI);
    }
    rights[rc] = rI - 1;
  }

  vector<int> answer;

  for (vector<int>& q : queries) {
    int i = q[0], c = q[1] - 1;

    int d = dists[i][c];

    answer.push_back(d == INT_MAX ? -1 : d);
  }

  return answer;
}
```

## 고생한 점
