# 376. Wiggle Subsequence

[링크](https://leetcode.com/problems/wiggle-subsequence/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우에 대해 탐색할 경우 시간 복잡도는 O(2^N)이 되며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법 혹은 그리디 알고리즘을 이용해 풀이한다.

동적 계획법을 이용할 경우 현재 값에 대해서 직전값들을 탐색해 갱신할 경우 O(N^2)의 시간 복잡도를 사용한다.

이 때 최적의 값 만으로 갱신할 경우 O(N)의 시간복잡도로 해결이 가능하다.

그리디 알고리즘을 사용할 경우 한번의 순회에 최적의 해를 찾으므로 O(N)의 시간 복잡도로 가능하다.

### 공간 복잡도

각 index마다의 최적의 값을 필요로 하므로 모든 index에 대해 동적 계획법을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

여기서 직전의 값만 이용하는것을 이용할 경우 O(1)의 공간 복잡도로 풀이가 가능하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |   O(N^2)    |    O(N)     |

현재 index에 대해서 다음과 같은 2개의 dp배열을 생성한다.

```cpp
up[index]; // index번째가 up일 때 wiggleMaxLength
down[index]; // index번째가 down일 때 wiggleMaxLength
```

각 값의 초기값은 다음과 같다.

```cpp
// 모든 경우에 대해서 최소 1의 길이의 wiggle을 생성 가능하다.
up[0] = 1;
down[0] = 1;
```

점화식은 다음과 같이 나타낼 수 있다.

```cpp
for (int before = 0; before < i; ++before) {
  if (nums[i] > nums[before]) {
    up[i] = max(up[i], down[before] + 1);
  } else if (nums[i] < nums[before]) {
    down[i] = max(down[i], up[before] + 1);
  }
}
```

현재 index에 대해서 이전의 index들을 탐색하며 가능한 wiggleMaxLength를 갱신한다.

이를 이용해 구현하면 다음과 같다.

```cpp
int wiggleMaxLength(vector<int>& nums) {
  int size = nums.size();
  if (size == 1) return size;

  vector<int> up(size), down(size);
  // initialize
  up[0] = down[0] = 1;
  int answer = 1;

  for (int i = 1; i < size; ++i) {
    for (int before = 0; before < i; ++before) {
      if (nums[i] > nums[before]) {
        up[i] = max(up[i], down[before] + 1);
      } else if (nums[i] < nums[before]) {
        down[i] = max(down[i], up[before] + 1);
      }
    }
  }

  answer = max(answer, max(up.back(), down.back()));
  return answer;
}
```

### 동적 계획법 - one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

dp식을 다음과 같이 설정한다.

```cpp
up[index]; // 현재 index가 직전값에 wiggle up일 때 wiggleMaxLength
down[index]; // 현재 index가 직전값에 wiggle down일 때 wiggleMaxLength
```

이를 이용한다면 직전의 모든 경우를 탐색할 필요 없이 직전 dp값만을 이용해 갱신이 가능하다.

초기값은 동일하다.

점화식은 다음과 같다.

```cpp
// 현재 wiggle up인경우
up[i] = nums[i] > nums[i - 1] ? down[i - 1] + 1 : up[i - 1];
// 현재 wiggle down인경우
down[i] = nums[i] < nums[i - 1] ? up[i - 1] + 1 : down[i - 1];
```

현재 wiggle up, down이 가능한 경우 count를 증가시키고, 불가능한 경우는 직전 값을 그대로 유지한다.

이를 이용해 풀이할 경우 다음과 같다.

```cpp
int wiggleMaxLength(vector<int>& nums) {
  int size = nums.size();
  if (size == 1) return size;

  vector<int> up(size), down(size);
  up[0] = down[0] = 1;

  for (int i = 1; i < size; ++i) {
    up[i] = nums[i] > nums[i - 1] ? down[i - 1] + 1 : up[i - 1];
    down[i] = nums[i] < nums[i - 1] ? up[i - 1] + 1 : down[i - 1];
  }

  return max(up.back(), down.back());
}
```

### 동적 계획법 - space optimized

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

위 풀이방법에서 dp의 직전값만을 이용하므로 최적화 할 경우 다음과 같이 풀이가 가능하다.

```cpp
int wiggleMaxLength(vector<int>& nums) {
  int size = nums.size();
  if (size == 1) return size;

  int down = 1, up = 1;

  for (int i = 1; i < size; ++i) {
    if (nums[i] > nums[i - 1]) {
      up = down + 1;
    } else if (nums[i] < nums[i - 1]) {
      down = up + 1;
    }
  }

  return max(up, down);
}
```

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

매 경우 가능한 최선의 방법을 이용해서 한번에 정답을 찾는다.

매 diff값을 이용해 직전의 diff값과 현재의 diff값이 부호가 다른경우 count를 증가시킨다.

count가 증가한 경우 diff값을 갱신한다. (부호 변경)

이를 이용해 모든 diff값에 대해서 상승 구간, 하강 구간, 유지 구간 세 경우로 판단이 가능하며,

결국 구간에 대해서 상승과 하강이 반복되는 구간을 찾을 수 있다.

이 때 시작구간의 diff값이 0인지 분기 처리한다.

```cpp
int wiggleMaxLength(vector<int>& nums) {
  int size = nums.size();
  if (size == 1) return size;

  int prevdiff = nums[1] - nums[0];
  int count = prevdiff != 0 ? 1 : 0;
  for (int i = 2; i < size; ++i) {
    int diff = nums[i] - nums[i - 1];
    if ((diff > 0 && prevdiff <= 0) || (diff < 0 && prevdiff >= 0)) {
      count++;
      prevdiff = diff;
    }
  }
  return 1 + count;
}
```

## 고생한 점
