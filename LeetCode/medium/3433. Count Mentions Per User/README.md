# 3433. Count Mentions Per User

[링크](https://leetcode.com/problems/count-mentions-per-user/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

유저의 수를 N, 이벤트의 수를 E라 하자.

이벤트를 시간순으로 정렬해야하며, 시간이 같은 경우 offline, online 이벤트가 앞에 오도록 정렬해야 한다.

따라서 정렬하는데 O(E \* log_2(E))의 시간이 소요된다.

이후 이벤트를 순회하며 각 유저들에게 멘션을 카운트하는데 O(E \* N)의 시간이 소요된다.

따라서 총 시간 복잡도는 O(E \* (log_2(E) + N))이다.

### 공간 복잡도

이벤트를 정렬하는데 O(E)의 공간이 소요된다.

또한 각 유저별 멘션 카운트를 저장하는데 O(N)의 공간이 소요된다.

### 정렬

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      37      | O(E \* (log_2(E) + N)) |  O(E + N)   |

이벤트를 우선 시간순으로 정렬해야한다.

이 때 문제 조건에 따라 offline, online으로 변하는 이벤트가 같은 시간에서 우선 처리되어야 한다.

정렬 이후 각 유저들의 상태를 변경하거나 멘션을 카운트한다.

이 때 offline 이벤트가 발생하면 해당 유저는 60초 후에 online 상태로 변경된다.

이를 위해 큐를 이용하여 offline 이벤트가 발생한 유저와 그 유저가 online 상태로 변경되는 시간을 저장한다.

```cpp
vector<int> split(string& line) {
  stringstream ss(line);
  vector<int> ret;
  string temp;

  while (ss >> temp) {
    int id = stoi(temp.substr(2));
    ret.push_back(id);
  }
  return ret;
}

vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
  sort(events.begin(), events.end(), [&](const auto& a, const auto& b) {
    int atimestamp = stoi(a[1]);
    int btimestamp = stoi(b[1]);
    if (atimestamp != btimestamp) {
      return atimestamp < btimestamp;
    }
    return a[0] > b[0];
  });

  vector<int> answer(numberOfUsers);
  vector<bool> isOnline(numberOfUsers, true);

  queue<pair<int, int>> q;

  for (vector<string>& e : events) {
    string type = e[0];
    int timestamp = stoi(e[1]);

    while (!q.empty() && q.front().first <= timestamp) {
      isOnline[q.front().second] = true;
      q.pop();
    }

    if (type == "MESSAGE") {
      if (e[2] == "ALL") {
        for (int i = 0; i < numberOfUsers; i++) {
          answer[i]++;
        }
      } else if (e[2] == "HERE") {
        for (int i = 0; i < numberOfUsers; i++) {
          if (isOnline[i]) answer[i]++;
        }
      } else {
        vector<int> targets = split(e[2]);

        for (int i : targets) {
          answer[i]++;
        }
      }
    } else {
      int target = stoi(e[2]);

      isOnline[target] = false;
      q.push({timestamp + 60, target});
    }
  }

  return answer;
}
```

## 고생한 점
