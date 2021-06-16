# 131. Palindrome Partitioning

[링크](https://leetcode.com/problems/palindrome-partitioning/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자

subString의 index 범위를 left ~ right라고 하자. 각 left ~ right범위의 문자열이 팰린드롬인지 판별하는데 O(N)의 시간 복잡도가 필요하다.

이후 subString들을 나누는 데 현재 index에서 나누는지 나누지 않는지 두가지 경우에 대해 모두 탐색해야 해므로 시간 복잡도는 O(2^N)이다.

매 경우마다 subString들이 문자열인지 판별하는데 O(N)의 시간 복잡도가 소요되므로 최종 시간 복잡도는 O(N \* 2^N)이다.

여기서 동적 계획법을 이용해 미리 팰린드롬의 경우를 모두 구해놓는 경우 시간 복잡도는 O(2^N)이다.

### 공간 복잡도

모든 경우에 대해 탐색하는데 call stack에 최대 O(N)이 쌓인다. 이는 문자열에서 최대 스택에 쌓을 수 있는 갯수가 문자열의 길이와 같기 때문이다.

동적 계획법을 이용할 경우 left ~ right에 대해 팰린드롬인지 여부를 저장해야 한다. 이는 O(N^2)의 공간 복잡도가 필요하다.

### 백트래킹 & 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      64      |   O(2^N)    |    O(N)     |

미리 모든 left ~ right쌍에 대해 팰린드롬 여부를 구해놓는다.

일반식은 다음과 같다.

```cpp
isPalindrome[left][right] = isPalindrome[left + 1][right - 1] && s[left] == s[right]
```

초기값은 다음과 같다.

```cpp
isPalindrome[i][i] = true;
isPalindrome[i][i+1] = s[i] == s[i+1];
```

이와 동시에 palindrome인 경우의 subString들을을 모두 구해놓는다.

```cpp
subStrings[left][right] = s[left] + subStrings[left + 1][right - 1] + s[right];
```

이후 재귀 호출을 이용해 중간에 자르는 모든 경우에 대해 탐색을 진행한다.

입력받은 현재 index(인자)에서부터 끝낼 점을 반복문을 이용해 탐색한다.

이 때 팰린드롬인 경우에만 탐색을 진행해 불필요한 탐색을 중지한다.

```cpp
void recursive(string &s, int left, vector<string> &array) {
  if (left >= s.length()) {
    answers.push_back(array);
    return;
  }

  for (int right = left; right < s.length(); right++) {
    if (isPalindrome[left][right]) {
      array.push_back(subStrings[left][right]);
      recursive(s, right + 1, array);
      array.pop_back();
    }
  }
}
```

이를 종합하면 다음과 같다.

```cpp
vector<vector<string>> partition(string s) {
  int length = s.length();
  vector<vector<string>> answers;
  vector<vector<bool>> isPalindrome(length, vector<bool>(length, false));
  vector<vector<string>> subStrings(length, vector<string>(length, ""));

  for (int i = 0; i < length; i++) {
    isPalindrome[i][i] = true;
    subStrings[i][i] += s[i];

    if (i + 1 < length && s[i] == s[i + 1]) {
      isPalindrome[i][i + 1] = true;
      subStrings[i][i + 1] += s[i];
      subStrings[i][i + 1] += s[i + 1];
    }
  }

  for (int size = 0; size < length; size++) {
    for (int left = 1; left < length - size - 1; left++) {
      int right = left + size;

      if (isPalindrome[left][right] && s[left - 1] == s[right + 1]) {
        isPalindrome[left - 1][right + 1] = true;
        subStrings[left - 1][right + 1] = s[left - 1] + subStrings[left][right] + s[right + 1];
      }
    }
  }

  vector<string> currentList;

  recursive(answers, s, 0, currentList, isPalindrome, subStrings);
  return answers;
}

void recursive(vector<vector<string>> &answers, string &s, int left, vector<string> &array, vector<vector<bool>> &isPalindrome, vector<vector<string>> &subStrings) {
  if (left >= s.length()) {
    answers.push_back(array);
    return;
  }

  for (int right = left; right < s.length(); right++) {
    if (isPalindrome[left][right]) {
      array.push_back(subStrings[left][right]);
      recursive(answers, s, right + 1, array, isPalindrome, subStrings);
      array.pop_back();
    }
  }
}
```

## 고생한 점
