# 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence

[링크](https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 sentence의 길이를 N, searchWord의 길이를 M이라 하자.

문자열을 공백 기준으로 나누는 데 O(N)의 시간 복잡도가 소요된다.

이 나눠진 문자의 갯수를 K라 하자.

이후 각 토큰을 순회하며 searchWord와 비교하며, searchWord의 길이만큼 비교하므로 O(K \* M)의 시간 복잡도가 소요된다.

따라서 총 O(N + K \* M)의 시간 복잡도가 소요된다.

### 공간 복잡도

문자열을 공백 기준으로 나누는 데 O(N)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* M)  |    O(N)     |

```cpp
vector<string> split(string &s) {
  stringstream ss(s);
  string temp;
  vector<string> ret;

  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

int isPrefixOfWord(string sentence, string searchWord) {
  vector<string> arr = split(sentence);
  int size = arr.size();

  for (int i = 0; i < size; i++) {
    string word = arr[i];
    int idx = word.find(searchWord);

    if (idx == 0) {
      return i + 1;
    }
  }
  return -1;
}
```

## 고생한 점
