#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
  int answer = 0;
  vector<string> LRU;

  for (string city : cities) {
    transform(city.begin(), city.end(), city.begin(), ::tolower);

    auto it = find(LRU.begin(), LRU.end(), city);

    if (it != LRU.end()) {
      answer += 1;

      LRU.erase(it);
    } else {
      answer += 5;
    }

    LRU.insert(LRU.begin(), city);
    if (cacheSize < LRU.size()) {
      LRU.pop_back();
    }
  }

  return answer;
}

struct TestCase {
  int cacheSize;
  vector<string> cities;
  int result;
};

int main() {
  vector<TestCase> testCases = {
      {3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}, 50},
      {3, {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"}, 21},
      {2, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}, 60},
      {5, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"}, 52},
      {2, {"Jeju", "Pangyo", "NewYork", "NewYork"}, 16},
      {0, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"}, 25}};

  for (TestCase tc : testCases) {
    int answer = solution(tc.cacheSize, tc.cities);

    cout << "answer : " << tc.result << ", myAnswer : " << answer << "\n";
  }
}