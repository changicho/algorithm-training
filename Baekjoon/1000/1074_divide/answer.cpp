#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Axis{
  int y,x;
};

int N, R, C;
int answer;

void recusive(Axis from, Axis to, int total){
  if(from.y == to.y && from.x == to.x){
    answer = total;
    return;
  }

  int length = (to.y - from.y) / 2;
  int size = (length + 1) * (length + 1);

  if(from.x + length < C) {
    from.x += length + 1;
    total += size;
  }
  if(from.y + length < R) {
    from.y += length + 1;
    total += size * 2;
  }

  recusive(from, {from.y + length, from.x + length}, total);
}

void solution() { 
  cin >> N >> R >> C;

  int length = 1 << N;
  length -= 1;

  Axis from = {0,0};
  Axis to = {length, length};

  recusive({0,0},to, 0);

  cout << answer << "\n"; 
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}