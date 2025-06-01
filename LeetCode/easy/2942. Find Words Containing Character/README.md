# 2942. Find Words Containing Character

[링크](https://leetcode.com/problems/find-words-containing-character/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 각 단어의 길이를 L이라 하자.

각 단어를 순회하며 정답을 찾는데 O(N \* L)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답 배열에 저장하기 위해 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* L)  |    O(N)     |

```cpp
vector<int> findWordsContaining(vector<string>& words, char x) {
  int size = words.size();
  vector<int> answer;

  for (int i = 0; i < size; i++) {
    if (words[i].find(x) != -1) {
      answer.push_back(i);
    }
  }
  return answer;
}
```

## 고생한 점
