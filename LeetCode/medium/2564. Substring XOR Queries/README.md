# 2564. Substring XOR Queries

[링크](https://leetcode.com/problems/substring-xor-queries/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, queries의 크기를 M이라 하자. (N <= 10^4, M <= 10^5)

각 쿼리마다 원하는 값을 찾기 위해 모든 s의 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

숫자의 범위가 int형 임을 이용해 2진수로 나타냈을 때 각 수는 최대 32자리까지만을 가진다.

이를 이용해 가능한 쌍을 미리 계산 후 탐색할 경우 O(32 \* N)의 시간 복잡도로 모든 경우를 미리 구할 수 있다. 이를 hash map에 저장해놓는다.

이후 쿼리를 순회하며 정답을 구할 경우 총 O(32 \* N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 경우를 hash map에 저장해 놓을 경우 O(32 \* N)의 공간 복잡도를 사용한다.

정답에 O(M)의 공간 복잡도를 사용한다.

### hash map & 비트연산

| 내 코드 (ms) |  시간 복잡도   |  공간 복잡도   |
| :----------: | :------------: | :------------: |
|     382      | O(32 \* N + M) | O(32 \* N + M) |

```cpp
vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
  unordered_map<long long, pair<int, int>> um;

  for (int i = 0; i < s.size(); i++) {
    long long val = 0;
    for (int j = 0; j < 32; j++) {
      if (i + j >= s.size()) break;
      val *= 2;
      val += s[i + j] - '0';

      if (um.count(val) == 0) {
        um[val] = {i, i + j};
      }
      if (val == 0) break;
    }
  }

  vector<vector<int>> answer;
  for (vector<int>& q : queries) {
    long long target = q[0] ^ q[1];

    if (um.count(target) == 0) {
      answer.push_back({-1, -1});
    } else {
      answer.push_back({um[target].first, um[target].second});
    }
  }

  return answer;
}
```

## 고생한 점
