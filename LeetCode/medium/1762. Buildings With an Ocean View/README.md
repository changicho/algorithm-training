# 1762. Buildings With an Ocean View

[링크](https://leetcode.com/problems/buildings-with-an-ocean-view/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

heights의 크기를 N이라 하자.

각 index별로 모든 경우를 순회할 경우 O(N^2)의 시간 복잡도를 사용한다.

왼쪽부터 순회하며 stack을 이용해 직전 값보다 큰 값이 나올 때마다 pop하며 정답을 채울 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용하며 스택의 연산에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

스택을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

그리디한 방법을 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     172      |    O(N)     |    O(N)     |

왼쪽에서 부터 순회하며 스택에 저장한다.

이 때 스택의 top이 현재 원소보다 높이가 이하인 경우는 스택에서 뺀다.

이를 반복할 경우 스택에 있는 높이들은 top이 제일 낮고 bottom이 제일 높도록 정렬되어있다.

이를 이용해 정답을 구한다.

```cpp
vector<int> findBuildings(vector<int>& heights) {
  int size = heights.size();
  vector<int> answer;

  for (int i = 0; i < size; i++) {
    int h = heights[i];
    while (!answer.empty() && heights[answer.back()] <= h) {
      answer.pop_back();
    }
    answer.push_back(i);
  }

  return answer;
}
```

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     216      |    O(N)     |    O(N)     |

위 스택을 이용한 방법에서 모노토닉 스택을 이용해 오른쪽에서 왼쪽으로 순회하며 문제를 풀이할 수 있다.

stack에 높이를 오른쪽부터 순회하며 높이를 저장한다.

이 때 현재 높이보다 낮은 값들은 모두 pop한다.

스택에는 현재 높이보다 높은 높이들만 남아있을 수 있으므로 스택이 빈 경우 또한 존재한다.

이 경우 현재 index는 답이 될 수 있으므로 정답에 삽입한다.

이를 모든 높이에 대해 반복한 뒤 정답을 뒤집는다.

```cpp
vector<int> findBuildings(vector<int>& heights) {
  int size = heights.size();
  vector<int> answer;
  stack<int> st;

  for (int i = size - 1; i >= 0; i--) {
    // remove lower than current height
    while (!st.empty() && heights[st.top()] < heights[i]) {
      st.pop();
    }

    // if stack empty, there is no building to the right
    if (st.empty()) answer.push_back(i);

    // push current index
    st.push(i);
  }

  reverse(answer.begin(), answer.end());
  return answer;
}
```

### 역순회 (그리디, 모노토닉 스택)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     257      |    O(N)     |    O(1)     |

모노토닉 스택 방법에서 직전의 maxHeight 높이값만을 이용해 현재 index를 정답에 삽입할 수 있는지 판단할 수 있다.

만약 현재 높이가 maxHeight 이하인 경우는 오른쪽에 같거나 큰 값들이 존재한다는 의미이다.

반대의 경우는 maxHeight값을 갱신하고 현재 index를 정답에 추가한다.

```cpp
vector<int> findBuildings(vector<int>& heights) {
  int size = heights.size();
  vector<int> answer;
  int maxHeight = -1;

  for (int i = size - 1; i >= 0; i--) {
    if (maxHeight >= heights[i]) continue;

    answer.push_back(i);
    // update
    maxHeight = heights[i];
  }

  reverse(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
