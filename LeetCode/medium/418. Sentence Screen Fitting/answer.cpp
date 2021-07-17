#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use brute force

class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int lineCount = 0;
    int lineLength = 0;

    int answer = 0;
    int i = 0;

    int oneSentenceLineLength = 0;
    for (string& word : sentence) {
      oneSentenceLineLength += word.length() + 1;
    }
    oneSentenceLineLength -= 1;

    while (lineCount < rows) {
      if ((cols - lineLength) / (oneSentenceLineLength + 1) > 0) {
        int repeat = (cols - lineLength) / (oneSentenceLineLength + 1);
        lineLength += (oneSentenceLineLength + 1) * repeat;
        answer += repeat;

        if (lineLength == cols) {
          lineLength = 0;
          lineCount += 1;
        }
        continue;
      }

      if (lineLength + sentence[i].length() <= cols) {
        lineLength += sentence[i].length();
        i += 1;

        if (i == sentence.size()) {
          i = 0;
          answer += 1;
        }
        if (lineLength < cols) {
          lineLength += 1;
        }
        if (lineLength == cols) {
          lineLength = 0;
          lineCount += 1;
        }
        continue;
      }

      lineLength = 0;
      lineCount += 1;
    }

    return answer;
  }
};

// use count by sentence (memoization)

class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int size = sentence.size();
    vector<int> counts(size, 0);

    int oneSentenceLineLength = 0;
    for (string& word : sentence) {
      oneSentenceLineLength += word.length() + 1;
    }

    for (int startIdx = 0; startIdx < size; startIdx++) {
      int count = 0, length = 0;
      int wordIdx = startIdx;
      while (length + sentence[wordIdx].length() <= cols) {
        // fill by one cycle
        if (length + oneSentenceLineLength <= cols) {
          int repeat = (cols - length) / oneSentenceLineLength;
          length += oneSentenceLineLength * repeat;

          count += repeat * size;
          continue;
        }

        length += sentence[wordIdx].length() + 1;
        count++;
        wordIdx = (wordIdx + 1) % size;
      }

      counts[startIdx] = count;
    }

    int totalCount = 0;
    for (int row = 0; row < rows; row++) {
      int start = totalCount % size;

      totalCount += counts[start];
    }

    return totalCount / size;
  }
};

// use count by sentence (lazy memoization)

class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    int totalCount = 0, size = sentence.size();
    vector<int> counts(size, -1);

    int oneSentenceLineLength = 0;
    for (string& word : sentence) {
      oneSentenceLineLength += word.length() + 1;
    }

    for (int row = 0; row < rows; row++) {
      int startIdx = totalCount % size;
      if (counts[startIdx] == -1) {
        int count = 0, length = 0;

        int wordIdx = startIdx;
        while (length + sentence[wordIdx].length() <= cols) {
          // fill by one cycle
          if (length + oneSentenceLineLength <= cols) {
            int repeat = (cols - length) / oneSentenceLineLength;
            length += oneSentenceLineLength * repeat;

            count += repeat * size;
            continue;
          }

          length += sentence[wordIdx].length() + 1;
          count++;
          wordIdx = (wordIdx + 1) % size;
        }

        totalCount += count;
        counts[startIdx] = count;
      } else {
        totalCount += counts[startIdx];
      }
    }

    return totalCount / size;
  }
};