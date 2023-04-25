# Colliding Encoding (4pts, 10pts)

[링크](https://codingcompetitions.withgoogle.com/codejam/round/0000000000c95b94/0000000000cad7cf)

## 설계

### 시간 복잡도

각 알파벳을 치환할 숫자 배열 D와 N개의 단어들이 주어진다.

각 단어들의 평균 길이를 L이라 하자.

hash set을 이용해 단어들을 변환하고 해당 단어들을 변환했을 때 겹치는지 판단한다.

이 경우 각 단어들을 순회하며 hash set에 저장하므로 O(N \* L)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set을 이용할 경우 O(N \* L)의 공간 복잡도를 사용한다.

### hash set

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N \* L)  |  O(N \* L)  |

각 단어를 입력받은 D에 대해 변환한다.

이후 변환한 단어들을 hash set에 저장 하며 겹치는 변환된 단어가 존재하는지 판단한다.

```cpp
bool hasCollision(vector<int> &table, vector<string> &words) {
  unordered_set<string> converted;

  for (auto &word : words) {
    string temp = "";

    for (auto &c : word) {
      temp += table[c - 'A'] + '0';
    }

    if (converted.count(temp)) {
      return true;
    }

    converted.insert(temp);
  }

  return false;
}
```

## 고생한 점
