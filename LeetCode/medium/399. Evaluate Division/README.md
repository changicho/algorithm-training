# 399. Evaluate Division

[링크](https://leetcode.com/problems/evaluate-division/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연결 관계의 개수를 N, 쿼리의 개수를 M이라 하자.

유니온 파인드를 이용할 경우 내부적으로 find를 사용할 때 O(log_2(N))의 시간 복잡도를 사용한다.

이를 연결 관계와 쿼리 모두에 사용해야 하므로 시간 복잡도는 O((N + M) \* log_2(N))이다.

DFS와 메모이제이션을 이용할 경우 각 쿼리마다 최악의 경우 모든 노드를 방문할 수 있다. (모든 연결 관계)

따라서 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

최악의 경우 연결 관계의 개수 - 1이 노드의 개수가 된다.

유니온 파인드를 이용할 경우 O(N)의 공간 복잡도를 사용한다.

DFS를 사용할 경우 메모이제이션에 O(N)의 공간 복잡도를 사용한다. (연결 관계에 있는 경우만 탐색하므로)

### 유니온 파인드

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      0       | O((N + M) \* log_2(N)) |    O(N)     |

각 노드에는 부모와 값 두가지 자료를 가지고 있어야 한다.

```cpp
struct Node {
  string parent;
  double value;
};
```

이후 merge 마다 value를 같이 갱신해준다.

equations를 순회할 때 노드들을 초기화 해주고 연결 관계와 값을 부여한다.

이후 query시에 같은 그룹에 없거나 equation에 없던 노드인 경우 -1을 반환한다.

```cpp
unordered_map<string, Node> data;

string find(string key, double &value) {
  while (data[key].parent != key) {
    value = value * data[key].value;
    key = data[key].parent;
  }

  return key;
}

void merge(string a, string b, double v) {
  double valueA = 1.0, valueB = 1.0;
  string parentA = find(a, valueA), parentB = find(b, valueB);

  if (parentA == parentB) return;
  data[parentA].parent = parentB;
  data[parentA].value = v * valueB / valueA;
}

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries) {
  for (int i = 0; i < equations.size(); i++) {
    string a = equations[i][0], b = equations[i][1];
    double value = values[i];

    if (!data.count(a)) {
      data[a].parent = a;
      data[a].value = 1;
    }

    if (!data.count(b)) {
      data[b].parent = b;
      data[b].value = 1.0;
    }

    merge(a, b, value);
  }

  vector<double> answer;
  for (vector<string> &query : queries) {
    if (!data.count(query[0]) || !data.count(query[1])) {
      answer.push_back(-1);
      continue;
    }

    double valueA = 1, valueB = 1;
    string parentA = find(query[0], valueA), parentB = find(query[1], valueB);

    if (parentA != parentB) {
      answer.push_back(-1);
    } else {
      answer.push_back(valueA / valueB);
    }
  }
  return answer;
}
```

### DFS + memoization

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* M)  |    O(N)     |

각 쿼리마다 시작점에서 끝점까지 방문하며 value를 정답에 삽입한다.

이 때 이미 이전에 방문했던 노드에 대해서는 다시 방문처리를 하지 않는다. (백트래킹과 value의 갱신에 오류가 있을 수 있으므로)

이는 사이클이 발생할 시에 value를 제대로 갱신할 수 없기 때문이다.

```cpp
unordered_map<string, unordered_map<string, double>> memo;

double recursive(string from, string to, unordered_set<string> &visited) {
  if (memo[from].find(to) != memo[from].end()) return memo[from][to];

  double ret = 0;
  for (pair<const string, double> &next : memo[from]) {
    if (visited.find(next.first) != visited.end()) continue;
    visited.insert(next.first);

    double value = recursive(next.first, to, visited);

    if (value == 0) continue;

    ret = next.second * value;
    break;
  }
  return ret;
}

vector<double> calcEquation(vector<vector<string>> &equations,
                            vector<double> &values,
                            vector<vector<string>> &queries) {
  vector<double> answer;
  for (int i = 0; i < values.size(); ++i) {
    double value = values[i];
    string from = equations[i][0], to = equations[i][1];

    memo[from].insert({to, value});
    if (value == 0) continue;

    memo[to].insert({from, 1 / value});
  }

  for (vector<string> &query : queries) {
    string &from = query[0], &to = query[1];

    unordered_set<string> visited;
    double diff = recursive(from, to, visited);

    if (diff) {
      answer.push_back(diff);
    } else {
      answer.push_back(-1);
    }
  }
  return answer;
}
```

## 고생한 점

연결 관계까지는 생각할 수 있었지만, value를 갱신하는 부분이 어려웠다.
