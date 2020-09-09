#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
  vector<int> answer = {0, 0};
  set<string> s;

  int index = 0;
  char before = words[0].front();

  for (string word : words) {
    if (word.front() != before || s.find(word) != s.end()) {
      answer[0] = index % n + 1;
      answer[1] = index / n + 1;

      break;
    }

    s.insert(word);
    before = word.back();
    index += 1;
  }

  return answer;
}

struct TestCase {
  int n;
  vector<string> words;
  vector<int> answer;
};

int main() {
  vector<TestCase> tcs = {
      {3,
       {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot",
        "tank"},
       {3, 3}},
      {5,
       {"hello", "observe", "effect", "take", "either", "recognize",
        "encourage", "ensure", "establish", "hang", "gather", "refer",
        "reference", "estimate", "executive"},
       {0, 0}},
      {2, {"hello", "one", "even", "never", "now", "world", "draw"}, {1, 3}}

  };

  for (TestCase tc : tcs) {
    vector<int> answer = solution(tc.n, tc.words);

    cout << "answer : " << tc.answer[0] << ", " << tc.answer[1]
         << ", myAnswer : " << answer[0] << ", " << answer[1] << "\n";
  }

  return 0;
}