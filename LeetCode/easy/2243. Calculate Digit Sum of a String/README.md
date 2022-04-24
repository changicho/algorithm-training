# 2243. Calculate Digit Sum of a String

[링크](https://leetcode.com/problems/calculate-digit-sum-of-a-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 L이라 하자.

문자열의 길이가 k이하인 경우 때 까지 반복해야 하는 횟수를 C라고 하자.

각 경우마다 문자열을 순회하며 수를 변환해야하므로 총 시간 복잡도는 O(L \* C)이다.

### 공간 복잡도

각 경우마다 새로운 문자열을 생성하므로 O(L)의 공간 복잡도를 사용한다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(L \* C)  |    O(L)     |

현재 숫자의 길이가 K이하인 경우 해당 숫자를 그대로 반환한다.

그 외의 경우는 s를 길이가 k 이하인 문자열들로 쪼개고, 각 문자열들을 구성하는 숫자의 합으로 새로운 문자열을 만든다.

이를 구현하면 다음과 같다.

```cpp
vector<string> split(string &s, int k) {
  string temp = "";
  vector<string> v;
  for (char &c : s) {
    temp += c;
    if (temp.length() == k) {
      v.push_back(temp);
      temp = "";
    }
  }

  if (temp != "") v.push_back(temp);
  return v;
}

string digitSum(string s, int k) {
  if (s.length() <= k) return s;

  vector<string> array = split(s, k);

  string next = "";
  for (string &num : array) {
    int cur = 0;
    for (char &c : num) {
      cur += c - '0';
    }

    next += to_string(cur);
  }
  return digitSum(next, k);
}
```

## 고생한 점
