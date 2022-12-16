# 알고스팟. 두니발 박사의 탈옥

[링크](https://www.algospot.com/judge/problem/read/NUMB3RS)

| 정답률 |
| :----: |
|  41%   |

## 설계

### 시간 복잡도

마을의 갯수를 N, 지난 일수를 D라 하자.

각 마을들은 다른 마을들과 연결되어 있을 수 있으므로 (간선), 모든 마을을 이동하는 경우를 순회하는 데 O(N^2)의 시간 복잡도를 사용한다.

이를 모든 경우를 BFS로 순회하면 매우 많은 시간이 걸리므로, 각 마을에서 다른 마을로 이동하는 경우를 동적 계획법을 이용해 탐색한다.

이 경우 각 마을에서 다른 마을로 이동할 확률을 계산하고 넘기는 데 O(N^2)의 시간 복잡도를 사용한다.

이를 D일 반복하므로 총시간 복잡도는 O(D \* N^2)가 된다.

### 공간 복잡도

동적 계획법을 사용할 경우, 각 마을의 각 일마다의 확률을 구해야 한다.

이는 O(N \* D)의 공간 복잡도를 사용한다.

각 과정에서 직전 dp값만 사용하므로 O(N)의 공간 복잡도를 사용하도록 최적화 할 수 있다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     16ms     | O(D \* N^2) |    O(N)     |

[백준.본대 산책](https://www.acmicpc.net/problem/12849)과 유사한 문제. 확률을 계속 넘겨줘야 하는점이 달랐다.

각 마을에서 다른 마을로 넘어갈 때, 다른 마을로 넘어갈 확률은 다음과 같다.

- (현재 마을에 있을 확률) / (연결된 다른 마을의 수)

이를 이용해 각 마을들에서 다른 마을들로 이동하는 확률들을 모두 계산하고 갱신한다.

이를 반복해 각 마을들에 존재활 확률을 구한다.

```cpp
vector<double> solution(int size, vector<vector<bool>> &graph, int day, int start, vector<int> &targets) {
  vector<double> counts(size, 0);
  counts[start] = 1;

  while (day--) {
    vector<double> curCounts(size, 0);

    for (int from = 0; from < size; from++) {
      double allCaseCount = 0;
      for (int to = 0; to < size; to++) {
        if (graph[from][to]) allCaseCount++;
      }

      for (int to = 0; to < size; to++) {
        if (!graph[from][to]) continue;

        curCounts[to] += counts[from] / allCaseCount;
      }
    }

    counts = curCounts;
  }

  vector<double> answer;
  for (int &target : targets) {
    answer.push_back(counts[target]);
  }
  return answer;
}
```

## 고생한 점
