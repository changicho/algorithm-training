# 767. Reorganize String

[링크](https://leetcode.com/problems/reorganize-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

각 문자열의 갯수를 count 한 후에 그리디하게 문자열을 배치할 수 있다.

이 때 우선순위 큐를 사용해 가장 갯수가 많은 문자열들을 차례로 배치할 수 있다.

유니크한 문자의 갯수를 K라 하자.

이 경우 시간 복잡도는 O(N \* log_2(K)) 이다.

혹은 그리디 하게 문자열을 짝수 index와 홀수 index에 바로 배치할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답으로 반환하는 문자열에 O(N)의 공간 복잡도를 사용한다.

우선순위 큐에 O(K)의 공간 복잡도를 사용한다.

### 우선순위 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      3       | O(N \* log_2(K)) |  O(N + K)   |

각 경우마다 가장 갯수가 많은 문자를 배치한다. 이후 해당 문자의 count를 줄인다.

이 때 직전 문자와 현재 가장 갯수가 많은 문자가 같은 경우, 두번째로 많은 문자를 선택한다.

만약 이 또한 불가능한 경우 (가장 많은 문자밖에 선택할수 없는 경우) 정답을 만족할 수 없는 경우이다.

```cpp
struct Data {
  int count;
  char c;

  bool operator<(const Data &other) const { return count < other.count; }
};

string reorganizeString(string s) {
  vector<int> counts(26, 0);
  for (char &c : s) {
    counts[c - 'a'] = counts[c - 'a'] + 1;
  }

  priority_queue<Data> pq;
  for (int i = 0; i < 26; i++) {
    if (counts[i] > 0) {
      pq.push({counts[i], char(i + 'a')});
    }
  }

  string answer;
  while (!pq.empty()) {
    Data cur = pq.top();
    pq.pop();

    if (answer.empty() || cur.c != answer.back()) {
      answer += cur.c;
      cur.count--;
      if (cur.count > 0) {
        pq.push(cur);
      }

      continue;
    }

    if (pq.empty()) return "";
    // pick from second
    Data second = pq.top();
    pq.pop();
    answer += second.c;
    second.count--;
    if (second.count > 0) {
      pq.push(second);
    }
    pq.push(cur);
  }

  return answer;
}
```

### 그리디 배치

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(N)     |

각 문자들을 겹치지 않게 배치하기 위해 다음과 같이 배치할 수 있다.

- 같은 문자들은 최소 한칸씩 떨어지게 배치한다.
- 가장 많은 문자를 짝수 index에 배치한다.
- 가장 많은 문자를 배치한 후, 다른 문자들을 배치한다.

즉 각 index마다 문자를 배치할 때 1칸씩 띄워 배치하며 최대한 많은 문자를 배치한다.

이 때 가장 많이 나타나는 문자가 (N+1)/2 보다 많이 나타나는 경우 정답을 만들 수 없다.

```cpp
string reorganizeString(string s) {
  vector<int> counts(26, 0);
  for (char &c : s) {
    counts[c - 'a']++;
  }

  int maxCount = 0, letter = 0;
  for (int i = 0; i < counts.size(); i++) {
    if (counts[i] > maxCount) {
      maxCount = counts[i];
      letter = i;
    }
  }

  if (maxCount > (s.length() + 1) / 2) {
    return "";
  }
  string answer = s;

  int index = 0;
  while (counts[letter] != 0) {
    answer[index] = char(letter + 'a');
    index += 2;
    counts[letter]--;
  }

  for (int i = 0; i < counts.size(); i++) {
    while (counts[i] > 0) {
      if (index >= s.length()) {
        index = 1;
      }
      answer[index] = char(i + 'a');
      index += 2;
      counts[i]--;
    }
  }

  return answer;
}
```

## 고생한 점
