#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Data {
  int abs, value;

  bool operator<(const Data &b) const {
    if (abs != b.abs) {
      return abs > b.abs;
    }
    return value > b.value;
  }
};

void solution() {
  priority_queue<Data> pq;
  int N;
  int number;

  cin >> N;

  while (N--) {
    cin >> number;
    if (number != 0) {
      pq.push({abs(number), number});
      // cout << number << ", " << pq.top().abs << ", " << pq.top().value << endl;
    } else {
      if (pq.size() > 0) {
        cout << pq.top().value << "\n";
        pq.pop();
      } else {
        cout << "0\n";
      }
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}