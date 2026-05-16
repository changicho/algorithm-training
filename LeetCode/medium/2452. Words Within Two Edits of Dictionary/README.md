# 2452. Words Within Two Edits of Dictionary

[링크](https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

쿼리의 갯수를 M, 단어의 갯수를 N이라 하자. 각 길이의 평균을 L이라 하자.

완전 탐색을 수행할 경우 O(NML)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(NL)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |   O(NML)    |    O(NL)    |

하나하나 비교하며 두 문자열의 차이가 2 이하인지 확인한다.

이후 해당 쿼리가 dictionary에 존재하면 정답에 추가한다.

이를 모든 쿼리에 대해 반복한다.

```cpp
bool check(string& a, string& b) {
  int diff = 0;

  if (a.size() != b.size()) return false;
  int size = a.size();
  for (int i = 0; i < size; i++) {
    if (a[i] != b[i]) diff++;
  }
  return diff <= 2;
}

vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
  vector<string> answer;

  for (string& q : queries) {
    for (string& dic : dictionary) {
      if (check(q, dic)) {
        answer.push_back(q);
        break;
      }
    }
  }
  return answer;
}
```

## 고생한 점
