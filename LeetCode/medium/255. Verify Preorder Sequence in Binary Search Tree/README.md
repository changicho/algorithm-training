# 255. Verify Preorder Sequence in Binary Search Tree

[링크](https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 개수를 N이라 하자.

stack과 한번의 순회를 통해 유효한 preOrder인지 확인할 수 있다. 이 경우 시간 복잡도는 O(N)이다.

이는 stack을 이용해 방문한 노드에서 왼쪽에 있는 가장 가까운 노드들을 확인할 수 있기 때문이다.

### 공간 복잡도

스택에 최대 O(N)의 공간 복잡도를 필요로 할 수 있다.

### stack

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

노드를 순회하며 stack에는 순회를 하며 왼쪽에 존재했던 값들을 순서대로 넣는다.

이 때 현재 값이 stack의 top보다 큰 경우는 stack에서 현재 값보다 작은 값들을 pop한다.

이는 각 노드들을 preOrder로 순회했을 때 stack에는 root에서 해당 노드까지 도달한 경로가 저장한다.

또한 노드들을 preOrder로 방문했을 때 이전에 방문한 노드들 중 가장 마지막에 pop한 노드 (가장 왼쪽에 있었던 노드) beforeLeft로 저장한다.

만약 현재 노드의 값이 beforeLeft보다 작은 경우는 preOrder 순서를 어긋나므로 (left순으로 방문했을 때 이전에 방문한 값이 현재 값보다 작을 수 없음) 이 경우 false를 반환한다.

```cpp
bool verifyPreorder(vector<int>& preorder) {
  int size = preorder.size();
  if (size <= 1) return true;

  stack<int> s;
  s.push(preorder.front());
  int beforeLeft = -1;

  for (int i = 1; i < size; i++) {
    if (s.empty() || preorder[i] < s.top()) {
      if (preorder[i] < beforeLeft) return false;

      s.push(preorder[i]);
    } else {
      while (!s.empty() && s.top() < preorder[i]) {
        beforeLeft = s.top();
        s.pop();
      }
      s.push(preorder[i]);
    }
  }
  return true;
}
```

## 고생한 점
