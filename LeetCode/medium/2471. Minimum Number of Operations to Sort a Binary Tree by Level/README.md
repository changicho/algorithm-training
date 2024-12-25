# 2471. Minimum Number of Operations to Sort a Binary Tree by Level

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

BFS를 이용해 트리를 step별로 탐색하며, 각 step 별 노드의 값들을 오름차순으로 정렬하는 최소 횟수를 구할 수 있다.

이를 위해 정렬과 hash map을 step마다 사용할 수 있다.

따라서 총 시간 복잡도는 O(N * log_2(N))이다.

### 공간 복잡도

hash map, BFS, 정렬에 O(N)의 공간 복잡도가 필요하다.

### BFS, 정렬, hash map

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     177      | O(N * log_2(N)) |    O(N)     |

트리를 step별로 방문하기 위해 BFS를 사용한다.

현재 step의 노드들의 값을 배열에 저장하고 이를 arr이라 하자.

arr을 오름차순으로 정렬하기 위한 최소 횟수를 구하기 위해 정렬과 hash map을 사용한다.

정렬된 값 arr을 target이라 하자.

arr과 target의 index를 증가시키며 비교하며 값이 다른 경우 target의 값에 맞춰 swap을 수행한다.

이를 반복해 최소 횟수를 구한다.

```cpp
int calc(vector<int> &original) {
  int size = original.size();

  int ret = 0;
  vector<int> target = original;
  sort(target.begin(), target.end());

  unordered_map<int, int> indexes;
  for (int i = 0; i < size; i++) {
    indexes[original[i]] = i;
  }

  for (int i = 0; i < size; i++) {
    if (original[i] == target[i]) continue;

    int targetI = indexes[target[i]];
    indexes[original[i]] = targetI;
    swap(original[targetI], original[i]);

    ret++;
  }
  return ret;
}

int minimumOperations(TreeNode *root) {
  int answer = 0;

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    vector<int> vals;
    while (size--) {
      TreeNode *cur = q.front();
      q.pop();

      vals.push_back(cur->val);

      if (cur->left) q.push(cur->left);
      if (cur->right) q.push(cur->right);
    }

    answer += calc(vals);
  }
  return answer;
}
```

## 고생한 점
