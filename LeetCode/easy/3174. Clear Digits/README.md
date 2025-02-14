# 3174. Clear Digits

[링크](https://leetcode.com/problems/clear-digits/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

스택을 이용해 문자열을 순회하며 새로운 문자열을 만들 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

새로운 정답을 생성할 경우 O(N)의 공간 복잡도가 필요하다.

직접 입력받은 문자열을 수정할 경우 별도의 공간이 필요하지 않다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

왼쪽부터 순회하며 숫자를 만난 경우 정답의 이전 문자를 제거한다.

그 외의 경우는 정답에 더한다.

```cpp
string clearDigits(string s) {
  string ret = "";
  for (char &c : s) {
    if (isdigit(c)) {
      ret.pop_back();
    } else {
      ret.push_back(c);
    }
  }

  return ret;
}
```

### 스택 (in place)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

위 방법에서 새로운 문자열을 생성하지 않고 입력받은 문자열을 수정할 수 있다.

이 때 현재 문자의 index를 관리하며, 숫자를 만난 경우 index를 감소시킨다.

```cpp
string clearDigits(string s) {
  int size = s.size();

  int length = 0;
  for (int i = 0; i < size; i++) {
    if (isdigit(s[i])) {
      length = max(length - 1, 0);
    } else {
      s[length] = s[i];
      length++;
    }
  }

  s.resize(length);

  return s;
}
```

## 고생한 점
