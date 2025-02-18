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

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

모든 경우가 I인 경우 1부터 차례로 증가시키는 경우가 정답일 것이다.

만약 중간에 D를 만나는 경우를 생각해보자.

이 경우 I인 구간을 I', D인 구간을 D'라 하자.

I' + D'으로 구성된 배열의 경우 D'을 뒤집을 경우 모든 패턴이 I인 경우가 된다.

I' + D' + I' 으로 구성된 경우 또한 마찬가지이다.

따라서 1부터 숫자를 차례로 정답에 더해가며, D'인 구간을 뒤집는 경우가 정답이 된다.

이를 구현하면 다음과 같다.

```cpp
string smallestNumber(string s) {
  int size = s.size();

  string answer;
  for (int num = 0, index = 0; num <= size; num++) {
    answer.push_back('1' + num);

    if (num == size || s[num] == 'I') {
      reverse(answer.begin() + index, answer.end());
      index = num + 1;
    }
  }
  return answer;
}
```

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

위 방법에서 뒤집는 부분을 스택을 이용해 구현할 수 있다.

```cpp
string smallestNumber(string pattern) {
  int size = pattern.size();
  string result;
  stack<int> stk;

  for (int i = 0; i <= size; i++) {
    stk.push(i + 1);

    if (i == pattern.size() || pattern[i] == 'I') {
      while (!stk.empty()) {
        result.push_back(stk.top() + '0');
        stk.pop();
      }
    }
  }

  return result;
}
```

## 고생한 점
