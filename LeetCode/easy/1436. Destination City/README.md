# 1436. Destination City

[링크](https://leetcode.com/problems/destination-city/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 path의 길이를 N이라 하자.

정답은 존재하므로 destination은 항상 존재하며 outDegree가 0이다.

path를 순회하며 각 도시마다의 outDegree를 구할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

outDegree를 저장하는 데 O(N)의 공간 복잡도가 필요하다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(N)     |

paths를 순회하며 각 도시의 outDegree를 count한다.

이후 outDegree가 0인 도시를 찾아 정답으로 반환한다.

```cpp
string destCity(vector<vector<string>>& paths) {
  unordered_map<string, int> outDegrees;

  for (vector<string>& path : paths) {
    string from = path[0], to = path[1];

    outDegrees[from]++;
  }

  string answer = paths[0][0];
  for (vector<string>& path : paths) {
    string to = path[1];
    if (outDegrees[to] == 0) {
      answer = to;
      break;
    }
  }
  return answer;
}
```

## 고생한 점
