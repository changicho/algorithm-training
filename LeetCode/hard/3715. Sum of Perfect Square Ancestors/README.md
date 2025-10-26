# 3715. Sum of Perfect Square Ancestors

[링크](https://leetcode.com/problems/sum-of-perfect-square-ancestors/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N, 간선의 수를 N-1, 숫자의 최대값을 M이라 하자.

그래프를 생성하는데 O(N)의 시간 복잡도를 사용한다.

에라토스테네스의 채를 이용해 소수를 구하는 데 O(M \* log_2(log_2(M)))의 시간 복잡도를 사용한다. 이는 거의 O(M)이다.

이후 DFS를 이용해 트리부터 특정 노드까지의 path를 탐색하며, 각 과정에서 현재 소인수분해한 수가 이전에 나타나는 경우 두 수의 곱은 제곱수가 되므로 정답을 증가시킨다.

DFS를 이용해 탐색하는데 O(N)의 시간 복잡도를 사용하며 각 과정마다 소인수분해에 O(sqrt(M))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* sqrt(M) + M)이 된다.

### 공간 복잡도

에라토스테네스의 채를 저장하는데 O(sqrt(M))의 공간 복잡도를 사용한다.

DFS에 O(N)의 공간 복잡도를 사용한다.

### DFS & 소인수 분해 & 에라토스테네스의 채

| 내 코드 (ms) |     시간 복잡도     |  공간 복잡도   |
| :----------: | :-----------------: | :------------: |
|     294      | O(N \* sqrt(M) + M) | O(N + sqrt(M)) |

현재 X를 소인수분해 하며, 이 때 1개인 소수로만 이루어진 수를 Y라고 하자.

만약 현재 노드의 조상 중 Y가 존재하는 경우 Y^2는 제곱수가 된다.

따라서 각 노드마다 소인수 분해를 통해 Y를 구하고 DFS를 통해 조상 노드 중 Y가 몇개 존재하는지 구하면 된다.

DFS로 탐색하며 정답을 증가시킨다.

```cpp
vector<int> primes;
vector<vector<int>> graph;

unordered_map<int, long long> count;

int getRemainPrime(int num) {
  int ret = 1;

  for (int& p : primes) {
    if (p > num) break;

    int count = 0;
    while (num % p == 0) {
      num /= p;
      count++;
    }

    if (count % 2 == 1) {
      ret *= p;
    }
  }

  return ret * num;
}

// sieve of eratosthenes
void init() {
  bool isNotPrime[1001] = {
      false,
  };

  int limit = sqrt(1e5);

  for (int i = 3; i <= limit; i += 2) {
    if (isNotPrime[i]) continue;

    for (int j = i + i; j <= limit; j += i) {
      isNotPrime[j] = true;
    }
  }

  primes.push_back(2);
  for (int i = 3; i <= limit; i += 2) {
    if (!isNotPrime[i]) primes.push_back(i);
  }
}

long long recursive(int node, int parent, vector<int>& nums) {
  int primes = getRemainPrime(nums[node]);

  long long ret = count[primes];

  count[primes]++;
  for (int& next : graph[node]) {
    if (next == parent) continue;

    ret += recursive(next, node, nums);
  }
  count[primes]--;
  return ret;
}

long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
  init();

  graph.resize(n);

  for (vector<int>& e : edges) {
    int a = e[0], b = e[1];

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  long long answer = recursive(0, -1, nums);

  return answer;
}
```

## 고생한 점
