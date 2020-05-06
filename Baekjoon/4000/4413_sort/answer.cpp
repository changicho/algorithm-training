#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct photo {
  string lic;
  string h_s;
  int h;
  string e;
  int d;

  string toString() { return lic + " " + h_s + " " + e + " " + to_string(d); }
};

bool compare(photo a, photo b) { return a.toString() < b.toString(); }

int trim_hour(string mmddhhmm) {
  return (mmddhhmm[6] - '0') * 10 + mmddhhmm[7] - '0';
}

void solution() {
  int fare[24];
  vector<photo> photos;

  string lic;
  double bill = 0;

  for (int i = 0; i < 24; i++) {
    cin >> fare[i];
  }

  photo current;
  while (cin >> current.lic) {
    cin >> current.h_s >> current.e >> current.d;
    current.h = trim_hour(current.h_s);

    photos.push_back(current);
  }

  sort(photos.begin(), photos.end(), compare);

  lic = "***";
  for (int i = 0; i < photos.size() - 1; i++) {
    photo prev = photos[i];
    photo next = photos[i + 1];

    if (lic != prev.lic) {
      if (bill) cout << lic << " $" << (double)bill / 100 + 2 << "\n";
      bill = 0;
      lic = prev.lic;
    }
    if (prev.lic != next.lic) continue;
    if (prev.e != "enter") continue;
    if (next.e != "exit") continue;

    bill += fare[prev.h] * abs(next.d - prev.d) + 100;
  }

  if (bill) {
    cout << lic << " $" << (double)bill / (double)100 + 2 << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout.precision(2);
  cout.setf(ios::showpoint);

  solution();

  return 0;
}