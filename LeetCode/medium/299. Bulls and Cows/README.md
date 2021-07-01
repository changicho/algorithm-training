# 299. Bulls and Cows

[링크](https://leetcode.com/problems/bulls-and-cows/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

bulls가 될 수 있는 경우는 먼저 탐색하고, 이후 cows가 되는 경우들을 탐색하면된다.

bulls를 찾기 위해선 한번만 순회하면 되므로 O(N)의 시간 복잡도가 소요된다.

이후 cows를 찾기 위한 방법으로 다음 두가지 방법이 존재한다.

- brute force : O(N^2)
- hash map : O(1)

hash map을 이용한 경우 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

brute force를 이용할 경우 매 index마다 방문 여부를 체크해야 한다. 이 경우 공간 복잡도는 O(N)이 소요된다.

hash map을 이용할 경우 한글자 마다 판별하게 된다. 입력된 문자열의 한 글자는 digits가 유일하므로 10가지 이다.

따라서 공간 복잡도는 O(1)이다.

### brute force

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |   O(N^2)    |    O(N)     |

먼저 순회하며 bulls를 찾는다. 체크한 index들을 모두 방문 처리 한다.

이후 bulls가 되지 못한 것들을 순회하며 cows를 모두 찾는다.

이 때 이전에 방문한 index들은 건너 뛴다.

N은 최대 1,000 이므로 O(N^2)의 시간 복잡도로도 충분히 가능하다.

```cpp
string getHint(string secret, string guess) {
  int bulls = 0;
  int cows = 0;

  int length = secret.length();
  vector<bool> visitedSecret(length, false);
  vector<bool> visitedGuess(length, false);

  for (int target = 0; target < length; target++) {
    if (secret[target] == guess[target]) {
      visitedSecret[target] = visitedGuess[target] = true;
      bulls += 1;
    }
  }

  for (int target = 0; target < length; target++) {
    if (visitedSecret[target]) continue;

    for (int cur = 0; cur < length; cur++) {
      if (visitedGuess[cur]) continue;

      if (secret[target] == guess[cur]) {
        cows += 1;

        visitedGuess[cur] = visitedSecret[target] = true;

        break;
      }
    }
  }

  return to_string(bulls) + "A" + to_string(cows) + "B";
}
```

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

bulls가 되지 못한것들은 위치에 관계없으므로 hash map에 저장한다.

여기서 secret, guess 모두에 대해 hash map을 만들어준다.

```cpp
hash_map[key] = count; // key : digit, value : count
```

이후 hash_map의 key를 순회하며 나온 같은 key에 대한 value들의 최솟값을 cows에 더한다.

이는 두 문자열에서 최소로 나온 문자의 수 만큼만 cows가 될 수 있기 때문이다.

```cpp
string getHint(string secret, string guess) {
  int bulls = 0;
  int cows = 0;

  int length = secret.length();
  unordered_map<char, int> secretMap;
  unordered_map<char, int> guessMap;

  for (int index = 0; index < length; index++) {
    if (secret[index] == guess[index]) {
      bulls += 1;
    } else {
      secretMap[secret[index]] += 1;
      guessMap[guess[index]] += 1;
    }
  }

  for (auto &cur : secretMap) {
    cows += min(cur.second, guessMap[cur.first]);
  }

  return to_string(bulls) + "A" + to_string(cows) + "B";
}
```

## 고생한 점
