# 524. Longest Word in Dictionary through Deleting

[링크](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 L, dictionary의 크기를 N, 각 단어의 평균 길이를 M이라 하자.

dictionary의 각 단어를 순회하는데 O(N)의 시간 복잡도를 사용한다.

미리 각 글자들이 나타나는 index를 저장해놓고 이후에 사용할 수 있다. 해당 순회에 O(L)의 시간 복잡도를 사용한다.

현재 단어를 S에서 만들 수 있는지 판단하는데 index에 대한 이분 탐색을 사용할 경우 O(M \* log_2(L))의 시간 복잡도를 사용한다.

이 방법의 경우 총 시간 복잡도는 O(L + N \* M \* log_2(L)) 이다.

### 공간 복잡도

각 글자마다의 index들을 저장할 경우 O(L)의 공간 복잡도를 사용한다.

### index binary search

| 내 코드 (ms) |        시간 복잡도        | 공간 복잡도 |
| :----------: | :-----------------------: | :---------: |
|     184      | O(L + N \* M \* log_2(L)) |    O(L)     |

각 글자들이 나타나는 index들이 각 글자마다 오름차순으로 정렬되어 있다고 하자.

이 경우 현재 단어를 만들기 위해선 다음 조건을 충족해야한다.

- 각 글자는 다음 글자보다 index가 앞서야 한다.

즉 각 글자들을 가능한 index들로 치환했을 때 오름차순으로 정렬되어있는경우 해당 단어를 만들 수 있다.

이를 위해 S를 index순으로 순회하며 index들을 저장한다.

이후 각 단어들을 순회하며 해당 조건을 충족하는지 검사한다.

이 때 직전 index보다 큰 index를 찾기 위해 이분탐색을 사용한다.

이후 현재 단어를 생성 가능한 경우 정답을 갱신할 수 있다면 갱신한다.

이를 구현하면 다음과 같다.

```cpp
string findLongestWord(string s, vector<string> &dictionary) {
  vector<int> indexes[26];

  for (int i = 0; i < s.size(); i++) {
    indexes[s[i] - 'a'].push_back(i);
  }

  string answer = "";
  for (string &word : dictionary) {
    int index = -1;
    bool isError = false;
    for (char &c : word) {
      if (indexes[c - 'a'].empty() || indexes[c - 'a'].back() <= index) {
        isError = true;
        break;
      }

      int nextIdx = upper_bound(indexes[c - 'a'].begin(),
                                indexes[c - 'a'].end(), index) -
                    indexes[c - 'a'].begin();
      index = indexes[c - 'a'][nextIdx];
    }

    if (isError) continue;
    if (answer == "") {
      answer = word;
    } else if (answer.size() < word.size()) {
      answer = word;
    } else if (answer.size() == word.size() && answer > word) {
      answer = word;
    }
  }
  return answer;
}
```

### two pointer

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      75      | O((L + M) \* N) |    O(1)     |

dictionary의 각 단어들이 S의 subsequence인지 찾으면 된다.

S의 특정 글자들을 지웠을 때 단어가 나오면 되므로, 투 포인터를 이용해 subsequence인지 판단한다.

이를 구현하면 다음과 같다.

```cpp
bool isSubsequence(string &target, string &origin) {
  int j = 0;
  for (int i = 0; i < origin.length() && j < target.length(); i++) {
    if (target[j] == origin[i]) j++;
  }
  return j == target.length();
}

string findLongestWord(string s, vector<string> &dictionary) {
  string answer = "";
  for (string &word : dictionary) {
    if (isSubsequence(word, s)) {
      if (answer.length() < word.length()) {
        answer = word;
      } else if (answer.length() == word.length() && answer > word) {
        answer = word;
      }
    }
  }
  return answer;
}
```

## 고생한 점
