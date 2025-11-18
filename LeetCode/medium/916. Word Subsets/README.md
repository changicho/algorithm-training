# 916. Word Subsets

[링크](https://leetcode.com/problems/word-subsets/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 words1, words2의 크기를 각각 N + M이라 하자. (N, M <= 10^4)

각 단어의 길이는 최대 10 이다.

각 단어를 순회하며 모두 포함하는지 검사할 경우 O(N \* M)의 시간 복잡도가 필요하다. 이는 제한시간 내에 불가능하다.

만족해야 하는 최소 조건을 찾아내고 이를 모든 단어에 대해 검사할 경우 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도가 필요하다.

각 경우마다 알파벳의 갯수를 저장하는데 O(1)의 공간 복잡도가 필요하다.

### 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      64      |   (N + M)   |    O(1)     |

words2에 포함된 모든 단어를 만들 수 있어야한다.

이를 모두 만족하는 최소 알파벳 갯수 배열을 만들고 이를 words1의 모든 단어에 대해 검사한다.

```cpp
bool isValid(vector<int> &count1, vector<int> &count2) {
  for (int i = 0; i < 26; i++) {
    if (count2[i] > count1[i]) {
      return false;
    }
  }
  return true;
}

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
  vector<int> target(26, 0);

  for (string &word : words2) {
    vector<int> count(26, 0);

    for (char &c : word) {
      count[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      target[i] = max(target[i], count[i]);
    }
  }

  vector<string> answer;
  for (string &word : words1) {
    vector<int> count(26, 0);
    for (char &c : word) {
      count[c - 'a']++;
    }

    bool flag = true;
    if (!isValid(count, target)) {
      flag = false;
    }

    if (flag) answer.emplace_back(word);
  }
  return answer;
}
```

## 고생한 점
