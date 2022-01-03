#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort

class Solution {
 private:
  struct Data {
    int index;
    string source;
    string target;

    bool operator<(const Data& b) const { return index < b.index; }
  };

 public:
  string findReplaceString(string s, vector<int>& indices,
                           vector<string>& sources, vector<string>& targets) {
    int size = indices.size();

    vector<Data> datas;
    for (int i = 0; i < size; i++) {
      datas.push_back({indices[i], sources[i], targets[i]});
    }

    sort(datas.begin(), datas.end());

    int diff = 0;
    int originLength = s.length();

    for (Data& data : datas) {
      int index = data.index;
      string source = data.source;
      string target = data.target;

      if (s.find(source, index + diff) - diff != index) continue;

      int beforeLength = s.length();

      s.erase(index + diff, source.length());
      s.insert(index + diff, target);

      diff = s.length() - originLength;
    }

    return s;
  }
};

// use sort (reverse)

class Solution {
 private:
  struct Data {
    int index;
    string source;
    string target;

    bool operator<(const Data& b) const { return index > b.index; }
  };

 public:
  string findReplaceString(string s, vector<int>& indices,
                           vector<string>& sources, vector<string>& targets) {
    int size = indices.size();

    vector<Data> datas;
    for (int i = 0; i < size; i++) {
      datas.push_back({indices[i], sources[i], targets[i]});
    }

    sort(datas.begin(), datas.end());

    for (Data& data : datas) {
      int index = data.index;
      string source = data.source, target = data.target;

      if (s.find(source, index) != index) continue;

      s.erase(index, source.length());
      s.insert(index, target);
    }

    return s;
  }
};