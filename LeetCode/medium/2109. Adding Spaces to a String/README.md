# 2109. Adding Spaces to a String

[링크](https://leetcode.com/problems/adding-spaces-to-a-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, 배열 spaces의 길이를 M이라 하자.

모든 경우를 직접 수행할 경우 O(M \* N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

투 포인터를 사용할 경우 O(N + M)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

정답 문자열에 O(N + M)의 공간 복잡도가 필요하다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      21      |  O(N + M)   |  O(N + M)   |

s의 현재 문자 index와 추가할 공백의 index를 나타내는 포인터를 이용해 풀이한다.

이 때 s에 공백이 추가될 때마다 이후 공백 index를 보정해준다.

```cpp
string addSpaces(string s, vector<int>& spaces) {
  int size = s.size();
  string ret = "";

  for (int i = 0, sI = 0; i < size; i++) {
    if (sI < spaces.size() && spaces[sI] == i) {
      ret += ' ';
      sI++;
    }
    ret += s[i];
  }

  return ret;
}
```

## 고생한 점
