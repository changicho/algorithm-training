# 1282. Group the People Given the Group Size They Belong To

[링크](https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 groupSizes의 크기를 N이라 하자.

각 index를 빈도에 따라 그룹화 하고, 해당 그룹을 순회하며 정답을 채울 수 있다.

이 경우 빈도에 따라 분류하는 데 hash map을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이를 정답 배열로 변환하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      13      |    O(N)     |    O(N)     |

정답이 존재함이 보장된다.

각 index를 빈도에 따라 묶는다.

이 경우 해당 빈도에 묶인 index들은 빈도만큼 묶어서 정답에 채워넣으면 된다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
  unordered_map<int, vector<int>> um;

  int size = groupSizes.size();

  for (int i = 0; i < size; i++) {
    um[groupSizes[i]].push_back(i);
  }

  vector<vector<int>> answer;
  for (pair<int, vector<int>> cur : um) {
    int key = cur.first;
    vector<int> val = cur.second;

    if (key == val.size()) {
      answer.push_back(val);
    } else {
      vector<int> temp;
      for (int &num : val) {
        temp.push_back(num);

        if (temp.size() == key) {
          answer.push_back(temp);
          temp.resize(0);
        }
      }
    }
  }
  return answer;
}
```

## 고생한 점
