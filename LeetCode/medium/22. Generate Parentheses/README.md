# 22. Generate Parentheses

[링크](https://leetcode.com/problems/generate-parentheses/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

n은 최대 8 이다. 브루트 포스를 사용할 경우 O(2^(N+N)) 만큼의 시간 복잡도가 소요된다.

이는 매우 큰 숫자이므로 백트래킹, 분할정복을 이용해 풀이할 수 있다.

### 공간 복잡도

vector에 담길 수 있는 크기 만큼의 공간이 필요하다.

### 백트래킹

> 0ms, 시간 복잡도 : O(4^N / sqrt(N))

탐색을 진행할 때 불필요한 경우는 더이상 탐색하지 않을 수 있다.

여는 괄호의 갯수를 open, 닫는 괄호의 갯수를 close라고 하자

open이 N보다 큰경우, close가 open보다 많은 경우는 정답이 될 수 없으므로 탐색을 중지한다.

이 때 탐색의 중지를 함수 호출 후 하는것이 아닌 함수호출 자체를 안하는 편이 속도에 유리하다.

괄호 조합의 갯수는 카탈란 수(Catalan number)로 찾을 수 있다.

백트래킹을 수행할 경우 시간 복잡도는 대략 다음과 같다.

```cpp
4^N / sqrt(N) // time complexity
```

```cpp
vector<string> ret;
int size;

vector<string> generateParenthesis(int n) {
  size = n;

  recursive(0, 0, "");

  return ret;
}

void recursive(int open, int close, string cur) {
  if (close == size && open == size) {
    ret.push_back(cur);
  }
  if (open < size) {
    recursive(open + 1, close, cur + "(");
  }
  if (close < open) {
    recursive(open, close + 1, cur + ")");
  }
}
```

### 부분 집합

> 12ms, 시간 복잡도 : O(4^N / sqrt(N))

하나의 문장을 살펴보면 다음과 같은 구조로 만들어져 있음을 알 수 있다.

```cpp
string line = "(" + leftPart + ")" + rightPart;
```

따라서 여는 괄호의 위치를 0으로 고정하고, 닫는 괄호의 위치를 옮겨가며 leftPart와 rightPart를 재귀호출해 탐색해 정답을 구할 수 있다.

이 때 재귀호출 함수에는 사용할 수 있는 쌍의 수 n을 넣는다.

임계값은 n이 0일때며 이때는 빈 문자열의 조합만 가능하다.

정답인 경우만 탐색하므로 시간 복잡도는 백트래킹일 떄와 동일하다.

```cpp
vector<string> generateParenthesis(int n) {
  vector<string> ret;

  if (n == 0) {
    ret.push_back("");
  } else {
    for (int leftSize = 0; leftSize < n; leftSize++) {
      // 0 ~ n-1까지 할당할 수 있음
      for (string leftPart : generateParenthesis(leftSize)) {
        // rightPart의 크기는 n - 1 - leftSize가 됨
        for (string rightPart : generateParenthesis(n - 1 - leftSize)) {
          ret.push_back("(" + leftPart + ")" + rightPart);
        }
      }
    }
  }
  return ret;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
