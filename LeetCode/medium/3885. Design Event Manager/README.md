# 3885. Design Event Manager

[링크](https://leetcode.com/problems/design-event-manager/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

원소와 연산의 수를 N이라 하자.

각 연산마다 BST기반의 map, set을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

map, set에 O(N)의 공간 복잡도를 사용한다.

### BST set

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     237      | O(N \* log_2(N)) |    O(N)     |

set에 pair를 저장하며 첫번째 값에 priority를, 두번째 값으로 id를 음수로 치환해 저장한다.

이를 이용해 priority순, id역순 으로 자동으로 정렬되어 저장된다.

priority를 변경할 경우 기존 id에 해당하는 priority를 저장하는 hash map을 사용하고, 해당 정보를 set에서 제거 후 다시 저장한다.

이후 poll 연산에서 가장 큰 값을 반환한다.

```cpp
class EventManager {
 private:
  set<pair<int, int>> s;
  unordered_map<int, int> um;

 public:
  EventManager(vector<vector<int>>& events) {
    for (vector<int>& e : events) {
      int id = e[0], p = e[1];

      um[id] = p;
      s.insert({p, -id});
    }
  }

  void updatePriority(int eventId, int newPriority) {
    int beforeP = um[eventId];
    um[eventId] = newPriority;

    s.erase({beforeP, -eventId});
    s.insert({newPriority, -eventId});
  }

  int pollHighest() {
    if (s.empty()) return -1;

    auto it = prev(s.end());
    int target = abs(it->second);
    s.erase(it);

    return target;
  }
};
```

## 고생한 점
