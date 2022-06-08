# 439. Ternary Expression Parser

[링크](https://leetcode.com/problems/ternary-expression-parser/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

expression의 길이를 N이라 하자.

T, F에 따라 이후 삼항연산자에서 왼쪽, 오른쪽 식에 대해 구분 후 값을 반환할 수 있다.

이를 분리 -> 재귀호출을 이용해 탐색할 경우 각 과정마다 O(N)의 시간 복잡도를 사용한다.

분리할 때 stack을 사용하며 겹친 식에 대해 구분할 수 있다. 이 과정에 O(1)의 시간 복잡도를 사용한다.

이를 최대 N번까지 반복할 수 있으므로 O(N^2)의 시간 복잡도를 사용한다.

혹은 분리와 재귀호출을 동시에 수행할 수 있다. 이 경우 최종적으로 한번만 순회하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

stack을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

call stack에 O(N)의 공간 복잡도를 사용한다.

### 분리 & 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |   O(N^2)    |    O(N)     |

현재 식에 대해서 다음과 같은 부분으로 분리할 수 있다.

- flag 값 T/F
- 왼쪽 파트
- 오른쪽 파트

이후 flag값에 따라서 왼쪽, 혹은 오른쪽 파트를 선택하고 재귀호출로 답을 반환한다.

이 때 expression의 크기가 1인 경우는 값만 존재하므로 이를 반환한다.

왼쪽, 오른쪽 파트를 찾을 때 stack을 이용해 모든 내부식을 제대로 찾는다.

이를 구현하면 다음과 같다.

```cpp
string parseTernary(string expression) {
  int length = expression.length();
  if (length <= 1) {
    return expression;
  }
  string left = "", right = "";

  bool isTrue = false;
  if (expression.front() == 'T') isTrue = true;

  stack<bool> flags;
  flags.push(true);

  bool isLeft = true;
  for (int i = 2; i < length; i++) {
    char cur = expression[i];

    if (cur == '?') {
      flags.push(true);
    } else if (cur == ':') {
      flags.pop();

      if (flags.empty()) isLeft = false;
    }

    if (isLeft) {
      left += cur;
    } else {
      if (right.length() == 0 && cur == ':') continue;
      right += cur;
    }
  }

  if (isTrue) return parseTernary(left);
  return parseTernary(right);
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(N)     |

위 방법에서 왼쪽 파트, 오른쪽 파트를 매번 찾고 반환하지 않고, 한번만 순회한다.

각 과정에서 flag 문자가 나오는 경우는 파트가 구별되는것을 알 수 있다.

따라서 각 과정에서 flag 가 나오는 경우 해당 부분부터 재귀호출을 수행한다.

이 때 ':' 문자가 나오는 경우 해당 부분에서 탐색을 중지하고 return한다.

현재 조건은 다음 2가지 경우일 수 있다.

- flag부터 시작하는 3항연산자인경우
- 값인 경우

여기서 flag만 존재하는 경우 값이므로 값 째로 반환한다. (flag 이후 '?'가 나오는 지로 판단)

이 탐색에서 결국 한번만 순회하면 되므로 index를 하나만 두고 탐색한다.

이를 구현하면 다음과 같다.

```cpp
int index = 0;

string recursive(string &expression) {
  int length = expression.length();
  string temp = "";

  if (expression[index] == 'T' || expression[index] == 'F') {
    bool isTrue = expression[index] == 'T';
    index++;
    if (index >= length || expression[index] != '?') {
      return (isTrue ? "T" : "F");
    }

    index++;
    string left = recursive(expression);

    index++;
    string right = recursive(expression);

    return isTrue ? left : right;
  }

  for (; index < length; index++) {
    char cur = expression[index];

    if (cur == '?') {
      continue;
    } else if (cur == ':') {
      return temp;
    }
    temp += cur;
  }
  return temp;
}

string parseTernary(string expression) { return recursive(expression); }
```

## 고생한 점
