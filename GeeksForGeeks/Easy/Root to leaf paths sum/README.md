# Root to leaf paths sum

[링크](https://practice.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

노드의 개수는 최대 12개이다.

리프 노드를 찾기 위해선 모든 노드를 방문해야한다.

모든 노드를 DFS, BFS로 방문하는 데 시간 복잡도는 O(N)이다.

### 공간 복잡도

리프 노드 까지의 각 상태를 저장해야 한다.

재귀함수를 이용하는 경우 함수의 인자로 넘어가므로 별도의 공간이 필요하지 않다.

각 리프노드들의 합을 알아야 하므로 필요한 공간 복잡도는 O(N) 이다.

### DFS

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

재귀함수를 호출하며 현재 노드가 리프 노드인 경우에만 정답에 더한다.

이 때 다음 재귀함수로 호출하거나 리프 노드인 경우 자기 자신의 값을 더하는 것에 유의한다.

```cpp
void recursive(Node *node, long long number, long long &leafVal) {
  if (!node) {
    return;
  }
  long long data = node->data;

  if (!node->left && !node->right) {
    leafVal += number * 10 + data;
    return;
  }

  if (node->left) {
    recursive(node->left, number * 10 + data, leafVal);
  }
  if (node->right) {
    recursive(node->right, number * 10 + data, leafVal);
  }
}

long long treePathsSum(Node *root) {
  long long leafVal = 0;

  recursive(root, 0, leafVal);

  return leafVal;
}
```

## 고생한 점

전역변수 초기화를 매번 해줘야한다.
