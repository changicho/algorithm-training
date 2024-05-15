# C - Merge the balls

[링크](https://atcoder.jp/contests/abc351/tasks/abc351_c)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

입력받은 배열 A의 크기를 N이라 하자.

스택을 이용해 각 경우마다 연산을 수행 할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

스택에 O(N)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |    O(N)     |    O(N)     |

2의 X승을 직접 구하는 것이 아닌, 제곱수를 이용해 비교를 수행한다.

스택의 top과 현재 값을 비교하며 같은 경우 pop을 수행하며 현재 값을 증가시킨다.

이후 더이상 비교가 불가능한 경우 현재 값을 스택에 push한다.

```cpp
int solution(vector<int> &nums) {
  int size = nums.size();

  stack<int> stk;

  for (int &num : nums) {
    int cur = num;

    while (!stk.empty() && stk.top() == cur) {
      cur++;
      stk.pop();
    }

    stk.push(cur);
  }

  return stk.size();
}
```

## 고생한 점
