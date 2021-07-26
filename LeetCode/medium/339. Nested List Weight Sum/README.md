# 339. Nested List Weight Sum

[링크](https://leetcode.com/problems/nested-list-weight-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 원소의 개수를 N이라 하자.

결국 모든 원소를 한번씩 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

이 때 내부 원소가 List인 경우에 depth를 증가시키며 이동해야 한다.

이를 재귀호출로 구현할 수 있으며 결과적으로 모든 요소를 방문하는것과 같으므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

재귀호출을 이용할 경우 call stack에 depth만큼 쌓이게 된다.

문제에서 depth는 최대 50까지임이 보장된다. N의 크기 또한 50 이하임이 보장된다.

따라서 공간 복잡도는 O(N)이다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 요소를 탐색하며 각 요소가 숫자인 경우와 list인 경우에 대해서 분기 처리한다.

- 숫자 : depth와 해당 숫자의 곱을 더한다.
- list : depth를 증가시켜 재귀 호출한다.

```cpp
int depthSum(vector<NestedInteger> const &nestedList, int depth) {
  int sum = 0;

  for (NestedInteger const &cur : nestedList) {
    if (cur.isInteger()) {
      sum += depth * cur.getInteger();
      continue;
    }
    sum += depthSum(cur.getList(), depth + 1);
  }

  return sum;
}

int depthSum(vector<NestedInteger> &nestedList) {
  return depthSum(nestedList, 1);
}
```

## 고생한 점
