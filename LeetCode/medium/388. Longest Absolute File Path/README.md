# 388. Longest Absolute File Path

[링크](https://leetcode.com/problems/longest-absolute-file-path/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 최대 길이는 10^4 이다.

파일과 폴더의 개수를 N이라 하자.

한번의 순회를 통해 각 파일과 폴더를 정리가 가능하고, depth별로 구분할수 있다.

stack을 이용해 dir구조를 구현하고 이를 통해서 최대 길이를 가지는 파일 경로를 갱신한다.

결국 one pass에 풀이가 가능하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

stack에 최대 O(N)크기만큼 저장될 수 있으므로 공간 복잡도는 O(N)이다.

### stack

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

입력받은 문자열들을 유의미한 자료 구조로 변환한다.

'\n' 문자를 기준으로 line별로 분리하고 다음과 같은 자료 구조로 변환한다.

```cpp
struct Data {
  int tabs; // /t의 개수
  string name; // 파일명 혹은 폴더명
};
```

유의미한 구조로 변환하기 위해 다음과 같은 함수를 생성한다.

```cpp
vector<string> parsing(string &input) {
  vector<string> ret;
  string temp = "";

  for (char c : input) {
    if (c == '\n') {
      ret.push_back(temp);
      temp = "";
      continue;
    }
    temp += c;
  }

  if (temp != "") {
    ret.push_back(temp);
  }
  return ret;
}

vector<Data> convert(vector<string> vs) {
  vector<Data> ret;

  for (string &line : vs) {
    int tabs = 0;
    string name = "";

    for (char &c : line) {
      if (c == '\t') {
        tabs += 1;
        continue;
      }
      name += c;
    }

    ret.push_back({tabs, name});
  }

  return ret;
}
```

파일명 혹은 폴더명인지 구분은 .의 개수와 위치에 따라서 구현한다.

```cpp
bool isFile(string name) {
  int dotCount = 0;
  for (char &c : name) {
    if (c == '.') dotCount++;
  }
  return dotCount >= 1 && name.front() != '.' && name.back() != '.';
}
```

이렇게 변환한 데이터들을 순회하며 stack에 폴더를 쌓는다. 이 때 현재 데이터의 tabs에 따라서 stack에 push, pop을 구현한다.

- stack.top보다 큰 경우 : push
- stack.top과 같은 경우 : pop
- stack.top보다 작은 경우 : pop

이는 파일의 directory 구조는 stack의 형태를 따르기 때문이다.

directory 구조를 갱신한 이후 현재 데이터가 파일, 폴더인지에 따라서 정답을 갱신하거나 stack에 push 한다.

```cpp
int lengthLongestPath(string input) {
  int answer = 0;
  vector<Data> datum = convert(parsing(input));

  vector<Data> dirs;
  for (Data &data : datum) {
    // trim tabs
    while (!dirs.empty() && data.tabs <= dirs.back().tabs) {
      dirs.pop_back();
    }

    if (isFile(data.name)) {
      int length = data.name.length();
      length += dirs.size();
      for (Data &dir : dirs) {
        length += dir.name.length();
      }

      answer = max(answer, length);
    } else {
      dirs.push_back(data);
    }
  }

  return answer;
}
```

## 고생한 점
