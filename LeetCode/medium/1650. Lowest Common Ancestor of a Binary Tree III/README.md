# 1650. Lowest Common Ancestor of a Binary Tree III

[링크](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N, 높이를 H라 하자.

하나의 노드에서 루트노드까지 모든 노드의 path를 저장하고 다른 노드에서 루트노드까지 이동하며 이를 비교하며 공통 조상을 구할 수 있다.

이 경우 하나의 노드에서 루트 노드까지 O(H)의 시간 복잡도로 탐색을 진행한다.

따라서 총 시간 복잡도는 O(H)이다.

두 노드에서 높이까지 서로 한칸씩 이동하며, 루트에 도달할 경우 반대쪽 시작점으로 이동해 문제를 풀이할 수 있다.

이 경우 두 노드의 path를 합한 만큼 이동하므로 O(H)의 시간 복잡도를 사용한다.

### 공간 복잡도

path를 모두 저장할 경우 O(H)의 공간 복잡도를 사용한다.

두 노드의 경로를 같이 이동시키며 swap할 경우 O(1)의 공간복잡도를 사용한다.

### path check

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      33      |    O(H)     |    O(H)     |

하나의 노드를 루트까지 이동시키며 path를 전부 저장한다.

이후 다른 노드를 루트까지 이동시키며 이전에 방문한 노드가 있다면 이 노드가 LCA이다.

```cpp
Node* lowestCommonAncestor(Node* p, Node* q) {
  unordered_set<int> paths;

  while (p) {
    paths.insert(p->val);
    p = p->parent;
  }

  while (q) {
    if (paths.count(q->val) > 0) return q;

    q = q->parent;
  }

  return NULL;
}
```

### iterative

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      33      |    O(H)     |    O(1)     |

두 노드를 한칸씩 루트노드까지 이동시킨다.

이때 루트 노드에 도달하는 경우 해당 노드를 다른 노드의 시작점부터 다시 이동시킨다.

이 경우 두 노드가 총 이동하는 거리는 O(2 \* H)이다. (각 노드에서 루트까지 거리를 H1, H2라고 할 경우 H1 + H2)

같은 길이를 이동하며 도중에 LCA를 만나는 경우 이후부터 같은 경로를 이동하게 된다.

따라서 이동중에 LCA를 만나는 경우 이를 반환한다.

```cpp
Node* lowestCommonAncestor(Node* p, Node* q) {
  Node *first = p, *second = q;

  while (first != second) {
    first = first ? q : first->parent;
    second = second ? p : second->parent;
  }
  return first;
}
```

## 고생한 점
