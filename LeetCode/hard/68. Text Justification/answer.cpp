#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> answer;

    for (int i = 0, next; i < words.size(); i = next) {
      int width = 0;

      for (next = i; next < words.size() &&
                     width + words[next].size() + (next - i) <= maxWidth;
           next++) {
        width += words[next].size();
      }

      int space = 1, extra = 0;
      if (next - i != 1 && next != words.size()) {
        space = (maxWidth - width) / (next - i - 1);
        extra = (maxWidth - width) % (next - i - 1);
      }

      string line(words[i]);
      for (int k = i + 1; k < next; k++) {
        line += string(space, ' ');
        if (extra-- > 0) {
          line += " ";
        }
        line += words[k];
      }

      line += string(maxWidth - line.size(), ' ');
      answer.push_back(line);
    }
    return answer;
  }
};

//

class Solution {
 public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> answer;

    vector<string> temp;
    int wordLengthSum = 0;
    for (string &word : words) {
      // can push current word
      if (wordLengthSum + temp.size() + word.length() <= maxWidth) {
        temp.push_back(word);
        wordLengthSum += word.size();
        continue;
      }

      int size = temp.size(), remain = maxWidth - wordLengthSum;
      int space = 1, extra = 0;
      if (size != 1) {
        space = remain / (size - 1);
        extra = remain % (size - 1);
      }

      string line = "";
      for (string &word : temp) {
        line += word + string(space, ' ');

        if (extra > 0) {
          extra--;
          line += " ";
        }
      }

      if (line.length() > maxWidth) line.erase(maxWidth, line.length());
      line += string(maxWidth - line.length(), ' ');

      answer.push_back(line);

      temp = {word};
      wordLengthSum = word.length();
    }

    // if there are words not included in answer
    if (temp.size() > 0) {
      string line = "";
      for (string &word : temp) {
        line += word + " ";
      }

      if (line.length() > maxWidth) line.erase(maxWidth, line.length());
      line += string(maxWidth - line.length(), ' ');

      answer.push_back(line);
    }

    return answer;
  }
};