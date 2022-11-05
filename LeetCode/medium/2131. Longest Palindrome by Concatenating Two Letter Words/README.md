# 2131. Longest Palindrome by Concatenating Two Letter Words

[링크](https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

words의 크기를 N이라 하자.

각 word는 알파벳 소문자(26종류) 두 글자의 조합이므로 최대 26^2가지 조합이 생성된다.

words를 순회하며 각 단어들을 hash map에 counting한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

이 과정이서 각 단어와, 뒤집은 단어가 같이 존재하는 경우 이를 감소시키며 정답을 증가시킨다.

이후 words 중에서 팰린드롬의 중앙에 올 수 있는 값을 찾는다.

이 경우 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash map에 저장될 수 있는 단어의 종류는 26^2가지이다.

따라서 공간 복잡도는 O(1)이다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     463      |    O(N)     |    O(1)     |

각 word를 순회하며 다음을 수행한다.

- 현재 word를 뒤집은 단어가 hash map에 존재하는 경우, count를 감소시키고 정답을 증가시킨다.
- 존재하지 않는 경우 hash map에 count를 증가시킨다.

이후 중앙에 위치할 수 있는 값 (두 글자가 같음)이 존재하는 지 찾고 존재할 경우 정답을 증가시킨다.

```cpp
int longestPalindrome(vector<string> &words) {
  unordered_map<string, int> counts;
  int answer = 0;
  for (string &word : words) {
    string reversed = {word.back(), word.front()};

    if (counts.count(reversed) > 0) {
      counts[reversed]--;
      if (counts[reversed] == 0) counts.erase(reversed);
      answer += 4;
    } else {
      counts[word]++;
    }
  }

  for (auto &it : counts) {
    string word = it.first;
    if (word.front() == word.back()) {
      answer += 2;
      break;
    }
  }
  return answer;
}
```

## 고생한 점

중복된 문자들이 존재할 수 있음
