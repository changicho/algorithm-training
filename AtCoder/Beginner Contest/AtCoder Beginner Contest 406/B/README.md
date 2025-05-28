# B - Product Calculator

[링크](https://atcoder.jp/contests/abc406/tasks/abc406_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열 A의 크기를 N이라 하자. 이 중 가장 큰 값을 M이라  하자.

각 수를 순회하며 곱셈을 수행하는데 O(N)의 시간 복잡도를 사용한다.

직접 큰 수 곱을 구현할 경우 매번 O(log_10(M)^2)의 시간 복잡도를 사용하며 이는 거의 O(1)이다.

### 공간 복잡도

10^18을 넘을 수 있으므로 long long을 사용한다.

이에 공간 복잡도는 O(1)이다.

연산 과정에서 범위를 넘을 수 있으므로 수식을 변환하거나 큰 수 곱을 사용한다.

이에 O(log_10(M))의 공간 복잡도를 사용한다. 이는 거의 O(1)이다.

### 나눗셈 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

a \* b의 자리수가 k를 넘는지 확인해야 한다.

이를 반대로 a = k자리수 / b 로 변환해 long long 형을 넘치지 않도록 구현한다.

```cpp
long long solution(int n, int k, vector<long long> &nums) {
  long long answer = 1;

  long long limit = 1;
  for (int i = 0; i < k; i++) {
    limit *= 10;
  }
  limit -= 1;

  for (long long &num : nums) {
    if (answer > (limit / num)) {
      answer = 1;
    } else {
      answer *= num;
    }
  }

  return answer;
}
```

### 큰수 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

큰 수 연산을 구현해 매번 곱셈을 수행한다.

```cpp
string multiply(string s1, string s2) {
  int n1 = s1.size(), n2 = s2.size();
  if (n1 == 0 || n2 == 0) return "0";

  vector<int> temp(n1 + n2, 0);
  int i1 = 0;
  int i2 = 0;
  for (int i = n1 - 1; i >= 0; i--) {
    int carry = 0;
    int n1 = s1[i] - '0';
    i2 = 0;

    for (int j = n2 - 1; j >= 0; j--) {
      int n2 = s2[j] - '0';

      int sum = n1 * n2 + temp[i1 + i2] + carry;
      carry = sum / 10;

      temp[i1 + i2] = sum % 10;

      i2++;
    }

    if (carry > 0) temp[i1 + i2] += carry;

    i1++;
  }

  int i = temp.size() - 1;
  while (i >= 0 && temp[i] == 0) i--;
  if (i == -1) return "0";

  string s = "";
  while (i >= 0) s += to_string(temp[i--]);

  return s;
}

string solution(int n, int k, vector<string> &A) {
  string answer = "1";
  for (string &num : A) {
    answer = multiply(answer, num);

    if (answer.size() > k) {
      answer = "1";
    }
  }

  return answer;
}
```

## 고생한 점
