# 96. Unique Binary Search Trees

[링크](https://leetcode.com/problems/unique-binary-search-trees/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N은 최대 19까지이다. 1부터 N까지의 숫자를 순서대로 삽입해 BST를 만든다고 했을 때 모든경우를 수행하는경우 시간 복잡도는 O(N!)이므로 제한시간 내에 불가능하다.

따라서 분할 정복기법 & 동적 계획법을 이용해 문제를 해결한다.

이 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

i번째 노드를 루트 노드로 했을 때 왼쪽에는 i - 1개의 노드가, 오른쪽에는 N - i개의 노드가 서브 트리를 만든다.

dp 배열로 노드의 개수에 따른 BST의 개수를 저장한다고 했을 때 필요한 공간은 O(N)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^2)    |    O(N)     |

dp의 일반식을 다음과 같이 설정한다.

```cpp
dp[node]; // 노드가 node개일 때 만들 수 있는 BST의 갯수
```

현재 노드의 개수가 number일때 dp값은 다음과 같다.

```cpp
dp[number] = 0;
for (int center = 1; center <= number; center++) {
  dp[number] += dp[center - 1] * dp[number - center];
}
```

초기값은 다음과 같다.

```cpp
dp[0] = 1;
dp[1] = 1;
```

이를 이용해 bottom-up방식과 top-down방식 모두 만들 수 있다.

먼저 bottom-up 방식의 경우 일반식과 동일한 방식으로 반복문을 돌려 dp 배열을 채운다.

```cpp
int numTrees(int n) {
  int dp[20] = {0};
  dp[0] = dp[1] = 1;

  for (int number = 2; number <= n; number++) {
    for (int center = 1; center <= number; center++) {
      dp[number] += dp[center - 1] * dp[number - center];
    }
  }

  return dp[n];
}
```

top-down 방식의 경우 다음과 같다.

```cpp
int dp[20] = {0};
int numTrees(int n) {
  return recursive(1, n);
}

int recursive(int from, int to) {
  if (from > to) return 1;
  if (from == to) return 1;
  if (dp[to - from] != 0) return dp[to - from];
  int count = 0;

  for (int root = from; root <= to; root++) {
    int leftCount = recursive(from, root - 1);
    int rightCount = recursive(root + 1, to);

    count += leftCount * rightCount;
  }

  return dp[to - from] = count;
}
```

## 고생한 점
