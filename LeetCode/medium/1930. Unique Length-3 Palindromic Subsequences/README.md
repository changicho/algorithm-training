# 1930. Unique Length-3 Palindromic Subsequences

[링크](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(N^3)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

3글자에 대한 팰린드롬을 판별하면 되므로 prefix sum을 이용해 현재까지 방문한 단어의 종류들을 저장후 탐색을 이용해 구할 수 있다.

이 경우 prefix sum의 갱신에 O(N), 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum에 O(N)의 공간 복잡도를 사용한다.

### prefix sum & bit mask

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     159      |    O(N)     |    O(N)     |

중복되는 경우를 제거해야 하므로 가운데 글자와 양 끝 글자의 쌍에 대한 visited 배열을 생성한다.

가운데 글자에 대해 탐색하며 해당 가운데 글자의 index 왼쪽부분과 오른쪽 부분을 나눠 생각할 수 있다.

이 때 왼쪽 부분과 오른쪽 부분에 같은 글자가 있는 경우 palindrome을 만들 수 있는 경우이다.

따라서 각 index까지의 왼쪽 부분과 오른쪽 부분에 대해 각 알파벳을 포함하는 여부를 미리 prefix sum을 이용해 구해놓고 사용할 수 있다.

이 때 각 알파벳에 대한 존재 여부만 판단하면 되므로 bit mask를 이용해 구할 수 있다.

```cpp
int countPalindromicSubsequence(string s) {
  int length = s.size();

  vector<int> fromLeft(length, 0);
  vector<int> fromRight(length, 0);

  for (int i = 0; i < length; i++) {
    if (i - 1 >= 0) {
      fromLeft[i] = fromLeft[i - 1];
    }
    fromLeft[i] |= 1 << (s[i] - 'a');
  }
  for (int i = length - 1; i >= 0; i--) {
    if (i + 1 < length) {
      fromRight[i] = fromRight[i + 1];
    }
    fromRight[i] |= 1 << (s[i] - 'a');
  }

  bool visited[26][26] = {
      false,
  };
  int answer = 0;
  for (int i = 1; i < length - 1; i++) {
    int cur = s[i] - 'a';

    int left = i - 1, right = i + 1;

    for (int j = 0; j < 26; j++) {
      int bit = 1 << j;
      if (fromLeft[left] & bit && fromRight[right] & bit) {
        if (visited[cur][j]) continue;
        visited[cur][j] = true;

        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
