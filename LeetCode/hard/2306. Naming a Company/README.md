# 2306. Naming a Company

[링크](https://leetcode.com/problems/naming-a-company/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

ideas의 크기를 N이라 하자.

idea를 첫 글자와, 첫 글자를 뺀 나머지 문자열로 분리해 생각해 볼 수 있다. 각각을 key, val이라고 하자.

ideas를 key별로 그룹을 지어 묶고, 두개의 key끼리 비교해 가며 정답에 더한다.

이 때 두개의 key로 만들 수 있는 조합의 갯수는 각각의 갯수에서 중복된 수를 뺀 두 값의 곱이 된다.

ideas를 순회 하는 데 O(N)의 시간 복잡도를 사용한다. 이 과정에서 key, val로 분리하는 데 최악의 경우 O(10)의 시간 복잡도를 사용한다.

이후 두개의 알파벳의 중복되지 않은 조합을 순회하는 데 O(1)의 시간 복잡도를 사용하며, 각 경우마다 한번 순회하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 ideas를 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

### prefix grouping

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     556      |    O(N)     |    O(N)     |

각 idea를 첫글자와 나머지 문자열로 나눈다.

이후 첫글자에 대해 묶어 저장한다.

idea를 첫 글자와, 첫 글자를 뺀 나머지 문자열로 분리해 생각해 볼 수 있다. 각각을 key, val이라고 하자.

같은 val을 가지는 것들 끼리는 key를 교환하더라도 정답을 생성할 수 없다. (이미 중복된 값이 존재하므로)

ideas를 key별로 그룹을 지어 묶고, 두개의 key끼리 비교했을 때 같은 val을 가지는 경우는 정답이 될 수 없다.

따라서 두 개의 key로 만들 수 있는 조합의 갯수는 각각의 갯수에서 중복된 수를 뺀 두 값의 곱이 된다.

이를 구현하면 다음과 같다.

```cpp
long long distinctNames(vector<string>& ideas) {
  unordered_set<string> suffix[26];
  long long result = 0;

  for (string& idea : ideas) {
    suffix[idea[0] - 'a'].insert(idea.substr(1));
  }

  // a ~ z
  for (int i = 0; i < 26; i++) {
    for (int j = i + 1; j < 26; j++) {
      int duplicate = 0;
      for (string item : suffix[i]) {
        duplicate += suffix[j].count(item);
      }

      result +=
          2 * (suffix[i].size() - duplicate) * (suffix[j].size() - duplicate);
    }
  }

  return result;
}
```

## 고생한 점
