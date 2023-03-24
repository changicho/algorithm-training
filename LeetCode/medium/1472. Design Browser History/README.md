# 1472. Design Browser History

[링크](https://leetcode.com/problems/design-browser-history/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 url의 갯수를 N, 페이지 이동시의 step을 S라 하자.

두 개의 stack을 이용해 현재 페이지를 저장할 경우 O(1)의 시간 복잡도로 이동이 가능하다.

페이지 이동시에 두 개의 stack에서 값을 이동시킬경우 O(S)의 시간 복잡도가 소요된다.

페이지 방문시 다음 페이지들을 모두 초기화 하는데 최대 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

url을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### two stack

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     212      | O(1), O(S), O(N) |    O(N)     |

페이지를 이동하며 이전페이지, 다음페이지 들에 대해 저장해야 한다.

이 때 visit 명령의 경우 다음페이지들을 모두 초기화 해야한다.

두 개의 스택을 다음과 같이 정의한다.

- 이전에 방문한 페이지들 (현재 페이지 포함)
- 다음에 방문한 페이지들

이를 이용해 페이지 이동시마다 스택의 값을 뽑아 다른 스택으로 이동시킨다.

visit 명령의 경우 다음페이지들을 모두 초기화한다.

```cpp
class BrowserHistory {
 private:
  stack<string> backs, fronts;

 public:
  BrowserHistory(string homepage) { backs.push(homepage); }

  void visit(string url) {
    backs.push(url);
    while (!fronts.empty()) {
      fronts.pop();
    }
  }

  string back(int steps) {
    int size = backs.size();
    for (int i = 0; i < min(steps, size - 1); i++) {
      fronts.push(backs.top());
      backs.pop();
    }
    return backs.top();
  }

  string forward(int steps) {
    int size = fronts.size();
    for (int i = 0; i < min(steps, size); i++) {
      backs.push(fronts.top());
      fronts.pop();
    }
    return backs.top();
  }
};
```

## 고생한 점
