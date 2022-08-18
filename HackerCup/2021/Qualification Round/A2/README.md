# Problem A2: Consistency - Chapter 2

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2021/qualification-round/problems/A2)

| 난이도 |
| :----: |
| 17 pt  |

## 설계

### 시간 복잡도

문자열의 길이를 N, 간선의 갯수를 K라 하자.

우선 간선을 순회하며 그래프를 만든다.

이후 플로이드 와샬 알고리즘을 이용해 각 문자에서 다른 문자들 까지의 가장 짧은 거리를 모두 계산한다.

문자(노드)의 갯수는 26개이므로 이에 O(26^3) = O(1)의 시간 복잡도를 사용한다.

각 문자들의 갯수를 count하고, 이후 target문자를 'A' ~ 'Z'로 순회하며 cost를 모두 계산해본다.

이 count에 O(N)의 시간 복잡도를 사용한다.

이후 target을 지정하고 cost를 계산하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프를 구성하는데 O(K)의 공간 복잡도를, cost를 지정하는데 O(1)의 공간 복잡도를 사용한다.

### 브루트 포스 + 플로이드 와샬

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + K)   |    O(K)     |

각 글자에서 다른 글자까지의 최소 비용을 모두 계산한다. (플로이드 와샬 알고리즘 이용)

이후 각 글자의 수를 count하고, target문자열을 순회하며 다른 문자들을 target으로 바꿧을 때의 cost를 모두 더한다. 이중 최소값을 구한다.

이 때 정답을 생성하는 경우가 불가능 할 수 있으므로 이를 구별한다.

```cpp
int solution(string &s, unordered_set<string> &edges) {
  int length = s.length();
  long costs[256][256] = {
      INT_MAX,
  };
  vector<vector<char>> graph(256);
  unordered_map<char, int> counts;

  for (char from = 'A'; from <= 'Z'; from++) {
    for (char to = 'A'; to <= 'Z'; to++) {
      costs[from][to] = from == to ? 0 : INT_MAX;
    }
  }
  for (string edge : edges) {
    char from = edge.front();
    char to = edge.back();

    graph[from].push_back(to);
    costs[from][to] = 1;
  }

  for (char &c : s) {
    counts[c]++;
  }

  for (char through = 'A'; through <= 'Z'; through++) {
    for (int from = 'A'; from <= 'Z'; from++) {
      for (int to = 'A'; to <= 'Z'; to++) {
        costs[from][to] =
            min(costs[from][to], costs[from][through] + costs[through][to]);
      }
    }
  }

  int answer = INT_MAX;
  for (char target = 'A'; target <= 'Z'; target++) {
    int curCost = 0;
    bool canConvert = true;
    for (auto &it : counts) {
      char c = it.first;
      int count = it.second;

      if (c == target) continue;

      if (costs[c][target] == INT_MAX) {
        canConvert = false;
        break;
      }
      curCost += costs[c][target] * count;
    }

    if (!canConvert) continue;
    answer = min(answer, curCost);
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
