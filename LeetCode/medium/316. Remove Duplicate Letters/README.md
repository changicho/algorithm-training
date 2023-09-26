# 316. Remove Duplicate Letters

[링크](https://leetcode.com/problems/remove-duplicate-letters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자. (N <= 10^4)

모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이며 이는 제한시간 내에 불가능하다.

스택을 이용해 가장 유리한 경우를 탐색할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택을 이용해 알파벳만을 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 알파벳별로 마지막에 등장한 index를 저장한다.

이후 왼쪽부터 글자를 순회한다.

이 때 스택에는 현재까지 저장한 알파벳들이 오름차순으로 정렬되어 있고 top에는 가장 큰 값이 저장되어있다.

이 때 현재 알파벳이 top보다 작고, top이 뒤에 또 등장할 경우 top을 pop한다.

뒤에 존재하는지는 현재 index와 해당 알파벳이 가장 늦게 등장하는 index를 비교해 수행한다.

이후 스택에 저장된 값을 뒤집은 값이 정답이 된다.

```cpp
string removeDuplicateLetters(string s) {
  int size = s.size();

  vector<int> lastIs(26, 0);
  for (int i = 0; i < size; i++) {
    lastIs[s[i] - 'a'] = i;
  }

  vector<bool> visited(26, false);
  stack<char> stk;

  for (int i = 0; i < size; i++) {
    char cur = s[i];
    if (visited[cur - 'a']) {
      continue;
    }
    while (!stk.empty() && stk.top() > s[i] && i < lastIs[stk.top() - 'a']) {
      visited[stk.top() - 'a'] = false;
      stk.pop();
    }
    stk.push(cur);
    visited[cur - 'a'] = true;
  }

  string ans = "";
  while (!stk.empty()) {
    ans += stk.top();
    stk.pop();
  }
  reverse(ans.begin(), ans.end());
  return ans;
}
```

## 고생한 점
