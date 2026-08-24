# 4015. Weighted Sum of a Tree

[링크](https://leetcode.com/problems/weighted-sum-of-a-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 수를 N 간선의 수를 N-1이라 하자.

루트 노드부터 탐색하며 트리의 전체 높이와 각 노드마다 점수를 생신한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

트리를 탐색하는데 최대 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     129      |    O(N)     |    O(N)     |

연결 구조를 사용해 그래프를 생성 후 루트 노드부터 탐색을 진행한다.

이 때 각 노드마다 점수 식은 다음과 같다.

- `nums[i] * (h - d + 1)`

이 식을 변형하면

- `nums[i] * h - nums[i] * d + nums[i]`

가 되므로 이를 나눠서 계산한다.

트리의 높이를 탐색 하며 구한 뒤 정답에 더하고 트리 탐색을 진행하면서는 깊이와 노드의 값을 이용해 정답에 더한다.

```cpp
long long weightedSum(vector<int>& parent, vector<int>& nums) {
  int size = parent.size();
  vector<vector<int>> graph(size + 1);

  long long sum = nums[0];
  for (int i = 1; i < size; i++) {
    sum += nums[i];

    int p = parent[i];

    graph[p].push_back(i);
  }

  long long answer = 0;
  queue<int> q;
  q.push(0);
  long long d = 1;
  while (!q.empty()) {
    int qSize = q.size();

    while (qSize--) {
      int cur = q.front();
      q.pop();

      answer += nums[cur] - nums[cur] * d;
      for (int& c : graph[cur]) {
        q.push(c);
      }
    }

    d++;
  }

  answer += sum * (d - 1);
  return answer;
}
```

## 고생한 점
