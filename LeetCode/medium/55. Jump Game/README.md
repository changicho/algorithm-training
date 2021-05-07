# 55. Jump Game

[링크](https://leetcode.com/problems/jump-game/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기는 최대 3 \* 10^4 이다.

모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

따라서 그리디 알고리즘과 동적 계획법을 이용해 문제를 풀이한다.

동적 계획법의 경우 최악의 경우 O(N^2)번 만에 문제 풀이가 가능하다.

그리디 알고리즘의 경우 O(N)번 만에 문제 풀이가 가능하다.

### 공간 복잡도

동적 계획법의 경우 각 index마다 도달 가능한지 여부를 판단해야 하므로 O(N)의 공간 복잡도가 필요하다.

그리디 알고리즘의 경우 별도의 공간이 필요하지 않다. O(1)

### 그리디 알고리즘 (시작점 부터)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

시작점부터 각 단계별로 도달 가능한 다음 위치의 최대 값을 갱신한다.

매번 다음 위치를 두 값중에 큰 값으로 갱신한다.

- 이전 다음 위치
- 현재 위치 + 현재 위치에서 뛰어 넘을수 있는 크기

이 때 값을 갱신했음에도 현재 위치가 다음 위치와 동일한 경우는 뛰어넘을 수 없는 공백이 생기는 경우이다.

공백이 생기는 경우 맨 끝에 도달할 수 없으므로 false를 반환한다.

모든 순회를 끝낸 경우는 끝에 도달할 수 있는 경우이므로 true를 반환한다.

```cpp
bool canJump(vector<int>& nums) {
  int size = nums.size();

  int next = 0;
  for (int position = 0; position < nums.size() - 1; position++) {
    next = max(next, position + nums[position]);

    if (next == position) {
      return false;
    }
  }

  return true;
}
```

### 그리디 알고리즘 (끝점 부터)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

위 방법과는 반대로 끝점부터 탐색을 진행한다.

도달 가능한 위치를 맨 끝점으로 고정시킨다.

끝 위치부터 탐색을 진행하며 만약 현재 위치에서 점프를 했을 때 도달 가능한 위치에 닿을 수 있는 경우 도달 가능한 위치를 현재 위치로 갱신한다.

이 때 중간에 도달 가능한 위치에 닿지 않는 경우는 공백이 있는 경우이다.

맨 마지막에 도달 가능한 위치가 0인지 판별한다.

```cpp
bool canJump(vector<int>& nums) {
  int size = nums.size();

  int next = size - 1;
  for (int position = size - 1; position >= 0; position--) {
    if (position + nums[position] >= next) {
      next = position;
    }
  }

  if (next == 0) {
    return true;
  }
  return false;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     576      |   O(N^2)    |    O(N)     |

다음과 같은 배열을 생성한다.

```cpp
bool memo[position]; // position위치에 도달 가능한지
```

맨 마지막 위치에서 부터 시작점에 도착가능한지 여부를 판별할 것이므로 맨 마지막 위치의 값은 true로 설정한다.

이후 끝점부터 탐색을 진행한다.

일반식은 다음과 같다.

- 현재 위치에서부터 도달 가능한 모든 위치를 탐색한다.
- 만약 도달 가능한 위치가 이전에 끝점에서부터 도달 가능하면 현재 위치도 도달 가능하다.

```cpp
bool canJump(vector<int> nums) {
  int size = nums.size();
  vector<bool> memo(size, false);

  memo[size - 1] = true;

  for (int position = size - 2; position >= 0; position--) {
    int furthest = min(position + nums[position], size - 1);

    for (int next = position + 1; next <= furthest; next++) {
      if (memo[next] == true) {
        memo[position] = true;
      }
    }
  }

  if (memo.front() == true) {
    return true;
  }
  return false;
}
```

맨 처음부터 탐색을 진행하는 경우 또한 동일하다.

```cpp
bool canJump(vector<int>& nums) {
  int size = nums.size();
  vector<bool> memo(size, false);
  memo[0] = true;

  for (int from = 0; from < size; from++) {
    int limit = min(size, from + nums[from] + 1);
    for (int to = from + 1; to < limit; to++) {
      if (memo[from] == true) {
        memo[to] = true;
      }
    }
  }

  if (memo.back() == true) {
    return true;
  }
  return false;
}
```

## 고생한 점
