# 606. Construct String from Binary Tree

[링크](https://leetcode.com/problems/construct-string-from-binary-tree/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

노드를 전위 순회 (preorder) 하며 문자열을 생성할 수 있다.

이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

트리의 순회에 재귀호출을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### preorder

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

트리를 전위 순회하며 자식노드로 넘어갈 때마다 괄호를 붙여준다.

이 때 트리의 오른쪽 노드만 존재하는 경우도 빈 괄호쌍을 붙여준다.

```cpp
string ret = "";

void recursive(TreeNode *node) {
  ret += to_string(node->val);

  if (!node->left && !node->right) return;

  if (node->left) {
    ret += '(';
    recursive(node->left);
    ret += ')';
  }
  if (node->right) {
    if (!node->left) {
      ret += "()";
    }
    ret += '(';
    recursive(node->right);
    ret += ')';
  }
}

string tree2str(TreeNode *root) {
  if (root) recursive(root);
  return ret;
}
```

## 고생한 점
