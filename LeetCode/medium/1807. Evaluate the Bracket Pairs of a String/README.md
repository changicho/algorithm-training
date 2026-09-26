# 1807. Evaluate the Bracket Pairs of a String

[링크](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N, 단어의 갯수를 M이라 하자.

hash map을 이용해 단어쌍을 저장하는데 O(M), 순회 후 단어를 변경하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map과 정답에 O(N + M)의 공간 복잡도를 사용한다.

### hash map & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      88      |  O(N + M)   |  O(N + M)   |

단어들을 hash map에 저장 후 문자열을 순회하며 괄호 안의 단어를 치환한다.

이 때 현재 괄호가 열린 경우와 닫힌 경우를 flag변수로 관리해 안의 단어를 생성한다.

```cpp
string evaluate(string s, vector<vector<string>>& knowledge) {
  unordered_map<string, string> um;
  for (vector<string>& cur : knowledge) {
    string key = cur[0];
    string val = cur[1];
    um[key] = val;
  }

  string answer = "";
  bool isBracket = false;
  string temp = "";

  for (char& c : s) {
    if (c == '(') {
      isBracket = true;
      continue;
    } else if (c == ')') {
      if (um.count(temp)) {
        answer += um[temp];
      } else {
        answer += "?";
      }

      temp = "";
      isBracket = false;
      continue;
    }

    if (isBracket) {
      temp += c;
    } else {
      answer += c;
    }
  }

  return answer;
}
```

## 고생한 점
