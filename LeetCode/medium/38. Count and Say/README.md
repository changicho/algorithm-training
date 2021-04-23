# 38. Count and Say

[링크](https://leetcode.com/problems/count-and-say/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

각 연산을 수행할 때마다 소요되는 시간 복잡도는 해당 숫자의 길이 만큼이다.

각 연산마다 숫자의 길이는 대략 2배씩 증가할 수 있다.

따라서 최악의 경우 시간 복잡도는 O(2^N) 이다.

### 공간 복잡도

각 연산마다 필요한 string 문자열의 길이는 최대 O(2^(N-1)) 이다.

### 브루트 포스

> 8ms

n번째 숫자를 구하기 위해선 n-1번째 숫자를 알아야한다.

결국 연속된 숫자들의 묶음으로 변환한 후, 묶음의 개수 + 숫자 형태로 변환하는 작업이 필요하다.

직접 구현할 경우 다음과 같다.

```cpp
string countAndSay(int n) {
  string number = "1";

  for (int i = 1; i < n; i++) {
    number = convert(number);
  }
  return number;
}

string convert(string number) {
  vector<string> v = split(number);
  string ret = "";

  for (string s : v) {
    int count = s.length();
    char target = s[0];

    ret += to_string(count) + target;
  }
  return ret;
}

vector<string> split(string number) {
  vector<string> v;
  string temp = "";
  char before = 'a';
  for (char c : number) {
    if (c != before) {
      if (temp != "") v.push_back(temp);
      temp = "";
      before = c;
    }
    temp += c;
  }

  v.push_back(temp);
  return v;
}
```

함수로 나누지 않고 다음과 같이 구현할 수 있다.

```cpp
string countAndSay(int n) {
  string number = "1";
  for (int i = 1; i < n; i++) {
    string temp = "";
    number += '&';

    int count = 1;
    for (int index = 1; index < number.length(); index++) {
      if (number[index] == number[index - 1]) {
        count++;
      } else {
        temp += to_string(count);
        temp += number[index - 1];
        count = 1;
      }
    }
    number = temp;
  }
  return number;
}
```

재귀를 이용한 방법

```cpp
string countAndSay(int n) {
  if (n == 1) {
    return "1";
  }
  string number = countAndSay(n - 1);
  string temp = "";
  number += '&';

  int count = 1;
  for (int index = 1; index < number.length(); index++) {
    if (number[index] == number[index - 1]) {
      count++;
    } else {
      temp += to_string(count);
      temp += number[index - 1];
      count = 1;
    }
  }
  number = temp;
  return number;
}
```

실행 시간을 빠르게 하기 위해서 1번째, 2번째 숫자 등은 변환을 수행하지 않고 return할 수 있다.

## 정리

| 내 코드 (ms) |
| :----------: |
|      8       |

## 고생한 점
