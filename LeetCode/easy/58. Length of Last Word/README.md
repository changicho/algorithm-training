# 58. Length of Last Word

[링크](https://leetcode.com/problems/length-of-last-word/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 최대 길이는 10^4 이다. 모든 문자열을 순회할 때 시간 복잡도는 O(N) 이다.

### 공간 복잡도

문자열의 최대 길이가 10^4 이므로 정답의 최대값 또한 10^4 이다.

### 순회

맨 마지막 단어의 길이만 구하면 되므로 역순으로 탐색한다.

```cpp
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int length = 0;
    for (int index = s.length() - 1; index >= 0; index -= 1) {
      if (length != 0 && s[index] == ' ') {
        break;
      }
      if (s[index] != ' ') {
        length += 1;
      }
    }

    return length;
  }
};
```

### split을 이용

split 함수를 만들 때 공백을 제거하기 위해 단어를 추가할 때 분기처리를 수행한다.

```cpp
class Solution {
 public:
  int lengthOfLastWord(string s) {
    vector<string> vs = split(s);

    if (vs.size() == 0) return 0;
    return vs.back().length();
  }

 private:
  vector<string> split(string s) {
    vector<string> ret;
    string temp = "";

    for (char c : s) {
      if (c == ' ') {
        if (temp == "") continue;
        ret.push_back(temp);
        temp = "";
      } else {
        temp += c;
      }
    }

    if (temp != "") ret.push_back(temp);

    return ret;
  }
};
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      0       |

## 고생한 점
