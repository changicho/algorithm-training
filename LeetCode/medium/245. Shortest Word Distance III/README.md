# 245. Shortest Word Distance III

[링크](https://leetcode.com/problems/shortest-word-distance-iii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열안의 단어의 개수를 N개라 하자.

한번 순회를 통해 각 단어의 index들을 찾을 수 있다.

이 순회에 O(N)의 시간 복잡도가 필요하다.

두 단어의 index들 중에서 차이가 최소가 되는 값을 구해 답을 구할 수 있으며 이를 슬라이딩 윈도우로 구현할 경우 O(N)의 시간 복잡도 내에 풀이 가능하다.

혹은 한번의 순회 동안 해당 target들의 index가 나오는 경우 매번 차이를 갱신해 문제를 풀이할 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

두 단어의 index들을 구하고 그 중 최소가 되는 값을 구하는 경우 O(N)만큼의 공간이 필요하다.

한번의 순회동안 index를 이용해 최소를 구하는 경우 O(1)만큼의 공간이 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     144      |    O(N)     |    O(N)     |

word1, word2에 해당하는 단어의 index들을 갖는 두 배열을 만든다.

이후 두 배열에 대해 슬라이딩 윈도우를 이용해 차이의 최소를 갱신한다.

이 때, 같은 index들에 대해서는 차이의 최소를 갱신하지 않음에 유의한다.

```cpp
int shortestWordDistance(vector<string> &wordsDict, string word1, string word2) {
  int size = wordsDict.size();
  vector<int> arr1, arr2;

  for (int i = 0; i < size; i++) {
    string &word = wordsDict[i];

    if (word == word1) {
      arr1.emplace_back(i);
    }
    if (word == word2) {
      arr2.emplace_back(i);
    }
  }

  int diff = 10001;
  int idx1 = 0, idx2 = 0;
  int size1 = arr1.size(), size2 = arr2.size();

  while (idx1 < size1 && idx2 < size2) {
    if (arr1[idx1] != arr2[idx2]) {
      diff = min(abs(arr1[idx1] - arr2[idx2]), diff);
    }

    if (arr1[idx1] < arr2[idx2]) {
      idx1 += 1;
    } else {
      idx2 += 1;
    }
  }

  return diff;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     160      |    O(N)     |    O(1)     |

한번 순회를 하며 word1이 나타났을 때와 word2가 나타났을 때 각각의 마지막 index들을 갱신한다.

이후 각 경우마다 갱신한 index들을 가지고 정답을 갱신한다.

여기서 (word1 == word2)인 경우 두 index가 동시에 갱신될 수 있으므로 갱신되는 하나의 index를 다른 index 값과 swap한다.

이는 하나의 index만 계속 갱신되지 않게 하기 위함이다.

```cpp
int shortestWordDistance(vector<string> &wordsDict, string word1, string word2) {
  int dist = 10001;
  int i1 = dist, i2 = -dist;
  bool isSame = word1 == word2;

  for (int i = 0; i < wordsDict.size(); i++) {
    if (wordsDict[i] == word1) {
      i1 = i;

      if (isSame) swap(i1, i2);
    } else if (wordsDict[i] == word2) {
      i2 = i;
    }

    dist = min(dist, abs(i1 - i2));
  }

  return dist;
}
```

## 고생한 점
