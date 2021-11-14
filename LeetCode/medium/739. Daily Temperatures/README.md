# 739. Daily Temperatures

[링크](https://leetcode.com/problems/daily-temperatures/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

우선 한번 순회를 하며 각 index별로 이후에 나오는 자기보다 높은 온도의 index를 구해야 한다.

이 때 자기보다 높은 온도의 index를 빨리 구하기 위해 다음 방법들을 사용할 수 있다.

- stack
- 역순으로 순회 + 이동

두 방법 모두 내부적으로 한번의 순회를 통해서 구할 수 있으므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답 배열을 생성하는데 O(N)의 공간 복잡도를 사용한다.

stack을 사용하는 경우 O(N)의 공간 복잡도를 사용한다.

역순으로 순회하며 가장 최적의 해를 구하는 경우 O(1)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     160      |    O(N)     |    O(N)     |

온도의 index를 저장하는 stack을 사용한다.

만약 현재 온도가 stack의 top보다 큰 경우 stack을 pop하며 해당 index의 정답을 갱신한다. (현재 index로)

이를 stack이 비거나 top보다 크지 않은 경우까지 반복한다.

(stack에 있는 index의 정답들을 갱신함)

이후 현재 index를 stack에 저장한다.

현재 온도에 대해서 이전에 정답을 찾지 못한 index들의 정답을 갱신하는 방법이다.

```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) {
  int size = temperatures.size();
  vector<int> answer(size, 0);

  stack<int> st;
  st.push(0);

  for (int i = 1; i < size; i++) {
    while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
      int idx = st.top();
      st.pop();

      answer[idx] = i - idx;
    }

    st.push(i);
  }

  return answer;
}
```

### 역순으로 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     160      |    O(N)     |    O(N)     |

온도를 역순으로 순회하며 정답을 채워나간다.

이는 역순으로 순회하는 경우 이전에 방문한 index에 해당하는 정답은 다시 갱신되지 않기 때문이다.

역순으로 순회하며 방문한 최고 온도를 갱신한다.

만약 현재 온도가 최고 온도보다 낮은 경우는 현재 index에 대한 정답을 갱신해야 한다.

이 때 이전에 갱신한 정답을 이용한다.

현재 index + 1의 정답에 해당하는 위치의 온도가 현재 온도보다 큰지 확인한다.

- 만약 큰 경우 정답은 해당 위치의 값이 된다.
- 만약 작은 경우 해당 위치의 정답의 위치한 온도와 비교한다.

이를 반복해 정답을 갱신할 수 있다.

```cpp
vector<int> dailyTemperatures(vector<int>& temperatures) {
  int size = temperatures.size();
  int hottest = 0;
  vector<int> answer(size, 0);

  for (int i = size - 1; i >= 0; i--) {
    int currentTemp = temperatures[i];

    if (currentTemp >= hottest) {
      hottest = currentTemp;
      continue;
    }

    int days = 1;
    while (temperatures[i + days] <= currentTemp) {
      days += answer[i + days];
    }
    answer[i] = days;
  }

  return answer;
}
```

## 고생한 점
