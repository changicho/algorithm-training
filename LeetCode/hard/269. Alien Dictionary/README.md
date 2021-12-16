# 269. Alien Dictionary

[링크](https://leetcode.com/problems/alien-dictionary/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

words의 개수를 N, 최장 단어의 길이를 L, words의 단어의 길이의 합을 S라 하자.

두 단어 사이에서 특정 문자의 우선관계를 파악하는데 O(L)의 시간 복잡도가 사용된다.

주어진 배열이 만약 특정 순서로 정렬되어있다면, 인접한 두 단어들을 비교하며 특정 문자들에 대한 우선순위 관계 (단방향 그래프)를 O(L)의 시간 복잡도로 알 수 있다.

이를 모든 문자에 대해서 반복하면 시간 복잡도는 O(S)가 된다. (N \* L)

이후 해당 단방향 그래프로 위상정렬을 사용해 사이클이 생기는 지 여부를 판단할 수 있다.

이 경우 간선의 개수는 최대 N가 될 수 있다. (인접한 두 단어 사이에 연결관계가 하나만 나올 수 있음)

이 경우 위상 정렬에 시간 복잡도는 O(N + N)가 되며 최종 시간 복잡도는 O(S)이 된다.

### 공간 복잡도

위상 정렬을 사용하기 위해 그래프를 생성할 경우 공간 복잡도는 O(N)이 된다. (간선의 개수는 최대 N 이므로 V + E = 2N)

위상 정렬에 큐를 사용하며 큐는 unique한 문자들에 대해서 순회하므로 최대 O(N)의 공간 복잡도를 사용한다.

따라서 O(N)의 공간 복잡도를 사용한다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(S)     |    O(N)     |

각 인접한 단어들을 순회하며 그래프를 만든다.

이 때 만약 i번째 단어와 i+1번째 단어가 앞에서부터 똑같고 i번째 단어의 길이가 더 긴 경우는, 문제에서 주어진 정렬 관계에 어긋나므로 예외 처리한다.

이후 각 그래프에서 진입차수가 0인 노드부터 큐에 담아 위상정렬을 수행한다.

만약 모든 노드를 방문하기 전에 위상 정렬이 끝난 경우 사이클이 존재하는 것이므로 정답을 생성하는것이 불가능하다.

위상정렬시 문자의 순서는 진입차수가 낮은 순서로 방문하므로 우선순위가 높은 문자가 맨 뒤에 위치한다.

이를 뒤집어 반환한다.

```cpp
unordered_map<char, unordered_set<char>> graph;
unordered_map<char, unordered_set<char>> reverseGraph;
unordered_map<char, int> inDegree;

bool canMakeAnswer = true;

void findDiff(string a, string b) {
  int length = min(a.length(), b.length());
  for (int i = 0; i < length; i++) {
    if (a[i] != b[i]) {
      graph[b[i]].insert(a[i]);
      reverseGraph[a[i]].insert(b[i]);
      return;
    }
  }
  // edge case
  if (a.length() > b.length()) canMakeAnswer = false;
}

string alienOrder(vector<string> &words) {
  unordered_set<char> uniqueChars;

  int size = words.size();
  // initialize
  for (string &word : words) {
    for (char c : word) {
      uniqueChars.insert(c);
      inDegree[c] = 0;
      graph[c];
    }
  }

  for (int i = 0; i < size - 1; i++) {
    findDiff(words[i], words[i + 1]);
  }
  if (!canMakeAnswer) return "";

  for (auto &it : reverseGraph) {
    inDegree[it.first] = it.second.size();
  }

  queue<char> q;
  // push all inDegree 0 node to q;
  for (auto &it : inDegree) {
    if (it.second == 0) {
      q.push(it.first);
    }
  }

  string answer = "";
  while (!q.empty()) {
    char cur = q.front();
    q.pop();

    answer += cur;

    for (char next : graph[cur]) {
      inDegree[next]--;

      if (inDegree[next] == 0) {
        q.push(next);
      }
    }
  }

  if (answer.length() != uniqueChars.size()) return "";

  reverse(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
