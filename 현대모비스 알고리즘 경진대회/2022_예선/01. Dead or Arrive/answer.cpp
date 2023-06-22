#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Car {
  long v, w, id;
};

long long solution(vector<Car> &cars) {
  unordered_map<int, Car> um;

  for (Car &c : cars) {
    if (um.count(c.v) == 0 || um[c.v].w <= c.w) {
      um[c.v] = c;
    }
  }

  long long answer = 0;

  for (auto &it : um) {
    long key = it.first;
    Car val = it.second;

    answer += val.id;
  }

  return answer;
}

int main() {
  int N;
  cin >> N;

  vector<Car> cars(N);

  for (int i = 0; i < N; i++) {
    cin >> cars[i].v >> cars[i].w;
    cars[i].id = i + 1;
  }

  long long answer = solution(cars);

  cout << answer << endl;

  return 0;
}