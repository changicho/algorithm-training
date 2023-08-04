# 17. Letter Combinations of a Phone Number

[링크](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

digits의 길이는 최대 4이다. 각 digit의 종류는 3~4 가지이다.

탐색의 횟수는 대략 최악의 경우 O(4^N) 이다.

매 탐색의 경우마다 digit을 탐색하므로 O(N) 번의 연산이 필요하다.

그러므로 시간 복잡도는 O(4^N \* N) 이다.

### 공간 복잡도

BFS로 탐색할 경우 큐 안에 정답의 경우의 수만큼 담길 수 있으므로 공간은 최대 O(4^N \* N)이다.

DFS로 탐색할 경우 콜스택에서 사용할 수 있으므로 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(4^N \* N) |    O(N)     |

전역변수에 정답을 담고 return한다.

```cpp
string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> answer;
vector<string> letterCombinations(string digits) {
  recursive(0, digits, "");

  return answer;
}

void recursive(int index, string digits, string cur) {
  if (index == digits.length()) {
    if (cur != "") {
      answer.push_back(cur);
    }
    return;
  }

  int targetIndex = digits[index] - '0';
  for (char c : letters[targetIndex]) {
    recursive(index + 1, digits, cur + c);
  }
}
```

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(4^N \* N) | O(4^N \* N) |

```cpp
vector<string> letterCombinations(string digits) {
  string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  vector<string> ret;

  vector<string> combi;
  for (char digit : digits) {
    combi.push_back(letters[digit - '0']);
  }

  queue<string> q;
  q.push("");

  while (!q.empty()) {
    string cur = q.front();
    q.pop();

    if (cur.length() == digits.length()) {
      if (cur != "") {
        ret.push_back(cur);
      }
      continue;
    }

    int index = cur.length();
    for (char c : combi[index]) {
      q.push(cur + c);
    }
  }

  return ret;
}
```

## 고생한 점
