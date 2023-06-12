# 1376. Time Needed to Inform All Employees

[링크](https://leetcode.com/problems/time-needed-to-inform-all-employees/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 수를 N이라 하자. 간선의 수는 N-1개 이다.

루트 노드에서 부터 리프 노드까지의 도달하는 시간 중 가장 긴 값을 찾으면 된다.

이를 위해 DFS를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 이용할 경우 call stack에 O(N)의 공간 복잡도를 사용한다.

그래프 관계를 표현하는 데 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     325      |    O(N)     |    O(N)     |

루트 노드에서 부터 각 노드까지의 도달하는 시간을 넘겨주며 계산 후 정답을 갱신한다.

```cpp
int size = 0;
int answer = 0;
vector<vector<int>> children;
vector<int> informTime;

void recursive(int node, int time) {
  answer = max(answer, time);

  for (int& next : children[node]) {
    recursive(next, time + informTime[node]);
  }
}

int numOfMinutes(int n, int headID, vector<int>& manager,
                  vector<int>& informTime) {
  this->size = n;
  this->informTime = informTime;

  children.resize(n);

  for (int i = 0; i < n; i++) {
    if (manager[i] == -1) continue;
    children[manager[i]].push_back(i);
  }

  recursive(headID, 0);
  return answer;
}
```

## 고생한 점
