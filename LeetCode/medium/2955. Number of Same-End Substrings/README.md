# 2955. Number of Same-End Substrings

[링크](https://leetcode.com/problems/number-of-same-end-substrings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N, 쿼리의 수를 Q라 하자.

각 쿼리마다 모두 탐색할 경우 O(N * Q)의 시간 복잡도가 소요된다. 이는 제한시간 내에 불가능하다.

각 알파벳마다 index들을 저장 후 이분 탐색을 이용할 경우 O(N + Q * log_2(N))의 시간 복잡도가 소요된다.

prefix sum을 이용할 경우 O(N + Q)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 index들을 저장할 배열이 필요하다. 이에 O(N)의 공간 복잡도가 필요하다.

prefix sum에 O(N)의 공간 복잡도가 필요하다.

정답에 O(Q)의 공간 복잡도가 필요하다.

### 이분 탐색

| 내 코드 (ms) |     시간 복잡도     | 공간 복잡도 |
| :----------: | :-----------------: | :---------: |
|     531      | O(N + Q * log_2(N)) |  O(N + Q)   |

substring의 시작과 끝이 같은 경우를 빠르게 찾아야 한다.

각 알파벳별로 나타나는 index들을 저장한다.

이후 쿼리에 포함되는 index의 갯수를 셀 수 있다.

해당 index 중 2개를 고르는 조합을 찾으면 이는 substring의 갯수가 된다.

이를 각 알파벳마다 수행하고, 이를 더해 정답을 구한다.

```cpp
int getCount(vector<int> &indexes, int left, int right) {
  int count = upper_bound(indexes.begin(), indexes.end(), right) -
              lower_bound(indexes.begin(), indexes.end(), left);
  return count;
}

vector<int> sameEndSubstringCount(string s, vector<vector<int>> &queries) {
  int size = s.size();

  vector<int> indexes[26];

  for (int i = 0; i < size; i++) {
    indexes[s[i] - 'a'].push_back(i);
  }

  vector<int> answer;
  for (vector<int> &q : queries) {
    int left = q[0], right = q[1];
    int cur = 0;

    for (int c = 0; c < 26; c++) {
      int count = getCount(indexes[c], left, right);

      cur += (count + 1) * count / 2;
    }

    answer.push_back(cur);
  }
  return answer;
}
```

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     143      |  O(N + Q )  |  O(N + Q)   |

각 index마다 시작점부터 해당 index까지의 알파벳별 갯수를 저장한다.

이후 쿼리에 포함되는 index의 갯수를 이용해 정답을 구한다.

```cpp
vector<int> sameEndSubstringCount(string s, vector<vector<int>> &queries) {
  int size = s.size();

  vector<vector<int>> counts(26, vector<int>(size + 1));

  for (int i = 0; i < size; i++) {
    for (int c = 0; c < 26; c++) {
      counts[c][i + 1] = counts[c][i];
      if (s[i] - 'a' == c) counts[c][i + 1]++;
    }
  }

  vector<int> answer;
  for (vector<int> &q : queries) {
    int left = q[0], right = q[1];

    int cur = 0;
    for (int c = 0; c < 26; c++) {
      int count = counts[c][right + 1] - counts[c][left];
      cur += (count + 1) * count / 2;
    }

    answer.push_back(cur);
  }
  return answer;
}
```

## 고생한 점
