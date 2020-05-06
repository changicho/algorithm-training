# 5052. 전화번호 목록

[링크](https://www.acmicpc.net/problem/5052)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Gold III |   29.763    |

## 설계

### 시간복잡도

N은 최대 10,000까지이며 전화번호의 길이는 최대 10자리, 테스트 케이스는 최대 50개 까지이다.

풀이 방법은 다음 2가지가 존재한다.

- Map을 이용
- Trie를 이용

Map을 이용하는 방법의 경우 map에 전화번호를 하나하나 저장해가며 탐색해야한다.

전화번호의 길이가 작은 순으로 map에 저장하고, 각 전화번호의 부분마다 map에 존재해야 하는지 확인해야 한다.

각 전화번호마다 모든 자리수를 판단해야 하므로 최악의 경우 시간복잡도는 다음과 같다

```cpp
// 전화번호의 갯수 * 전화번호의 자릿수 * 테스트케이스
(10,000 + 10,000 * 10) * 50 = 5,500,000
```

Trie를 이용하는 경우 Trie를 생성하고, 찾으면서 중복 여부를 판단할 수 있으므로 시간복잡도는 줄어든다.

```cpp
// (전화번호의 갯수 * 2 + 정렬) * 테스트케이스
(10,000 + 10,000 * log_2(10,000) + 10,000) * 50 = 1,000,700‬
// 전화번호의 갯수 * 2 * 테스트케이스
(10,000 + 10,000) * 50 = 1,000,000
```

두 방법 모두 제한시간 내에 풀이하기 충분하다.

### 트라이의 구현

구조

```cpp
// trie node
struct TrieNode {
  struct TrieNode *children[WORD_SIZE];
  bool isEnd;

  // 삭제할 때 자식들도 전부삭제
  ~TrieNode() {
    for (int i = 0; i < 10; i++) {
      if (children[i] != NULL) {
        delete children[i];
      }
    }
  }
};

// new trie node
struct TrieNode *makeNode(void) {
  struct TrieNode *newNode = new TrieNode;

  newNode->isEnd = false;
  for (int i = 0; i < WORD_SIZE; i++) {
    newNode->children[i] = NULL;
  }

  return newNode;
}
```

삽입

```cpp
void insertTrie(struct TrieNode *root, string key) {
  struct TrieNode *parent = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - '0';

    if (!parent->children[index]) {
      parent->children[index] = makeNode();
    }

    parent = parent->children[index];
  }

  parent->isEnd = true;
}
```

탐색

```cpp
bool searchTrie(struct TrieNode *root, string key) {
  struct TrieNode *parent = root;

  for (int i = 0; i < key.length(); i++) {
    int index = key[i] - '0';
    if (!parent->children[index]) {
      return false;
    }

    parent = parent->children[index];
  }

  return (parent != NULL && parent->isEnd);
}
```

### insert를 이용해 풀이하는 경우

전화번호를 삽입할 때마다 중간 과정중에 isEnd가 true인지를 검사한다.

이 방법을 수행하기 위해서는 글자수가 작은 전화번호를부터 삽입해야 한다.

따라서 전화번호들을 글자수에 따라 정렬을 수행해야한다.

또한 insert함수를 다음과 같이 변경한다.

```cpp
bool insertTrie(struct TrieNode *root, string key) {
  struct TrieNode *parent = root;

  for (int i = 0; i < key.length(); i++) {
    if (parent->isEnd) {
      return false;
    }

    int index = key[i] - '0';

    if (!parent->children[index]) {
      parent->children[index] = makeNode();
    }

    parent = parent->children[index];
  }

  parent->isEnd = true;
  return true;
}
```

이 방법을 이용하는 경우 search를 구현할 필요가 없어진다.

### search를 이용해 풀이하는 경우

search로 단어를 탐색하면서 단어의 끝에 도달하지 않았지만 단어에 끝에 도달했을 경우에는
전화번호가 겹치는 것을 의미한다.

또한 이미 트라이에 저장된 단어를 끝까지 찾은 경우는 (자기자신) 찾지 않은것으로 처리해야 하므로 다음과 같이 수정한다

```cpp
bool searchTrie(struct TrieNode *root, string key) {
  struct TrieNode *parent = root;

  for (int i = 0; i < key.length(); i++) {
    if (parent->isEnd) {
      return true;
    }

    int index = key[i] - '0';

    parent = parent->children[index];
  }

  return false;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     168      |       24       |

## 고생한 점

insert를 이용한 방법의 경우 단어를 정렬해야 한다. 이는 예시데이터가 길이순으로 정렬되어있어 바로 발견하지 못한 문제였다.

search를 이용한 방법의 경우 유효하지 않은 단어가 나오는 경우 더이상 탐색을 중지해야한다.

delete로 메모리에서 사용하지 않는 트라이를 삭제하는것은 시간에 큰 영향을 끼치지 않았다.
