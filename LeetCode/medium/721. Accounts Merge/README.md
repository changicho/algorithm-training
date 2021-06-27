# 721. Accounts Merge

[링크](https://leetcode.com/problems/accounts-merge/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 이메일의 수를 N이라고 하자.

각각을 집합이라고 생각하자.

일반적으로 두 집합을 합칠 때 매번 합칠 경우 시간 복잡도는 N이다.

이 때 합쳐야 할 집합을 찾는데 N번의 연산이 필요하다.

이를 모든 계정정보에 대해서 수행해야 하므로 브루트 포스 방법을 사용할 경우 시간 복잡도는 O(N^3) 이다.

분리된 집합들을 합칠 때 union find를 이용할 수 있다.

이 경우 시간 복잡도는 두 집합을 합칠 때 O(a(N)) 이며 이는 애커만 상수이므로 거의 상수이다.

따라서 모든 집합에 대해서 연산을 수행하면 되므로 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

유니온 파인드를 사용할 경우 각 노드마다의 부모 노드를 알아야 한다.

따라서 공간 복잡도는 O(N)이다.

### 정리

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     160      | O(N \* log_2(N)) |    O(N)     |

우선 사용자의 이름별로 구분지을 수 있다.

이후 입력되는 사용자와 이메일 정보를 바탕으로 merge를 수행한다.

이 때 기존에 모든 이메일을 대상으로 부모를 초기화 하는 연산 대신, 중복되는 이메일이 아닌 경우에만 초기화를 수행하고 이전에 나온 합칠 수 있는 이메일의 경우 기존 parent와 merge를 수행한다.

이후에 부모 별로 그룹들을 다시 나눈다.

이후 자료들을 정답에 맞게 정렬해 반환한다.

```cpp
string find(unordered_map<string, unordered_map<string, string>>& parents, string& name, string& email) {
  if (parents[name][email] == email) return email;

  return parents[name][email] = find(parents, name, parents[name][email]);
}

void merge(unordered_map<string, unordered_map<string, string>>& parents, string& name, string& email1, string& email2) {
  string parent1 = find(parents, name, email1);
  string parent2 = find(parents, name, email2);

  if (parent1 == parent2) return;
  if (parent1 > parent2) swap(parent1, parent2);

  parents[name][parent2] = parent1;
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
  unordered_map<string, unordered_map<string, string>> parents;
  vector<vector<string>> answer;

  // merge by group
  for (vector<string> account : accounts) {
    int size = account.size();
    string name = account.front();
    string parent = account[1];

    for (int i = 1; i < size; i++) {
      if (parents[name].find(account[i]) != parents[name].end()) {
        string emailParent = parents[name][account[i]];
        merge(parents, name, account[i], emailParent);
      } else {
        parents[name][account[i]] = account[i];
      }
      merge(parents, name, parent, account[i]);
    }
  }

  // divide by parents
  unordered_map<string, unordered_map<string, vector<string>>> groupByParents;
  for (auto& it : parents) {
    string name = it.first;

    for (auto& it2 : it.second) {
      string parent = find(parents, name, it2.second);

      groupByParents[name][parent].push_back(it2.first);
    }
  }

  // make answer
  for (auto& it : groupByParents) {
    string name = it.first;

    for (auto& it2 : it.second) {
      vector<string> line;
      line.push_back(name);

      for (string email : it2.second) {
        line.push_back(email);
      }

      sort(line.begin() + 1, line.end());
      answer.push_back(line);
    }
  }

  return answer;
}
```

## 고생한 점
