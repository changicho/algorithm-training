# 60058. 괄호 변환

[링크](https://programmers.co.kr/learn/courses/30/lessons/60058)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv2   |   3732   |

## 설계

### 시간 복잡도

분할해서 재귀호출을 반복해서 풀이하는 문제이다. (요구조건대로 구현하기만 하면 됨)

따라서 시간 복잡도는 N^2 이내이다.

### 공간 복잡도

문자열만 이용하므로 string 으로 충분하다.

### 구현

```text
1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다.
2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다.
3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
  3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다.
4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다.
  4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다.
  4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다.
  4-3. ')'를 다시 붙입니다.
  4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙입니다.
  4-5. 생성된 문자열을 반환합니다.
```

위와 같은 방법대로 하나하나 구현한다.

우선 u와 v로 분리하는 작업은 다음과 같이 수행한다.

1. 문자열을 순회하며 열린 괄호와 닫힌 괄호의 수의 count 가 같아지는 지점을 찾는다.
2. 그 지점을 기준으로 u,v를 분리함.

```cpp
vector<string> divide(string p) {
  int openCount = 0;
  string a = "", b = "";

  for (int i = 0; i < p.length(); i++) {
    a += p[i];
    if (p[i] == '(') {
      openCount += 1;
    } else {
      openCount -= 1;
    }

    if (openCount == 0) {
      for (int j = i + 1; j < p.length(); j++) {
        b += p[j];
      }
      break;
    }
  }

  return {a, b};
}
```

올바른 괄호 문자열인지의 여부는 stack을 이용해 검사한다.

그리고 solution을 재귀호출해 문제를 해결

```cpp
string solution(string p) {
  if (p == "") return "";

  vector<string> uv = divide(p);
  string u = uv[0];
  string v = uv[1];

  if (isFine(u)) {
    return u + solution(v);
  } else {
    string newLine = "(";
    newLine += solution(v);
    newLine += ")";

    newLine += reverse(u);

    return newLine;
  }
}
```

## 고생한 점
