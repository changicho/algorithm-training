# 1257. Smallest Common Region

[링크](https://leetcode.com/problems/smallest-common-region/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 연결관계 regions의 길이를 N, 각 region마다 구역의 갯수의 평균값을 M이라 하자.

총 지역의 수를 N \* M이라 할 수 있다.

각 지역마다 부모를 저장할 수 있다. 이 경우 hash map을 사용할 경우 O(N \* M)의 시간 복잡도를 사용한다.

정답을 구하기 위해 region1, region2의 부모를 찾아가야 한다. 해당 경로에서 최초로 중복된 경우를 검색하는데 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 지역마다 부모를 저장하는 데 O(N \* M)의 공간 복잡도를 사용한다.

### hash map, parent path

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      79      |  O(N \* M)  |  O(N \* M)  |

입력받은 각 지역마다 부모 지역을 설정한다.

이후 입력받은 두 지역중 하나의 지역부터 부모를 탐색하며 방문한 지역들을 저장한다.

이후 나머지 지역을 탐색하며 방문한 지역이 나오는 경우 해당 지역을 반환한다.

```cpp
string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
  unordered_map<string, string> parents;

  for (vector<string>& r : regions) {
    string p = r[0];

    for (int i = 1; i < r.size(); i++) {
      string c = r[i];
      parents[c] = p;
    }
  }

  unordered_set<string> visited;
  string cur = region1;
  visited.insert(cur);
  while (parents.count(cur)) {
    cur = parents[cur];
    visited.insert(cur);
  }

  cur = region2;
  if (visited.count(cur)) return cur;
  while (parents.count(cur)) {
    cur = parents[cur];
    if (visited.count(cur)) return cur;
  }
  return "";
}
```

## 고생한 점
