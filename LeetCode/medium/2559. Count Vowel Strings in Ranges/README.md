# 2559. Count Vowel Strings in Ranges

[링크](https://leetcode.com/problems/count-vowel-strings-in-ranges/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 단어의 수를 N, 쿼리의 수를 M이라 하자.

각 단어를 순회하며 각 단어가 모음으로 시작하고 끝나는지 판단하는데 O(N)의 시간 복잡도를 사용한다.

이후 각 쿼리마다의 구간합을 구하기 위해 prefix sum을 사용할 경우 O(M)의 시간 복잡도를 사용한다.

따라서 총 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

구간합을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

정답으로 반환할 공간에 O(M)의 공간 복잡도를 사용한다.

### 구간합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     155      |  O(N + M)   |  O(N + M)   |

각 쿼리에 대해서 특정 구간에 모음으로 시작, 끝나는 단어의 수를 세서 반환해야 한다.

이를 위해 구간합을 생성 후 쿼리를 순회하며 정답을 반환한다.

```cpp
unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
bool isVowel(char c) { return vowels.count(c) > 0; }

vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
  int size = words.size();
  vector<bool> isVowelCase(size, false);

  for (int i = 0; i < size; i++) {
    if (isVowel(words[i].front()) && isVowel(words[i].back())) {
      isVowelCase[i] = true;
    }
  }

  vector<int> prefixSum(size + 1, 0);
  for (int i = 1; i <= size; i++) {
    prefixSum[i] = prefixSum[i - 1] + isVowelCase[i - 1];
  }

  vector<int> answer;
  for (vector<int>& q : queries) {
    int l = q[0], r = q[1];

    int cur = prefixSum[r + 1] - prefixSum[l];
    answer.push_back(cur);
  }
  return answer;
}
```

## 고생한 점
