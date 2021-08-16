# 271. Encode and Decode Strings

[링크](https://leetcode.com/problems/encode-and-decode-strings/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

각 문자열의 모든 길이의 합을 N이라 하자.

하나의 문자열로 vector를 인코딩 하는데 결과적으로 O(N)의 시간 복잡도가 필요하다.

문자열을 vector로 디코딩하는데도 결과적으로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 과정에서 인코딩과 디코딩에 각각 O(N)의 공간 복잡도가 필요하다.

### ASCII divide

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      48      |    O(N)     |    O(N)     |

문제에서 주어지는 문자열은 256개의 valid한 ASCII 문자들이다.

따라서 해당 문자열 범위를 벗어나는 값을 구분자로 사용할 경우 문자열에서 vector를 추출하는것이 가능하다.

casting을 사용해 구분자로 동작하도록 한다.

```cpp
class Codec {
 public:
  string encode(vector<string>& strs) {
    string ret = "";
    for (string str : strs) {
      char divide = (char)257;
      ret += str + divide;
    }
    return ret;
  }

  vector<string> decode(string s) {
    vector<string> ret;

    string temp = "";
    for (char c : s) {
      if (c != (char)257) {
        temp += c;
      } else {
        ret.emplace_back(temp);
        temp = "";
      }
    }

    return ret;
  }
};
```

### index move

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      48      |    O(N)     |    O(N)     |

하나의 단어의 길이의 최대값은 200글자이다.

따라서 최대 3글자를 단어의 길이로 할당하고 다음과 같은 형태로 인코딩이 가능하다.

```javascript
['글자수', '단어', '글자수', '단어', ...];
```

디코딩을 할 때는 글자수를 추출하고 이후 단어를 추출한 뒤 다음 글자수가 나오는 위치로 이동한다.

혹은 글자수를 3자리로 고정하지 않고, 글자수만 단어 앞에 붙일 수 있다.

이 때 단어가 숫자로 구성되는 경우 글자 수를 제대로 판단하기 위해 숫자가 아닌 다른 기호를 통해 글자수와 단어를 구분한다.

```javascript
['글자수', '특수기호', '단어', '글자수', '특수기호', '단어',...];
```

해당 방법으로 인코딩과 디코딩을 구현한다.

```cpp
class Codec {
 public:
  string encode(vector<string>& strs) {
    string ret = "";
    for (string str : strs) {
      ret += to_string(str.length()) + ":";
      ret += str;
    }
    return ret;
  }

  vector<string> decode(string s) {
    vector<string> ret;

    int length = s.length();
    int i = 0;
    string temp = "";

    while (i < length) {
      if (s[i] != ':') {
        temp += s[i];
        i++;
        continue;
      }

      int count = stoi(temp);
      temp = "";
      i++;

      string cur = "";
      for (int j = i; j < i + count; j++) {
        cur += s[j];
      }
      ret.emplace_back(cur);
      i += count;
    }

    return ret;
  }
};
```

## 고생한 점
