# 690. Employee Importance

[링크](https://leetcode.com/problems/employee-importance/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

노드들은 트리구조로 연결되어있으며, id를 루트로 하는 서브트리를 탐색해야 한다.

최악의 경우 모든 노드를 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

내부적으로 subtree의 노드들을 id를 이용해서 찾기 편하게 하기 위해 hash map을 이용한다.

이 경우 검색에 O(1)의 시간 복잡도가 소요된다.

따라서 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash map을 이용하는 경우 O(N)의 공간 복잡도가 필요하다.

트리의 탐색을 BFS를 이용해서 수행할 수 있다. 이 경우 큐에 최대 N개의 노드가 쌓일 수 있다.

따라서 공간 복잡도는 O(N)이다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

모든 노드들을 다음과 같은 hash map에 저장한다.

- key : id
- value : Employee 데이터

이후 입력받은 id노드부터 BFS를 이용해 탐색을 진행한다.

```cpp
int getImportance(vector<Employee*> employees, int id) {
  unordered_map<int, Employee*> m;

  for (Employee* employee : employees) {
    m[employee->id] = employee;
  }

  int answer = 0;
  queue<Employee*> q;
  if (m[id] != NULL) q.push(m[id]);

  while (!q.empty()) {
    Employee* cur = q.front();
    q.pop();

    answer += cur->importance;

    for (int id : cur->subordinates) {
      q.push(m[id]);
    }
  }

  return answer;
}
```

## 고생한 점
