# 1216. Valid Palindrome III

[링크](https://leetcode.com/problems/valid-palindrome-iii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열의 길이를 N, 입력받은 수를 K라 하자.

각 문자를 skip하는 모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용한다. 이는 매우 크므로 제한시간 내에 불가능하다.

동적 계획법을 이용해 이전 결과를 재사용해 탐색의 횟수를 줄일 수 있다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법 (top-down)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      54      |   O(N^2)    |   O(N^2)    |

중간에 단어를 건너뛰는 경우가 존재한다.

따라서 각 index에 대한 dp를 선언한다.

현재 index들에서 사용된 K의 최소 갯수에 대한 dp식을 선언 뒤 탐색을 진행한다.

이 때 현재상황에서 가능한 최소값을 설정해야한다.

모든 경우를 탐색했을 때 사용된 K가 입력받은 K이하인지를 판단한다.

```cpp
// definition
int dp[leftI][rightI]; // minimum k count of [leftI][rightI]

// update
if (leftI > rightI) {
  return 0;
}
if (s[leftI] == s[rightI]) {
  return dp[leftI][rightI] = recursive(s, leftI + 1, rightI - 1);
}
return dp[leftI][rightI] = 1 + min(recursive(s, leftI + 1, rightI),
                                    recursive(s, leftI, rightI - 1));

// init
dp[leftI][rightI] = -1; // not visited
```

결과적으로 팰린드롬을 생성해야 하므로, 비교할 왼쪽 index, 오른쪽 index를 재귀호출에 같이 넘겨준다.

이를 이용해 재귀호출로 각 경우들을 탐색하며, 이전에 방문한 경우일 때 더이상의 탐색을 중지한다.

이 때 현재 불가능한 경우 왼쪽, 오른쪽 index에 대해서 한칸씩만 이동시킨 후 탐색을 지속한다.

여기서 현재 남은 글자수와 K에 대해서 이미 이전에 방문이 완료된 경우 더이상 탐색을 중지한다.

이를 구현하면 다음과 같다.

```cpp
// minimum k count of [leftI][rightI]
vector<vector<int>> dp;

int recursive(string &s, int leftI, int rightI) {
  if (leftI > rightI) {
    return 0;
  }

  if (dp[leftI][rightI] != -1) {
    return dp[leftI][rightI];
  }

  if (s[leftI] == s[rightI]) {
    return dp[leftI][rightI] = recursive(s, leftI + 1, rightI - 1);
  }
  return dp[leftI][rightI] = 1 + min(recursive(s, leftI + 1, rightI),
                                      recursive(s, leftI, rightI - 1));
}

bool isValidPalindrome(string s, int k) {
  int length = s.length();
  dp.resize(length + 1, vector<int>(length + 1, -1));

  return recursive(s, 0, length - 1) <= k;
}
```

## 고생한 점
