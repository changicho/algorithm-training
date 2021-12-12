#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use simulation and hash set

class Solution {
 private:
  string removeDots(string email) {
    string ret = "";
    for (char &c : email) {
      if (c == '.') continue;
      ret += c;
    }
    return ret;
  }

  string removeFirstPlus(string email) {
    return email.substr(0, email.find('+'));
  }

  string convert(string email) {
    int target = email.find('@');
    string local = email.substr(0, target), domain = email.substr(target);

    // first. remove all dots in local
    // second. remove all string start from first + in local
    local = removeFirstPlus(removeDots(local));

    return local + domain;
  }

 public:
  int numUniqueEmails(vector<string> &emails) {
    unordered_set<string> uniqueEmails;

    for (string &email : emails) {
      string converted = convert(email);
      uniqueEmails.insert(converted);
    }

    return uniqueEmails.size();
  }
};