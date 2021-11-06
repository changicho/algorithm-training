# 332. Reconstruct Itinerary

[링크](https://leetcode.com/problems/reconstruct-itinerary/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

지역의 개수를 V, 티켓의 개수를 E라고 하자.

오일러 경로 알고리즘을 이용할 경우 O(E \* log_2(E))의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

edges를 그래프로 변환하는데 O(E)의 공간 복잡도를 사용한다.

### 오일러 경로

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      12      | O(E \* log_2(E)) |    O(E)     |

오일러 경로(eulerian trail) 란 그래프에 존재하는 모든 Edge를 정확히 1번씩만 방문하는 연속된 경로이다.

이를 구하기 위해 Hierholzer's Algorithm을 사용한다.

해당 알고리즘은 다음과 같이 동작한다.

1. 시작 정점 v를 선택해서 v로 다시 돌아오는 경로를 찾는다.
2. 경로에 포함되어 있는 정점 중에 사용되지 않은 간선이 연결된 정점 u를 찾고, 아직 쓰이지 않은 간선들을 사용해 u에서 시작해서 u로 돌아오는 경로를 찾은 뒤 원래의 경로에 삽입한다,
3. u를 찾을 수 없을 때까지 2를 반복한다.

DFS를 이용해 끝점부터 정답에 추가하므로 내림차순으로 정렬한 큐를 이용한다.

여기서 사전순으로 가장 앞서는 경로를 출력해야 한다.

따라서 긱 노드별로 lexical order가 낮은순으로 (알파벳 순) 부터 DFS로 탐색을 하며, 가능한 경로를 미리 모두 방문한다.

```cpp
unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

void recursive(string node, vector<string>& answer) {
  while (!graph[node].empty()) {
    string next = graph[node].top();
    graph[node].pop();

    recursive(next, answer);
  }

  answer.push_back(node);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
  vector<string> answer;

  for (vector<string>& ticket : tickets) {
    string from = ticket[0], to = ticket[1];

    graph[from].push(to);
  }
  recursive("JFK", answer);

  reverse(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
