# 508. Most Frequent Subtree Sum

[링크](https://leetcode.com/problems/most-frequent-subtree-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자.

노드를 DFS로 순회하며 각 subTree 의 합을 hash map에 저장해 count를 증가시킨다.

이 순회에 O(N)의 시간 복잡도를 사용한다.

이후 각 값과 count에 대해 정렬할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

순회와 동시에 가장 높은 빈도를 저장하고 이를 이후 순회하며 찾을 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

count에 O(N)의 공간 복잡도를 사용한다.

정답에 O(N)의 공간 복잡도를 사용한다.

### DFS & 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

DFS를 이용해 루트부터 노드를 순회하며 subTree의 합을 count한다.

이 과정에서 count와 동시에 가장 높은 빈도수를 저장한다.

이후 count를 순회하며 가장 높은 빈도인 값들만 정답에 저장하고 반환한다.

```cpp
struct Data {
  int val, count;

  bool operator<(const Data &b) { return count > b.count; }
};

unordered_map<int, int> counts;
int freq = 0;

int recursive(TreeNode *node) {
  int sum = node->val;

  if (node->left) {
    sum += recursive(node->left);
  }
  if (node->right) {
    sum += recursive(node->right);
  }

  counts[sum]++;
  freq = max(freq, counts[sum]);
  return sum;
}

vector<int> findFrequentTreeSum(TreeNode *root) {
  if (root) recursive(root);

  vector<int> answer;
  for (auto &it : counts) {
    int key = it.first, val = it.second;

    if (val == freq) answer.push_back(key);
  }

  return answer;
}
```

## 고생한 점
