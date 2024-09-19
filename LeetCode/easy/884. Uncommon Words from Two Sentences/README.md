# 884. Uncommon Words from Two Sentences

[링크](https://leetcode.com/problems/uncommon-words-from-two-sentences/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

두 문자열의 길이를 각각 N, M이라 하자.

각 문자열을 공백을 기준으로 나누는 데 O(N + M)의 시간 복잡도를 사용한다.

나눈 단어들을 hash map을 이용해 count 하는 데 O(N + M)의 시간 복잡도가 필요하다.

### 공간 복잡도

hash map에 단어들을 저장할 때 O(N + M)의 공간 복잡도가 필요하다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |  O(N + M)   |  O(N + M)   |

두 문자열에서 유일하게 존재하는 단어들의 목록을 반환해야 한다.

이를 위해 두 문자열의 단어들을 뽑은 뒤 hash map에 전부 카운트한다.

이후 1개만 있는 단어들을 반환한다.

```cpp
vector<string> split(string &s) {
  vector<string> ret;

  stringstream ss(s);
  string temp;
  while (ss >> temp) {
    ret.push_back(temp);
  }

  return ret;
}

vector<string> uncommonFromSentences(string s1, string s2) {
  vector<string> v1 = split(s1), v2 = split(s2);

  unordered_map<string, int> um;
  for (string &w : v1) {
    um[w]++;
  }
  for (string &w : v2) {
    um[w]++;
  }

  vector<string> answer;
  for (auto [key, val] : um) {
    if (val == 1) answer.push_back(key);
  }
  return answer;
}
```

## 고생한 점
