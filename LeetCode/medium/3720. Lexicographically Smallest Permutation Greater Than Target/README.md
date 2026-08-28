# 3720. Lexicographically Smallest Permutation Greater Than Target

[링크](https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

탐욕 알고리즘을 사용해 가장 유리하게 DFS로 탐색할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 알파벳의 수를 count하는데 O(1)의 시간 복잡도를 사용한다. DFS탐색 및 정답에 O(N)의 공간 복잡도를 사용한다.

### greedy & DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

s의 각 알파벳의 수를 센다.

이후 target의 왼쪽부터 DFS로 탐색을 진행하며 가장 유리한 알파벳을 선택한다. 

이 때 이전 문자를 target의 문자보다 큰 값을 선택했을 경우 현재 문자는 target보다 작은 값을 선택해도 된다.

그렇지 않은 경우 현재 문자 또한 target이상의 문자를 선택해야 한다.

해당 방법으로 가장 유리한 정답을 찾은 경우 이후 탐색을 중단하고 정답을 반환한다.

```cpp
int count[26] = {
    0,
};
string answer = "";

void dfs(string& target, int index, string& temp, bool beforeFit) {
  if (answer != "") return;
  if (index == target.size()) {
    if (temp > target) {
      answer = temp;
    }

    return;
  }

  for (int i = beforeFit ? target[index] - 'a' : 0; i < 26; i++) {
    if (count[i] == 0) continue;
    count[i]--;

    temp += ('a' + i);
    dfs(target, index + 1, temp, beforeFit && target[index] == temp.back());
    temp.pop_back();
    count[i]++;
  }
}

string lexGreaterPermutation(string s, string target) {
  for (char& c : s) {
    count[c - 'a']++;
  }

  string temp = "";
  dfs(target, 0, temp, true);

  return answer;
}
```

## 고생한 점
