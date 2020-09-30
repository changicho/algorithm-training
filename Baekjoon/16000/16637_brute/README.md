# 16637. 괄호 추가하기

[링크](https://www.acmicpc.net/problem/16637)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Gold III |   35.676    |

## 설계

### 시간 복잡도

수식의 길이는 최대 19이며, 숫자의 개수는 최대 10개이다.

괄호를 이어지는 상황에서만 묶는다고 했을 때 가능한 경우의 수는 2^10 = 1024 번 정도이다.

이는 모든 경우를 탐색해도 제한시간 내에 충분하다.

### 공간 복잡도

곱하기 연산이 존재하므로 숫자의 형태를 long long 형으로 선언한다.

### 탐색

현재 경우에서 탐색은 다음 두가지 경우로 나뉜다.

- 현재 숫자에 괄호를 씌운 경우
- 현재 숫자에 괄호를 씌우지 않은 경우

따라서 dfs를 다음을 인자로 받는다

- 연산 식의 현재 index
- 지금까지의 연산 결과
- 연산 식

그리고 현재 숫자에 괄호를 씌운 경우는, 현재 숫자와 다음 숫자를 미리 연산한 결과를 바탕으로 이전까지의 결과와 연산을 수행한다.

```cpp
void dfs(int index, long long value, string line) {
  if (index >= line.length()) {
    answer = max(value, answer);
    return;
  }
  char oper = line[index - 1];

  if (index + 2 < line.length()) {
    int bracket = operation(line[index] - '0', line[index + 2] - '0', line[index + 1]);
    dfs(index + 4, operation(value, bracket, oper), line);
  }
  dfs(index + 2, operation(value, line[index] - '0', oper), line);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
