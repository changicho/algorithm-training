#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct room {
  int start, end;
};

bool compare(room a, room b) {
  if (a.end != b.end) {
    return a.end < b.end;
  }
  return a.start < b.start;
}

void solution() {
  int N;
  int count = 0;
  cin >> N;

  vector<room> rooms;

  for (int i = 0; i < N; i++) {
    room temp;
    cin >> temp.start >> temp.end;

    rooms.push_back(temp);
  }

  sort(rooms.begin(), rooms.end(), compare);

  int index = 0;
  int end = 0;

  for (int i = 0; i < N; i++) {
    if (rooms[i].start >= end) {
      end = rooms[i].end;
      count += 1;
    }
  }

  cout << count << "\n";
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}