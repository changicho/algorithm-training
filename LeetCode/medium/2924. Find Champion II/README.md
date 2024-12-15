# 2924. Find Champion II

[링크](https://leetcode.com/problems/find-champion-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N, 간선의 갯수를 E라 하자.

각 간선을 순회하며 진입차수를 센다. 이후 진입차수가 0인 노드를 찾아야 한다.

이에 O(N + E)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 노드마다 진입차수를 저장하는데 O(N)의 공간 복잡도가 필요하다.

### 진입 차수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + E)   |    O(N)     |

각 간선을 순회하며 진입차수를 센다.

진입차수가 0인 노드는 다른 노드에 패배하지 않는 노드이다.

해당 노드가 1개인 경우 해당 노드가 정답이다. 이외의 경우에는 정답이 없다.

```cpp
int findChampion(int n, vector<vector<int>>& edges) {
  vector<int> inDegrees(n, 0);

  for (vector<int>& e : edges) {
    int from = e[0], to = e[1];

    inDegrees[to]++;
  }

  int answer = -1;
  for (int i = 0; i < n; i++) {
    if (inDegrees[i] == 0) {
      if (answer != -1) return -1;
      answer = i;
    }
  }
  return answer;
}
```

## 고생한 점
