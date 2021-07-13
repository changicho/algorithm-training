#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// use word vector

class Solution {
 public:
  string reverseWords(string s) {
    vector<string> words;

    string temp = "";
    for (char c : s) {
      if (c == ' ') {
        if (temp != "") words.push_back(temp);
        temp = "";
        continue;
      }

      temp += c;
    }
    if (temp != "") words.push_back(temp);

    reverse(words.begin(), words.end());

    string answer = "";
    for (string word : words) {
      answer += word + " ";
    }
    // answer.erase(answer.length() - 1);
    answer.pop_back();

    return answer;
  }
};

// use constant space

class Solution {
 public:
  string reverseWords(string s) {
    string answer = "";
    string temp = "";
    for (char c : s) {
      if (c == ' ') {
        if (temp != "") {
          answer.insert(0, temp + ' ');
        }
        temp = "";
        continue;
      }

      temp += c;
    }
    if (temp != "") {
      answer.insert(0, temp + ' ');
    }

    answer.pop_back();
    return answer;
  }
};

// use reverse

class Solution {
 public:
  string reverseWords(string s) {
    string answer = "";
    string temp = "";

    reverse(s.begin(), s.end());

    for (char c : s) {
      if (c == ' ') {
        if (temp != "") {
          reverse(temp.begin(), temp.end());
          answer += temp + " ";
        }
        temp = "";
        continue;
      }

      temp += c;
    }
    if (temp != "") {
      reverse(temp.begin(), temp.end());
      answer += temp + " ";
    }

    answer.erase(answer.length() - 1);
    return answer;
  }
};

// use stringstream

class Solution {
 public:
  string reverseWords(string s) {
    std::istringstream iss(s);
    string answer = "";
    string word;

    while (iss >> word) {
      answer.insert(0, word + ' ');
    }

    answer.pop_back();
    return answer;
  }
};