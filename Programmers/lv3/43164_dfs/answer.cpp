#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> answer;
map<string, map<string, int>> m;
bool isOver = false;
int ticket_size;

void dfs(string start, vector<string> routes) {
  if (isOver) return;

  int countLeft = 0;
  routes.push_back(start);

  if (ticket_size == routes.size() - 1) {
    isOver = true;
    answer = routes;
    return;
  }

  for (auto it = m[start].begin(); it != m[start].end(); it++) {
    string next = it->first;
    if (m[start][next] == 0) continue;

    m[start][next] -= 1;
    dfs(next, routes);
    if (isOver) return;
    m[start][next] += 1;
  }
}

vector<string> solution(vector<vector<string>> tickets) {
  vector<string> routes;
  ticket_size = tickets.size();

  for (vector<string> ticket : tickets) {
    m[ticket[0]][ticket[1]] += 1;
  }

  dfs("ICN", routes);

  return answer;
}

struct TestCase {
  vector<vector<string>> tickets;
  vector<string> answer;
};

string vectorToString(vector<string> v) {
  string ret = "(";

  for (string s : v) {
    ret += s + ", ";
  }
  ret.erase(ret.length() - 2, 2);
  return ret + ")";
}

void init() {
  answer.clear();
  m.clear();
  isOver = false;
  ticket_size = 0;
}

int main() {
  vector<TestCase> tcs = {
      {{{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}, {"ICN", "JFK", "HND", "IAD"}},
      {{{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}},
       {"ICN", "ATL", "ICN", "SFO", "ATL", "SFO"}},
      {{{"ICN", "A"}, {"ICN", "A"}, {"A", "ICN"}},
       {"ICN", "A", "ICN", "A"}},
      {{{"ICN", "A"}, {"A", "C"}, {"A", "D"}, {"D", "B"}, {"B", "A"}},
       {"ICN", "A", "D", "B", "A", "C"}}};

  for (TestCase tc : tcs) {
    init();

    vector<string> answer = solution(tc.tickets);
    bool isCorrect = vectorToString(answer) == vectorToString(tc.answer);

    cout << isCorrect << " answer : " << vectorToString(tc.answer) << ", myAnswer : " << vectorToString(answer) << "\n";
  }

  return 0;
}