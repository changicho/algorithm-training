#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Status {
  int number;
  string commands;
};

void solution() {
  string answer;
  int number, target;
  cin >> number >> target;

  bool visited[10000] = {
      false,
  };

  queue<Status> q;
  q.push({number, ""});
  visited[number] = true;

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.number == target) {
      answer = cur.commands;
      break;
    }

    int first = cur.number / 1000;
    int second = (cur.number % 1000) / 100;
    int third = (cur.number % 100) / 10;
    int fourth = cur.number % 10;

    int Dnumber = (cur.number * 2) % 10000;
    int Snumber = (cur.number - 1 + 10000) % 10000;
    int Lnumber = second * 1000 + third * 100 + fourth * 10 + first;
    int Rnumber = fourth * 1000 + first * 100 + second * 10 + third;

    if (!visited[Dnumber]) {
      visited[Dnumber] = true;
      q.push({Dnumber, cur.commands + "D"});
    }
    if (!visited[Snumber]) {
      visited[Snumber] = true;
      q.push({Snumber, cur.commands + "S"});
    }
    if (!visited[Lnumber]) {
      visited[Lnumber] = true;
      q.push({Lnumber, cur.commands + "L"});
    }
    if (!visited[Rnumber]) {
      visited[Rnumber] = true;
      q.push({Rnumber, cur.commands + "R"});
    }
  }

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  while (T--) {
    solution();
  }

  return 0;
}