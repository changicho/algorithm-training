# 394. Decode String

[링크](https://leetcode.com/problems/decode-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

모든 문자열을 한번씩 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

괄호 안의 패턴들을 숫자만큼 반복해야 하며, 패턴 내부에 패턴이 존재할 수 있다.

K를 패턴 내에 존재하는 가장 큰 수라고 하자. 패턴을 최대 K번 붙여야한다.

따라서 내부적으로 최악의 경우 inner 시간 복잡도는 O(K)이다.

재귀호출하며 결국 모든 문자를 한번씩 방문하므로 최종 시간 복잡도는 O(K \* N)이다.

### 공간 복잡도

기존 패턴을 convert한 새로운 문자열을 계속 붙여나가야한다.

이를 저장할 공간이 필요하므로 새로운 패턴에 대해 최악의 경우 공간 복잡도는 O(K \* N)이다.

재귀호출의 경우 call stack에 최대 N번까지 쌓일 수 있으므로 O(N)이 필요하다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(K \* N)  |  O(K \* N)  |

문자를 순회하며 다음과 같은 규칙으로 진행한다.

함수가 호출된 경우 새로운 문자열을 반환한다.

- 소문자인 경우 반환할 문자열에 더한다.
- 숫자를 발견한 경우 문자열을 순회하며 숫자를 찾는다.
- 이후 괄호 안에 속해있는 패턴문자열을 찾는다.
- 이 패턴 문자열을 재귀호출을 통해 다시 변환하며 숫자만큼 반복해 붙인다.
- index를 뒤로 이동시킨다.

```cpp
string decodeString(string s) {
  int length = s.length();
  if (length == 0) return "";
  string ret = "";

  for (int i = 0; i < length; i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      ret += s[i];
      continue;
    }

    string countStr = getNumber(s, i);
    int count = stoi(countStr);
    i += countStr.length();

    string temp = getInnerStr(s, i);
    i += temp.length() + 1;

    string innerString = decodeString(temp);
    while (count--) {
      ret += innerString;
    }
  }

  return ret;
}

string getNumber(string &s, int start) {
  string temp = "";
  while (s[start] >= '0' && s[start] <= '9') {
    temp += s[start];
    start++;
  }
  return temp;
}

string getInnerStr(string &s, int start) {
  string temp = "";
  int openCount = 1;
  start++;
  while (openCount > 0) {
    if (s[start] == '[') {
      openCount += 1;
    } else if (s[start] == ']') {
      openCount -= 1;
    }
    temp += s[start];
    start++;
  }
  temp.erase(temp.length() - 1, 1);

  return temp;
}
```

## 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(K \* N)  |  O(K \* N)  |

문자를 순회하며 괄호가 열린 경우에 숫자와 직전의 반환할 문자열을 stack에 저장하고 패턴을 다시 찾기 시작한다.

이후 괄호가 닫힌 경우 직전의 숫자와 문자열 그리고 현재 패턴을 이용해 새로운 정답을 생성한다.

```cpp
string decodeString(string s) {
  stack<string> chars;
  stack<int> nums;

  string answer = "";
  int num = 0;

  for (char c : s) {
    if (isdigit(c)) {
      num = num * 10 + (c - '0');
      continue;
    }
    if (isalpha(c)) {
      answer += c;
      continue;
    }
    if (c == '[') {
      chars.push(answer);
      nums.push(num);

      answer = "";
      num = 0;
      continue;
    }
    if (c == ']') {
      string pattern = answer;
      int count = nums.top() - 1;

      while (count--) {
        answer += pattern;
      }
      answer = chars.top() + answer;
      chars.pop();
      nums.pop();
      continue;
    }
  }

  return answer;
}
```

## 고생한 점
