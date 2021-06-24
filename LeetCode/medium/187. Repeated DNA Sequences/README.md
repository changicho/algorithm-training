# 187. Repeated DNA Sequences

[링크](https://leetcode.com/problems/repeated-dna-sequences/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 문자의 index에서 시작하는 10글자 크기의 문자열들을 DNA라고 했을 때 해당 DNA가 반복해서 나타나는지를 판단하는 문제이다.

따라서 각 글자수 별로 DNA를 추출해야한다. 이전에 나온 DNA여부를 판단하는데 hash set을 이용한다면 O(1)의 시간 복잡도로 찾을 수 있다.

각 글자별 순회에 O(N)의 outer 시간 복잡도가 필요하고, 내부적으로 10글자의 문자열을 만드는데 O(1)의 시간 복잡도가 소요된다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash set을 사용할 경우 O(N)의 복잡도가 필요하다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |    O(N)     |    O(N)     |

각 index를 순회하며 각 index에서 시작하는 10자리 글자의 문자열이 이전에 나타났는지를 판단한다.

이는 hash set에 이전에 나온 DNA들을 저장하는 것으로 구현한다.

정답은 unique한 문자열이 되어야 하므로 정답또한 hash set에 저장한다.

```cpp
vector<string> findRepeatedDnaSequences(string s) {
  int length = s.length();
  unordered_set<string> answer_set;
  unordered_set<string> hs;

  for (int index = 0; index < length + 1 - 10; index++) {
    string cur = s.substr(index, 10);

    if (hs.find(cur) != hs.end()) {
      answer_set.insert(cur);
    } else {
      hs.insert(cur);
    }
  }

  vector<string> answers;
  for (string s : answer_set) {
    answers.push_back(s);
  }
  return answers;
}
```

## 고생한 점
