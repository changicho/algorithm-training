# 267. Palindrome Permutation II

[링크](https://leetcode.com/problems/palindrome-permutation-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

우선 팰린드롬으로 변환이 가능한 지 판별하는데 O(N)의 시간 복잡도가 필요하다.

이후 팰린드롬으로 가능한 경우를 탐색하기 위해서 O((N/2)!)만큼의 시간 복잡도가 필요하다.

이는 N이 최대 16까지이므로 O(40,320) 이므로 제한시간 내에 가능하다.

### 공간 복잡도

정답을 저장하는 데 최대 O((N/2)!)만큼의 공간이 필요하다.

그 외에 각 경우마다 탐색을 진행하는 데 최대 call stack에 O(N/2)만큼 쌓일 수 있다.

따라서 시간 복잡도는 O(N)이다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |  O((N/2)!)  |    O(N)     |

각 문자열들을 count한다.

이후 먼저 팰린드롬으로 변환이 가능한 지 판별한다.

변환이 가능한 경우, 가운데 들어갈 문자를 찾은 뒤 남은 문자와 count를 갖고 탐색을 시작한다.

```cpp
vector<string> answer;
unordered_map<char, int> um;

void recursive(int n, string s) {
  if (s.length() == n) {
    answer.emplace_back(s);
    return;
  }

  for (auto &cur : um) {
    if (cur.second >= 2) {
      char target = cur.first;
      um[cur.first] -= 2;

      recursive(n, target + s + target);

      um[cur.first] += 2;
    }
  }
}

vector<string> generatePalindromes(string s) {
  for (char c : s) {
    um[c] += 1;
  }

  int oddCount = 0;
  string center = "";
  for (auto &cur : um) {
    if (cur.second % 2 == 1) {
      oddCount += 1;
      center += cur.first;
    }
  }

  if (oddCount >= 2) return answer;

  recursive(s.length(), center);

  return answer;
}
```

### permutation

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |  O((N/2)!)  |    O(N)     |

팰린드롬으로 만들기 위해 가운데 들어갈 문자는 fix된다.

가운데를 기준으로 왼쪽, 오른쪽에 있는 문자열은 서로 대칭관계이다.

따라서 한쪽에 있는 문자열에 들어갈 수 있는 문자들로 만들 수 있는 모든 순열을 이용해 정답을 구할 수 있다.

먼저 팰린드롬으로 변환이 가능한 지 판별하며 가운데 들어갈 문자와 한쪽의 문자열을 생성한다.

이후 한쪽의 문자열로 모든 경우의 순열을 만든다.

```cpp
vector<string> generatePalindromes(string s) {
  vector<string> answer;
  unordered_map<char, int> um;

  // step1. count characters
  for (char c : s) {
    um[c] += 1;
  }

  int oddCount = 0;
  string center = "";
  string half = "";

  // step2. count odd & set middle character & half string
  for (auto &cur : um) {
    if (cur.second % 2 == 1) {
      oddCount += 1;

      center += cur.first;
    } else {
      for (int i = 0; i < cur.second / 2; i++) {
        half += cur.first;
      }
    }
  }

  // if unable to make permutation return
  if (oddCount >= 2) return {};

  // make half from middle character
  um[center.front()] -= 1;
  if (um[center.front()] > 0) {
    for (int i = 0; i < um[center.front()] / 2; i++) {
      half += center.front();
    }
  }

  // step3. make permutation of half string
  sort(half.begin(), half.end());

  do {
    // current answer is (half + center + half')
    string cur = half + center + half;
    reverse(cur.begin() + (cur.length() + 1) / 2, cur.end());
    answer.emplace_back(cur);
  } while (next_permutation(half.begin(), half.end()));

  return answer;
}
```

## 고생한 점
