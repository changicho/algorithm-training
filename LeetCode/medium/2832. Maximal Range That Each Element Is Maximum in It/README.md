# 2832. Maximal Range That Each Element Is Maximum in It

[링크](https://leetcode.com/problems/maximal-range-that-each-element-is-maximum-in-it/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이므로 제한시간 내에 불가능하다.

모노토닉 스택을 사용해 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

모노토닉 스택에 O(N)의 공간 복잡도가 필요하다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      38      |    O(N)     |    O(N)     |

각 index마다의 각 방향별로 현재 index보다 큰 가장 가까운 index를 저장하는 배열을 생성한다.

이후 모노토닉 스택을 이용해 각 index마다의 왼쪽, 오른쪽의 가장 먼 index를 구한다.

이 때 모노토닉 스택은 top으로 갈 수록 작아지는 스택이다.

따라서 현재 index까지 왔을 때 이전 스택에 남아있는 값들은 현재 값들보다 큰 값이 남아있다고 판단할 수 있다.

따라서 스택의 top에 존재하는 값의 index는 현재 index보다 큰 값이 존재하는 index이다.

```cpp
vector<int> maximumLengthOfRanges(vector<int>& nums) {
  int size = nums.size();
  vector<int> left(size), right(size);

  stack<int> l2rDesc;
  for (int i = 0; i < size; i++) {
    while (!l2rDesc.empty() && nums[l2rDesc.top()] < nums[i]) {
      l2rDesc.pop();
    }
    left[i] = l2rDesc.empty() ? -1 : l2rDesc.top();
    l2rDesc.push(i);
  }

  stack<int> r2lDesc;
  for (int i = size - 1; i >= 0; i--) {
    while (!r2lDesc.empty() && nums[r2lDesc.top()] < nums[i]) {
      r2lDesc.pop();
    }
    right[i] = r2lDesc.empty() ? size : r2lDesc.top();
    r2lDesc.push(i);
  }

  vector<int> answer(size);
  for (int i = 0; i < size; i++) {
    answer[i] = right[i] - left[i] - 1;
  }

  return answer;
}
```

## 고생한 점
