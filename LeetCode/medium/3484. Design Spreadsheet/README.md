# 3484. Design Spreadsheet

[링크](https://leetcode.com/problems/design-spreadsheet/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

각 연산마다 문자열 s의 길이를 L이라 하자. 연산의 갯수를 N이라 하자.

각 연산마다 hash map을 사용할 경우 O(L)의 시간 복잡도가 소요된다.

### 공간 복잡도

hash map에 O(N \* L)의 공간 복잡도가 필요하다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      86      |  O(N \* L)  |  O(N \* L)  |

각 cell에 대한 값을 저장하기 위해 hash map을 사용한다.

이후 formula를 계산할 때 이를 토큰화 한 뒤 cell을 의미하는 경우 cell의 값을 가져오고 숫자인 경우 그대로 사용한다.

```cpp
class Spreadsheet {
 private:
  unordered_map<string, int> um;

  vector<string> split(string &s) {
    int size = s.size();
    vector<string> ret;
    string temp = "";
    for (int i = 1; i <= size; i++) {
      if (i == size || s[i] == '+') {
        ret.push_back(temp);
        temp = "";
      } else {
        temp += s[i];
      }
    }

    return ret;
  }

  bool isNumber(string &s) {
    for (char &c : s) {
      if (!isdigit(c)) return false;
    }
    return true;
  }

  int pick(string &s) {
    if (isNumber(s)) {
      return stoi(s);
    }
    return um[s];
  }

 public:
  Spreadsheet(int rows) {}

  void setCell(string cell, int value) { um[cell] = value; }

  void resetCell(string cell) { um[cell] = 0; }

  int getValue(string formula) {
    vector<string> arr = split(formula);

    int first = pick(arr[0]);
    if (arr.size() == 1) {
      return first;
    }
    int second = pick(arr[1]);

    return first + second;
  }
};
```

## 고생한 점
