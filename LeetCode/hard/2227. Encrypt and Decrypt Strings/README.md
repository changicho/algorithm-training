# 2227. Encrypt and Decrypt Strings

[링크](https://leetcode.com/problems/encrypt-and-decrypt-strings/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

keys, values의 크기를 N, dictionary의 크기를 M이라 하자.

우선 key-value 쌍을 hash map으로 설정해야 한다. 이는 O(N)의 시간 복잡도를 사용한다.

이후 입력받은 word2를 dictionary에서 가능한지 판단하기 위해 기존 dictionary를 변환하는 과정을 수행한다.

이 순회에 O(M)의 시간 복잡도를 사용하며 각각의 단어마다 변환에 평균 O(L)의 시간 복잡도를 사용한다.

이후 입력받은 word1을 변환하는데 O(L)의 시간 복잡도를 사용하며, 반대로 word2를 만들 수 있는지 판단하는데 hash map을 사용할 경우 O(1)의 시간 복잡도로 가능하다.

### 공간 복잡도

두개의 hash map을 사용하므로 O(N)의 공간 복잡도를 사용한다.

### two hash map

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|     351      | O(N + M \* L) |    O(N)     |

encrypt 연산에서 주어지는 word1은 keys에 있는 문자들로만 이루어져있음이 보장된다.

따라서 keys, values 쌍을 이용해 단순히 변환시키면 구현할 수 있다.

decrypt연산에 주어진 word2를 변환하지 않고,

dictionary의 각 단어들을 미리 변환후 decrypt 연산으로 주어진 word2와 같은 경우의 수를 반환하는 방식을 사용할 수 있다.

여기서 word2를 꼭 변환해야 하므로 만약 word2에서 변환했을 때 나올 수 없는 문자 (keys에 없는 문자)가 있는 경우 이는 변환이 불가능하다 판단할 수 있다.

따라서 미리 dictionary의 단어를 변환할 때 keys에 없는 문자가 나온 경우는 없는 단어 취급한다. (변환이 불가능하므로)

이후 hash map에 변환한 단어를 저장하고 count한다.

```cpp
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
```

## 고생한 점
