# 2207. Maximize Number of Subsequences in a String

[링크](https://leetcode.com/problems/maximize-number-of-subsequences-in-a-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

pattern중 한 문자를 붙였을 때 가장 정답이 클 경우는 다음 2가지중 하나이다.

- pattern.front를 맨 앞에 붙임
- pattern.back을 맨 뒤에 붙임

위 두가지 경우에 대해서 정답을 구해 풀이할 수 있다.

이 경우 subSequences를 구하는 데 한번의 순회로 구할 수 있다. 이 때의 시간 복잡도는 O(N)이다.

2가지 경우에 대해 구할 수 있으므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

2가지 경우에 대해 새로운 문자열을 구해 풀이할 경우 O(N)의 공간 복잡도를 사용한다.

한번의 순회로 미리 가능한 정답 세트를 구한 뒤, 두 경우중 유리한 경우를 판단해 구할 수 있다.

이 경우 O(1)의 공간 복잡도를 사용한다.

### greedy & brute force

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      91      |    O(N)     |    O(N)     |

다음 2가지 경우가 정답이 될 수 있는 가장 가능성 높은 후보이다.

- pattern.front를 맨 앞에 붙임
- pattern.back을 맨 뒤에 붙임

이는 subSequences를 만들 때 가장 가능성이 높은 경우는 text에 존재하는 모든 문자들에 대해 가능성을 높이는 경우이기 때문이다.

(pattern의 시작점, 끝점이 각각 맨 앞, 맨 뒤에 있는 경우 text에 존재하는 가능한 쌍들에 대해서 만족시킬 수 있으므로)

이후 문자열에 대해서 subSequences의 갯수는 다음과 같이 구한다.

- 각 문자들을 왼쪽에서 부터 순회한다.
- pattern의 시작점을 만나는 경우 count한다.
- pattern의 끝점을 만나는 경우 현재까지 시작점의 갯수를 정답에 더한다.
- 이를 끝까지 반복한다.

이를 구현하면 다음과 같다.

```cpp
long long getCount(string text, string pattern) {
  long long result = 0;
  long long count = 0;

  // greedy way
  for (char &c : text) {
    if (c == pattern.back()) {
      result += count;
    }
    if (c == pattern.front()) {
      count++;
    }
  }

  return result;
}

long long maximumSubsequenceCount(string text, string pattern) {
  long long frontCase = getCount(pattern.front() + text, pattern);
  long long backCase = getCount(text + pattern.back(), pattern);

  return max(frontCase, backCase);
}
```

### greedy & one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(1)     |

위 방법에서 2가지 경우에 순회하는데 중복되는 경우가 발생한다.

따라서 다음과 같이 생각해 볼 수 있다.

- text만 이용해 위 순회 방법을 사용한다.
- 이 때 pattern의 시작점, 끝점에 대한 count를 순회한다.
- 이후 시작점이 많은 경우 text에 시작점을 붙이고, 반대의 경우는 끝점을 붙인다.
- 이 경우 위에서 사용한 방법때로 기존에 count한 시작점, 끝점의 갯수를 더할 수 있다.

이는 두 경우에서 더 유리한 경우를 선택하기 위함이다.

이를 구현하면 다음과 같다.

```cpp
long long maximumSubsequenceCount(string text, string pattern) {
  long long answer = 0;
  long long first = 0, second = 0;

  // greedy way
  for (char &c : text) {
    if (c == pattern.back()) {
      answer += first;
      second++;
    }
    if (c == pattern.front()) {
      first++;
    }
  }

  return answer + max(first, second);
}
```

## 고생한 점
