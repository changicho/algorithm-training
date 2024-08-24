# 320. Generalized Abbreviation

[링크](https://leetcode.com/problems/generalized-abbreviation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 word의 길이를 N이라 하자.

각 문자별로 숫자에 포함할지 아닐지 두 경우를 탐색해야 한다.

이에 O(2^N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답의 경우의 수는 2^N개 이하 이다. 각 경우마다 N의 공간 복잡도를 사용하므로 O(2^N \* N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |   O(2^N)    | O(2^N \* N) |

각 index별로 순회하며 다음 두 가지 경우가 존재한다.

- 현재 문자를 count에 포함하는 경우
- 현재 문자를 count에 포함하지 않는 경우

따라서 두 경우에 대해 탐색을 진행한다.

이후 각 경우의 수를 정답에 추가한다.

```cpp
vector<string> answer;

void recursive(int index, string &word, int temp, string &ret) {
  int size = word.size();
  if (index == size) {
    int beforeLen = ret.size();
    if (temp > 0) ret += to_string(temp);

    answer.push_back(ret);
    while (ret.size() > beforeLen) {
      ret.pop_back();
    }
    return;
  }

  // count case
  recursive(index + 1, word, temp + 1, ret);

  // cut case
  int beforeLen = ret.size();
  if (temp > 0) ret += to_string(temp);

  ret += word[index];
  recursive(index + 1, word, 0, ret);
  while (ret.size() > beforeLen) {
    ret.pop_back();
  }
}

vector<string> generateAbbreviations(string word) {
  string temp = "";
  recursive(0, word, 0, temp);

  return answer;
}
```

## 고생한 점
