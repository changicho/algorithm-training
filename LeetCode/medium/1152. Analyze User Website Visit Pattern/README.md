# 1152. Analyze User Website Visit Pattern

[링크](https://leetcode.com/problems/analyze-user-website-visit-pattern/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

3개의 배열의 크기를 N이라 하자.

각 정보를 시간순으로 정렬해야 하므로 O(N \* log_2(N))의 시간 복잡도를 가진다.

이후 방문 패턴별로 방문한 유저의 수를 저장해야 하며 이에 최대 O(N^3)개의 패턴이 존재할 수 있으므로, O(N^3)의 시간 복잡도를 가진다.

이후 각 패턴마다 방문한 유저의 수를 비교한다. 이에 map과 set 자료구조를 사용해 접근을 빠르게 할 수 있다.

총 시간 복잡도는 O(N^3)이다.

### 공간 복잡도

map, set에 O(N)의 공간 복잡도를 사용한다.

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |   O(N^3)    |    O(N)     |

각 유저별로 방문한 웹을 시간순으로 정렬 한다.

이후 방문한 웹 목록에 대해서 3개의 웹 패턴을 모두 탐색하며 패턴별 방문한 유저 목록을 생성한다.

이후 패턴별 방문 유저가 가장 많은 패턴을 반환한다. (사전순으로 가장 앞서는 패턴)

```cpp
struct Data {
  string u;
  int t;
  string w;

  bool operator<(const Data &b) const { return t < b.t; }
};

vector<string> mostVisitedPattern(vector<string> &username, vector<int> &timestamp, vector<string> &website) {
  int size = username.size();

  vector<Data> arr;
  for (int i = 0; i < size; i++) {
    arr.push_back({username[i], timestamp[i], website[i]});
  }
  sort(arr.begin(), arr.end());

  unordered_map<string, vector<string>> um;

  for (Data &d : arr) {
    um[d.u].push_back(d.w);
  }

  map<vector<string>, unordered_set<string>> visited;
  for (auto &[k, v] : um) {
    string key = k;
    int vSize = v.size();

    for (int i = 0; i < vSize; i++) {
      for (int j = i + 1; j < vSize; j++) {
        for (int k = j + 1; k < vSize; k++) {
          visited[{v[i], v[j], v[k]}].insert(key);
        }
      }
    }
  }

  vector<string> answer;
  int count = 0;
  for (auto &[k, v] : visited) {
    if (v.size() > count) {
      answer = k;
      count = v.size();
    } else if (v.size() == count) {
      answer = min(answer, k);
    }
  }
  return answer;
}
```

## 고생한 점
