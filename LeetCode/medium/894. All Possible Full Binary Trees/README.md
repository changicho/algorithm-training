# 894. All Possible Full Binary Trees

[링크](https://leetcode.com/problems/all-possible-full-binary-trees/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 노드의 수를 N이라 하자.

수학적으로 가능한 모든 경우의 수는 2^(N/2)개 이다. (N은 홀수여야 하며 각 경우마다 서브트리에도 홀수개가 존재해야 한다)

동적 계획법을 이용해 사용할 노드의 수에 대해 모든 경우의 수를 구할 수 있다. 이 경우 O(2^(N/2))의 시간 복잡도를 사용한다.

### 공간 복잡도

사용가능한 갯수마다의 트리 정보를 저장해야 하므로 O(N \* 2^(N/2))의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 |   공간 복잡도   |
| :----------: | :---------: | :-------------: |
|      84      | O(2^(N/2))  | O(N \* 2^(N/2)) |

노드의 갯수가 짝수개인 경우 불가능하다.

현재 가능한 노드의 갯수가 N개 일때 가능한 모든 경우의 수를 아래와 같이 구할 수 있다.

- 1개의 노드는 루트노드로 할당.
- 왼쪽에 L개의 노드, 오른쪽에 R개의 노드를 할당한다.
- 가능한 L,R의 조합에 대해 트리들을 생성한다.

이때 L과 R을 재사용하기 위해 동적 계획법을 사용한다.

따라서 X개의 노드가 존재할 때 가능한 트리들을 dp에 저장 후 이를 사용한다.

여기서 X가 1인 경우는 base condition으로 하나의 노드만을 반환한다.

```cpp
vector<TreeNode *> allPossibleFBT(int n) {
  // ignore case
  if (n % 2 == 0) {
    return {};
  }

  vector<TreeNode *> dp[21];

  dp[1].push_back(new TreeNode(0));
  for (int count = 3; count <= n; count += 2) {
    for (int leftCount = 1; leftCount < count - 1; leftCount += 2) {
      // one node will be root
      int rightCount = count - 1 - leftCount;

      for (TreeNode *leftRoot : dp[leftCount]) {
        for (TreeNode *rightRoot : dp[rightCount]) {
          TreeNode *root = new TreeNode(0, leftRoot, rightRoot);
          dp[count].push_back(root);
        }
      }
    }
  }

  return dp[n];
}
```

## 고생한 점
