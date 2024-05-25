# 1255. Maximum Score Words Formed by Letters

[링크](https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

단어의 갯수를 N, letters의 길이를 L이라 하자.

단어를 선택하는 모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이다.

각 단어마다 직접 순회하며 문자의 갯수를 세지 않고 미치 각 알파벳 별로 count한뒤 이용할 수 있다.

이 경우 전처리에 O(N + L)의 시간 복잡도를 사용한다. (각 단어의 길이는 15 이하이므로 O(1)로 순회 가능하다고 가정한다.)

따라서 총 시간 복잡도는 O(2^N + N + L)이다.

### 공간 복잡도

DFS로 모든 경우를 탐색할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색 & 백트래킹

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|      3       | O(2^N + N + L) |    O(N)     |

재귀호출을 이용해 가능한 모든 단어를 선택하는 경우를 탐색한다.

이 때 현재 남은 letter로 현재 단어를 선택하지 못하는 경우는 제외한다.

```cpp
int letterCounts[26] = {
    0,
};
int answer = 0;

vector<vector<int>> wordCounts;

void recursive(int index, int sum, vector<int> &score) {
  if (wordCounts.size() == index) {
    answer = max(answer, sum);
    return;
  }

  recursive(index + 1, sum, score);

  bool isPossible = true;
  int curScore = 0;

  // subtract
  for (int i = 0; i < 26; i++) {
    letterCounts[i] -= wordCounts[index][i];

    curScore += wordCounts[index][i] * score[i];
    if (letterCounts[i] < 0) isPossible = false;
  }

  if (isPossible) recursive(index + 1, sum + curScore, score);

  // rollback
  for (int i = 0; i < 26; i++) {
    letterCounts[i] += wordCounts[index][i];
  }
}

int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
  int size = words.size();
  for (string &word : words) {
    vector<int> count(26);
    for (char &c : word) {
      count[c - 'a']++;
    }
    wordCounts.push_back(count);
  }

  for (char &c : letters) {
    letterCounts[c - 'a']++;
  }

  recursive(0, 0, score);

  return answer;
}
```

## 고생한 점
