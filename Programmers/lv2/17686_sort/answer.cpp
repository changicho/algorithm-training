#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct File {
  string head;
  string numberString;
  long long number;
  string tail;
};

File parse(string file) {
  File ret = {"", "", 0, ""};
  string number = "";
  bool isNumber = false;
  bool isTail = false;

  for (char c : file) {
    if (c >= '0' && c <= '9' && !isTail) {
      number += c;
      isNumber = true;
    } else {
      if (isNumber) {
        isTail = true;
      }

      if (isNumber) {
        ret.tail += c;
      } else {
        ret.head += c;
      }
    }
  }
  ret.numberString = number;
  ret.number = stoll(number);

  return ret;
}

bool compare(File a, File b) {
  transform(a.head.begin(), a.head.end(), a.head.begin(), ::tolower);
  transform(b.head.begin(), b.head.end(), b.head.begin(), ::tolower);

  if (a.head != b.head) {
    return a.head < b.head;
  }
  if (a.number != b.number) {
    return a.number < b.number;
  }
  return false;
}

vector<string> solution(vector<string> files) {
  vector<string> answer;

  vector<File> sortedFiles;

  for (string file : files) {
    File cur = parse(file);
    sortedFiles.push_back(cur);
  }
  stable_sort(sortedFiles.begin(), sortedFiles.end(), compare);

  for (File file : sortedFiles) {
    string cur = "";
    cur += file.head + file.numberString + file.tail;
    answer.push_back(cur);
  }

  return answer;
}