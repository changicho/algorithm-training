# 809. Expressive Words

[링크](https://leetcode.com/problems/expressive-words/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

단어의 개수를 N, 단어의 길이를 L이라 하자.

각 단어들을 나타나는 순서대로 알파벳, 갯수의 쌍으로 변환한다.

이 작업에 O(N \* L)의 시간 복잡도가 소요된다.

이후 변환한 데이터를 순차적으로 순회하며 변환이 가능한지 판단한다.

이 과정에 O(L)의 시간 복잡도가 소요된다.

따라서 시간 복잡도는 O(N \* L)이다.

### 공간 복잡도

변환한 데이터들이 차지하는 공간은 O(N \* L)이다.

따라서 공간 복잡도는 O(N \* L)이다.

### 단어 변환

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(N \* L)  |  O(N \* L)  |

단어들을 사용하기 쉽도록 변환한다.

문자열을 순회하며 중복된 문자열이 나올 경우 (문자, 횟수)로 압축해 변환한다.

변환에 다음과 같은 함수를 이용한다.

```cpp
struct Data {
  char c;
  int count;
};

vector<Data> convertString(string &str) {
  char before = str.front();
  int count = 1;

  vector<Data> ret;

  for (int i = 1; i < str.length(); i++) {
    if (before != str[i]) {
      ret.push_back({before, count});

      before = str[i];
      count = 1;
      continue;
    }
    count++;
  }
  ret.push_back({before, count});

  return ret;
}
```

이후 각 단어들 변환한 자료들을 문자열 s와 순차적으로 비교한다.

- 자료의 갯수가 다른경우 : 불가능. s에 필요한 문자가 없거나 단어에 불필요한 문자가 존재함
- 순차적으로 비교했을 때 특정 문자가 다른경우 : 불가능.
- 현재 단어의 문자가 더 많은경우 : 불가능. 늘리는 작업만 가능하다.
- s의 해당 문자의 개수가 2개이며, 현재 단어의 문자열이 2개가 아닌경우 : 불가능. 3개부터 늘릴 수 있다.

이를 구현하면 다음과 같다.

```cpp
bool canStretch(string &from, vector<Data> &targets) {
  vector<Data> froms = convertString(from);

  if (froms.size() != targets.size()) return false;

  int size = froms.size();
  for (int i = 0; i < size; i++) {
    if (froms[i].c != targets[i].c) return false;
    if (froms[i].count > targets[i].count) return false;
    if (froms[i].count != 2 && targets[i].count == 2) return false;
  }
  return true;
}

int expressiveWords(string s, vector<string> &words) {
  vector<Data> targets = convertString(s);

  int answer = 0;
  for (string &word : words) {
    if (canStretch(word, targets)) answer++;
  }
  return answer;
}
```

## 고생한 점
