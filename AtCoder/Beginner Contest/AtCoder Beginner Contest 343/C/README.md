# C - 343

[링크](https://atcoder.jp/contests/abc343/tasks/abc343_c)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

X^3 = K이며 K <= N 인 팰린드롬 수인 최대값 K를 구해야 한다.

이를 모든 K에 대해 순회하며 찾고 팰린드롬인지 검사하는 데 O(sqrt_3(N) \* log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

수의 범위가 매우 크므로 unsigned long long으로 선언한다.

팰린드롬 검사 시에 문자열로 변환할 경우 O(log_10(N))의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) |        시간 복잡도        | 공간 복잡도  |
| :----------: | :-----------------------: | :----------: |
|      31      | O(sqrt_3(N) \* log_10(N)) | O(log_10(N)) |

X^3 = K이며 K <= N 인 모든 K를 순회한다.

이 때 K가 N보다 큰 경우는 탐색을 중지한다.

이 때 K가 팰린드롬인지 검사하고, 팰린드롬인 경우 최대값을 갱신한다.

```cpp
bool isPalindrome(unsigned long long num) {
  string s = to_string(num);
  int len = s.length();
  for (int i = 0; i < len / 2; i++) {
    if (s[i] != s[len - i - 1]) {
      return false;
    }
  }
  return true;
}

unsigned long long solution(unsigned long long &num) {
  unsigned long long answer = 0;

  long long limit = sqrt(num);
  for (unsigned long long i = 0; i <= limit; i++) {
    unsigned long long temp = i * i * i;

    if (temp > num) {
      break;
    }

    if (isPalindrome(temp)) {
      answer = max(answer, temp);
    }
  }

  return answer;
}
```

## 고생한 점
