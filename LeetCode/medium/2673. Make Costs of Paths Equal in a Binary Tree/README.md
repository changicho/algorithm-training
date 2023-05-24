# 2673. Make Costs of Paths Equal in a Binary Tree

[링크](https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자.

루트노드에서 부터 각 리프노드까지의 합을 구하는 데 O(N)의 시간 복잡도를 사용한다.

이후 각 합에서 부족한 부분을 채울 때 중복되는 부분이 있을 수 있다.

이를 위해 구간에 대해 분할 정복을 이용할 수 있다. 이 경우 총 O(N * log_2(N))의 시간 복잡도를 사용한다.

리프노드에서 부터 순회하며 각 자식노드들과의 차이를 더해 루트까지 순회할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

리프노드까지의 합의 갯수는 N/2개 이다. 따라서 O(N)의 시간 복잡도를 사용한다.

리프노드부터 순회할 경우 O(1)의 공간 복잡도를 사용한다.

### 분할 정복

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     309      | O(N * log_2(N)) |    O(N)     |

루트노드에서부터 리프노드까지의 합을 구한다.

해당 합들은 총 N/2개가 존재한다.

각 합들 중의 최대값을 구하고, 다른 합들을 최대값에 맞춰 부족한만큼 더하는 경우가 최소 비용이다.

이 때 특정 노드에 값을 더할 경우 자식노드 모두에 영향이 간다.

따라서 자식을 가진 특정 노드의 경우, 해당 노드를 거치는 리프까지의 경로들이 존재할 때 총 합이 최대값을 넘지 않도록 가능한 최소값을 더해야한다.

이는 다음과 같다.

- 최대값을 M이라 하자.
- 리프노드까지의 합의 집합을 S라 하자.
- 합의 집합 중 가장 큰 값을 M`라 하자.
- 현재 노드에 M-M` 만큼 더한다. 이를 D라 하자.
- 이 경우 S의 값들에 모두 D를 더한다.
- S의 값들은 M을 초과하지 않는다.

이를 루트노드에서부터 리프노드까지 반복한다. 이는 분할정복으로 구현한다.

```cpp
vector<int> cost;
vector<int> costSums;
int answer = 0;

bool isLeaf(int node, int limit) { return node * 2 > limit; }

void recursive(int node, int limit, int costSum) {
  costSum += cost[node - 1];

  if (isLeaf(node, limit)) {
    costSums.push_back(costSum);
    return;
  }

  recursive(node * 2, limit, costSum);
  recursive(node * 2 + 1, limit, costSum);
}

void divide(int left, int right, int maximum) {
  int curMax = 0;
  for (int i = left; i <= right; i++) {
    int costSum = costSums[i];

    curMax = max(curMax, costSum);
  }

  int diff = maximum - curMax;

  answer += diff;
  for (int i = left; i <= right; i++) {
    costSums[i] += diff;
  }

  if (left == right) return;

  int mid = left + (right - left) / 2;

  divide(left, mid, maximum);
  divide(mid + 1, right, maximum);
}

int minIncrements(int n, vector<int>& cost) {
  this->cost = cost;

  recursive(1, n, 0);

  int maximum = 0;
  for (int& costSum : costSums) {
    maximum = max(maximum, costSum);
  }

  divide(0, costSums.size() - 1, maximum);

  return answer;
}
```

### 역순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     244      |    O(N)     |    O(1)     |

리프노드에서부터 루트노드까지 역순으로 노드를 순회한다.

이 때 자식노드들의 값들을 비교하며 두 값의 차이만큼 정답에 더한다.

이후 현재 노드의 값에 자식노드들 중 큰 값을 더한다.

이 과정에서 값이 작은 자식쪽에 큰 자식의 값과의 차이를 더해 두 값을 같게 만들 수 있다.

```cpp
int minIncrements(int n, vector<int>& cost) {
  int answer = 0;

  for (int node = n; node >= 0; node--) {
    int left = node * 2 + 1, right = node * 2 + 2;

    // leaf node case
    if (left >= n) continue;

    int diff = abs(cost[left] - cost[right]);

    // make left and right node's cost equal
    // and increase answer
    answer += diff;
    if (cost[left] < cost[right]) {
      cost[left] += diff;
    } else if (cost[left] > cost[right]) {
      cost[right] += diff;
    }

    cost[node] += cost[left];
  }
  return answer;
}
```

## 고생한 점
