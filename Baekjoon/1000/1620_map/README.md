# 1620. 나는야 포켓몬 마스터 이다솜

[링크](https://www.acmicpc.net/problem/1620)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver IV |   30.632    |

## 설계

### 시간 복잡도

M, N은 최대 100,000 까지의 자연수이다.

검색 시에 일반 배열로 검색을 하는 경우, O(MN)의 시간복잡도가 들어가며 이는 제한시간 내에 불가능하다.

따라서 문제를 해결하기 위해 검색시에는 logN번 내에 검색이 가능한 자료구조를 이용한다.

### 공간 복잡도

key, value 구조를 사용해야 하므로 map을 사용한다.

### map

(index, name) (name, index) 의 구조로 되어있는 map을 두개 만들어 사용한다.

이 때 index의 자료형에 주의한다.

문제의 편의를 위해 둘다 string으로 통일해 사용했다.

```cpp
map<string, string> pokemonByIndex;
map<string, string> indexByPokemon;

for (int i = 1; i <= N; i++) {
  cin >> query;

  string index = to_string(i);

  pokemonByIndex.insert(pair<string, string>{index, query});
  indexByPokemon.insert(pair<string, string>{query, index});
}
```

query로 들어오는 값은 map에 key로 존재하는 값임이 보장되므로 하나의 map에 key로 존재하지 않으면 다른 map에 key임이 보장된다.

따라서 다음과 같은 분기로 처리한다.

```cpp
if (indexByPokemon.find(query) != indexByPokemon.end()) {
  cout << indexByPokemon.find(query)->second << "\n";
} else {
  cout << pokemonByIndex.find(query)->second << "\n";
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     308      |       24       |

## 고생한 점
