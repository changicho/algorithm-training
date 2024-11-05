# 3163. String Compression III

[링크](https://leetcode.com/problems/string-compression-iii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 word의 길이를 N이라 하자.

스택을 이용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

순회를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

스택을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

순회를 사용할 경우 O(1)의 공간 복잡도가 필요하다.

정답 문자열에 O(N)의 공간 복잡도가 필요하다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      53      |    O(N)     |    O(N)     |

스택에 연속된 문자열과 갯수를 저장하며 이를 갱신해나간다.

```cpp
struct Data {
  char c;
  int count;
};

string compressedString(string word) {
  vector<Data> stk;

  for (char &c : word) {
    if (stk.empty() || stk.back().c != c || stk.back().count == 9) {
      stk.push_back({c, 1});
      continue;
    }

    int count = stk.back().count;
    stk.pop_back();
    stk.push_back({c, count + 1});
  }

  string answer = "";
  for (Data &cur : stk) {
    answer += (cur.count + '0');
    answer += cur.c;
  }

  return answer;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |    O(N)     |    O(N)     |

위 방법에서 순회를 이용해 구현한다.

```cpp
string compressedString(string word) {
  string answer = "";

  char before;
  int count = 0;
  for (char &c : word) {
    if (c == before) {
      count++;
      continue;
    }

    while (count > 0) {
      answer += min(count, 9) + '0';
      answer += before;
      count -= 9;
    }

    before = c;
    count = 1;
  }

  while (count > 0) {
    answer += min(count, 9) + '0';
    answer += before;
    count -= 9;
  }

  return answer;
}
```

## 고생한 점
