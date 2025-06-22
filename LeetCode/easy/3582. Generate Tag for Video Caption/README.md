# 3582. Generate Tag for Video Caption

[링크](https://leetcode.com/problems/generate-tag-for-video-caption/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

주어진 문자열 caption의 길이를 N이라 하자.

각 문자열을 토큰화 후 조건에 맞춰 변경하는데 O(N)의 시간이 소요된다.

### 공간 복잡도

정답 문자열에 O(N)의 공간이 소요된다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

```cpp
vector<string> split(string &s) {
  stringstream ss(s);
  string temp;
  vector<string> ret;

  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

string generateTag(string caption) {
  string ret = "#";

  vector<string> tokens = split(caption);

  for (string &token : tokens) {
    int size = token.size();
    ret += toupper(token[0]);

    for (int i = 1; i < size; i++) {
      ret += tolower(token[i]);
    }
  }

  if (ret.size() > 1) {
    ret[1] = tolower(ret[1]);
  }

  return ret.substr(0, 100);
}
```

## 고생한 점
