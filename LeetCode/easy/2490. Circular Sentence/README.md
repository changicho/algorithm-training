# 2490. Circular Sentence

[링크](https://leetcode.com/problems/circular-sentence/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

직접 순회하며 비교할 경우 O(N)의 시간 복잡도를 사용한다.

공백별로 나누어 문자열을 만들 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

문자열을 공백별로 나누어 저장할 경우 O(N)의 공간 복잡도가 필요하다.

직접 순회할 경우 O(1)의 공간 복잡도가 필요하다.

### split

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

문자열 s를 공백별로 나누어 배열에 저장한다.

이후 배열을 순회하며 각 단어의 끝과 다음 단어의 시작이 같은지 비교한다.

이 때 처음과 끝 문자열도 비교함에 유의한다.

```cpp
vector<string> split(string &s) {
  stringstream ss(s);
  string temp;

  vector<string> ret;
  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

bool isCircularSentence(string sentence) {
  vector<string> words = split(sentence);

  int size = words.size();
  for (int i = 0; i < size; i++) {
    int next = (i + 1 + size) % size;

    if (words[i].back() != words[next].front()) return false;
  }
  return true;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

위 방법에서 공백을 나누지 않고 직접 순회하며 비교할 수 있다.

```cpp
bool isCircularSentence(string sentence) {
  if (sentence.front() != sentence.back()) return false;

  char before;
  bool isNew = false;
  for (char &c : sentence) {
    if (c == ' ') {
      isNew = true;
      continue;
    }

    if (isNew && before != c) return false;
    before = c;
    isNew = false;
  }
  return true;
}
```


## 고생한 점
