# 1525. Number of Good Ways to Split a String

[링크](https://leetcode.com/problems/number-of-good-ways-to-split-a-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

문자열 s를 p, q로 나누는 데 N - 1가지 경우가 존재한다. (나눌 수 있는 divide point가 글자 사이이므로 N-1개이기 때문)

q의 맨 앞글자를 p의 맨 뒤로 옮기면 경우의 수를 만들 수 있다.

이 순회에 O(N)의 시간 복잡도를 소요하며, 각 경우마다 p, q의 각 알파벳들의 갯수를 구해야한다.

이를 매번 순회해 구할 경우 O(N)의 시간 복잡도를 소요하며 이 방법으로 구현하면 최종 O(N^2)의 시간 복잡도를 사용한다.

이를 구하기 위해 sliding window를 hash map을 통해 구현할 경우 O(1)의 시간 복잡도로 구할 수 있다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

sliding window를 이용하기 위해 hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### sliding window

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |    O(N)     |    O(N)     |

문자열 s는 p와 q로 나눌 수 있으므로 다음 식이 성립한다. p + q = s

p와 q를 구성하는 알파벳의 개수가 같으면 정답의 갯수를 늘린다.

또한 p, q의 최소 길이는 1이여야 한다.

나누는 구분점인 index를 0 ~ (length - 1)까지 순회한다. (between index, index+1)

p, q의 알파벳의 갯수를 구하기 위해 동적 계획법을 사용할 수 있다.

```cpp
dp[length]; // means all alphabet counts until length from first.

dp[index]; // p
dp[length - index]; // q

getAlphabets(dp[index]) == getAlphabets(dp[length - index]) // answer += 1
```

dp를 이용하기 위해 hash map을 사용할 수 있다.

```cpp
unordered_map<char, int> // key : char, value : count of char
```

그리고 p와 q를 비교하는 순서는 다음과 같다.

- 0, length
- 1, length - 1
- 2, length - 2

순차적으로 순회하므로 s의 모든 문자열을 순회하며 first에 추가하고, second에서 제거한다.

만약 first와 second를 구성하는 문자의 갯수가 같다면 정답을 증가시킨다.

```cpp
int numSplits(string s) {
  int answer = 0;
  // make 2 hash map. first (dp[0]), second (dp[length])
  unordered_map<char, int> first, second;
  // fill all char counting to second hash map
  for (char &c : s) {
    second[c] += 1;
  }

  // iterate all char c in string s
  for (char &c : s) {
    // 1. insert c to first (first[c] += 1)
    first[c] += 1;
    // 2. erase c in second (second[c] -= 1)
    second[c] -= 1;
    if (second[c] == 0) second.erase(c);

    // compare different letters of first, second
    if (first.size() == second.size()) {
      answer += 1;
    }
  }
  return answer;
}
```

## 고생한 점
