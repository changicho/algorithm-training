# 433. Minimum Genetic Mutation

[링크](https://leetcode.com/problems/minimum-genetic-mutation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 bank의 크기를 N이라 하자.

startGene에서 BFS를 이용해 endGene까지 탐색할 수 있다.

이 경우 두개의 gene이 돌연변이 관계인지 판단하는데 O(1)의 시간 복잡도를 사용한다.

현재 gene에서 다음 방문할 gene을 탐색하는 데 bank를 순회할 경우 O(N)의 시간 복잡도를 사용한다.

이때 가장 빠른 길이를 찾아야 하므로 이미 한번 방문한 gene은 방문하지 않아도 된다.

각 노드를 방문하는데 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

방문 여부를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

startGene부터 시작하는 BFS 탐색을 진행한다.

이 과정에서 endGene에 도달한 경우 종료한다.

이 때 이동 가능한 경우는 bank에 존재하는 경우만이다.

```cpp
bool isMutation(string &a, string &b) {
  int diffCount = 0;
  for (int i = 0; i < 8; i++) {
    if (a[i] != b[i]) diffCount++;
  }
  return diffCount == 1;
}

int minMutation(string startGene, string endGene, vector<string> &bank) {
  queue<string> q;
  unordered_set<string> visited;
  q.push(startGene);
  int step = 0;
  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      string cur = q.front();
      q.pop();

      if (visited.count(cur) > 0) continue;
      visited.insert(cur);

      if (cur == endGene) {
        return step;
      }

      for (string &next : bank) {
        if (!isMutation(cur, next)) continue;

        q.push(next);
      }
    }

    step++;
  }

  return -1;
}
```

## 고생한 점
