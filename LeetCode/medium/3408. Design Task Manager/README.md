# 3408. Design Task Manager

[링크](https://leetcode.com/problems/design-task-manager/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

총 task의 갯수를 N이라 하자.

각 경우마다 task의 우선 순위 중 가장 높은 값을 찾으며, 우선순위는 변동될 수 있다.

hash map과 heap을 이용해 각 task마다 우선순위를 갱신할 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

hash map과 heap에 O(N)의 공간 복잡도를 가진다.

### 힙 & 해시 맵

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     171      | O(N \* log_2(N)) |    O(N)     |

priority와 taskId를 기준으로 힙을 생성한다.

이 때 task를 저장할 때 taskId를 기준으로 하는 해시 맵을 함께 사용한다.

만약 특정 taskId의 우선순위가 변경되거나 삭제되는 경우, 해시 맵에서 해당 taskId의 우선순위를 갱신한다.

이후 execTop이 호출되는 경우, 힙에서 우선순위가 가장 높은 task를 꺼내 해당 taskId의 우선순위를 해시 맵에서 확인한다.

만약 해시 맵에 존재하지 않거나 우선순위가 다르다면 무시하고 다음 task를 확인한다.

```cpp
class TaskManager {
 private:
  unordered_map<int, pair<int, int>> um;
  priority_queue<pair<int, int>> pq;

 public:
  TaskManager(vector<vector<int>>& tasks) {
    for (vector<int>& t : tasks) {
      // [userId, taskId, priority
      int userId = t[0], taskId = t[1], priority = t[2];
      um[taskId] = {priority, userId};
      pq.emplace(priority, taskId);
    }
  }

  void add(int userId, int taskId, int priority) {
    um[taskId] = {priority, userId};
    pq.emplace(priority, taskId);
  }

  void edit(int taskId, int newPriority) {
    um[taskId].first = newPriority;
    pq.emplace(newPriority, taskId);
  }

  void rmv(int taskId) { um[taskId].first = -1; }

  int execTop() {
    while (!pq.empty()) {
      auto [priority, taskId] = pq.top();
      if (um.count(taskId) && um[taskId].first == priority) {
        pq.pop();
        int userId = um[taskId].second;
        um.erase(taskId);
        return userId;
      }
      pq.pop();
    }
    return -1;
  }
};
```

## 고생한 점
