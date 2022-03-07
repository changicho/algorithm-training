# 49. Group Anagrams

[링크](https://leetcode.com/problems/group-anagrams/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 배열의 길이는 최대 10^4이다. 각 문자열들의 길이는 100이다.

애너그램들을 그룹으로 묶는 방법은 다음과 같다.

- 애너그램을 정렬한다.
- 애너그램의 알파벳 수가 같은것들을 찾는다.

두 방법 모두 애너그램 내부의 문자들을 이용해 애너그램 묶음을 찾는다.

애너그램을 정렬하는 경우 시간 복잡도는 O(K \* log_2(K))이다. (K는 문자의 길이)

알파벳 수가 같은것들을 찾는 경우 시간 복잡도는 O(K)이다.

이를 모든 문자에 대해 N번씩 반복한다. hash map을 이용할 경우 key에 매칭하는데 들어가는 복잡도는 O(1)이므로 모든 문자열을 순회 하는데 O(N)의 복잡도가 소요된다.

따라서 두 시간복잡도의 곱이 각각의 시간 복잡도가 된다.

### 공간 복잡도

모든 단어를 그룹화 해야 하므로 O(N \* K)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|      28      | O(N \* K \* log_2(K)) |  O(N \* K)  |

애너그램 단어들을 같은 규칙으로 내부 알파벳들을 정렬해 동일한 key를 찾는다.

이 key를 이용해 다음과 같은 구조의 hash map을 만든다

- key : 알파벳을 정렬한 key
- value : 애너그램 단어 vector

단어의 알파벳을 모두 오름차순으로 정렬할 경우 하나의 단어에 대해 애너그램들은 전부 같은 단어가 된다.

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> answer;
  unordered_map<string, vector<string>> m;

  for (string str : strs) {
    string key = str;
    sort(key.begin(), key.end());

    m[key].push_back(str);
  }

  for (auto it : m) {
    answer.push_back(it.second);
  }

  return answer;
}
```

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |  O(N \* K)  |  O(N \* K)  |

애너그램 단어들을 같은 규칙으로 내부 알파벳들을 카운팅 정렬해 동일한 key를 찾는다.

이 key를 이용해 다음과 같은 구조의 hash map을 만든다

- key : 알파벳을 정렬한 key
- value : 애너그램 단어 vector

애너그램을 순회하며 a ~ z까지의 개수를 counting하는 배열을 생성해 key로 설정한다.

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  vector<vector<string>> answer;
  unordered_map<string, vector<string>> m;

  for (string str : strs) {
    string key = string('z' - 'a' + 1, '0');
    for (char c : str) {
      key[c - 'a'] += 1;
    }

    m[key].push_back(str);
  }

  for (auto it : m) {
    answer.push_back(it.second);
  }

  return answer;
}
```

key를 생성할 때 각 count별로 구분을 원하는 경우 다음과 같이 구성할 수 도 있다.

```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
  // space : O(N * L)
  unordered_map<string, vector<string>> groups;

  // O(N)
  for (string& str : strs) {
    vector<int> charCount('z' - 'a' + 1, 0);
    for (char& c : str) {
      charCount[c - 'a']++;
    }

    string key = "";
    // O(26)
    for (int& c : charCount) {
      key += "#" + to_string(c);
    }

    groups[key].push_back(str);
  }

  // O(N * L)
  vector<vector<string>> answer;
  for (auto it : groups) {
    answer.push_back(it.second);
  }
  return answer;
}
```

## 고생한 점
