# 833. Find And Replace in String

[링크](https://leetcode.com/problems/find-and-replace-in-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

주어지는 쿼리의 개수를 N, 문자열의 길이를 L이라 하자.

각 쿼리를 수행하면 문자열의 길이가 바뀌므로 각 쿼리의 index로 찾을 수 없다.

따라서 정렬을 수행 후 이전 퀴리를 수행한 후 현재 index를 찾을 수 있다.

정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

각 쿼리마다 연산에 들어가는 시간 복잡도는 O(L)이며 이를 모든 쿼리에 진행할 경우 O(N \* L)이다.

L이 N보다 큰것은 자명하다.

따라서 총 시간 복잡도는 O(N \* L)이다.

### 공간 복잡도

정렬을 수행하기 위해 입력한 정보들을 묶어야 한다. (indice, source, target)

이를 저장하는 공간에 O(N)의 공간 복잡도를 사용한다.

이후 문자열을 변환하는데 총 O(L)의 공간 복잡도를 사용한다.

따라서 총 공간 복잡도는 O(N + L)이다.

### 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N \* L)  |  O(N + L)   |

입력받은 쿼리들을 실행하면 문자열의 길이가 바뀌므로 해당 index로 바로 찾을 수 없다.

따라서 해당 쿼리를 정렬해 바뀌는 길이에 따른 index의 변화를 추적 가능하게 한다.

이 때 index에서 쿼리를 수행했을 때 바뀌는 길이는 이후 index에만 영향을 끼치므로 index가 큰 쿼리부터 수행한다.

쿼리의 수행은 string의 erase, insert를 이용해 구성한다.

```cpp
struct Data {
  int index;
  string source;
  string target;

  bool operator<(const Data& b) const { return index > b.index; }
};

string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
  int size = indices.size();

  vector<Data> datas;
  for (int i = 0; i < size; i++) {
    datas.push_back({indices[i], sources[i], targets[i]});
  }
  // index desc order
  sort(datas.begin(), datas.end());

  for (Data& data : datas) {
    int index = data.index;
    string source = data.source, target = data.target;

    if (s.find(source, index) != index) continue;

    s.erase(index, source.length());
    s.insert(index, target);
  }

  return s;
}
```

만약 작은 index부터 순회할 경우 현재 쿼리 수행 후 문자열 길이의 차이를 이후 쿼리의 index에 더해 구현한다.

```cpp
string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
  int size = indices.size();

  vector<Data> datas;
  for (int i = 0; i < size; i++) {
    datas.push_back({indices[i], sources[i], targets[i]});
  }

  sort(datas.begin(), datas.end());

  int diff = 0;
  int originLength = s.length();

  for (Data& data : datas) {
    int index = data.index;
    string source = data.source;
    string target = data.target;

    if (s.find(source, index + diff) - diff != index) continue;

    int beforeLength = s.length();

    s.erase(index + diff, source.length());
    s.insert(index + diff, target);

    diff = s.length() - originLength;
  }

  return s;
}
```

## 고생한 점
