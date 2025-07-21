# 3612. Process String with Special Operations I

[링크](https://leetcode.com/problems/process-string-with-special-operations-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연산의 수를 N이라 하자.

최악의 경우 이어붙이는 연산을 계속 수행할 경우 O(2^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

최악의 경우 이어붙이는 연산을 계속 수행할 경우 O(2^N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(2^N)    |   O(2^N)    |

각 연산마다 문자열을 직접 수정하며 정답을 구한다.

```cpp
string processStr(string s) {
  string ret = "";

  for (char &c : s) {
    switch (c) {
      case '*': {
        if (ret.size() > 0) {
          ret.pop_back();
        }
        break;
      }
      case '#': {
        ret += ret;
        break;
      }
      case '%': {
        reverse(ret.begin(), ret.end());
        break;
      }
      default: {
        ret += c;
        break;
      }
    }
  }

  return ret;
}
```

## 고생한 점
