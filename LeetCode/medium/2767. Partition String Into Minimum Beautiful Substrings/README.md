# 2767. Partition String Into Minimum Beautiful Substrings

[링크](https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

각 글자마다 cut하는 모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 이용해 완전 탐색할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |   O(2^N)    |    O(N)     |

각 index에 대해서 cut하는 경우와 cut하지 않는 경우를 모두 탐색한다.

이 때 현재까지 넘어온 부분 문자열이 유효한지 판별해야 한다.

이후 index의 끝에 도달한 경우 정답을 갱신한다.

이 때 정답은 s를 나눈 문자들의 최소 개수이다.

```cpp
int answer = INT_MAX;
string s;
int size;

int convert(string s) {
  int num = 0;
  reverse(s.begin(), s.end());
  int digit = 1;
  for (char &c : s) {
    if (c == '1') {
      num += digit;
    }
    digit *= 2;
  }
  return num;
}

bool checkFivePow(int num) {
  while (num > 1) {
    if (num % 5 != 0) return false;
    num /= 5;
  }
  return true;
}

bool isValid(string s) {
  if (s[0] == '0') return false;
  int num = convert(s);

  return checkFivePow(num);
}

void recursive(int index, int count, string cur) {
  if (index == size) {
    if (cur == "") {
      answer = min(answer, count);
    }
    return;
  }

  cur += s[index];

  if (cur[0] == '0') return;
  // cut case
  if (isValid(cur)) {
    recursive(index + 1, count + 1, "");
  }

  // not cut case
  recursive(index + 1, count, cur);
}

int minimumBeautifulSubstrings(string s) {
  this->s = s;
  this->size = s.size();

  recursive(0, 0, "");

  if (answer == INT_MAX) return -1;
  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |   O(N^2)    |    O(N)     |

각 index마다 시작점으로, 해당 index에서 시작하는 부분 문자열들마다 조건을 만족하는 경우 쪼갤 수 있는 최소 횟수를 갱신한다.

다음과 같은 dp식을 생성한다.

```cpp
// definition
int dp[index+1]; // 해당 index에서 cut했을 때의 최소 부분숫자 갯수

// init
dp[0] = 0;

// update
dp[j + 1] = min(dp[j + 1], dp[i] + 1); // i ~ j까지의 부분 문자열이 조건을 만족하는 경우
```

이를 이용해 구현하면 다음과 같다.

```cpp
int minimumBeautifulSubstrings(string s) {
  int size = s.size();

  vector<int> dp(size + 1, MAX);
  dp[0] = 0;

  for (int i = 0; i < size; i++) {
    if (s[i] == '0') continue;

    for (int j = i, cur = 0; j < size; j++) {
      cur = cur * 2 + s[j] - '0';

      // 15625 is the biggest pow of 5 with 15 bits.
      if (15625 % cur == 0) {
        dp[j + 1] = min(dp[j + 1], dp[i] + 1);
      }
    }
  }
  return dp[size] == MAX ? -1 : dp[size];
}
```

## 고생한 점
