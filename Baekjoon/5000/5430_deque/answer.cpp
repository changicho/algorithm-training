#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

deque<int> stringToNums(string str) {
  deque<int> v;

  if (str.length() == 2) {
    return v;
  }

  int temp = 0;
  for (char c : str) {
    if (c == '[') {
      continue;
    }
    if (c == ',' || c == ']') {
      v.push_back(temp);
      temp = 0;
      continue;
    }
    temp = temp * 10 + c - '0';
  }
  return v;
}

void printDeque(deque<int> dq, bool dir) {
  if (!dir) {
    deque<int> temp_dq;

    for (int i : dq) {
      temp_dq.push_front(i);
    }
    dq = temp_dq;
  }

  string output = "[";

  for (int i : dq) {
    output += to_string(i);
    output += ",";
  }
  if (output.length() == 1) {
    output += ']';
  } else {
    output[output.length() - 1] = ']';
  }

  cout << output;
}

void solution() {
  string commands, nums;
  int size;
  bool isError = false;
  bool dir = 1;

  deque<int> dq;

  cin >> commands >> size >> nums;
  dq = stringToNums(nums);

  for (char command : commands) {
    if (isError) {
      break;
    }

    if (command == 'R') {
      dir = !dir;
    } else if (command == 'D') {
      if (dq.empty()) {
        cout << "error";
        isError = true;
        break;
      }

      if (dir == false) {
        dq.pop_back();
      } else {
        dq.pop_front();
      }
    }
  }

  if (isError) {
    cout << "\n";
    return;
  }

  printDeque(dq, dir);
  cout << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    solution();
  }

  return 0;
}