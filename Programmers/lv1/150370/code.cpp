#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// every month has 28
int convert(string date) {
  string year = {date[0], date[1], date[2], date[3]};
  string month = {date[5], date[6]};
  string day = {date[8], date[9]};

  int count = stoi(year) * 12 * 28 + stoi(month) * 28 + stoi(day);
  return count;
}

vector<int> solution(string today, vector<string> terms,
                     vector<string> privacies) {
  vector<int> answer;

  unordered_map<char, int> um;

  int todayDate = convert(today);

  for (string &term : terms) {
    char key = term[0];
    int month = stoi(term.substr(2));

    um[key] = month * 28;
  }

  for (int i = 0; i < privacies.size(); i++) {
    string privacy = privacies[i];
    char key = privacy.back();
    string date = privacy.substr(0, 10);

    if (todayDate >= convert(date) + um[key]) {
      answer.push_back(i + 1);
    }
  }

  return answer;
}
