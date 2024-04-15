# 2709. Greatest Common Divisor Traversal

[링크](https://leetcode.com/problems/greatest-common-divisor-traversal/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. 배열의 원소의 최대값을 M이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다. 이는 제한시간 내에 불가능하다.

union find를 이용해 풀이할 수 있다.

각 num마다 약수들을 구하는 데 O(sqrt(M))의 시간 복잡도를 사용하다.

nums를 순회하며 약수들끼리 묶는 데 O(N \* sqrt(M))의 시간 복잡도가 필요하다.

### 공간 복잡도

union find에 O(N)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     433      | O(N \* sqrt(M)) |    O(N)     |

각 nums를 순회하며 약수들을 구하고, 해당 약수들을 가지고 있는 다른 num들과 묶는다.

이를 위해 유니온 파인드를 사용한다.

이후 모든 숫자들이 하나로 묶인 경우 true를 반환하고, 그 외의 경우 false를 반환한다.

```cpp
vector<int> parents;
vector<int> children;

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) {
    return;
  }

  if (children[a] < children[b]) {
    swap(a, b);
  }
  parents[b] = a;
  children[a] += children[b];
}

bool canTraverseAllPairs(vector<int> &nums) {
  int size = nums.size();
  if (size == 1) return true;

  parents.resize(size);
  children.resize(size, 1);
  for (int node = 0; node < size; node++) {
    parents[node] = node;
  }

  unordered_map<int, int> divisor2targets;
  for (int node = 0; node < size; node++) {
    int cur = nums[node];
    if (cur == 1) return false;

    for (int d = 2; d * d <= cur; d++) {
      if (cur % d != 0) continue;

      if (divisor2targets.count(d)) {
        int target = divisor2targets[d];
        merge(node, target);
      } else {
        divisor2targets[d] = node;
      }

      while (cur % d == 0) {
        cur /= d;
      }
    }

    if (cur == 1) continue;
    if (divisor2targets.count(cur)) {
      merge(node, divisor2targets[cur]);
    } else {
      divisor2targets[cur] = node;
    }
  }

  return children[find(0)] == size;
}
```

## 고생한 점
