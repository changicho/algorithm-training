#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b) { return a.size() < b.size(); }

vector<vector<int>> parsing(string s) {
  vector<vector<int>> tuples;
  vector<int> tuple;

  int temp = 0;
  for (char c : s) {
    switch (c) {
      case '}': {
        if (temp != 0) {
          tuple.push_back(temp);
        }
        if (tuple.size() != 0) {
          tuples.push_back(tuple);
        }

        temp = 0;
        tuple.resize(0);
      } break;
      case ',': {
        if (temp != 0) {
          tuple.push_back(temp);
        }
        temp = 0;
      } break;
      case '{': {
        temp = 0;
      } break;
      default: {
        temp = temp * 10 + (c - '0');
      }
    }
  }

  sort(tuples.begin(), tuples.end(), compare);

  return tuples;
}

vector<int> solution(string s) {
  vector<int> answer;
  bool check[100001] = {false};

  vector<vector<int>> tuples = parsing(s);

  for (vector<int> tuple : tuples) {
    for (int number : tuple) {
      if (!check[number]) {
        answer.push_back(number);
        check[number] = true;
      }
    }
  }

  return answer;
}

int main() {
  // string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
  string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";

  vector<int> ans = solution(s);

  for (int i : ans) {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}