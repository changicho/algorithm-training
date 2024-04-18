# 3035. Maximum Palindromes After Operations

[링크](https://leetcode.com/problems/maximum-palindromes-after-operations/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

words의 갯수를 N, 평균 길이를 L이라 하자.

각 알파벳의 숫자를 센 뒤, 탐욕 알고리즘을 사용해 길이가 작은 word부터 팰린드롬으로 재배열한다.

이 경우 길이에 대해 words를 정렬하는데 O(N * log_2(N))의 시간 복잡도를 사용한다.

알파벳의 숫자를 세는데 O(N \* L)의 시간 복잡도가 필요하다.

이후 각 글자의 길이들을 순회하며 팰린드롬을 만들 수 있는지 확인한다.

따라서 총 시간 복잡도는 O(N \* (L + log_2(N)))이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

### 탐욕 알고리즘

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      34      | O(N \* (L + log_2(N))) |    O(N)     |

words중에서 길이가 작은 단어들을 팰린드롬으로 만드는 편이 가장 많은 수의 단어를 팰린드롬으로 만드는데 유리하다.

따라서 길이가 작은 단어부터 팰린드롬으로 만들어 팰린드롬의 갯수를 증가시킨다.

각 단어들을 팰린드롬으로 만들기 위해 모든 단어의 알파벳의 수를 센다.

이후 알파벳들을 이용해 만들 수 있는 pair들의 수를 센다.

각 단어를 길이가 짧은 순으로 순회하며 팰린드롬으로 만들기 위해 필요한 pair만큼 기존 pair에서 감소시키며 이를 pair가 음수가 되지 않을 때까지 반복한다.

```cpp
int maxPalindromesAfterOperations(vector<string> &words) {
  int counts[26] = {
      0,
  };
  int pairs = 0;
  int answer = 0;

  vector<int> lengths;
  for (string &w : words) {
    for (char &c : w) {
      counts[c - 'a']++;
    }

    lengths.push_back(w.size());
  }

  for (int i = 0; i < 26; i++) {
    pairs += counts[i] / 2;
  }

  sort(lengths.begin(), lengths.end());
  for (int &length : lengths) {
    pairs -= length / 2;

    if (pairs >= 0) {
      answer++;
    }
  }
  return answer;
}
```

## 고생한 점
