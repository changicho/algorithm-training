#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two hash map
// time-init : O(N + M * L)
// time-encrypt : O(L)
// time-decrypt : O(1)
// space : O(N)
class Encrypter {
 private:
  unordered_map<char, string> converts;
  unordered_map<string, int> counts;

 public:
  Encrypter(vector<char>& keys, vector<string>& values,
            vector<string>& dictionary) {
    int size = keys.size();

    for (int i = 0; i < size; i++) {
      converts[keys[i]] = values[i];
    }

    for (string& dic : dictionary) {
      counts[encrypt(dic)]++;
    }
  }

  string encrypt(string word1) {
    string converted = "";
    for (char& c : word1) {
      if (!converts.count(c)) return "";

      converted += converts[c];
    }
    return converted;
  }

  int decrypt(string word2) {
    // count
    return counts[word2];
  }
};

// use trie

class Trie {
 public:
  Trie* chars[26]{};
  bool isEnd = false;

  void insert(string& s) {
    Trie* cur = this;

    for (char& c : s) {
      char key = c - 'a';
      if (!cur->chars[key]) {
        cur->chars[key] = new Trie();
      }

      cur = cur->chars[key];
    }

    cur->isEnd = true;
  }
};

class Encrypter {
  Trie* trie = new Trie();                       // Trie of dictionary strings
  unordered_map<char, string> key2val;           // key : value
  unordered_map<string, vector<char>> val2keys;  // value : [key]

  int dfs(string& word, Trie* trieNode, int index = 0) {
    int length = word.length();
    if (index == length) {
      return trieNode->isEnd ? 1 : 0;
    }
    int count = 0;

    string target = word.substr(index, 2);
    for (char& c : val2keys[target]) {
      if (trieNode->chars[c - 'a']) {
        count += dfs(word, trieNode->chars[c - 'a'], index + 2);
      }
    }

    return count;
  }

 public:
  Encrypter(vector<char>& keys, vector<string>& values,
            vector<string>& dictionary) {
    int size = keys.size();

    for (int i = 0; i < size; i++) {
      key2val[keys[i]] = values[i];
      val2keys[values[i]].push_back(keys[i]);
    }

    for (string& d : dictionary) {
      trie->insert(d);
    }
  }

  string encrypt(string word1) {
    string converted = "";
    for (char& c : word1) {
      converted += key2val[c];
    }
    return converted;
  }

  int decrypt(string word2) { return dfs(word2, trie); }
};