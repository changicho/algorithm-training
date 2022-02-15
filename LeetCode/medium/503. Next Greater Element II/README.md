# 503. Next Greater Element II

[링크](https://leetcode.com/problems/next-greater-element-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

각 원소에 대해서 직접 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

모노토닉 스택을 이용해 O(N)의 시간 복잡도로 풀이할 수 있다.

### 공간 복잡도

정답 배열을 생성하는데 O(N)의 공간 복잡도를 사용한다.

각 원소에 대해 직접 구할 경우 O(1)의 공간 복잡도를 사용한다.

모노토닉 스택을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     564      |   O(N^2)    |    O(N)     |

각 index에 대해서 가장 가까이 (오른쪽)에 있는 큰 원소를 구한다.

이 때 해당 원소를 찾은 경우 더이상 탐색하지 않는다.

각 index를 순회하는데 O(N), 각 index마다 오른쪽으로 순회하는데 O(N)의 시간 복잡도를 사용하므로 시간 복잡도는 O(N^2)이다.

별도의 추가 공간을 정답 배열에만 사용하므로 O(N)의 공간 복잡도를 사용한다.

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
  int size = nums.size();
  vector<int> answer(size, -1);

  for (int i = 0; i < size; i++) {
    for (int move = 1; move < size; move++) {
      if (nums[(i + move) % size] <= nums[i]) continue;

      answer[i] = nums[(i + move) % size];
      break;
    }
  }

  return answer;
}
```

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      42      |    O(N)     |    O(N)     |

각 index를 왼쪽에서부터 오른쪽으로 순회한다.

순회하며 스택에 원소들이 top으로 갈수록 작아지도록 쌓도록 한다.

각 원소를 순회하며 현재 원소값이 스택의 top에 있는 index의 값보다 큰 경우 정답의 해당 index의 값을 현재 값으로 업데이트한다.

이를 스택이 비거나 스택의 top이 현재 수보다 클 때까지 반복한다.

이후 스택에 현재 index를 삽입한다.

이 과정을 통해 스택의 값이 top에 가까울수록 작은 값을 가지도록 decrease하게 유지할 수 있다.

또한 stack에서 pop과 동시에 해당 index의 정답을 갱신할 수 있다.

여기서 갱신이 되지 않는 값이 있을 수 있으므로 미리 정답 배열을 -1로 초기화한다.

만약 정답이 circular하는 경우면 어떻게 처리할까? (size - 1이후에 0번째 i부터 정답을 고르는 경우)

이를 위해 기존 스택을 유지한 채로 한번의 순회를 더 수행한다.

이 경우 스택에 남은 index들에 대해서 다시 처음부터 nums를 순회하며 정답을 갱신할 수 있다.

한번의 순회에 O(N)의 시간 복잡도를, stack을 유지하는데 O(N)의 공간 복잡도를 사용한다.

```cpp
vector<int> nextGreaterElements(vector<int>& nums) {
  int size = nums.size();

  vector<int> answer(size, -1);
  stack<int> maxStack;  // idx, decrease

  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    // pop stack's top until top's val is same or bigger than current
    while (!maxStack.empty() && cur > nums[maxStack.top()]) {
      answer[maxStack.top()] = cur;
      maxStack.pop();
    }

    maxStack.push(i);
  }

  // loop one more time for circular case
  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    while (!maxStack.empty() && cur > nums[maxStack.top()]) {
      answer[maxStack.top()] = cur;
      maxStack.pop();
    }
  }

  return answer;
}
```

## 고생한 점
