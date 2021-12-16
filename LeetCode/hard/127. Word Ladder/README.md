# 127. Word Ladder

[링크](https://leetcode.com/problems/word-ladder/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

단어의 개수를 N, 단어의 길이를 L이라 하자.

시작 단어에서 끝 단어까지 도달할 수 있는 경우를 BFS를 이용해 탐색한다.

이 과정에서 가장 빠르게 도달하는 경우를 찾는다.

이 경우 중복을 제거하는 BFS를 사용하면 O(N)의 시간 복잡도를 사용한다.

현재 단어에서 다음 단어로 넘어갈 때 모든 단어마다 검사하고 넘어갈 경우 O(N \* L)의 시간 복잡도가 소요되며 이 경우 O(N^2 \* L)의 시간 복잡도를 소요한다.

만약 현재 단어에서 다음 단어로 넘어갈 때 각 자리들을 변경시켜보며 가능한 경우의 수 중에서 존재하는 단어만 넘어갈 경우 O(L)의 시간 복잡도를 소요한다.

이 경우 O(N \* L)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS에 사용하는 공간복잡도는 O(N \* L)이다.

또한 단어의 hash set에 O(N \* L)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     102      |  O(N \* L)  |  O(N \* L)  |

특정 문자가 wordList에 있는지 빠르게 판단하기 위해 hash set을 이용한다.

이 때 hash set에 endWord가 없는 경우는 정답을 만들지 못하는 경우이다.

이후 현재 단어부터 큐에 집어넣고 BFS를 시작한다.

이 때 탐색하는 문자마다 hash set에서 지워 이후 중복방문이 일어나지 않도록 한다.

BFS는 step 별로 진행한다.

현재 단어에서 다음 단어로 넘어갈 때 남은 모든 단어를 순회할 수도 있다.

이 방법의 경우 시간 복잡도가 O(N \* L)이 소요된다.

또는 단어의 index마다 순회하며 해당 글자를 변경해가며 탐색할 수 있다.

이 경우 시간 복잡도는 O(L)이다.

따라서 현재 단어를 변형시켜가며 이후 탐색을 진행한다.

만약 정답을 발견한 경우 step을 반환한다.

```cpp
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  unordered_set<string> words = {wordList.begin(), wordList.end()};
  // edge case: can't reach to endWord
  if (words.find(endWord) == words.end()) return 0;

  int size = words.size();

  queue<string> q;
  q.push(beginWord);
  words.erase(beginWord);

  int step = 0;
  while (!q.empty()) {
    int size = q.size();

    while (size--) {
      string cur = q.front();
      q.pop();

      if (cur == endWord) {
        return step + 1;
      }

      // find all possible case from current word
      for (char& c : cur) {
        char before = c;
        for (char next = 'a'; next <= 'z'; next++) {
          c = next;

          if (words.find(cur) == words.end()) continue;
          words.erase(cur);

          q.push(cur);
        }
        c = before;
      }
    }
    step++;
  }

  return 0;
}
```

## 고생한 점
