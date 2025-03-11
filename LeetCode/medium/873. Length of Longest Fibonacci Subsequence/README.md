# 873. Length of Longest Fibonacci Subsequence

[링크](https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N, 원소의 최대값을 M이라 하자.

M은 최대 10^9 이다.

맨 처음 피보나치 수열의 시작값 2개를 정해야 한다. 이에 O(N^2)의 시간 복잡도를 사용한다.

hash set을 이용해 이전에 나오는 수인지 판별할 때 각 경우마다 O(1)의 시간 복잡도가 소요된다.

또한 각 쌍에 대해 다음 피보나치 수열을 모두 구하는 경우 최악의 경우 O(43)의 시간 복잡도를 사용한다.

혹은 동적 계획법을 이용해 각 diff에 대해 값을 갱신할 수 있다.

이 경우 O(N^2)의 시간 복잡도가 소요된다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도가 필요하다.

동적 계획법에 O(N^2)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     270      |   O(N^2)    |    O(N)     |

두 수를 고르고 이 두 수로 생성할 수 있는 모든 피보나치 수들을 탐색한다.

이 때 피보나치 수들을 구하는 데 M이 10^9이며 최대 43번까지만 반복한다.

이를 모든 쌍에 대해 반복한다.

```cpp
int lenLongestFibSubseq(vector<int>& arr) {
  int size = arr.size();
  unordered_set<int> us(arr.begin(), arr.end());

  int answer = 0;

  for (int first = 0; first < size; first++) {
    for (int second = first + 1; second < size; second++) {
      int prev = arr[second];
      int target = arr[first] + arr[second];

      int len = 2;

      while (us.count(target) > 0) {
        int temp = target;
        target += prev;
        prev = temp;

        len++;
        answer = max(answer, len);
      }
    }
  }

  return answer;
}
```

## 고생한 점
