# 666. Path Sum IV

[링크](https://leetcode.com/problems/path-sum-iv/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. 트리에는 노드가 N개 존재한다.

각 수를 트리의 노드로 변환한 뒤 루트에서부터 DFS로 탐색한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 수를 트리로 변환하는데 O(N)의 공간 복잡도를 사용한다.

DFS에 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 수를 이용해 트리의 위치로 변환할 수 있다.

이 때 배열의 index를 이용해 트리의 노드의 위치를 설정한다.

현재 노드의 위치를 i라 할 때 다음과 같이 자식 노드들을 설정한다.

- 왼쪽 자식 노드 : i * 2
- 오른쪽 자식 노드 : i * 2 + 1

이후 루트에서부터 DFS로 탐색하며 path sum을 모두 더한다.

```cpp
int pathSum(vector<int>& nums) {
  int size = nums.size();
  vector<int> tree(100, -1);

  for (int& num : nums) {
    int d = num / 100;
    int l = (num % 100) / 10;
    int v = num % 10;

    int index = (1 << (d - 1)) - 1 + l;
    tree[index] = v;
  }

  int answer = 0;
  function<void(int, int)> recursive = [&](int node, int sum) {
    bool isLeaf = true;
    sum += tree[node];

    int left = node * 2, right = node * 2 + 1;
    if (tree[left] != -1) {
      recursive(left, sum);
      isLeaf = false;
    }
    if (tree[right] != -1) {
      recursive(right, sum);
      isLeaf = false;
    }

    if (isLeaf) {
      answer += sum;
    }
  };

  recursive(1, 0);
  return answer;
}
```

## 고생한 점
