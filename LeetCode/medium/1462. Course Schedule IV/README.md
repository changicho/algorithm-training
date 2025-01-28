# 1462. Course Schedule IV

[링크](https://leetcode.com/problems/course-schedule-iv/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

그래프의 정점의 수를 V, 간선의 수를 E, 쿼리의 수를 Q라 하자.

그래프를 생성하는 데 O(E)의 시간 복잡도가 소요된다.

모든 쿼리마다 직접 BFS로 탐색할 수 있다. 이 경우 탐색에 O(V + E)의 시간 복잡도가 소요된다.

이를 Q번 반복할 경우 시간 복잡도는 O(Q \* (V + E))이다.

플로이드 와샬 알고리즘을 이용할 경우 O(V^3)의 시간 복잡도가 소요된다.

### 공간 복잡도

그래프를 생성하는데 O(V + E)의 공간 복잡도가 필요하다.

BFS로 탐색할 경우 방문한 노드를 저장할 공간이 필요하다. 이는 O(V)의 공간 복잡도가 필요하다.

플로이드 와샬 알고리즘을 이용할 경우 O(V^2)의 공간 복잡도가 필요하다.

### 플로이드 와샬

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|      48      | O(V^3 + E + Q) |   O(V^2)    |

각 노드에서 다른 노드로 도달 가능한 지 플로이드 와샬 알고리즘을 이용해 계산한다.

이후 각 쿼리마다 해당 노드로 도달 가능한지 판별한다.

```cpp
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
  vector<vector<int>> costs(numCourses, vector<int>(numCourses, 1));
  for (int i = 0; i < numCourses; i++) {
    costs[i][i] = 0;
  }
  for (vector<int>& edge : prerequisites) {
    int from = edge[0], to = edge[1];

    costs[from][to] = 0;
  }

  for (int through = 0; through < numCourses; through++) {
    for (int from = 0; from < numCourses; from++) {
      for (int to = 0; to < numCourses; to++) {
        costs[from][to] =
            min(costs[from][to], costs[from][through] + costs[through][to]);
      }
    }
  }

  vector<bool> answer;
  for (vector<int>& q : queries) {
    int from = q[0], to = q[1];

    answer.push_back(costs[from][to] == 0);
  }
  return answer;
}
```

## 고생한 점
