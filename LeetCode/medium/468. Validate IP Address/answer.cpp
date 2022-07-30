#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool isValidTokenizer(string &query){
    bool hasSemi = false;
    bool hasDot = false;

    for(char &c : query){
      if(c == ':') hasSemi = true;
      if(c == '.') hasDot = true;
    }

    if(hasSemi == hasDot) return false;
    return true;
  }

  vector<string> split(string &query) {
    vector<string> ret;
    string temp = "";
    for (char &c : query) {
      if (c == ':' || c == '.') {
        ret.push_back(temp);
        temp = "";
        continue;
      }
      temp += c;
    }
    ret.push_back(temp);
    return ret;
  }

  bool isValidIPv4(vector<string> &tokens) {
    if (tokens.size() != 4) return false;

    for (string &t : tokens) {
      if (t.length() >= 4 || t.length() == 0) return false;
      if (t.length() >= 2 && t.front() == '0') return false;
      for (char &c : t) {
        if (!isdigit(c)) return false;
      }
      if (stoi(t) < 0 || 256 <= stoi(t)) return false;
      continue;
    }
    return true;
  }

  bool isValidIPv6(vector<string> &tokens) {
    if (tokens.size() != 8) return false;

    for (string &t : tokens) {
      if (t.length() > 4 || t.length() == 0) return false;
      for (char &c : t) {
        if (islower(c) && c > 'f') return false;
        if (isupper(c) && c > 'F') return false;
        if (!isdigit(c) && !isupper(c) && !islower(c)) return false;
      }
    }
    return true;
  }

 public:
  string validIPAddress(string queryIP) {
    if (!isValidTokenizer(queryIP)) return "Neither";
    vector<string> tokens = split(queryIP);

    if (isValidIPv4(tokens)) {
      return "IPv4";
    } else if (isValidIPv6(tokens)) {
      return "IPv6";
    }

    return "Neither";
  }
};