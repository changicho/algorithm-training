# 843. Guess the Word

[링크](https://leetcode.com/problems/guess-the-word/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

단어의 갯수를 N이라 하자.

두 단어에서 같은 자리에 같은 문자가 있는 지 세는데 O(1)의 시간 복잡도를 사용한다. (길이는 6 이므로)

임의로 하나의 단어를 선택하고, 해당 단어보다 확률이 낮은 단어들을 제외하는 방법으로 단어를 맞출 수 있다. 이 때 임의의 단어를 선택하는 데 O(N)의 시간 복잡도를 사용한다.

이 경우 맞는 단어의 후보군을 찾기 위해 순회하는 데 총 O(N)의 시간 복잡도를 사용한다.

이를 총 10번까지 반복할 수 있으므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

새로운 단어의 후보군에 최대 O(N)의 공간 복잡도를 사용한다.

### 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

임의로 단어를 하나 선택한다.

이후 해당 단어를 guess하고 해당 단어와 match한 수가 같은 단어들 만 후보군에 넣고 다시 시도한다.

이를 반복하며 해당 단어를 찾는다.

```cpp
class Solution {
 private:
  int getMatches(string& a, string& b) {
    int matches = 0;
    int length = min(a.length(), b.length());

    for (int i = 0; i < length; ++i) {
      if (a[i] == b[i]) matches++;
    }
    return matches;
  }

 public:
  void findSecretWord(vector<string>& wordlist, Master& master) {
    // shuffle wordList by random
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(wordlist.begin(), wordlist.end(), default_random_engine(seed));

    for (int tried = 0, matches = 0; tried < 10 && matches < 6; ++tried) {
      string guess = wordlist.front();
      matches = master.guess(guess);

      vector<string> newWordList;

      // only pick match with current word
      for (string& w : wordlist) {
        if (getMatches(guess, w) == matches) {
          newWordList.push_back(w);
        }
      }
      wordlist = newWordList;
    }
  }
};
```

## 고생한 점
