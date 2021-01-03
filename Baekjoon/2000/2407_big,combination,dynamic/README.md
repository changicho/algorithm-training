# 2407. 조합

[링크](https://www.acmicpc.net/problem/2407)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   34.269    |

## 설계

### 시간 복잡도

조합을 구하는 경우 factorial 연산을 수행해야 한다.

이 때 시간 복잡도는 N 자체이다.

조합의 공식 nCr = n-1Cr + n-1Cr-1 을 이용하는 경우 문제를 분할해 생각할 수 있다.

이 때 이전의 연산 결과를 저장해 다음번에 구할 때 이용하면 시간복잡도를 더 줄일 수 있다.

최악의 경우 시간 복잡도는 N^2 정도이다. 이는 제한시간 2초 내에 충분하다.

### 공간 복잡도

조합을 덧셈으로 분리해 생각할 수 있다. 이 때 조합으로 만들어 지는 수는 매우 큰 수 이므로 큰 수 연산을 이용해야 한다.

따라서 정답은 매우 큰 수가 나올 수 있으므로 string으로 선언한다.

### 큰 수 연산 (덧셈)

숫자를 string으로 치환하고 이를 이용해 큰수의 연산을 수행할 수 있다.

각 자리수별로 덧셈을 수행하며 올림수 (carry)가 발생하는지 판단한다.

```cpp
string bigNumberAdd(string a, string b) {
  int carry = 0;
  string result = "";

  while (!a.empty() || !b.empty() || carry) {
    if (!a.empty()) {
      carry += a.back() - '0';
      a.pop_back();
    }

    if (!b.empty()) {
      carry += b.back() - '0';
      b.pop_back();
    }

    result += ((carry % 10) + '0');
    carry /= 10;
  }

  reverse(result.begin(), result.end());
  return result;
}
```

### 조합의 공식

조합의 공식인 nCr = n-1Cr + n-1Cr-1 를 이용해 문제를 풀이한다.

이 때 이전 연산 결과를 저장해 이용한다.

```cpp
string dp[101][101];
```

```cpp
// nCr = n-1Cr + n-1Cr-1
string combination(int n, int r) {
  if (n == r || r == 0) {
    return "1";
  }
  string &result = dp[n][r];
  if (result != "") {
    return result;
  }

  result = bigNumberAdd(combination(n - 1, r - 1), combination(n - 1, r));

  return result;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
