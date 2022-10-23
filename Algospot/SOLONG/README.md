# 안녕히, 그리고 물고기는 고마웠어요!

[링크](https://www.algospot.com/judge/problem/read/SOLONG)

| 정답률(\_%) |
| :---------: |
|     26      |

## 설계

### 시간 복잡도

단어의 갯수를 N, 완성하고자 하는 문자열의 단어의 수를 M이라 하자.

단어의 길이는 최대 10까지이다.

각 단어를 우선순위에 따라 정렬 후 트라이에 집어넣는다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이를 순회하며 트라이에 저장할 경우 O(N)의 시간 복잡도를 사용한다.

이후 완성하고자 하는 문자열을 순회하며 트라이에서 각 단어를 완성하기 위한 최소 횟수를 반환한다.

이 경우 O(M)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N) + M)이다.

### 공간 복잡도

단어의 길이는 최대 10 까지이다.

트라이에 저장되는 단어의 갯수는 N개이며, 각 prefix마다 가능한 단어들을 세트로 집어넣는다.

이 경우 공간 복잡도는 O(N)이다. (트라이노드 중 리프노드인 경우의 갯수)

각 단어들을 hash set에 저장해놓고 이후에 타이핑해야 하는 문자가 존재하는지 아닌지를 판단할 수 있다. 이 경우 O(N)의 공간 복잡도를 사용한다.

## 트라이

| 수행시간(ms) |
| :----------: |
|     344      |

트라이 노드에 대한 path를 prefix로 볼 수 있다.

현재까지의 prefix 방문에서 만들 수 있는 단어의 수 (탭을 눌러 완성할 수 있는 경우)를 트라이 노드에 저장할 수 있다.

이후 만약 현재 완성하고자 하는 단어가 트라이노드에 저장된 단어일 경우 탭을 누르면 완성할 수 있다.

이 경우 키보드를 누르는 횟수는 다음 두 경우의 합이다.

- prefix의 길이
- 탭을 누르는 횟수 (1)

이후 트라이 노드에 단어를 저장하면서, 현재 prefix로 만들 수 있는 저장된 단어가 없는 경우 이를 저장한다.

해당 트라이를 구현하면 다음과 같다.

```cpp
class Trie {
 private:
  struct TrieNode {
    TrieNode* children[26] = {
        NULL,
    };
    bool isEnd = false;
    string branch = "";
  };

  TrieNode* root = new TrieNode;

 public:
  Trie() {}

  void insert(string& word) {
    TrieNode* cur = root;

    for (char& c : word) {
      if (cur->children[c - 'A'] == NULL) {
        cur->children[c - 'A'] = new TrieNode;
      }
      cur = cur->children[c - 'A'];
      if (cur->branch == "") {
        cur->branch = word;
      }
    }

    cur->isEnd = true;
  }

  int getMinCost(string& word) {
    TrieNode* cur = root;
    int ret = word.length();
    int depth = 0;

    for (char& c : word) {
      cur = cur->children[c - 'A'];
      depth++;

      if (cur->branch == word) {
        ret = min(ret, depth + 1);
      }
    }

    return ret;
  }
};
```

여기서 각 단어들은 우선순위를 가지므로, 이에 대해 미리 정렬 후 우선순위가 높은 순서대로 트라이 노드에 삽입한다.

만약 완성하고자 하는 단어가 트라이에 저장되지 않은 단어인 경우 해당 단어의 길이만큼 입력해야한다.

```cpp
struct Data {
  string str;
  int priority;

  bool operator<(const Data& b) const {
    if (b.priority == priority) return str < b.str;
    return priority > b.priority;
  }
};

int solution(vector<Data>& words, vector<string>& targets) {
  unordered_set<string> appears;
  sort(words.begin(), words.end());

  Trie trie;

  for (Data& word : words) {
    trie.insert(word.str);
    appears.insert(word.str);
  }

  int answer = targets.size() - 1;
  for (string& target : targets) {
    if (appears.count(target) == 0) {
      answer += target.length();
      continue;
    }

    int curCost = trie.getMinCost(target);
    answer += curCost;
  }
  return answer;
}
```

## 고생한 점
