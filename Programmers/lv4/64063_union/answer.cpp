#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<long long, long long> m;

long long findRoom(long long room) {
  if (m.find(room) == m.end()) return room;

  return m[room] = findRoom(m[room]);
};

vector<long long> solution(long long k, vector<long long> room_number) {
  vector<long long> answer;

  for (long long room : room_number) {
    long long room_target = findRoom(room);
    answer.push_back(room_target);
    m[room_target] = room_target + 1;
  }

  return answer;
}

struct TestCase {
  long long k;
  vector<long long> room_number;
  vector<long long> answer;
};

int main() {
  vector<TestCase> testCases = {{10, {1, 3, 4, 1, 3, 1}, {1, 3, 4, 2, 5, 6}}};

  for (TestCase testCase : testCases) {
    vector<long long> myAnswer = solution(testCase.k, testCase.room_number);

    cout << "MyAns  : ";
    for (long long i : myAnswer) {
      cout << i << " ";
    }
    cout << "\n";

    cout << "Answer : ";
    for (long long i : testCase.answer) {
      cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}