# 979. Distribute Coins in Binary Tree

[링크](https://leetcode.com/problems/distribute-coins-in-binary-tree/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

재귀 호출을 이용해 현재 노드에서 더 남거나 부족한 코인의 갯수를 반환하며 계산할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀 호출에 O(N)의 공간 복잡도를 사용한다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

현재 노드가 루트인 서브트리를 생각해보자.

현재 노드가 가지고 있는 코인의 갯수를 C, 왼쪽 자식 노드에서 필요하거나 남은 코인의 갯수를 L, 오른쪽 자식 노드에서 필요하거나 남은 코인의 갯수를 R이라 하자.

이 때 현재 노드에서 남거나 부족한 코인의 갯수는 다음과 같다.

- C + R + L
- (여유분은 양수, 부족분은 음수)

이를 재귀호출로 반환하며 부모 노드에게 자신에게 남은 코인의 갯수, 혹은 부족한 코인의 갯수를 반환한다. (코인의 이동)

이 때 부모에게 옮기거나 받는 코인의 갯수만큼 이동횟수가 추가되므로 이를 모두 더하면 정답이 된다.

```cpp
int answer = 0;

int recursive(TreeNode *node) {
  int coins = node->val;
  int needs = 1;

  if (node->left) {
    coins += recursive(node->left);
  }
  if (node->right) {
    coins += recursive(node->right);
  }

  coins -= needs;

  answer += abs(coins);

  return coins;
}

int distributeCoins(TreeNode *root) {
  recursive(root);

  return answer;
}
```

## 고생한 점
