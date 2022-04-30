# 2250. Count Number of Rectangles Containing Each Point

[링크](https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

rectangles의 크기를 N, points의 갯수를 P라 하자.

rectangles의 y범위는 작으므로 이를 같은 y에 대해서 묶는다.

이후 이분탐색을 사용하기 위해 각 좌표를 정렬한다. O(N \* log_2(N))

P를 순회하며 이분 탐색으로 현재 점을 포함하는 직사각형의 갯수를 O(log_2(N))의 시간 복잡도로 찾을 수 있다.

따라서 시간 복잡도는 O((P + N) \* log_2(N)) 이다.

### 공간 복잡도

각 직사각형 좌표를 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     720      | O((P + N) \* log_2(N)) |    O(N)     |

특정 점 p가 rec에 속해있는지 판단하기 위해선 다음을 만족하면 된다.

```cpp
// 각각 x, y좌표를 의미함
bool isInner(vector<int> &rec, vector<int> &p){
  return p[0] <= rec[0] && p[1] <= rec[1];
}
```

따라서 현재 점의 특정 좌표를 기준으로, 이상인 직사각형만 count하면 된다.

직사각형의 y좌표의 범위는 작으므로 이를 매번 전부 탐색해도 상수 시간복잡도 이내에 순회할 수 있다.

따라서 point.y 이상인 좌표부터 최대 y좌표까지 순회한다.

이후에 point.x보다 큰 x좌표를 갖는 rectangles의 갯수를 세면 되며, 이는 이미 정렬되어 있으므로 이분탐색으로 O(log_2(N))의 시간 복잡도로 찾을 수 있다.

이를 구현하면 다음과 같다.

```cpp
vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
  vector<vector<int>> recsByY(101);

  for (vector<int>& rec : rectangles) {
    recsByY[rec[1]].push_back(rec[0]);
  }
  for (vector<int>& recs : recsByY) {
    sort(recs.begin(), recs.end());
  }

  vector<int> answer;
  for (vector<int>& p : points) {
    int count = 0;

    for (int y = p[1]; y < 101; y++) {
      auto it = lower_bound(recsByY[y].begin(), recsByY[y].end(), p[0]);
      count += recsByY[y].end() - it;
    }

    answer.push_back(count);
  }
  return answer;
}
```

## 고생한 점
