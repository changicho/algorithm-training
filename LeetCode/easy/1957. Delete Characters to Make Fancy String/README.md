# 1957. Delete Characters to Make Fancy String

[링크](https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

스택을 이용해 순회하며 fancy string을 만들 수 있다. 이에 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

스택에 문자열을 저장할 경우 O(N)의 공간 복잡도가 필요하다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      39      |    O(N)     |    O(N)     |

스택을 이용해 직전과 직직전의 문자가 같은 경우를 제외하고 문자열을 만든다.

```cpp
string makeFancyString(string s) {
  string ret = "";

  for (char &c : s) {
    int size = ret.size();
    if (size >= 2) {
      if (ret[size - 1] == ret[size - 2] && c == ret[size - 1]) {
        continue;
      }
    }

    ret += c;
  }
  return ret;
}
```

## 고생한 점
