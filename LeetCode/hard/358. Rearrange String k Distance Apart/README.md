# 358. Rearrange String k Distance Apart

[링크](https://leetcode.com/problems/rearrange-string-k-distance-apart/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, 입력받은 수를 K라 하자.

우선순위 큐를 이용해 현재 채워넣을 값을 고를 수 있다. 이 경우 O((N + K) \* log_2(K))의 시간 복잡도가 소요된다.

### 공간 복잡도

우선순위 큐에 O(K)의 공간 복잡도를 사용한다.

정답으로 반환하는 문자열에 O(N)의 공간 복잡도를 사용한다.

### 우선순위 큐

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      14      | O((N + K) \* log_2(K)) |  O(N + K)   |

문자를 빈도 수에 따라 정렬하고, 아직 가장 많이 남은 문자를 선택한다.

각 경우마다 선택 가능한 문자 중 가장 많이 남은 문자를 현재 선택할 경우 K만큼 띄워진 공간에 가장 많이 채울 수 있기 때문이다.

이 때 현재 채워진 문자는 K만큼 떨어진 이후에 선택 가능한 목록에 추가해야한다.

각 경우마다 가장 많이 남은 문자를 선택하기 위해 우선순위 큐를 사용한다.

이후 현재 선택한 값을 모노토닉 큐에 넣고, K만큼 떨어진 경우에는 다시 우선순위 큐에 넣는다.

이를 반복하며 만약 완성되지 않은 경우에 선택 가능한 목록이 없는 경우 불가능한 경우이다.

```cpp
string rearrangeString(string s, int k) {
  int size = s.size();
  int counts[26] = {0};
  for (int i = 0; i < size; i++) {
    counts[s[i] - 'a']++;
  }

  priority_queue<pair<int, char>> pq;  // {count, char}
  for (int i = 0; i < 26; i++) {
    if (counts[i]) {
      pq.push({counts[i], i + 'a'});
    }
  }

  string answer;
  queue<pair<int, char>> wait;
  while (answer.size() < size) {
    int index = answer.size();

    if (!wait.empty() && (index - wait.front().first) >= k) {
      auto cur = wait.front();
      wait.pop();
      pq.push({counts[cur.second - 'a'], cur.second});
    }

    if (pq.empty()) {
      return "";
    }

    char currChar = pq.top().second;
    pq.pop();
    answer += currChar;

    counts[currChar - 'a']--;
    if (counts[currChar - 'a'] > 0) {
      wait.push({index, currChar});
    }
  }

  return answer;
}
```

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |    O(N)     |  O(N + K)   |

```cpp
string rearrangeString(string s, int k) {
  unordered_map<char, int> counts;
  int maxCount = 0;
  for (char &c : s) {
    counts[c]++;
    maxCount = max(maxCount, counts[c]);
  }

  unordered_set<char> mostChars;
  unordered_set<char> secondChars;
  for (pair<char, int> charPair : counts) {
    if (charPair.second == maxCount) {
      mostChars.insert(charPair.first);
    } else if (charPair.second == maxCount - 1) {
      secondChars.insert(charPair.first);
    }
  }

  vector<string> segments(maxCount);
  for (int i = 0; i < maxCount; i++) {
    for (char c : mostChars) {
      segments[i] += c;
    }

    if (i < maxCount - 1) {
      for (char c : secondChars) {
        segments[i] += c;
      }
    }
  }

  int index = 0;
  for (pair<char, int> charPair : counts) {
    char currChar = charPair.first;

    if (mostChars.find(currChar) != mostChars.end() ||
        secondChars.find(currChar) != secondChars.end()) {
      continue;
    }

    for (int freq = counts[currChar]; freq > 0; freq--) {
      segments[index] += charPair.first;
      index = (index + 1) % (maxCount - 1);
    }
  }

  for (int i = 0; i < maxCount - 1; i++) {
    if (segments[i].size() < k) {
      return "";
    }
  }

  string answer = "";
  for (string &line : segments) {
    answer += line;
  }
  return answer;
}
```

## 고생한 점
