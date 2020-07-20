# 2661. 좋은수열

[링크](https://www.acmicpc.net/problem/2661)

| 난이도  | 정답률(\_%) |
| :-----: | :---------: |
| Gold IV |   53.887    |

## 설계

### 시간 복잡도

완전 탐색으로 풀 경우 3^80번을 수행해야 하며 이는 제한시간 내에 불가능하다.

따라서 greedy한 방법으로 접근해야 한다.

각 경우마다 탐색이 가능한 경우만 탐색을 지속하며, 최초로 끝까지 다다랐을 때가 제일 작은 수이다.

이 때 탐색의 순서는 다음과 같다.

현재 index번째의 숫자가

1. 1
2. 2
3. 3

### 공간 복잡도

80자리 숫자는 매우 크므로 string으로 선언한다.

### 탐색

각 경우마다 최선의 경우로 탐색을 이어나간다.

이 때 현재 선택한 경우가 미래에 정답에 도달하지 못할 수 있음에 유의한다.

현재 경우에서 맨 뒤에 1, 2, 3을 붙였을 때 가능한지 여부는 다음과 같이 판단할 수 있다.

- 맨 뒤에서 부터의 수열들을 분석해 연속된 수열인지 판단한다.

이는 수열의 자리수를 증가시켜 가며 탐색하기 때문에, 맨 뒤에서 부터 부분 수열을 분석하면 되기 때문이다.

따라서 수열 123123의 경우는 다음과 같이 나눠 생각한다.

- 123/123
- 12 31/23
- 1231 2/3

```cpp
bool canMake(string line) {
  int length = line.length();
  for (int size = 1; size <= length / 2; size++) {
    int firstStart = length - (size * 2);
    int secondStart = length - size;

    string first = "";
    string second = "";

    for (int j = 0; j < size; j++) {
      first += line[firstStart + j];
      second += line[secondStart + j];
    }
    if (first == second) {
      return false;
    }
  }
  return true;
}
```

### DFS

DFS의 탐색은 다음과 같이 수행한다.

```cpp
void dfs(int index, string line) {
  if (line.length() == N) {
    if (answer > line) {
      answer = line;
      makeAnswer = true;
    }
    return;
  }
  if (makeAnswer) {
    return;
  }

  string newLine;

  for (int i = 1; i <= 3; i++) {
    newLine = line;
    newLine += i + '0';

    if (canMake(newLine)) {
      dfs(index + 1, newLine);
    }
  }
}
```

이 떄 한번 정답에 도달한 경우가 만들 수 있는 제일 작은 정답이므로, 이후 더이상 탐색을 이어나가지 않음에 유의한다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
