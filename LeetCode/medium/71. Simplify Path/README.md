# 71. Simplify Path

[링크](https://leetcode.com/problems/simplify-path/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

순회를 이용해 문제를 해결할 수 있다.

이 경우 시간 복잡도는 O(N)이 소요된다.

### 공간 복잡도

경로를 입력받을때 ".." 의 경우는 상위 경로로 이동하는 연산이다.

입력받은 경로들('/'로 나눠진 path들)의 개수를 N이라고 하자.

경로는 stack으로 표현할 수 있다. 이 경우 O(N)의 공간 복잡도가 필요하다.

### 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

입력받은 문자열에서 필요한 부분만 뽑아내야한다.

문자 '/'를 기준으로 문자열을 분리해 경로만 추출한 vector를 생성한다.

이후 경로를 순회하며 일반 경로가 나오면 스택에 push하고 ..이 나온 경우는 pop 한다.

이를 통해 경로 이동을 구현할 수 있다.

경로에 따른 연산을 정리하면 다음과 같다.

- ".." : pop
- "." : 아무것도 안함
- "" : 아무것도 안함
- directory : push

이후 스택에 쌓인 문자열을 이용해 반환할 값을 생성한다.

```cpp
string simplifyPath(string path) {
  vector<string> dirs = split(path, '/');
  stack<string> st;

  for (string dir : dirs) {
    if (dir == "") continue;
    if (dir == "..") {
      if (!st.empty()) st.pop();
      continue;
    } else if (dir == ".") {
      continue;
    }

    st.push(dir);
  }

  vector<string> paths;
  while (!st.empty()) {
    string s = st.top();
    st.pop();
    paths.push_back(s);
  }
  reverse(paths.begin(), paths.end());

  string ret = "/";
  for (string p : paths) {
    ret += p + "/";
  }

  if (ret.length() > 1) ret.erase(ret.length() - 1, 1);
  return ret;
}

vector<string> split(string s, char t) {
  vector<string> ret;
  string temp = "";

  for (char c : s) {
    if (c == t) {
      ret.push_back(temp);
      temp = "";
    } else {
      temp += c;
    }
  }

  if (temp.length() > 0) ret.push_back(temp);
  return ret;
}
```

## 고생한 점
