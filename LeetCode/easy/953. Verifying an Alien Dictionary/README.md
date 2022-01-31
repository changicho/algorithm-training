# 953. Verifying an Alien Dictionary

[링크](https://leetcode.com/problems/verifying-an-alien-dictionary/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

단어의 갯수를 N, 각 단어의 평균 문자열의 길이를 L이라 하자.

두 단어를 비교하며 정렬되지 않았는지 확인하는 데 O(L)의 시간 복잡도를 사용한다.

이를 인접한 2개의 단어들에 대해 비교하며 정렬되지 않았는지 확인한다.

이 경우 단어를 순회하는 데 O(N)의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(N \* L)이 된다.

### 공간 복잡도

각 문자별 우선순위를 저장할 공간에 O(26)의 공간 복잡도를 사용한다.

두 단어를 비교하는데 O(1)의 공간 복잡도를 사용한다.

### 우선순위 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |  O(N \* L)  |    O(1)     |

입력받은 order문자열로 각 문자의 우선순위를 설정한다.

이후 두 단어가 정렬되었는지 비교는 다음과 같이 수행한다.

(a가 앞서는게 맞는지)

- a와 b의 각 문자를 앞자리부터 같이 비교한다.
- 만약 a와 b의 문자가 같은 경우 다음 문자로 건너뛴다.
- 현재 a의 문자와 b의 문자를 비교했을 때 a의 우선순위가 더 낮은경우 false이다.
- 만약 a와 b에서 짧은 문자열까지 index비교가 끝났고, a의 길이가 긴 경우 false이다.
- 이를 모두 통과하면 true이다.

이를 이용해 i, i+1번째 단어들 끼리 비교를 수행한다.

```cpp
bool isFine(string &a, string &b, vector<int> &orderSet) {
  int length = min(a.length(), b.length());

  bool flag = false;
  for (int i = 0; i < length; i++) {
    if (a[i] == b[i]) continue;
    if (orderSet[a[i] - 'a'] > orderSet[b[i] - 'a']) return false;
    flag = true;
    break;
  }

  if (!flag && a.length() > b.length()) return false;
  return true;
}

bool isAlienSorted(vector<string> &words, string order) {
  vector<int> orderSet('z' - 'a' + 1);
  for (int i = 0; i < order.size(); i++) {
    orderSet[order[i] - 'a'] = i;
  }

  int size = words.size();
  for (int i = 0; i < size - 1; i++) {
    if (!isFine(words[i], words[i + 1], orderSet)) return false;
  }

  return true;
}
```

## 고생한 점
