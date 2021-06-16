# 105. Construct Binary Tree from Preorder and Inorder Traversal

[링크](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 노드의 개수를 N이라 하자.

모든 노드를 한번 순회하며 트리를 생성해야 한다. 이 모든 노드를 순회하는데 O(N)의 시간 복잡도가 필요하다.

inorder순으로 탐색을 진행하며 현재 노드가 postorder로 순회했을 때 어느 위치에 있는지를 찾아야한다.

이를 매번 검색할 경우 inner 순회에 O(N)의 시간 복잡도가 필요하다.

hash map을 이용할 경우 O(1)의 시간 복잡도로 탐색이 가능하다.

따라서 최소 시간 복잡도는 O(N) 이며, 공간 복잡도를 최소로 할 경우 O(N^2)이다.

### 공간 복잡도

각 노드마다 특정 순회를 진행했을 때 index를 hash map에 저장하는 경우 O(N)의 공간 복잡도가 필요하다.

이를 직접 찾는 경우 O(1)의 공간 복잡도가 필요하다.

### 중위 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

중위순회의 경우 현재 노드의 왼쪽 자식들은 전부 왼쪽에, 오른쪽 자식들은 전부 오른쪽에 존재하는 것을 확인할 수 있다.

또한 후위 순회를 이용해 현재 노드의 왼쪽, 오른쪽 순회 후 자기 자신을 판단할 수 있으므로 자신의 자식 노드들은 전부 index가 앞서는것을 확인할 수 있다.

따라서 postOrder 순으로 순회를 진행하며 재귀호출로 left, right 범위를 정해 탐색한다.

이 범위를 인자로 넘기는 이유는 중위순회시에 현재 노드의 왼쪽과 오른쪽의 범위를 정하기 위함이다.

다음 예시를 살펴보자

```plain_text
inorder   = [4 2 5 1 6 3 7]
postorder = [4 5 2 6 7 3 1]

        1
    /        \
[4 2 5]   [6 3 7]       <= inorder array
[4 5 2]   [6 7 3]       <= postorder array
```

위 예시를 통해 1 노드의 왼쪽과 오른쪽으로 분할해 문제를 풀이할 수 있다.

서브트리의 경우또한 살펴보면 각 범위의 postOrder를 통해 subTree의 root를 구할 수 있고, 나머지 또한 이와 동일하자.

```plain_text
          1
     /        \
    2          3
[4]  [5]    [6]  [7]       <= inorder array
[4]  [5]    [6]  [7]       <= postorder array
```

```cpp
unordered_map<int, int> m;

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
  int size = inorder.size();
  for (int i = 0; i < size; i++) {
    m[inorder[i]] = i;
  }
  int rootIdx = postorder.size() - 1;

  return build(inorder, postorder, rootIdx, 0, size - 1);
}

TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& rootIdx, int left, int right) {
  if (left > right) return NULL;

  int pivot = m[postorder[rootIdx]];
  rootIdx--;
  TreeNode* node = new TreeNode(inorder[pivot]);

  node->right = build(inorder, postorder, rootIdx, pivot + 1, right);
  node->left = build(inorder, postorder, rootIdx, left, pivot - 1);

  return node;
}
```

## 고생한 점
