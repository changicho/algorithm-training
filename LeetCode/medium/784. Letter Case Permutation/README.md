# 784. Letter Case Permutation

[링크](https://leetcode.com/problems/letter-case-permutation/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

모든 알파벳에 대해서 대문자, 소문자 2가지 경우로 탐색을 진행할 수 있다.

따라서 경우의 수는 최대 2^N개가 발생한다.

각 경우의 수마다 문자열의 길이만큼 탐색을 지속하므로 시간 복잡도는 O(2^N \* N)이 된다.

### 공간 복잡도

재귀호출로 탐색을 진행할 경우 콜 스택에 최대 N개까지 쌓일 수 있다.

정답은 최대 2^N개가 생길 수 있으며 문자열의 길이까지 고려할 경우 공간 복잡도는 O(2^N \* N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      | O(2^N \* N) | O(2^N \* N) |

재귀 호출을 이용해 탐색을 진행한다.

이 때 각 index별로 현재 문자가 숫자인경우와 문자인 경우에 대해서 탐색이 나뉜다.

- 문자인경우 : 현재 문자 그대로 가는 경우와 대,소문자 치환한 경우 2가지
- 숫자인 경우 : 현재 문자 그대로 가는 경우

```cpp
void recursive(vector<string> &answer, string &s, int index) {
  int length = s.length();
  if (length == index) {
    answer.push_back(s);
    return;
  }

  recursive(answer, s, index + 1);
  if (isdigit(s[index])) return;

  char origin = s[index];
  if (islower(s[index])) {
    s[index] = toupper(s[index]);
  } else if (isupper(s[index])) {
    s[index] = tolower(s[index]);
  }
  recursive(answer, s, index + 1);
  s[index] = origin;
}

vector<string> letterCasePermutation(string s) {
  vector<string> answer;

  recursive(answer, s, 0);

  return answer;
}
```

## 고생한 점
