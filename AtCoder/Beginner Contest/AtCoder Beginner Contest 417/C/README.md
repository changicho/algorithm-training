# C - Distance Indicators

[링크](https://atcoder.jp/contests/abc417/tasks/abc417_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

hash map과 수식을 이용해 순회하며 정답을 구할 수 있다. 이에 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

hash map을 사용하므로 O(N)의 공간 복잡도를 갖는다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      49      |    O(N)     |    O(N)     |

문제에서 주어신 식을 다음과 같이 변형할 수 있다.

```text
i < j 일때
j − i = A[i] + A[j] 를 만족하는 i, j쌍을 구한다.

변형하면 j - A[j] = i + A[i]
```

따라서 현재 j에 대해서 순회하며 조건을 만족하는 i의 갯수를 정답에 더한다.

이후 현재값을 토대로 j + nums[j]의 카운트를 증가시킨다.

```cpp
long long solution(int size, vector<int> &nums) {
  long long answer = 0;

  // i < j
  // j − i = A[i] + A[j]
  // j - A[j] = i + A[i]

  unordered_map<int, long long> um;
  for (int i = 0; i < size; i++) {
    int target = i - nums[i];

    answer += um[target];

    um[nums[i] + i]++;
  }

  return answer;
}
```

## 고생한 점
