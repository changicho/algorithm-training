# 97. Interleaving String

[링크](https://leetcode.com/problems/interleaving-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

s1과 s2를 sub string들로 나누고 붙였을 때 s3를 만들 수 있는지 확인해야 한다.

s1의 길이를 N, s2의 길이를 M이라 하자.

sub string들을 만느는 것과 어떻게 붙일 지 여부를 완전 탐색할 경우 O(2^(N + M))의 시간 복잡도가 필요하다.

모든 경우를 탐색할 경우 제한 시간 내에 불가능하다. 따라서 백트래킹과 메모이제이션을 이용해 중복된 경우를 줄인다.

이 경우 각 상황별로 s1의 index와 s2의 index의 경우만 탐색하면 되므로 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

동적 계획법을 사용하는 경우 s1의 index와 s2의 index들에 따른 방문 여부와 결과를 체크해야 한다.

이에 필요한 공간 복잡도는 O(N \* M)이다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* M)  |  O(N \* M)  |

s1의 index와 s2의 index를 각각 순회하며 한글자씩 덧붙이며 s3를 만들 수 있는지 검사한다.

이 때 현재 s1의 붙일 문자와 s2의 붙일 문자가 같은 경우에 순서에 따라 s3를 만들 수 있는 여부가 달라진다.

따라서 각 경우마다 s1과 s2의 문자를 붙이는 경우를 모두 탐색한다.

이렇게 모든 경우를 탐색할 경우 시간 복잡도는 O(2^(N + M))이므로 제한시간 내에 불가능하다.

따라서 s1의 index, s2의 index에 따른 방문 여부를 저장해 이전에 방문한 경우 더이상 탐색하지 않고 기존 결과를 이용한다.

```cpp
bool visited[100][100] = {
    false,
};
bool dp[100][100] = {
    false,
};
bool isInterleave(string s1, string s2, string s3) {
  if (s1.length() + s2.length() != s3.length()) return false;

  return recursive(s1, s2, s3, 0, 0, 0);
}

bool recursive(string &s1, string &s2, string &s3, int idx1, int idx2, int idx3) {
  if (idx3 == s3.length()) return true;
  if (visited[idx1][idx2] == true) return dp[idx1][idx2];

  bool response = false;
  if (idx1 < s1.length() && s3[idx3] == s1[idx1]) {
    response |= recursive(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
  }
  if (idx2 < s2.length() && s3[idx3] == s2[idx2]) {
    response |= recursive(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
  }

  visited[idx1][idx2] = true;
  return dp[idx1][idx2] = response;
}
```

## 고생한 점
