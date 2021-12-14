# 394. Decode String

[링크](https://leetcode.com/problems/decode-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N, 숫자들 중 가장 긴 숫자를 K라 하자.

모든 문자열을 한번씩 방문해야 하므로 outer 시간 복잡도는 O(N)이다.

괄호 안의 패턴들을 숫자만큼 반복해야 하며, 패턴 내부에 패턴이 존재할 수 있다.

이 과정에서 변환할 때 패턴을 최대 K번 붙여야한다.

따라서 내부적으로 최악의 경우 inner 시간 복잡도는 O(K \* N)이 된다. (문자열 복제)

재귀호출하며 결국 모든 문자를 한번씩 방문하므로 이에 O(N)의 시간 복잡도를 사용한다.

이는 중복되는 연산이 아니므로 최종 시간 복잡도는 O(K \* N)이다.

### 공간 복잡도

기존 패턴을 convert한 새로운 문자열을 계속 붙여나가야한다.

재귀호출의 경우 call stack에 최대 N번까지 쌓일 수 있으므로 O(N)이 필요하다.

이를 저장할 공간이 필요하므로 새로운 패턴에 대해 최악의 경우 공간 복잡도는 O(K \* N)이다.

### 재귀 호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(K \* N)  |  O(K \* N)  |

number만큼 반복할 괄호로 묶인 내부 문자열에 대해서 괄호는 stack구조로 처리해야한다.

이는 stack의 top에 있는 괄호로 묶인 문자열부터 변환해야 하기 때문이다.

이를 위해서 현재 문자열에 대해서 각 경우마다 다음과 같이 분기 처리한다.

- 알파벳 : 현재 문자열에 더한다
- 숫자 : 숫자 부분을 추출한뒤 괄호가 시작하는 부분부터 재귀호출 해준다.
- 닫는 괄호 : 시작한 index부터 현재까지 탐색한 문자열을 반환한다.

최 상단에 있는 괄호의 경우 일반 문자열을 반환하게 되며, 이 경우 호출함수는 call stack에서 빠져나온다.

이 결과값을 숫자만큼 반복한 뒤 다음 call stack에서도 닫는 괄호가 나오는 경우 이를 반복한다.

이 과정을 진행하면서 call stack에는 현재 괄호번째에 해당하는 converted 문자열을 가지게 된다.

여기서 각 문자열의 index를 함수의 인자로 넘겨주고 변화시킨다.

이는 이전에 방문한 위치를 다시 방문하지 않도록 하기 위함이다.

```cpp
string decodeString(const string& s, int& index) {
  int length = s.length();
  string result = "";

  while (index < length) {
    if (s[index] == ']') break;

    if (!isdigit(s[index])) {
      result += s[index++];
    } else {
      int number = 0;
      // build k while next character is a digit
      while (index < length && isdigit(s[index])) {
        number = number * 10 + s[index] - '0';
        index++;
      }

      // ignore the opening bracket '['
      index++;

      string converted = decodeString(s, index);
      // ignore the closing bracket ']'
      index++;

      while (number--) {
        result += converted;
      }
    }
  }

  return result;
}

string decodeString(string s) {
  int index = 0;
  return decodeString(s, index);
}
```

## 두개의 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(K \* N)  |  O(K \* N)  |

문자를 순회하며 괄호가 열린 경우에 숫자와 직전의 반환할 문자열을 stack에 저장하고 패턴을 다시 찾기 시작한다.

여기서 현재 스택의 아래에는 직전까지 탐색하던 문자열이 존재한다.

괄호가 닫힌 경우 직전의 숫자와 문자열 그리고 현재 패턴을 이용해 새로운 정답을 생성한다.

이 사용된 값들은 스택에서 pop한다.

해당 문자열에 현재 패턴을 반복한 새로운 문자열을 더하면 해당 문자열 괄호안에 들어갈 inner 문자열이 된다.

따라서 괄호가 닫힐때 마다 해당 괄호쌍의 inner문자열을 바로 찾을 수 있게 된다.

이 과정중에서 문자열을 중복 방문하지 않는다.

```cpp
string decodeString(string s) {
  stack<int> numberStk;
  stack<string> stringStk;
  string ret = "";
  int number = 0;

  for (char c : s) {
    if (isdigit(c)) {
      number = number * 10 + c - '0';
    } else if (c == '[') {
      // push the number k to numberStk
      numberStk.push(number);
      stringStk.push(ret);

      // initialize
      ret = "";
      number = 0;
    } else if (c == ']') {
      string before = stringStk.top();
      stringStk.pop();

      int count = numberStk.top();
      numberStk.pop();
      while (count--) {
        before += ret;
      }

      ret = before;
    } else {
      ret += c;
    }
  }
  return ret;
}
```

### 재귀 호출 (중복 방문)

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      0       | O(K^(countK) \* N) |  O(K \* N)  |

문자를 순회하며 다음과 같은 규칙으로 진행한다.

함수가 호출된 경우 새로운 문자열을 반환한다.

- 소문자인 경우 반환할 문자열에 더한다.
- 숫자를 발견한 경우 문자열을 순회하며 숫자를 찾는다.
- 이후 괄호 안에 속해있는 패턴문자열을 찾는다.
- 이 패턴 문자열을 재귀호출을 통해 다시 변환하며 숫자만큼 반복해 붙인다.
- index를 뒤로 이동시킨다.

여기서 패턴 문자열을 탐색하고 재귀호출의 인자로 넘겨주며 방문이 중복해서 일어나게 된다.

이 중복은 문자열 내부에 있는 숫자의 개수만큼 일어나게 되므로 이를 countK라고 하자.

이 과정에서 시간 복잡도는 O(K^(countK) \* N)가 된다.

```cpp
string getNumber(string& s, int start) {
  string temp = "";
  int index = start;
  while (isdigit(s[index])) {
    temp += s[index];
    index++;
  }
  return temp;
}

string getInnerStr(string& s, int start) {
  string temp = "";
  int openCount = 1;
  // skip first '['
  int index = start + 1;

  while (openCount > 0) {
    if (s[index] == '[') {
      openCount += 1;
    } else if (s[index] == ']') {
      openCount -= 1;
    }

    temp += s[index];
    index++;
  }
  // remove last ']'
  temp.erase(temp.length() - 1, 1);

  return temp;
}

string decodeString(string s) {
  int length = s.length();
  if (length == 0) return "";
  string ret = "";

  for (int i = 0; i < length; i++) {
    if (isalpha(s[i])) {
      ret += s[i];
      continue;
    }

    string countStr = getNumber(s, i);
    int count = stoi(countStr);
    i += countStr.length();

    string inner = getInnerStr(s, i);
    i += inner.length() + 1;
    // duplicate iterate inner
    string innerString = decodeString(inner);
    while (count--) {
      ret += innerString;
    }
  }

  return ret;
}
```

## 고생한 점
