# 920. Number of Music Playlists

[링크](https://leetcode.com/problems/number-of-music-playlists/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 숫자를 N, G, K라 하자.

동적 계획법을 이용해 트랙의 길이와 그 중 사용한 곡의 수를 이용해 풀이할 수 있다.

이 경우 O(G \* N)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 이용해 트랙의 길이와 사용한 곡의 수에 대한 2차원 배열을 사용한다.

이에 O(G \* N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(G \* N)  |  O(G \* N)  |

현재 플레이 리스트의 길이가 G일 때 이 중에서 N개의 곡을 사용한 경우의 수를 dp로 나타낸다.

만약 중복 없이 현재 길이가 len인 플레이리스트를 아래와 같이 구할 수 있다. (중복이 없으므로 len개의 곡을 사용함)

현재 플레이 리스트의 길이가 K보다 큰 경우 중복을 허용할 수 있다.

```cpp
// len : 플레이 리스트의 길이
// songs : 사용한 곡의 수

int newSongs = (n - songs + 1);
dp[len][songs] = dp[i - 1][songs - 1] * (n - songs + 1);

// 중복이 가능한 경우
if (songs > k) {
  int reuseSongs = songs - k;
  dp[len][songs] += dp[len - 1][songs] * reuseSongs;
  dp[len][songs] %= MOD;
}
```

이를 이용해 len과 songs에 대한 dp식을 채워나간다.

```cpp
const int MOD = 1e9 + 7;

int numMusicPlaylists(int n, int goal, int k) {
  long long dp[101][101] = {
      0,
  };

  dp[0][0] = 1;

  for (int len = 1; len <= goal; len++) {
    for (int songs = 1; songs <= min(len, n); songs++) {
      // The i-th song is a new song
      dp[len][songs] =
          dp[len - 1][songs - 1] * (n - songs + 1) % MOD;

      // The i-th song is a song we have played before
      if (songs > k) {
        dp[len][songs] += dp[len - 1][songs] * (songs - k);
        dp[len][songs] %= MOD;
      }
    }
  }

  return dp[goal][n];
}
```

## 고생한 점
