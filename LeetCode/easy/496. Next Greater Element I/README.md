# 496. Next Greater Element I

[링크](https://leetcode.com/problems/next-greater-element-i/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums1의 크기를 N, nums2의 크기를 M이라 하자.

모든 index에 대해서 직접 next greater element를 탐색할 경우 O(M^2)의 시간 복잡도를 사용하며 이를 모든 nums1에 대해서 매번 찾을 경우 O(M \* (N + M))의 시간 복잡도를 사용한다.

stack을 이용해 모든 nums2의 원소에 대해 next greater element를 구할 경우 O(M)의 시간 복잡도로 모두 구할 수 있다.

이를 미리 hash map에 저장하고 nums1을 탐색해 바로 정답을 찾을 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

stack과 hash map을 사용하는 데 공간 복잡도는 O(M)이 필요하다.

### monotonic stack & hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N + M)   |    O(M)     |

nums2의 모든 원소를 순차적으로 순회하며 각 index의 nextGreaterElement를 구한다.

이 때 monotonic stack을 이용하며, stack에는 현재 원소보다 작고 왼쪽에 있는 index들이 존재한다. (minStack, decreasing)

현재 원소가 stack의 top보다 큰 값인 경우 해당 index에 해당하는 next greater element는 현재 원소가 된다.

이는 스택 안에 들어있는 모든 원소의 index에 해당한다. 따라서 stack이 비거나 stack.top이 이를 만족하지 못할 때 까지 반복한다.

stack을 단조롭게 유지하기 때문이다. (위로 갈수록 작은 값인 경우에만 쌓이기 때문이다.)

이후 스택이 비어있거나, 스택의 top이 현재 값보다 큰 경우 스택에 현재 index를 삽입한다.

이 과정을 진행하며 next greater에 대한 hash map의 pair를 생성한다.

```cpp
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
  int size = nums2.size();

  vector<int> nextGreaters(size, 0);
  // key : index, value : next greater element
  unordered_map<int, int> nextGreaterByIndex;
  stack<int> minStack;

  for (int i = 0; i < size; i++) {
    while (!minStack.empty() && nums2[minStack.top()] < nums2[i]) {
      int target = minStack.top();
      minStack.pop();
      nextGreaterByIndex[nums2[target]] = nums2[i];
    }

    minStack.push(i);
  }

  vector<int> answers;
  for (int& num : nums1) {
    answers.emplace_back(
        nextGreaterByIndex.count(num) ? nextGreaterByIndex[num] : -1);
  }
  return answers;
}
```

## 고생한 점
