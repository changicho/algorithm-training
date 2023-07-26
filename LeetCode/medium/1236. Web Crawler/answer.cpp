#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class HtmlParser {
 public:
  vector<string> getUrls(string url);
};

// use BFS
// time : O(E * L)
// space : O(N * L)
class Solution {
 private:
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

 public:
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
};