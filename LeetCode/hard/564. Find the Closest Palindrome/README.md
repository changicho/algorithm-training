# 564. Find the Closest Palindrome

[링크](https://leetcode.com/problems/find-the-closest-palindrome/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 문자열 n의 길이를 N이라 하자.

팰린드롬중 가장 차이가 작은 수를 찾아야 하므로, 모든 경우를 탐색할 경우 시간 복잡도는 10^N 이다. 이는 제한시간 내에 불가능하다.

탐욕 알고리즘을 사용해 정답의 후보를 줄일 수 있다. 이 경우 모두 탐색할 경우 O(3^(N/2))의 시간 복잡도를 사용한다.

가장 차이가 작은 팰린드롬을 만들기 위해 정답의 후보를 줄일 수 있다.

5가지 경우를 고려하면 되므로 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

유리한 모든 경우를 탐색하는데 O(N)의 공간 복잡도가 필요하다.

각 과정마다 숫자와 문자열로 변경하는데 O(N)의 공간 복잡도가 필요하다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

정답의 후보로 n+1 길이의 숫자, n-1길이의 숫자, n길이의 숫자를 고려해야 한다.

n의 숫자들 중 다른 숫자들 보다 가운데 숫자를 변경하는 편이 유리하다.

이는 앞의 숫자들을 변경할 경우 뒤의 숫자들을 변경하는 것 보다 차이가 크기 때문이다. (단위가 앞으로 갈수록 커짐)

따라서 정답의 후보를 총 5개로 줄일 수 있으며 이는 다음과 같다.

- 앞 절반 부분으로 만든 팰린드롬
- 가운데 부분에 1을 더한 팰린드롬
- 가운데 부분에 1을 뺀 팰린드롬
- n-1 길이의 숫자로 만든 팰린드롬
- n+1 길이의 숫자로 만든 팰린드롬

이를 이용해 정답을 갱신한다.

```cpp
long long makePalindrome(long long number, int size) {
  string ret = to_string(number);

  int retSize = ret.size() - size % 2;
  for (int i = retSize - 1; i >= 0; i--) {
    ret += ret[i];
  }
  return stoll(ret);
}

string nearestPalindromic(string n) {
  int size = n.size();
  long long num = stoll(n);

  long long half = stoll(n.substr(0, (size + 1) / 2));

  long long lengthMinus = pow(10, size - 1) - 1;
  long long lengthPlus = pow(10, size) + 1;
  long long palindrome = makePalindrome(half, size);
  long long palindromePlus = makePalindrome(half + 1, size);
  long long palindromeMinus = makePalindrome(half - 1, size);

  vector<long long> targets = {lengthMinus, lengthPlus, palindrome,
                                palindromePlus, palindromeMinus};

  long long answer = lengthPlus;

  for (long long &target : targets) {
    long long diff = abs(num - target);
    long long ansDiff = abs(answer - num);

    if (diff == 0) continue;

    if (diff < ansDiff) {
      answer = target;
    } else if (diff == ansDiff) {
      answer = min(answer, target);
    }
  }

  return to_string(answer);
}
```

## 고생한 점
