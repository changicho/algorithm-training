# 3607. Power Grid Maintenance

[링크](https://leetcode.com/problems/power-grid-maintenance/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 수를 C, 간선의 수를 E, 쿼리의 수를 Q라고 하자.

유니온 파인드를 이용해 노드의 연결을 관리할 수 있다. 이에 O(E)의 시간 복잡도를 사용한다.

(유니온 파인드의 에크만 상수는 거의 상수에 가깝다.)

이후 연결된 노드들을 각각의 그래프라 하자. 각 그래프에서 쿼리마다 최소 노드를 BST set을 이용해 관리할 수 있다.

이에 O((C + Q) \* log_2(C))의 시간 복잡도를 사용한다.

혹은 쿼리를 역으로 순회하며 처리할 수도 있다. 이 경우 O(C + Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

유니온 파인드에 O(C)의 공간 복잡도를 사용한다.

정답에 O(Q)의 공간 복잡도를 사용한다.

### 유니온 파인드 & 쿼리 역순회

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      35      | O(E + C + Q) |  O(C + Q)   |

각 노드들을 유니온 파인드를 이용해 연결한다.

쿼리에서 특정 노드는 online->offline으로만 변하게 된다.

따라서 쿼리를 미리 순회해 노드를 미리 다 끈 뒤, 쿼리를 역순회 할 경우

현재 쿼리에서 online->offline으로 변하는 경우, 이전 쿼리에서는 계속 online 상태였음이 보장된다.

따라서 쿼리를 역순회하며 online상태로 되돌린 경우 연결된 노드들의 집합에 현재 노드의 값을 가장 작은 값으로 업데이트할 수 있다.

이를 이용해 각 집합마다 가장 작은 노드의 값을 관리하며 정답을 채운다.

```cpp
vector<int> parents;

int find(int a) {
  if (parents[a] == a) return a;
  return parents[a] = find(parents[a]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);

  if (a > b) swap(a, b);
  parents[b] = a;
}

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
  vector<int> answer;

  parents.resize(c + 1);
  for (int i = 1; i <= c; i++) {
    parents[i] = i;
  }
  for (vector<int>& e : connections) {
    int a = e[0], b = e[1];

    merge(a, b);
  }

  vector<int> delCount(c + 1, 0);
  vector<int> minByParent(c + 1, INT_MAX);
  for (vector<int>& q : queries) {
    int type = q[0], target = q[1];

    if (type == 2) {
      delCount[target]++;
    }
  }
  for (int i = 1; i <= c; i++) {
    if (delCount[i] == 0) {
      int p = find(i);
      minByParent[p] = min(minByParent[p], i);
    }
  }

  for (int i = queries.size() - 1; i >= 0; i--) {
    vector<int>& q = queries[i];
    int type = q[0], target = q[1];

    int p = find(target);
    if (type == 1) {
      if (delCount[target] == 0) {
        answer.push_back(target);
      } else if (minByParent[p] == INT_MAX) {
        answer.push_back(-1);
      } else {
        answer.push_back(minByParent[p]);
      }
    } else {
      delCount[target]--;

      if (delCount[target] == 0) {
        minByParent[p] = min(minByParent[p], target);
      }
    }
  }

  reverse(answer.begin(), answer.end());

  return answer;
}
```

## 고생한 점
