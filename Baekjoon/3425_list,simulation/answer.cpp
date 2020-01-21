#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define MAX 1000000000

typedef long long ll;

using namespace std;

struct command {
  string cmd;
  long long value;
};
stack<long long> s;

bool NUM(long long value) {
  s.push(value);
  return false;
}

bool POP() {
  if (s.empty()) return true;
  s.pop();
  return false;
}

bool INV() {
  if (s.empty()) return true;

  long long top = s.top();
  s.pop();
  s.push(-top);
  return false;
}

bool DUP() {
  if (s.empty()) return true;
  s.push(s.top());
  return false;
}

bool SWP() {
  if (s.size() < 2) return true;

  long long first = s.top();
  s.pop();
  long long second = s.top();
  s.pop();

  s.push(first);
  s.push(second);
  return false;
}

bool ADD() {
  if (s.size() < 2) return true;

  long long first = s.top();
  s.pop();
  long long second = s.top();
  s.pop();

  s.push(second + first);
  return false;
}

bool SUB() {
  if (s.size() < 2) return true;

  long long first = s.top();
  s.pop();
  long long second = s.top();
  s.pop();

  s.push(second - first);
  return 0;
}

bool MUL() {
  if (s.size() < 2) return true;

  long long first = s.top();
  s.pop();
  long long second = s.top();
  s.pop();

  s.push(second * first);
  return 0;
}

bool DIV() {
  if (s.size() < 2) return true;

  long long first = s.top();
  s.pop();
  long long second = s.top();
  s.pop();

  if (first == 0) return true;

  s.push(second / first);
  return 0;
}

bool MOD() {
  if (s.size() < 2) return true;

  long long first = s.top();
  s.pop();
  long long second = s.top();
  s.pop();

  if (first == 0) return true;

  long long result = second % first;

  s.push(result);
  return 0;
}

void solution() {
  vector<command> commands;
  vector<string> answers;

  while (true) {
    command cur;
    cin >> cur.cmd;

    if (cur.cmd == "QUIT") exit(0);
    if (cur.cmd == "END") break;
    if (cur.cmd == "NUM") cin >> cur.value;

    commands.push_back(cur);
  }

  int N, num;
  bool isError;
  cin >> N;

  for (int i = 0; i < N; i++) {
    while (!s.empty()) s.pop();
    isError = false;

    cin >> num;
    s.push(num);

    for (command c : commands) {
      if (c.cmd == "NUM")
        isError = NUM(c.value);
      else if (c.cmd == "POP")
        isError = POP();
      else if (c.cmd == "INV")
        isError = INV();
      else if (c.cmd == "DUP")
        isError = DUP();
      else if (c.cmd == "SWP")
        isError = SWP();
      else if (c.cmd == "ADD")
        isError = ADD();
      else if (c.cmd == "SUB")
        isError = SUB();
      else if (c.cmd == "MUL")
        isError = MUL();
      else if (c.cmd == "DIV")
        isError = DIV();
      else if (c.cmd == "MOD")
        isError = MOD();

      if (!s.empty() && (s.top() > MAX || s.top() < -MAX)) isError = true;

      if (isError) break;
    }

    // print result
    if (isError || s.size() != 1) {
      answers.push_back("ERROR");
    } else {
      answers.push_back(to_string(s.top()));
    }
  }

  for (string a : answers) {
    cout << a << "\n";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    solution();
  }

  return 0;
}