# 1404. Number of Steps to Reduce a Number in Binary Representation to One

[링크](https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

직접 시뮬레이션을 수행할 경우 덧셈에 O(N), 각 자리수를 순회하는데 O(N)의 시간 복잡도가 필요하다.

따라서 총 시간 복잡도는 O(N^2)이다.

탐욕 알고리즘을 사용해 한번의 순회로 풀이가 가능하다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

문자열 s를 변환하는데 직접 변환할 경우 O(1)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^2)    |    O(1)     |

주어진 조건에 따라 직접 연산을 수행한다.

```cpp
string addOne(string &s) {
  reverse(s.begin(), s.end());

  int carry = 1;
  for (int i = 0; i < s.size(); i++) {
    s[i] += carry;
    if (s[i] >= '2') {
      carry = 1;
      s[i] = '0';
    } else {
      carry = 0;
    }
  }

  if (carry) {
    s.push_back('1');
  }
  reverse(s.begin(), s.end());
  return s;
}

int numSteps(string s) {
  int answer = 0;
  while (s != "1") {
    answer++;
    if (s.back() == '1') {
      s = addOne(s);
    } else {
      s.pop_back();
    }
  }
  return answer;
}
```

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

나누기 2를 수행하는 경우 비트 시프트 이동과 동일하므로 맨 마지막 비트를 삭제한다.

이 때 짝수인 경우만 시프트를 수행할 수 있으므로 홀수인 경우에는 1을 더해준다.

각 과정마다 직전 carry와 현재 마지막 비트를 더한 값이 짝수, 홀수 여부에 따라 연산을 한번 더 수행한다.

이 때 한번이라도 캐리가 발생한 경우, 이후 과정에서도 계속 carry가 1로 발생함에 유의한다.

```cpp
int numSteps(string s) {
  int size = s.size();

  int answer = 0;
  int carry = 0;

  for (int i = size - 1; i > 0; i--) {
    answer++;

    if ((s[i] - '0' + carry) % 2 == 1) {
      answer++;
    }

    // update carry
    if (s[i] - '0' + carry > 0) {
      carry = 1;
    } else {
      carry = 0;
    }
  }

  return answer + carry;
}
```

## 고생한 점
