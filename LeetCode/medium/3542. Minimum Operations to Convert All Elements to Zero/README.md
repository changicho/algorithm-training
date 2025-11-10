# 3542. Minimum Operations to Convert All Elements to Zero

[링크](https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N <= 10^5)

모노토닉 스택을 사용할 경우 O(N)의 시간 복잡도를 사용할 수 있다.

### 공간 복잡도

모노토닉 스택에 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      34      |    O(N)     |    O(N)     |

0으로 구분되는 영역에 대해서 연산을 수행할 경우 해당 영역에서 가장 작은 수들은 다시 0이 된다.

최대한 큰 영역을 설정하는 편이 연산의 수를 줄일 수 있다.

이 때 각 영역에서 가장 작은 수들을 제외한 숫자들은 남게 된다. 이 숫자들은 추후에 별도로 연산을 수행해야 한다.

왼쪽부터 모노토닉 스택을 사용해 숫자가 증가하는 스택을 관리할 수 있다.

만약 현재 숫자가 스택의 top보다 작을 경우, 스택에서 pop을 수행한다.

스택에 숫자가 추가되는 경우 해당 숫자들은 추후에 0을 만들어야 하므로 연산이 필요하다.

따라서 스택에 수가 추가될 때 정답의 count를 증가시킨다.

숫자가 추가되지 않는 경우는 top과 동일한 숫자이며 이는 한번의 연산으로 0을 한꺼번에 만들 수 있다.

```cpp
int minOperations(vector<int>& nums) {
  int answer = 0;

  stack<int> stk;
  for (int& num : nums) {
    while (!stk.empty() && stk.top() > num) {
      stk.pop();
    }

    if (num > 0 && (stk.empty() || stk.top() < num)) {
      stk.push(num);
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
