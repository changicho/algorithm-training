# 2375. Construct Smallest Number From DI String

[링크](https://leetcode.com/problems/construct-smallest-number-from-di-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 패턴의 길이를 N이라 하자.

DFS로 가능한 경우들을 탐색 하며 백트래킹을 수행해 시간 복잡도를 줄일 수 있다.

이 경우 시간 복잡도는 O(9^N)이다.

### 공간 복잡도

DFS를 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### DFS & backtracking

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      53      |   O(9^N)    |    O(N)     |

DFS를 이용해 현재 패턴에 적합한 경우만 탐색을 이어나간다.

이 때 시작점의 수는 1 ~ 10 모두 가능할 수 있으므로 해당 DFS를 가능한 시작점에 대해 모두 반복한다.

이를 구현하면 다음과 같다.

```cpp
string answer = "987654321";

void recursive(int index, string &pattern, string &cur, vector<bool> &visited) {
  if (index == pattern.length()) {
    answer = min(answer, cur);
    return;
  }

  if (pattern[index] == 'D') {
    for (int num = (cur.back() - '0') - 1; num >= 1; num--) {
      if (visited[num]) continue;

      cur.push_back(char(num + '0'));
      visited[num] = true;
      recursive(index + 1, pattern, cur, visited);
      visited[num] = false;
      cur.pop_back();
    }
  } else {
    for (int num = (cur.back() - '0') + 1; num <= 9; num++) {
      if (visited[num]) continue;

      cur.push_back(char(num + '0'));
      visited[num] = true;
      recursive(index + 1, pattern, cur, visited);
      visited[num] = false;
      cur.pop_back();
    }
  }
}

string smallestNumber(string pattern) {
  vector<bool> visited(10, false);

  for (int num = 1; num <= 9; num++) {
    string cur = {
        char(num + '0'),
    };

    visited[num] = true;
    recursive(0, pattern, cur, visited);
    visited[num] = false;
  }

  return answer;
}
```

## 고생한 점
