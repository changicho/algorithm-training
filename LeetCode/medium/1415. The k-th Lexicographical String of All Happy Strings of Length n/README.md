# 1415. The k-th Lexicographical String of All Happy Strings of Length n

[링크](https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

모든 경우를 생성할 경우 O(2^N)의 시간 복잡도를 사용한다. 이를 모두 배열에 넣기 위해 O(N \* 2^N)의 시간 복잡도가 필요하다.

이후 정렬을 수행할 경우 O(2^N \* log_2(2^N))의 시간 복잡도가 필요하다.

이는 로그의 식을 풀어쓰면 O(2^N \* N)이다. 따라서 총 시간 복잡도는 O(N \* 2^N)이다.

### 공간 복잡도

모든 경우를 저장하는데 O(N \* 2^N)의 공간 복잡도가 필요하다.

### 백 트래킹 & 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      47      | O(N \* 2^N) | O(N \* 2^N) |

재귀호출을 이용해 가능한 모든 문자열을 탐색한 뒤 정렬을 수행한다.

이후 K번째 문자열을 반환한다.

```cpp
vector<string> ret;

void recursive(int size, string &s) {
  if (size == s.size()) {
    ret.push_back(s);
    return;
  }

  for (char c = 'a'; c <= 'c'; c++) {
    if (!s.empty() && s.back() == c) continue;

    s.push_back(c);
    recursive(size, s);
    s.pop_back();
  }
}

string getHappyString(int n, int k) {
  string temp = "";

  recursive(n, temp);

  if (ret.size() <= (k - 1)) return "";
  sort(ret.begin(), ret.end());

  return ret[k - 1];
}
```

## 고생한 점
