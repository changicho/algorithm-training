# 946. Validate Stack Sequences

[링크](https://leetcode.com/problems/validate-stack-sequences/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

pushed, popped의 원소의 갯수를 N이라 하자.

스택을 이용해 시뮬레이션 해 볼 수 있다. 이 경우 결국 N개의 원소를 넣었다 빼므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택을 이용해 시뮬레이션 할 경우 O(N)의 공간 복잡도를 사용한다.

### 스택 & 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(N)     |

pushed 순서대로 값을 넣고 popped의 순서대로 값을 뺀다.

여기서 현재들어간 값이 언제 나와야 하는지는 popped의 순서에 따라 다르다.

따라서 실제 stack에 pushed에 있는 값을 넣어보며 현재 popped의 순서대로 뺄 수 있는지를 검사한다.

결국 빼야하는 값은 popped 순이므로 popped를 순회한다.

pushed의 현재 값의 index를 i라 하자.

현재 popped의 값이 stack의 top과 같을 때까지 stack에 값을 계속 넣는다. 이 과정에서 i는 증가한다.

이후 현재 stack의 top이 현재 popped와 같은 경우 pop 한후 다음 popped값에 대해 이를 반복한다.

모든 pop을 순회했을 때 스택이 비어있는 경우 valid하다.

```cpp
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
  int size = pushed.size();

  stack<int> stk;
  int idx = 0;
  for (int& pop : popped) {
    while (idx < size && (stk.empty() || stk.top() != pop)) {
      stk.push(pushed[idx]);
      idx++;
    }

    if (pop == stk.top()) {
      stk.pop();
    }
  }

  return stk.empty();
}
```

## 고생한 점
