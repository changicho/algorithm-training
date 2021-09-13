# 42. Trapping Rain Water

[링크](https://leetcode.com/problems/trapping-rain-water/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

모든 index마다 채워넣을 물을 구할 경우 시간 복잡도는 O(N^2)가 된다.

이는 제한시간 내에 불가능 하므로 동적 계획법을 이용한다.

동적 계획법을 이용할 경우 left-right dp를 이용한다.

이 경우 한번의 순회를 3번 반복해 구할 수 있으므로 시간 복잡도는 O(N)이다.

스택과 투 포인터를 이용하는 경우 또한 한번의 순회로 풀이가 가능하다.

이 경우도 O(N)의 시간복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 index마다의 최선의 값을 저장해야 한다.

따라서 O(N)의 공간 복잡도를 사용한다.

스택의 경우도 최악의 경우 N개의 값이 스택에 쌓이므로 O(N)의 공간 복잡도를 사용한다.

투 포인터의 경우 left, right의 이동에 따른 값을 갱신하면 되므로 별도의 공간 복자도가 필요하지 않다.

### 동적 계획법 (left-right dp)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

다음과 같은 dp배열을 생성한다.

```cpp
left[i]; // 0부터 i번째 까지 방문했을 때 최대높이
right[i]; // size - 1부터 i번째 까지 방문했을 때 최대높이
```

항상 최대의 값을 사용하는 이유는 웅덩이의 시작점을 구하기 위함이다.

여기서 왼쪽과 오른쪽에 대해서 특정 index에 대한 최대 높이를 별도로 구하는 이유는 다음과 같다.

다음과 같은 예시의 경우를 생각해보자

```javascript
[0, 0, 4, 0, 0];
```

해당 예시의 경우 leftDP와 rightDp가 서로 다른 값을 갖는다 (i != 2일 때)

따라서 같은 index의 경우 두 값중 최소값을 이용해야 한다.

이 최소 값과 현재의 높이의 차이 만큼 물이 차오를 수 있기 때문이다.

```cpp
int trap(vector<int>& height) {
  int size = height.size();
  int answer = 0;

  vector<int> left(size, 0), right(size, 0);

  left.front() = height.front();
  for (int i = 1; i < size; i++) {
    left[i] = max(height[i], left[i - 1]);
  }

  right.back() = height.back();
  for (int i = size - 2; i >= 0; i--) {
    right[i] = max(height[i], right[i + 1]);
  }

  for (int i = 0; i < size; i++) {
    answer += min(left[i], right[i]) - height[i];
  }

  return answer;
}
```

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

위 동적 계획법에서 높이의 최대값을 갱신하는 부분에 주목한다.

높이를 순회하면서 stack에 높이를 저장한다.

이 때 스택의 가장 바닥에는 큰 값이, top에는 가장 작은값이 쌓이도록 조정한다.

이 이유는 stack에 남는 값이 웅덩이의 시작점이 되게 하기 위함이다.

그리고 해당 정렬 순서를 뒤집는 값이 현재 높이인 경우는 기존에 stack에 쌓인 높이들을 pop하며 웅덩이의 크기를 갱신할 수 있다.

```cpp
int trap(vector<int>& height) {
  int size = height.size();
  int answer = 0;
  int index = 0;
  stack<int> s;

  while (index < size) {
    // 현재 높이가 stack.top 보다 작은 경우 삽입
    if (s.empty() || height[index] <= height[s.top()]) {
      s.push(index);
      index++;
      continue;
    }

    // 현재 높이가 stack.top 보다 작은 경우 stack을 비우면서 행 별로 면적 계산
    while (!s.empty() && height[index] > height[s.top()]) {
      int top = s.top();
      s.pop();
      if (s.empty()) continue;

      int line_height = (index - s.top() - 1);
      int line_width = min(height[s.top()], height[index]) - height[top];

      answer += line_width * line_height;
    }
  }

  return answer;
}
```

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

left-right dp방법에서 모든 경우에 대해서 dp배열을 미리 구하지 않고,

투 포인터를 이용해서 현재 값들만 구하는 방법이다.

left, right 두 포인터를 이동하면서 각각 발견한 최대 값을 저장한다.

그리고 현재 위치의 높이가 이전의 최대값보다 작은 경우에는 쌓인 물을 정답에 더한다.

그 외의 경우는 최대 값을 갱신한다.

이 방법을 통해서 결국 두 포인터는 하나의 점에서 만나게 된다. (가장 높은 값)

이 때 left, right 두 포인터에 위치한 높이 중 작은 값을 갱신해야 한다.

같은 경우는 두 값들중 아무 값이나 갱신한다. (하나의 위치에서 만나게 하는것이 목적)

```cpp
int trap(vector<int>& height) {
  int size = height.size();
  int left = 0, right = size - 1;
  int leftMax = 0, rightMax = 0;
  int answer = 0;

  // left, right가 가장 높은 height에서 만나도록 설정
  while (left < right) {
    if (height[left] < height[right]) {
      // left++ case
      if (height[left] >= leftMax) {
        leftMax = height[left];
      } else {
        answer += (leftMax - height[left]);
      }

      left++;
    } else {
      // right-- case
      if (height[right] >= rightMax) {
        rightMax = height[right];
      } else {
        answer += (rightMax - height[right]);
      }

      right--;
    }
  }

  return answer;
}
```

## 고생한 점
