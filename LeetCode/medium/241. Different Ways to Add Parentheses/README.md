# 241. Different Ways to Add Parentheses

[링크](https://leetcode.com/problems/different-ways-to-add-parentheses/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

expression 문자열의 길이를 N이라 하자.

각 연산들을 기준으로 왼쪽과 오른쪽 식에 괄호를 넣을 수 있다.

모든 경우를 탐색할 때 중복된 경우가 생길 수 있으며 이를 저장할 경우 이전의 연산 결과를 사용할 수 있다.

따라서 문제는 각 문자열의 길이를 증가시키며 이전의 결과를 사용해 dp를 채우는 문제가 된다.

이 때 각 dp의 결과는 vector이며 이 vector의 원소의 개수를 M이라 하자.

dp배열의 크기는 O(N^2)이며 이를 채우는데 O(N^2)의 outer 시간 복잡도가 필요하다.

또한 vector내부의 원소를 탐색하며 dp의 값을 채워야 하므로 이를 탐색하는 데 O(M)의 inner 시간 복잡도가 필요하다.

따라서 시간 복잡도는 O(M \* N^2)이다.

### 공간 복잡도

이전 연산 결과를 사용해야 하므로 dp 배열을 만들어야 한다.

이 dp배열의 크기는 O(N^2)이며 각 dp는 내부에 O(M)크기까지의 공간복잡도가 필요하다.

따라서 공간 복잡도는 O(M \* N^2)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(M \* N^2) | O(M \* N^2) |

dp배열을 다음과 같이 선언한다.

```cpp
vector<int> dp[left][right]; // left ~ right 구간의 문자열에서 괄호를 넣는 모든 경우를 탐색해 만들 수 있는 수들의 집합
```

초기값은 다음과 같다.

```cpp
dp[index][index] = input[i] - '0';
```

일반식은 다음과 같이 나타낼 수 있다.

```cpp
// 모든 i에 대해
dp[left][right] = combine(dp[left][i-1], dp[i+1][right]);
```

이를 이용해 구간의 range를 변화시키며 문제를 풀이할 수 있다.

```cpp
vector<int> diffWaysToCompute(string input) {
  int length = input.length();
  return computeWithDP(input, 0, length - 1);
}

vector<int> dp[21][21];
vector<int> computeWithDP(string &line, int left, int right) {
  if (left == right) {
    return dp[left][right] = {line[left] - '0'};
  }

  vector<int> result;

  for (int i = left; i <= right; i++) {
    if (isdigit(line[i])) continue;
    char oper = line[i];

    if (left <= i - 1 && dp[left][i].empty()) {
      dp[left][i - 1] = computeWithDP(line, left, i - 1);
    }

    if (i + 1 <= right && dp[i + 1][right].empty()) {
      dp[i + 1][right] = computeWithDP(line, i + 1, right);
    }

    for (int leftVal : dp[left][i - 1]) {
      for (int rightVal : dp[i + 1][right]) {
        result.push_back(operation(leftVal, rightVal, oper));
      }
    }
  }

  if (result.empty()) {
    result.push_back(stoi(line.substr(left, right - left + 1)));
  }

  dp[left][right] = result;
  return result;
}

int operation(int left, int right, char oper) {
  if (oper == '+')
    return (left + right);
  else if (oper == '-')
    return (left - right);
  else
    return (left * right);
}
```

## 고생한 점
