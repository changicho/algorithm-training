# 1120. Maximum Average Subtree

[링크](https://leetcode.com/problems/maximum-average-subtree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

재귀호출을 이용해 현재노드를 서브트리의 루트로 하는 경우의 합과 노드의 수를 구할 수 있다.

해당 호출의 반환값들을 이용해 정답을 갱신할 경우 재귀호출에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀호출에 O(N)의 공간 복잡도가 필요하다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(N)     |

재귀호출의 반환값을 현재 노드를 루트로 하는 서브트리의 합과 노드의 수로 설정한다.

이 경우 현재 노드에서 자식노드들에 대해 재귀호출을 수행 후, 각 합들과 노드의 수를 이용해 현재 평균을 구할 수 있다.

이를 반복해 정답을 갱신한다.

```cpp
double answer = 0;

pair<int, long long> recursive(TreeNode *node) {
  int count = 1;
  long long sum = node->val;

  if (node->left) {
    auto ret = recursive(node->left);
    count += ret.first;
    sum += ret.second;
  }
  if (node->right) {
    auto ret = recursive(node->right);
    count += ret.first;
    sum += ret.second;
  }

  answer = max(answer, (double)sum / count);
  return {count, sum};
}

double maximumAverageSubtree(TreeNode *root) {
  if (root) recursive(root);

  return answer;
}
```

## 고생한 점
