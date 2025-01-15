# 2168. Unique Substrings With Equal Digit Frequency

[링크](https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 문자열 s의 길이를 L이라 하자.

각 경우마다 정답에 추가 가능한 경우를 탐색할 때 O(L^2)의 시간 복잡도가 소요된다.

이 때 hash set을 이용해 중복을 제거하고 삽입하는데 O(L)의 시간 복잡도가 소요되므로 전체 시간 복잡도는 O(L^3)이다.

### 공간 복잡도

중복을 제거하기 위해 hash set을 사용할 경우 O(L^3)의 공간 복잡도가 필요하다.

### 완전 탐색 & 비트마스킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     167      |   O(L^3)    |   O(L^3)    |

모든 left ~ right 쌍의 문자열에 대해 탐색한다.

이 때 right를 증가시키며 현재 substring에 존재하는 숫자들의 빈도수를 갱신한다.

각 숫자의 빈도수가 모두 같은지 빠르게 판단하기 현재 substring의 길이와 빈도수, 종류를 계산한다.

이 때 각 빈도수에 대해 존재하는 문자의 종류를 비트마스킹으로 표현한다.

```cpp
int equalDigitFrequency(string s) {
  unordered_set<string> us;

  int size = s.size();
  for (int i = 0; i < size; i++) {
    string temp = "";

    int pairs[1001] = {
        0,
    };
    for (int num = 0; num <= 9; num++) {
      pairs[0] |= (1 << num);
    }
    int counts[10] = {
        0,
    };

    for (int j = i; j < size; j++) {
      temp += s[j];

      int cur = s[j] - '0';
      int count = counts[cur];
      pairs[count] &= ~(1 << cur);
      pairs[count + 1] |= (1 << cur);
      counts[cur] = count + 1;

      if ((__builtin_popcount(pairs[count + 1]) * (count + 1)) ==
          temp.size()) {
        us.insert(temp);
      }
    }
  }

  return us.size();
}
```

### 롤링 해쉬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |   O(L^2)    |   O(L^2)    |

```cpp
int equalDigitFrequency(string s) {
  int size = s.size();
  int prime = 31;
  long long mod = 10e9;
  unordered_set<long long> us;

  for (int left = 0; left < size; left++) {
    vector<int> count(10, 0);
    int uniqueCount = 0;
    long long substringHash = 0;
    int maxCount = 0;

    for (int right = left; right < size; right++) {
      int cur = s[right] - '0';

      if (count[cur] == 0) {
        uniqueCount++;
      }

      count[cur]++;
      maxCount = max(maxCount, count[cur]);

      substringHash = (prime * substringHash + cur + 1) % mod;

      if (maxCount * uniqueCount == right - left + 1) {
        us.insert(substringHash);
      }
    }
  }

  return us.size();
}
```

### 트라이

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     704      |   O(L^2)    |   O(L^2)    |

각 경우마다 중복을 판단하는데 트라이를 사용한다.

각 substring을 탐색할 때 트라이 노드를 생성하고, 해당 노드를 방문했는지 여부를 저장한다.

```cpp
struct TrieNode {
  bool visited = false;
  TrieNode *children[10] = {NULL};
};

int equalDigitFrequency(string s) {
  int size = s.size();

  TrieNode *root = new TrieNode();
  int answer = 0;

  for (int left = 0; left < size; left++) {
    int count[10] = {
        0,
    };
    int uniqueCount = 0;
    int maxCount = 0;
    TrieNode *node = root;
    for (int right = left; right < size; right++) {
      int cur = s[right] - '0';

      if (count[cur] == 0) {
        uniqueCount++;
      }

      count[cur]++;
      maxCount = max(maxCount, count[cur]);

      if (!node->children[cur]) {
        node->children[cur] = new TrieNode();
      }
      node = node->children[cur];

      if (maxCount * uniqueCount == right - left + 1 && !node->visited) {
        answer++;
        node->visited = true;
      }
    }
  }

  return answer;
}
```

## 고생한 점
