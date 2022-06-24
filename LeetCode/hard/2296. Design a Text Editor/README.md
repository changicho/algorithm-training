# 2296. Design a Text Editor

[링크](https://leetcode.com/problems/design-a-text-editor/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

총 문자열의 길이를 N, 삭제 & 이동해야 하는 길이를 K라 하자.

모든 경우를 string으로 처리할 경우 삽입, 삭제에 O(N)의 시간 복잡도를 사용한다.

이동의 경우 O(K)의 시간 복잡도를 사용한다.

두개의 stack을 이용할 경우 삽입에 O(N), 삭제 & 이동에 O(K)의 시간 복잡도를 사용한다.

### 공간 복잡도

두개의 stack을 사용할 경우 모든 문자 저장에 O(N)의 공간 복잡도를 사용한다.

### two stack

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     702      | O(N), O(K)  |    O(N)     |

두 개의 stack left, right를 생성한다.

현재 커서의 위치를 left.top()으로 관리한다고 하자.

이 경우 커서의 이동은 left의 원소를 right에 옮기고 pop하면 된다. (반대로 이동할 경우 right -> left)

현재 커서에서 문자열의 추가는 left에 문자를 차례대로 삽입하면 된다.

커서의 이동의 경우 이동 후에 left의 상위 10개의 원소를 뽑아 문자열을 생성하고 반환하는것으로 구현한다.

```cpp
class TextEditor {
 private:
  // cur index : left.top()
  stack<char> left, right;

  string getLast10() {
    string ret = "";
    stack<char> temp;
    for (int i = 0; i < 10 && !left.empty(); i++) {
      ret += left.top();
      temp.push(left.top());
      left.pop();
    }

    while (!temp.empty()) {
      left.push(temp.top());
      temp.pop();
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }

 public:
  void addText(string text) {
    for (char &c : text) {
      left.push(c);
    }
  }

  int deleteText(int k) {
    int count = 0;
    while (count < k && !left.empty()) {
      left.pop();
      count++;
    }
    return count;
  }

  string cursorLeft(int k) {
    int leftCount = min((int)left.size(), k);
    for (int i = 0; i < leftCount; i++) {
      right.push(left.top());
      left.pop();
    }

    return getLast10();
  }

  string cursorRight(int k) {
    int rightCount = min((int)right.size(), k);
    for (int i = 0; i < rightCount; i++) {
      left.push(right.top());
      right.pop();
    }

    return getLast10();
  }
};
```

### two string

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     608      | O(N), O(K)  |    O(N)     |

위 방법에서 stack대신에 두개의 string으로 구현할 수 있다.

커서 이동 후 10개의 이전 문자열을 뽑아내는 과정이 달라진다.

```cpp
class TextEditor {
 private:
  // cur index : left.back()
  string left, right;

  string getLast10() {
    string ret = "";
    int length = left.length();
    for (int i = max(0, length - 10); i < length; i++) {
      ret += left[i];
    }
    return ret;
  }

 public:
  void addText(string text) {
    for (char &c : text) {
      left.push_back(c);
    }
  }

  int deleteText(int k) {
    int count = 0;
    while (count < k && !left.empty()) {
      left.pop_back();
      count++;
    }
    return count;
  }

  string cursorLeft(int k) {
    int leftCount = min((int)left.size(), k);
    for (int i = 0; i < leftCount; i++) {
      right.push_back(left.back());
      left.pop_back();
    }

    return getLast10();
  }

  string cursorRight(int k) {
    int rightCount = min((int)right.size(), k);
    for (int i = 0; i < rightCount; i++) {
      left.push_back(right.back());
      right.pop_back();
    }

    return getLast10();
  }
};
```

## 고생한 점
