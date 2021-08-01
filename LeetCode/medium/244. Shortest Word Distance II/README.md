# 244. Shortest Word Distance II

[링크](https://leetcode.com/problems/shortest-word-distance-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 원소의 개수를 N이라 하자.

단어의 index들을 저장하고, 각 단어에 대한 index의 차이 중 최소값을 찾아야한다.

단어들이 중복해서 나올 수 있으므로 index를 여러개 가질 수 있는 구조이다.

따라서 각 index를 담은 2개의 배열에서 차이의 최소 값을 찾는 문제이다.

두 배열의 원소의 개수의 합을 M이라 하자

투 포인터를 이용할 경우 O(M)만에 차이의 최소값을 찾을 수 있다.

최악의 경우 M = N이므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

각 원소들의 index들을 저장할 공간이 필요하며 이 공간 복잡도는 O(N)이다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

우선 각 단어의 index들을 담을 배열을 만들어야 한다.

이 index들을 담을 배열을 단어에 대해 찾기 위해 다음과 같은 구조의 hash map을 이용한다.

- key : 단어
- value : index들을 담은 배열

두 단어의 index들 중 가장 작은 차이를 찾기 위해 투 포인터를 사용한다.

두 배열의 시작점 부터 시작하며 두 배열의 현재 값중 작은 쪽의 index를 증가시킨다.

이는 현재 작은 배열의 값이 큰 배열의 값을 좇아가게 되므로 항상 최소값이 될 수 있는 경우를 탐색한다.

```cpp
unordered_map<string, vector<int>> um;

WordDistance(vector<string>& wordsDict) {
  int size = wordsDict.size();
  for (int i = 0; i < size; i++) {
    string word = wordsDict[i];

    um[word].emplace_back(i);
  }
}

int shortest(string word1, string word2) {
  vector<int>& v1 = um[word1];
  vector<int>& v2 = um[word2];

  int diff = abs(v1.front() - v2.back());
  int idx1 = 0, idx2 = 0;
  int size1 = v1.size(), size2 = v2.size();

  while (idx1 < size1 && idx2 < size2) {
    int temp = abs(v1[idx1] - v2[idx2]);
    diff = min(diff, temp);

    if (v1[idx1] < v2[idx2]) {
      idx1++;
    } else {
      idx2++;
    }
  }

  return diff;
}
```

## 고생한 점
