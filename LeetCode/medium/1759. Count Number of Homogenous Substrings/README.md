# 1759. Count Number of Homogenous Substrings

[링크](https://leetcode.com/problems/count-number-of-homogenous-substrings/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

문자열에서 각 알파벳들의 연속된 개수를 구해야 한다. 이 때 연속된 알파벳의 길이를 X라 했을 때 1~X길이의 substring들의 갯수를 구할 수 있다.

이 경우 순회를 이용해 각 알파벳의 연속된 길이를 구할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

별도의 배열을 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(1)     |

s에서 연속된 같은 문자열들을 부분으로 쪼갠다.

이 때 각 부분의 길이를 X라 했을 때 1~X길이의 substring들의 갯수를 다음과 같이 구할 수 있다.

- 길이가 1 : X개
- 길이가 2 : X-1개
- ...
- 길이가 X : 1개

즉 1부터 X까지의 합이 길이가 X인 substring들의 갯수가 된다.

따라서 순회를 이용해 각 알파벳의 연속된 길이를 구하고, 이를 이용해 각 부분의 substring들의 갯수를 구할 수 있다.

```cpp
const int MOD = 1e9 + 7;

int countHomogenous(string s) {
  char before = s.front();
  int count = 0;

  long long answer = 0;
  for (char &c : s) {
    if (c == before) {
      count++;
    } else {
      long long cur = ((long long)count * (count + 1)) / 2;
      answer += cur;
      answer %= MOD;

      before = c;
      count = 1;
    }
  }
  long long cur = ((long long)count * (count + 1)) / 2;
  answer += cur;
  answer %= MOD;

  return (int)answer;
}
```

## 고생한 점
