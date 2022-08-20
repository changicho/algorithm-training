# Problem C1: Gold Mine - Chapter 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/C1)

| 난이도 |
| :----: |
| 21 pt  |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 N-1개라 하자.

각 노드들을 1번부터 순회하며 리프노드에서 해당노드까지 도달했을 때의 경로의 가치 최대값을 찾는다. 이 탐색에 O(N)의 시간 복잡도를 사용한다.

이후 1번 노드와 연결된 자식 노드들 중 가장 가치가 높은 노드 2개를 찾는다. 이 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 노드들을 서브트리의 루트로 하는 가치를 저장하기 위해 O(N)의 공간 복잡도를 사용한다.

DFS로 각 노드들을 탐색할 경우 O(N)의 공간 복잡도를 사용한다.

### 서브트리 탐색

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(N \* log_2(N)) |    O(N)     |

터널을 한번 뚫을 수 있으며, 1번 동굴로 들어가고 나와야 한다.

즉 1번 동굴에서 리프 노드까지 탐색하고, 다른 리프노드까지 터널을 뚫고 해당 리프노드에서 1번 노드까지 순회하는 경로가 정답의 후보가 될 수 있다.

- 간선의 갯수는 N-1개 이므로 사이클이 존재할 수 없다.
- 금광의 가치는 양의 정수이므로 많이 방문할수록 가치가 높아진다.
- 리프 노드에서 루트 노드까지 방문했을때 가장 가치가 높다.

따라서 1번 노드의 자식 노드들을 루트로 하는 서브트리의 가치들을 탐색하고, 이 중 가장 큰 2개의 값의 가치를 이용해 정답을 구한다.

```cpp
long long recursive(int node, vector<long long> &totalValues, vector<int> &values, vector<vector<int>> &graph, vector<bool> &visited) {
  if (visited[node]) return 0;
  visited[node] = true;
  long long valueSum = 0;

  for (int &next : graph[node]) {
    if (visited[next]) continue;
    long long nextVal = recursive(next, totalValues, values, graph, visited);
    valueSum = max(valueSum, nextVal);
  }

  valueSum += values[node];
  visited[node] = false;
  totalValues[node] = valueSum;
  return valueSum;
}

long long solution(int n, vector<int> &values, vector<vector<int>> &graph) {
  vector<long long> totalValues(n + 1, 0);
  totalValues[1] = values[1];

  vector<bool> visited(n + 1, false);

  recursive(1, totalValues, values, graph, visited);

  vector<long long> maxSums;
  for (int &child : graph[1]) {
    maxSums.push_back(totalValues[child]);
  }
  sort(maxSums.begin(), maxSums.end(), greater<long long>());

  long long answer = values[1];
  if (maxSums.size() >= 1) {
    answer += maxSums[0];
  }
  if (maxSums.size() >= 2) {
    answer += maxSums[1];
  }

  return answer;
}
```

## 고생한 점
