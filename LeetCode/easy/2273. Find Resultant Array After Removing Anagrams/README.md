# 2273. Find Resultant Array After Removing Anagrams

[링크](https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 words의 크기를 N, 각 단어의 길이를 L이라 하자.

각 단어를 이전 단어와 비교해 아나그램인지 판단하는데 카운팅을 사용할 경우 O(L)의 시간이 걸린다.

따라서 총 시간 복잡도는 O(N \* L)이다.

### 공간 복잡도

정답에 O(N \* L)의 공간이 필요하다.

### 순회 & 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* L)  |  O(N \* L)  |

두 문자열이 아나그램인지 판별하는데 카운팅을 사용할 수 있다. 각 알파벳마다의 카운트가 모두 같은 경우 두 문자열은 아나그램이다.

이를 이용해 정답에 아나그램이 아닌 경우 추가하며, 직전에 추가된 단어와 현재 단어가 아나그램인 경우 추가하지 않는다.

```cpp
bool isAnagram(string &a, string &b) {
  int count[26] = {
      0,
  };
  for (char &c : a) {
    count[c - 'a']++;
  }
  for (char &c : b) {
    count[c - 'a']--;
  }
  for (int i = 0; i < 26; i++) {
    if (count[i] != 0) return false;
  }
  return true;
}

vector<string> removeAnagrams(vector<string> &words) {
  vector<string> answer;

  for (string &w : words) {
    if (!answer.empty() && isAnagram(answer.back(), w)) continue;
    answer.push_back(w);
  }
  return answer;
}
```

## 고생한 점
