# 1945. Sum of Digits of String After Convert

[링크](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 문자열 s의 길이를 N, 수를 K라 하자.

매 경우마다 직접 계산할 경우 O(N \* K)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 경우마다 문자열을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

각 경우마다 수를 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* K)  |    O(N)     |

각 경우마다 문자열로 수를 나타내며 이를 순회하며 새로운 수를 만든다.

```cpp
int getLucky(string s, int k) {
  string sum = "";
  for (char &c : s) {
    sum += to_string(int(c - 'a') + 1);
  }

  while (k--) {
    int newSum = 0;
    for (char &c : sum) {
      newSum += (c - '0');
    }
    sum = to_string(newSum);
  }
  return stoi(sum);
}
```

### 시뮬레이션 (숫자만)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* K)  |    O(1)     |

처음 s를 순회하며 수를 미리 만든 뒤 이후 숫자로만 변환을 수행한다.

```cpp
int getLucky(string s, int k) {
  int sum = 0;
  k--;
  for (char &c : s) {
    int num = c - 'a' + 1;
    sum += (num / 10) + num % 10;
  }

  while (k--) {
    int newSum = 0;
    while (sum > 0) {
      newSum += sum % 10;
      sum /= 10;
    }
    sum = newSum;
  }
  return sum;
}
```

## 고생한 점
