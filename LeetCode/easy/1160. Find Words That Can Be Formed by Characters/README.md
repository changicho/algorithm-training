# 1160. Find Words That Can Be Formed by Characters

[링크](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 words의 크기를 N, 각 단어의 평균 길이를 L이라 하자.

각 단어들의 원소의 수를 세고 이를 words의 크기만큼 반복하며 비교할 경우 시간 복잡도는 O(N \* L)이다.

### 공간 복잡도

각 단어의 알파벳 갯수를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 단어 알파벳 갯수

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |  O(N \* L)  |    O(1)     |

chars의 알파벳 수를 센 뒤 각 word의 알파벳 수와 비교하며 가능한지 판별한다.

chars의 각각 알파벳의 수들이 word보다 더 많은 경우 word를 만들 수 있다.

```cpp
bool check(string &word, int counts[26]) {
  int curCount[26] = {
      0,
  };
  for (char &c : word) {
    curCount[c - 'a']++;
    if (curCount[c - 'a'] > counts[c - 'a']) return false;
  }
  return true;
}

int countCharacters(vector<string> &words, string chars) {
  int answer = 0;

  int counts[26] = {
      0,
  };
  for (char &c : chars) {
    counts[c - 'a']++;
  }

  for (string &word : words) {
    if (check(word, counts)) {
      answer += word.size();
    }
  }
  return answer;
}
```

## 고생한 점
