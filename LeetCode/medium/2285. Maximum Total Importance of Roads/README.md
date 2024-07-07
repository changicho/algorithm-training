# 2285. Maximum Total Importance of Roads

[링크](https://leetcode.com/problems/maximum-total-importance-of-roads/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 노드의 수를 V, 간선 roads의 수를 E라 하자.

각 노드마다 연결된 간선의 수를 구하고, 간선의 수가 많은 순으로 높은 점수를 배정한다.

이 경우 간선의 순회에 O(E)의 시간 복잡도를 사용한다.

연결된 간선의 수에 대해 정렬을 수행할 때 O(V \* log_2(V))의 시간 복잡도가 소요된다.

이를 카운팅 정렬로 수행할 경우 O(V)의 시간 복잡도가 소요된다.

따라서 총 시간 복잡도는 O(V + E)이다.

### 공간 복잡도

각 노드마다 간선의 수를 구해야 하므로 O(V)의 공간 복잡도가 필요하다.

카운팅 정렬에 사용할 배열을 생성할 때 O(V)의 공간 복잡도가 필요하다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     259      |  O(V + E)   |    O(V)     |

각 노드마다 연결된 간선의 수를 구하고, 간선의 수에 따라 점수를 배정한다.

이 때 간선의 수가 많은 노드에 높은 점수를 배정하는 것이 유리하다.

따라서 간선의 수를 카운팅 정렬을 이용해 정렬한 뒤 큰 순서로 순회하며 점수를 배정한다.

```cpp
long long maximumImportance(int n, vector<vector<int>> &roads) {
  int inDegrees[50001] = {
      0,
  };

  for (vector<int> &e : roads) {
    int a = e[0], b = e[1];

    inDegrees[a]++;
    inDegrees[b]++;
  }

  int counts[50001] = {
      0,
  };
  for (int &inDegree : inDegrees) {
    counts[inDegree]++;
  }

  long long answer = 0;
  for (long long score = n, cur = n; cur >= 0; cur--) {
    while (counts[cur] > 0) {
      answer += score * cur;
      counts[cur]--;
      score--;
    }
  }

  return answer;
}
```

## 고생한 점
