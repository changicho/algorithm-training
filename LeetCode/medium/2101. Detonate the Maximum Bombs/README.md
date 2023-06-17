# 2101. Detonate the Maximum Bombs

[링크](https://leetcode.com/problems/detonate-the-maximum-bombs/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

bombs의 크기를 N이라 하자.

하나의 폭탄이 다른 폭탄을 연쇄적으로 파괴할 수 있는지 모든 쌍에 대해 조사한다. 이에 O(N^2)의 시간 복잡도를 사용한다.

이 관계를 그래프로 생성하고 (방향그래프) 이후 각 폭탄을 터뜨렸을때 연쇄적으로 터지는 폭탄의 수를 BFS로 구한다.

이 경우 BFS에 O(N)의 시간 복잡도를 사용한다.

따라서 최종 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

그래프에 O(N^2)의 공간 복잡도를 사용한다.

BFS에 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     358      |   O(N^2)    |   O(N^2)    |

현재 폭탄이 터졌을 때 다른 폭탄을 터뜨릴 수 있는지 모든 쌍에 대해 판단한다.

이 때 현재 폭탄의 반경에 다른 폭탄이 들어오는지는 피타고라스의 정리를 이용해 판단한다.

(두 점의 xDiff, yDiff를 구하고 이와 반지름을 비교함)

이후 각 폭탄을 순회하며 터뜨렸을 때 연쇄적으로 터지는 폭탄의 수를 BFS로 구한다.

```cpp
vector<vector<int>> graph;

// can reach a to b
bool isAssociate(vector<int> &a, vector<int> &b) {
  long long xDiff = abs(a[0] - b[0]);
  long long yDiff = abs(a[1] - b[1]);
  long long r = a[2];

  long long length = xDiff * xDiff + yDiff * yDiff;

  return length <= (r * r);
}

int calcDetonatedBombs(int node) {
  int size = graph.size();
  vector<bool> visited(size, false);
  int count = 0;
  queue<int> q;

  q.push(node);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (visited[cur]) continue;
    visited[cur] = true;
    count++;

    for (int &next : graph[cur]) {
      q.push(next);
    }
  }
  return count;
}

int maximumDetonation(vector<vector<int>> &bombs) {
  int size = bombs.size();

  graph.resize(size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) continue;
      if (isAssociate(bombs[i], bombs[j])) {
        graph[i].push_back(j);
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    int count = calcDetonatedBombs(i);
    answer = max(answer, count);
  }
  return answer;
}
```

## 고생한 점
