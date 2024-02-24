# 2092. Find All People With Secret

[링크](https://leetcode.com/problems/find-all-people-with-secret/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 meetings의 크기를 E (간선의 갯수), 인원의 수 (노드의 수)를 V라 자.

각 시간마다 미팅한 인원끼리 비밀을 모두 공유하므로 각 시간에 따라 미팅을 정렬해야 한다.

이에 O(E \* log_2(E))의 시간 복잡도가 필요하다.

같은 시간에 미팅을 하는 인원들 끼리 union-find를 이용해 묶을 수 있다.

이 경우 각 시간마다 O(V)의 시간 복잡도가 필요하다.

시간은 총 E개가 존재할 수 있으므로 시간 복잡도는 O(E \* V)이다.

이를 모두 종합하면 O(E \* log_2(E) + E \* V)이다.

### 공간 복잡도

정렬에 O(E)의 공간 복잡도를 사용한다. union-find를 사용할 경우 O(V)의 공간 복잡도가 필요하다.

### 정렬 & 유니온 파인드

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|     648      | O(E * (log_2(E) + V)) |  O(E + V)   |

각 시간마다 미팅은 동시에 일어나므로 미팅을 시간에 따라 정렬한 뒤 같은 시간의 미팅들을 묶는다.

이후 묶인 미팅에서 만나는 인원들 끼리 유니온 파인드를 이용해 묶는다.

만약 한 묶음에서 한 인원이라도 비밀을 아는 경우 해당 묶음에 모든 인원이 비밀을 알게 된다.

이를 모든 시간에 대해 순회하며 반복한다.

```cpp
int find(int node, unordered_map<int, int> &parents) {
  if (parents[node] == node) return node;
  return find(parents[node], parents);
}

void merge(int a, int b, unordered_map<int, int> &parents) {
  a = find(a, parents), b = find(b, parents);
  if (a > b) swap(a, b);
  parents[b] = a;
}

void choose(vector<vector<int>> &edges, unordered_set<int> &knows) {
  unordered_map<int, int> parents;

  for (vector<int> &e : edges) {
    int a = e[0], b = e[1];
    parents[a] = a;
    parents[b] = b;
  }
  for (vector<int> &e : edges) {
    int a = e[0], b = e[1];

    merge(a, b, parents);
  }
  for (vector<int> &e : edges) {
    int a = e[0], b = e[1];

    if (knows.count(a) > 0) {
      knows.insert(find(a, parents));
    }
    if (knows.count(b) > 0) {
      knows.insert(find(b, parents));
    }
  }
  for (vector<int> &e : edges) {
    int a = e[0], b = e[1];
    if (knows.count(find(a, parents))) {
      knows.insert(a);
      knows.insert(b);
    }
  }
}

vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                          int firstPerson) {
  sort(meetings.begin(), meetings.end(),
        [](auto &a, auto &b) { return a[2] < b[2]; });

  int time = 0;

  unordered_set<int> knows;
  knows.insert(0);
  knows.insert(firstPerson);

  vector<vector<int>> selected;

  for (vector<int> &m : meetings) {
    int a = m[0], b = m[1], t = m[2];

    if (t != time) {
      time = t;
      choose(selected, knows);
      selected.clear();
    }

    selected.push_back({a, b});
  }

  choose(selected, knows);
  selected.clear();

  vector<int> answer(knows.begin(), knows.end());
  sort(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
