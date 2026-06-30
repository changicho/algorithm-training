# 1967. Number of Strings That Appear as Substrings in Word

[링크](https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

word의 길이를 N, pattern의 갯수+길이의 합을 M이라 하자.

word의 가능한 모든 subString을 탐색 후 hash set에 저장하는데 O(N^2)의 시간 복잡도를 사용한다.

이후 pattern을 순회하며 갯수를 세는데 O(M)의 시간 복잡도를 사용한다.

### 공간 복잡도

subString을 모두 저장하는데 O(N^2)의 공간 복잡도를 사용한다.

### 완전 탐색 & hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      42      | O(N^2 + M)  |   O(N^2)    |

word의 가능한 모든 subString을 탐색 후 hash set에 저장한다.

이후 patterns를 순회하며 hash set에 있는 pattern의 수를 센다.

```cpp
int numOfStrings(vector<string>& patterns, string word) {
  unordered_set<string> us;
  int size = word.size();
  for (int i = 0; i < size; i++) {
    string temp = "";
    for (int j = i; j < size; j++) {
      temp += word[j];

      us.insert(temp);
    }
  }

  int answer = 0;
  for (string& p : patterns) {
    answer += us.count(p);
  }
  return answer;
}
```

## 고생한 점
