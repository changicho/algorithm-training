# 1026. Maximum Difference Between Node and Ancestor

[링크](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

각 노드마다 다른 부모 노드와의 차이중 가장 큰 값을 구해야 한다.

재귀호출로 탐색하고 과정마다 부모의 값들을 모두 넘기고 현재 값과의 차이를 계산해 반환할 경우 O(N^2)의 시간 복잡도를 사용한다.

재귀호출로 탐색하며 직전까지 방문한 최대값, 최소값들을 넘기며 탐색할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀호출로 탐색할 경우 call stack에 O(N)의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(N)     |

각 값들의 차이가 최대가 될 경우는 다음 경우중 한가지 이다.

- 직전까지 방문한 값들 중 최대값과 현재 값의 차이
- 직전까지 방문한 값들 중 최솟값과 현재 값의 차이

이를 이용해 자식 노드를 탐색할 때마다 최대값과 최소값들을 갱신해주고 이를 이용해 현재 값과의 차이중 최대를 구한다.

이를 구현하면 다음과 같다.

```cpp
int beforeMax, beforeMin;
int answer = INT_MIN;

void recursive(TreeNode *node) {
  if (!node) return;
  int tempMax = beforeMax, tempMin = beforeMin;
  int val = node->val;

  answer = max({answer, abs(val - beforeMax), abs(val - beforeMin)});

  beforeMax = max(beforeMax, val);
  beforeMin = min(beforeMin, val);

  if (node->left) recursive(node->left);
  if (node->right) recursive(node->right);

  beforeMax = tempMax, beforeMin = tempMin;
}

int maxAncestorDiff(TreeNode *root) {
  beforeMax = root->val, beforeMin = root->val;
  recursive(root);

  return answer;
}
```

## 고생한 점
