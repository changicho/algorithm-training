# 2707. Extra Characters in a String

[링크](https://leetcode.com/problems/extra-characters-in-a-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, 단어배열 dictionary의 길이를 M이라 하자.

동적 계획법을 이용해 중복되는 탐색 횟수를 줄일 수 있다. 이 경우 N^2가지의 경우가 존재한다.

각 경우마다 값을 갱신하는데 해당 범위에서 각 단어들을 검색해야 한다. 이 경우 시간 복잡도는 O(N \* M)이다.

따라서 총 시간 복잡도는 O(N^3 \* M)이다.

### 공간 복잡도

동적 계획법에 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     454      | O(N^3 \* M) |   O(N^2)    |

s에 대해서 현재 탐색할 범위를 left ~ right라고 하자.

만약 현재 범위 내에 단어가 존재한다면 해당 단어만큼 제거하고 남은 범위에 대해서 재귀호출로 탐색을 진행할 수 있다.

예를 들어 다음과 같은 경우를 살펴보자

```cpp
string s = "asdfasdf";
string word = "fa";

// left ~ right
int left = 0, right = 7;

// find word in s
// there are two parts

// left ~ 2
"asd"
// 5 ~ right
"sdf"
```

즉 각 경우마다 현재 범위애 word가 존재하는 경우에 대해 탐색을 진행하고, 이 때 현재 범위에서 탐색한 경우 중 가장 남은 문자의 수가 적은 경우를 반환한다.

이를 메모이제이션을 사용해 중복된 경우의 호출을 줄인다.

```cpp
const int MAX = 100001;
vector<string> words;
string s;

int dp[51][51] = {
    0,
};

vector<int> find(string &s, string &target, int left, int right) {
  vector<int> ret;
  int pos = s.find(target, left);
  while (pos != -1 && pos + target.size() - 1 <= right) {
    ret.push_back(pos);
    pos = s.find(target, pos + 1);
  }
  return ret;
}

int recursive(int left, int right) {
  if (left > right) return 0;
  if (dp[left][right] != MAX) return dp[left][right];

  int ret = right - left + 1;

  for (string &w : words) {
    for (int idx : find(s, w, left, right)) {
      int leftCount = recursive(left, idx - 1);
      int rightCount = recursive(idx + w.size(), right);

      int cur = leftCount + rightCount;

      ret = min(ret, cur);
    }
  }

  return dp[left][right] = ret;
}

int minExtraChar(string s, vector<string> &dictionary) {
  this->s = s;
  this->words = dictionary;

  int size = s.size();
  for (int l = 0; l < size; l++) {
    for (int r = 0; r < size; r++) {
      dp[l][r] = MAX;
    }
  }

  recursive(0, size - 1);

  return dp[0][size - 1];
}
```

## 고생한 점
