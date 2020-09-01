#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Ohm {
  long long value;
  long long multi;
};

map<string, Ohm> ohms = {
    {"black", {0, (long long)pow(10, 0)}},
    {"brown", {1, (long long)pow(10, 1)}},
    {"red", {2, (long long)pow(10, 2)}},
    {"orange", {3, (long long)pow(10, 3)}},
    {"yellow", {4, (long long)pow(10, 4)}},
    {"green", {5, (long long)pow(10, 5)}},
    {"blue", {6, (long long)pow(10, 6)}},
    {"violet", {7, (long long)pow(10, 7)}},
    {"grey", {8, (long long)pow(10, 8)}},
    {"white", {9, (long long)pow(10, 9)}}};

void solution() {
  string lines[3];
  cin >> lines[0] >> lines[1] >> lines[2];

  long long answer = (ohms[lines[0]].value * 10 + ohms[lines[1]].value) * ohms[lines[2]].multi;

  cout << answer << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}