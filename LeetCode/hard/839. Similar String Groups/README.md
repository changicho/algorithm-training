# 839. Similar String Groups

[링크](https://leetcode.com/problems/similar-string-groups/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 strs의 크기를 N, 각 str들의 길이를 L이라 하자.

두 단어가 비슷한지 판단하는 데 O(L)의 시간 복잡도로 비교가 가능하다.

따라서 모든 단어쌍들에 대해서 다른 단어로 변환 가능한지 비교를 진행할 경우 O(N^2 \* L)의 시간 복잡도가 소요된다.

이를 그래프로 나타낸다.

이후 각 단어마다 변환 가능한 단어들을 모두 탐색한 뒤 그룹의 수를 센다.

DFS, BFS를 이용해 진행할 경우 모든 간선의 갯수는 최대 N^2이다. 따라서 탐색을 진행하며 O(N^2)의 시간 복잡도를 사용한다.

유니온 파인드를 이용할 경우 각 단어마다 변환 가능한 단어들에 대해 유니온 파인드를 사용한다. 이 경우 merge에 상수만큼의 시간복잡도를 사용한다고 했을 때 총 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프를 표현하는 데 O(N^2 * L)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     491      | O(N^2 * L)  | O(N^2 * L)  |

입력받은 단어들 중 중복을 제거한다.

이후 남은 단어들에 대해서 다른 단어들로 변환 가능한지 판단한다.

이를 그래프로 생성한다.

이후 그래프를 이용해 연결된 노드들을 merge 시킨 후 남은 그룹의 갯수를 센다.

```cpp
bool isSimilar(string &a, string &b) {
  if (a.size() != b.size()) return false;

  int diffCount = 0;
  int size = a.size();
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) diffCount++;
  }
  return diffCount == 2;
}

unordered_map<string, string> parents;
int groupCount = 0;
string find(string &node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(string a, string b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (a > b) swap(a, b);

  parents[b] = a;
  groupCount--;
}

int numSimilarGroups(vector<string> &strs) {
  unordered_set<string> words(strs.begin(), strs.end());

  int size = words.size();
  unordered_map<string, vector<string>> graph;

  for (string from : words) {
    for (string to : words) {
      if (from == to) continue;
      if (!isSimilar(from, to)) continue;

      graph[from].push_back(to);
      graph[to].push_back(from);
    }
  }

  for (string word : words) {
    parents[word] = word;
  }
  groupCount = size;

  for (string word : words) {
    for (string next : graph[word]) {
      merge(word, next);
    }
  }

  return groupCount;
}
```

## 고생한 점
