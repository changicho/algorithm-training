# 249. Group Shifted Strings

[링크](https://leetcode.com/problems/group-shifted-strings/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 문자열의 개수를 N이라 하자.

각 문자열마다 shift를 했을 때 다른 문자열로 변환이 가능한지 여부를 판별해야 한다.

이를 위해 각 문자열을 shift한 값들도 모두 같은 key를 가질 수 있도록 압축을 해야 한다.

이는 각 문자값들의 diff로 체크 가능하며 문자의 길이를 M이라 했을 때 이 연산에 들어가는 시간 복잡도는 O(M)이다.

이를 모든 문자열마다 수행해 key별로 그룹화하고 정답을 생성할 경우 시간 복잡도는 O(N \* M) 이다.

### 공간 복잡도

문자열들을 저장해야 하므로 공간 복잡도는 O(N \* M)이다.

### diff 압축

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N \* M)  |  O(N \* M)  |

각 문자열들의 각 문자들에 대해서 맨 앞자리와의 차이값들로 key를 생성할 수 있다.

이는 shift한 문자열들도 결국에는 맨 앞자리 글자와 각각 글자들의 차이의 vector는 동일함을 이용한다.

```javascript
[a, b, c]; // origin
[a + x, b + x, c + x]; // shifted
```

여기서 z 다음은 a가 되는 원형 관계이므로 이를 mod연산을 이용해 구현한다.

```cpp
string convert(vector<int> v) {
  string ret = "";
  for (int &num : v) {
    ret += to_string(num) + '/';
  }
  return ret;
}

vector<vector<string>> groupStrings(vector<string> &strings) {
  // use diffs of chars to key

  // step1. create hash map
  unordered_map<string, vector<string>> um;

  // step2. convert string to key and push it to hash map
  for (string &str : strings) {
    char center = str.front();
    vector<int> arr;

    // step3. get diff of all char from front charactor
    for (char &c : str) {
      arr.emplace_back((center - c + 26) % 26);
    }

    string key = convert(arr);
    um[key].emplace_back(str);
  }

  // step4. convert hash map to vector
  vector<vector<string>> answer;
  for (auto &cur : um) {
    answer.emplace_back(cur.second);
  }
  return answer;
}
```

## 고생한 점
