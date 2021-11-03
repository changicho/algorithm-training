# 1202. Smallest String With Swaps

[링크](https://leetcode.com/problems/smallest-string-with-swaps/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자 s의 길이를 V, 연결 관계의 수를 E라고 하자. (정점의 개수, 간선의 개수)

pairs를 순회하며 문자들을 group으로 만들어야 한다.

pair의 순회에 O(E)의 시간 복잡도를 사용하고, 내부적으로 merge연산을 수행할 때 O(a(1))의 시간 복잡도를 사용한다.

이후 가장 사전순으로 빠른 문자를 만들기 위해 group내부의 문자들을 정렬해야 한다. 이 연산에 O(V \* log_2(V))만큼의 시간 복잡도를 사용한다.

이후 각 group을 순회하며 문자열들이 위치한 자리에 정렬된 문자들을 순차적으로 배치한다. (가장 빠른 순서가 되도록)

이 경우 시간 복잡도는 O(V \* log_2(V))가 된다.

### 공간 복잡도

모든 글자들을 parent에 대해서 그룹으로 묶어야 한다.

결과적으로 O(V)의 공간을 그룹핑하는데 사용한다.

### 유니온 파인드 & 우선순위 큐 & 해시맵

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     148      | O(V \* log_2(V)) |    O(V)     |

유니온 파인드를 이용해 문자들을 group으로 만든다.

이후 hash map을 사용해 각 group에 대해서 find연산을 통해 바로 접근할 수 있도록 구성한다.

이 값들을 모두 정렬한 후에 새로운 문자열을 만든다.

혹은 정렬을 이후에 수행하는 대신 우선순위 큐를 이용해 정렬된 순서가 보장된 상태로 저장되도록 구성한다.

이후 같은 방법으로 s를 순회하며 각 문자들을 속한 그룹에서 가장 빠른 문자로 치환한다.

```cpp
vector<int> parents;
vector<int> counts;

int find(int node) {
  if (parents[node] == node) return node;

  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  int parentA = find(a), parentB = find(b);
  if (parentA == parentB) return;

  if (parentA > parentB) swap(parentA, parentB);
  if (counts[parentA] < counts[parentB]) swap(parentA, parentB);

  parents[parentB] = parentA;
  counts[parentA] += counts[parentB];
}

string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
  int length = s.length();

  parents.resize(length);
  counts.resize(length, 1);

  for (int i = 0; i < length; i++) {
    parents[i] = i;
  }

  for (vector<int>& pair : pairs) {
    int first = find(pair[0]), second = find(pair[1]);

    merge(first, second);
  }

  unordered_map<int, priority_queue<char, vector<char>, greater<char>>> um;
  for (int i = 0; i < length; i++) {
    int key = find(i);
    char value = s[i];

    um[key].push(value);
  }

  string answer(length, ' ');
  for (int i = 0; i < length; i++) {
    int key = find(i);
    answer[i] = um[key].top();
    um[key].pop();
  }

  return answer;
}
```

### 유니온 파인드 & 정렬 & 해시맵

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     144      | O(V \* log_2(V)) |    O(V)     |

group에 문자 대신 문자의 index를 집어넣는다. (오름차순으로 삽입됨)

이후 각 group을 순회하면서 문자의 index별로 해당 group에서 가장 빠른 문자부터 집어넣는다.

```cpp
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
  int length = s.length();

  parents.resize(length);
  counts.resize(length, 1);
  for (int i = 0; i < length; i++) {
    parents[i] = i;
  }

  for (vector<int>& pair : pairs) {
    int first = find(pair[0]), second = find(pair[1]);

    merge(first, second);
  }
  string answer(length, ' ');
  unordered_map<int, vector<int>> um;

  for (int i = 0; i < length; i++) {
    int key = find(i);
    int value = i;

    um[key].emplace_back(value);
  }

  for (auto& it : um) {
    int key = find(it.first);
    vector<int> array = it.second;

    string line = "";
    for (int& i : array) {
      line += s[i];
    }
    sort(line.begin(), line.end());

    int index = 0;
    for (int i : array) {
      answer[i] = line[index];
      index++;
    }
  }

  return answer;
}
```

## 고생한 점
