# 1236. Web Crawler

[링크](https://leetcode.com/problems/web-crawler/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

최대 url들의 갯수를 N, url들끼리 연결된 간선의 갯수를 M, 각 url들의 평균 길이를 L이라 하자.

현재 url에서 다음 url들로 이동 할 수 있으며 이에 BFS를 사용할 수 있다.

이 때 시작 url과 host를 비교하는데 O(L)의 시간 복잡도를 사용한다.

간선끼리의 탐색에 O(M)의 시간 복잡도를 사용하므로 총 O(M \* L)의 시간 복잡도를 사용한다.

### 공간 복잡도

방문 여부를 저장하는 데 O(N \* L)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     119      |  O(M \* L)  |  O(N \* L)  |

startUrl로 부터 BFS를 수행하며, 현재 url이 startUrl과 host가 같은 경우만 탐색이 가능하다.

이 때 방문 여부를 저장하기 위해 unordered_set을 사용한다.

이를 구현하면 다음과 같다.

```cpp
string getHost(string &url) {
  int slashCount = 0;
  string ret = "";
  for (char &c : url) {
    if (c == '/') slashCount++;
    if (slashCount >= 3) break;
    ret += c;
  }
  return ret;
}
bool isSameHost(string &a, string &b) { return getHost(a) == getHost(b); }

vector<string> crawl(string startUrl, HtmlParser htmlParser) {
  unordered_set<string> targets;

  queue<string> q;
  q.push(startUrl);

  while (!q.empty()) {
    string cur = q.front();
    q.pop();

    if (!isSameHost(cur, startUrl)) continue;
    if (targets.count(cur) > 0) continue;
    targets.insert(cur);

    for (string &next : htmlParser.getUrls(cur)) {
      q.push(next);
    }
  }

  vector<string> ret;
  for (string url : targets) {
    ret.push_back(url);
  }

  return ret;
}
```

## 고생한 점
