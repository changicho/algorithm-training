# 734. Sentence Similarity

[링크](https://leetcode.com/problems/sentence-similarity/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문장의 원소의 갯수를 N, pair의 갯수를 M이라 하자.

각 pair를 순회하며 hash map에 연결된 단어들을 저장 후 이후 문장을 순회하며 변환 가능한지 여부를 판단한다.

이 경우 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(M)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(N + M)   |    O(M)     |

각 단어는 변환 가능 여부가 존재하고, 변환을 연이어 진행할 수는 없다.

따라서 유니온 파인드가 아닌 단순 hash map으로 변환할 수 있는 목록을 관리한다.

```cpp
bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
  if (sentence1.size() != sentence2.size()) return false;
  unordered_map<string, unordered_set<string>> um1;

  for (vector<string>& pair : similarPairs) {
    string a = pair[0], b = pair[1];
    um1[a].insert(b);
    um1[b].insert(a);
  }

  int size = sentence1.size();
  for (int i = 0; i < size; i++) {
    string a = sentence1[i], b = sentence2[i];

    if (a == b) continue;
    if (um1[a].count(b) == 0 || um1[b].count(a) == 0) {
      return false;
    }
  }
  return true;
}
```

## 고생한 점
