# D - XNOR Operation

[링크](https://atcoder.jp/contests/abc418/tasks/abc418_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

동적 계획법을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

길이, 1의 갯수에 대한 짝수,홀수 여부 상태에 대해 동적 계획법을 사용한다.

이에 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(1)     |

주어진 연이은 두 숫자의 변화는 다음과 같다.

- 0,0 : 1
- 0,1 : 0
- 1,0 : 0
- 1,1 : 1

`1` 을 시작으로 이전 단계로 만들 수 있는 문자열들을 나열하면 다음과 같다.

```text
1

00
11

100
001
111
010

...
```

위 규칙을 확인해보면 길이가 짝수인 경우와 홀수인 경우에 따라 1의 갯수가 짝수인지 홀수인지에 따라 다음 상태로 갈 수 있는 문자열의 갯수가 달라진다.

이를 정리하면 다음과 같다.

- 길이가 짝수인 경우 : 1의 갯수가 짝수여야함
- 길이가 홀수인 경우 : 1의 갯수가 홀수여야함

따라서 각 index별로 순회하며 0~index까지의 문자열의 길이와 1의 갯수를 확인한다.

이후 각 과정마다 정답으로 만들 수 있는 경우를 정답에 더한다.

```cpp
auto solution(int size, string &s) {
  int oneCount = 0;

  // [even,odd length][one count odd even]
  long long dp[2][2] = {0};
  dp[0][0] = 1;

  long long answer = 0;

  for (int i = 0; i < size; i++) {
    int length = i + 1;

    if (s[i] == '1') {
      oneCount++;
    }

    if (length % 2 == 0) {
      if (oneCount % 2 == 0) {
        // length even, oneCount even
        answer += dp[0][0];
        answer += dp[1][1];
      } else {
        // length even, oneCount odd
        answer += dp[0][1];
        answer += dp[1][0];
      }
    } else {
      if (oneCount % 2 == 0) {
        // length odd, oneCount even
        answer += dp[1][0];
        answer += dp[0][1];
      } else {
        // length odd, oneCount odd
        answer += dp[1][1];
        answer += dp[0][0];
      }
    }

    dp[length % 2][oneCount % 2]++;
  }

  return answer;
}
```

## 고생한 점
