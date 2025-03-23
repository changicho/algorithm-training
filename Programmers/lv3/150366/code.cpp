#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int LIMIT = 50;

struct Axis {
  int y, x;
};

vector<string> split(string line) {
  stringstream ss(line);
  string temp;
  vector<string> ret;
  while (ss >> temp) {
    ret.push_back(temp);
  }
  return ret;
}

vector<vector<string>> board(LIMIT + 1, vector<string>(LIMIT + 1));
vector<vector<Axis>> parents(LIMIT + 1, vector<Axis>(LIMIT + 1));

Axis find(Axis a) {
  if (parents[a.y][a.x].y == a.y && parents[a.y][a.x].x == a.x) return a;
  return parents[a.y][a.x] = find(parents[a.y][a.x]);
}

void updateAxis(Axis a, string &value) {
  Axis target = find(a);
  board[target.y][target.x] = value;
}

void updateValue(string &from, string &to) {
  for (int y = 0; y <= LIMIT; y++) {
    for (int x = 0; x <= LIMIT; x++) {
      if (board[y][x] == from) {
        board[y][x] = to;
      }
    }
  }
}

void merge(Axis from, Axis to) {
  to = find(to);
  from = find(from);

  if (to.y == from.y && to.x == from.x) return;
  string value =
      board[to.y][to.x] == "" ? board[from.y][from.x] : board[to.y][to.x];
  parents[from.y][from.x] = to;

  for (int y = 0; y <= LIMIT; y++) {
    for (int x = 0; x <= LIMIT; x++) {
      Axis axis = find({y, x});

      if (axis.y == to.y && axis.x == to.x && y != to.y && x != to.x) {
        board[y][x] = "";
      }
    }
  }

  board[to.y][to.x] = value;
}

void unmerge(Axis a) {
  Axis target = find(a);
  string value = board[target.y][target.x];

  for (int y = 0; y <= LIMIT; y++) {
    for (int x = 0; x <= LIMIT; x++) {
      Axis parent = find({y, x});

      if (parent.y == target.y && parent.x == target.x) {
        parents[y][x] = {y, x};
        board[y][x] = "";
      }
    }
  }

  board[a.y][a.x] = value;
}

string print(Axis a) {
  Axis target = find(a);
  if (board[target.y][target.x] == "") {
    return "EMPTY";
  }
  return board[target.y][target.x];
}

vector<string> solution(vector<string> commands) {
  for (int y = 0; y <= LIMIT; y++) {
    for (int x = 0; x <= LIMIT; x++) {
      parents[y][x] = {y, x};
    }
  }

  vector<string> answer;

  for (string &c : commands) {
    vector<string> chunk = split(c);

    string key = chunk[0];
    if (key == "UPDATE") {
      if (chunk.size() == 3) {
        updateValue(chunk[1], chunk[2]);
      } else if (chunk.size() == 4) {
        Axis axis = {stoi(chunk[1]), stoi(chunk[2])};
        string value = chunk[3];

        updateAxis(axis, value);
      }
    } else if (key == "MERGE") {
      Axis to = {stoi(chunk[1]), stoi(chunk[2])};
      Axis from = {stoi(chunk[3]), stoi(chunk[4])};
      merge(from, to);
    } else if (key == "UNMERGE") {
      Axis to = {stoi(chunk[1]), stoi(chunk[2])};

      unmerge(to);
    } else if (key == "PRINT") {
      Axis axis = {stoi(chunk[1]), stoi(chunk[2])};

      string ret = print(axis);
      answer.push_back(ret);
    }
  }

  return answer;
}