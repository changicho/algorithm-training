# D - Gomamayo Sequence

[링크](https://atcoder.jp/contests/abc346/tasks/abc346_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

prefix sum을 이용해 풀이할 경우 O(N)의 시간 복잡도로 풀이 가능하다.

### 공간 복잡도

prefix sum에 O(N)의 공간 복잡도가 필요하다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(N)     |

최종적으로 문자열은 다음과 같은 형태 중 하나로 나타낼 수 있다.

- 0101...100...10101
- 1010...110...10101
- 0101...001...10101
- 1010...011...10101

즉 중복되야 하는 문자열의 index를 i라 할 때 다음 두 가지 중 하나와 같은 문자로 맞춘 최종 형태를 생성한다.

- i-1과 같은 문자
- i+1과 같은 문자

이 때 0 ~ i-1까지 부분과 i+1 ~ N-1까지 부분을 나눠서 생각해 볼 수 있다.

두 부분은 0101, 1010등 직전값과 다른 문자로 이루어진 문자열이며 이를 만드는 비용을 바로 구할 수 있다.

이 값들을 prefix sum으로 저장해놓고 각 range에 대한 합을 빠르게 구한다.

i를 순회하며 각 경우들에 대한 정답을 갱신한다.

이 때 i가 양 끝 값인 경우 연이은 문자와 같은 문자로만 바꿔야 하므로 이를 별도로 계산한다.

```cpp
long long solution(string &s, vector<long long> &costs) {
  int size = s.size();

  // 010101
  vector<long long> dp0(size);
  // 101010
  vector<long long> dp1(size);

  dp0[0] = (s[0] == '0') ? 0 : costs[0];
  dp1[0] = (s[0] == '1') ? 0 : costs[0];

  for (int i = 1; i < size; i++) {
    char cur0 = i % 2 == 0 ? '0' : '1';
    char cur1 = i % 2 == 0 ? '1' : '0';

    dp0[i] = dp0[i - 1] + ((s[i] == cur0) ? 0 : costs[i]);
    dp1[i] = dp1[i - 1] + ((s[i] == cur1) ? 0 : costs[i]);
  }

  long long answer = LLONG_MAX;

  for (int i = 0; i < size; i++) {
    long long leftCost = 0, rightCost = 0;

    long long zeroCost = s[i] == '0' ? 0 : costs[i];
    long long oneCost = s[i] == '1' ? 0 : costs[i];

    if (i == 0) {
      // cur 0 case
      answer = min(answer, dp1[size - 1] - dp1[0] + zeroCost);

      // cur 1 case
      answer = min(answer, dp0[size - 1] - dp0[0] + oneCost);

      continue;
    }

    if (i == size - 1) {
      // dp0 : odd 1, even 0
      // dp1 : odd 0, even 1

      // cur 0 case
      answer =
          min(answer, ((i - 1) % 2 == 1 ? dp1[i - 1] : dp0[i - 1]) + zeroCost);

      // cur 1 case
      answer =
          min(answer, ((i - 1) % 2 == 1 ? dp0[i - 1] : dp1[i - 1]) + oneCost);
      continue;
    }

    // left 0 case
    leftCost = 0;
    rightCost = 0;
    if (i > 0) {
      leftCost = dp0[i - 1];
    }
    if (i < size - 1) {
      rightCost = dp1[size - 1] - dp1[i];
    }
    answer = min(answer, leftCost + rightCost);

    // left 1 case
    leftCost = 0;
    rightCost = 0;
    if (i > 0) {
      leftCost = dp1[i - 1];
    }
    if (i < size - 1) {
      rightCost = dp0[size - 1] - dp0[i];
    }
    answer = min(answer, leftCost + rightCost);
  }

  return answer;
}
```

## 고생한 점
