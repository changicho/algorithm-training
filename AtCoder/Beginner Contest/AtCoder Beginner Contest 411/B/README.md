# B - Distance Table

[링크](https://atcoder.jp/contests/abc411/tasks/abc411_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 좌표의 수를 N이라 하자.

각 좌표를 순회하며 다음 좌표까지의 거리를 모두 구하는데 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표를 저장하는데 O(N^2)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^2)    |   O(N^2)    |

첫번째 좌표부터 다른 좌표까지의 모든 거리를 구해 2차원 벡터에 저장한다.

```cpp
vector<vector<int>> solution(int n, vector<int> &dist) {
  vector<vector<int>> answer;

  for (int i = 0; i < n - 1; i++) {
    vector<int> cur;

    int d = 0;
    for (int j = i; j < n - 1; j++) {
      d += dist[j];
      cur.push_back(d);
    }

    answer.push_back(cur);
  }

  return answer;
}

```

## 고생한 점
