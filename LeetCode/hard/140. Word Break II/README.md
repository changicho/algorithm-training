# 140. Word Break II

[링크](https://leetcode.com/problems/word-break-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

단어의 수를 N, 문장의 길이를 L이라 하자.

각 단어를 빠르게 방문하기 위해 hash set을 이용한다. 이 경우 hash set에 저장하는데 O(N)의 시간 복잡도를 사용한다.

각 문장마다 단어로 조합하는 경우의 수는 2^L 이하이다.

각 경우마다 마지막에 정답 문자열을 생성하는데 O(L)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(2^L \* L + N)이다.

### 공간 복잡도

재귀 호출을 이용해 탐색할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      0       | O(2^L \* L + N) |    O(N)     |

s의 현재 탐색할 index를 시작점으로 잡고 prefix를 만들어가며 탐색을 진행 할 수 있는 경우 탐색을 진행한다.

```cpp
string convert(vector<string> &words) {
  string ret = "";
  for (string &w : words) {
    ret += w + " ";
  }
  ret.pop_back();
  return ret;
}

vector<string> wordBreak(string s, vector<string> &wordDict) {
  unordered_set<string> us(wordDict.begin(), wordDict.end());

  vector<string> answer;

  vector<string> temp;
  function<void(int)> recursive = [&](int index) {
    int size = s.size();
    if (size == index) {
      answer.push_back(convert(temp));
      return;
    }

    string key = "";
    for (int i = index; i < size; i++) {
      key += s[i];

      if (us.count(key) == 0) continue;

      temp.push_back(key);
      recursive(i + 1);
      temp.pop_back();
    }
  };

  recursive(0);

  return answer;
}
```

## 고생한 점
