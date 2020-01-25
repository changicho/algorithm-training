#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> m;

void solution() {
  string line;
  int count_total = 0;

  while (getline(cin, line)) {
    count_total += 1;
    m[line] += 1;
  }

  cout.precision(4);
  cout << fixed;

  for (auto it = m.begin(); it != m.end(); it++) {
    double percent = ((double)it->second / count_total);
    cout << it->first << " " << percent * 100 << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}