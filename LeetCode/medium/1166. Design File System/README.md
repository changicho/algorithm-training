# 1166. Design File System

[링크](https://leetcode.com/problems/design-file-system/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력되는 path들의 갯수와 길이를 L이라 하자. 파일 경로의 갯수를 T라 하자.

hash map에 path들을 저장할 경우 O(N \* L)의 시간 복잡도를 사용한다.

트라이를 사용할 경우 O(T)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 사용할 경우 O(N \* L)의 공간 복잡도를 사용한다.

트라이를 사용할 경우 O(T)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      80      |  O(N \* L)  |  O(N \* L)  |

hash map에 저장된 파일들의 경로를 저장하고, 새 파일을 저장할 때 해당 경로의 부모들이 모두 존재하는지 판단한다.

```cpp
class FileSystem {
 private:
  unordered_map<string, int> um;

  vector<string> split(string &path) {
    vector<string> ret;
    string temp = "";
    for (char &c : path) {
      if (c == '/') {
        if (temp == "") continue;
        ret.push_back(temp);
        temp = "";
      } else {
        temp += c;
      }
    }
    ret.push_back(temp);
    return ret;
  }

 public:
  FileSystem() { um["/"] = 0; }

  bool createPath(string path, int value) {
    if (um.count(path) > 0) return false;

    vector<string> token = split(path);

    string temp = "/";
    int size = token.size();

    for (int i = 0; i < size - 1; i++) {
      string p = token[i];
      temp += p;
      if (um.count(temp) == 0) return false;
      temp += "/";
    }

    temp += token.back();

    um[temp] = value;
    return true;
  }

  int get(string path) {
    if (um.count(path) == 0) return -1;
    return um[path];
  }
};
```

## 고생한 점
