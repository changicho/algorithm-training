#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void solution() {
  int N, M;
  string query;
  map<string, string> pokemonByIndex;
  map<string, string> indexByPokemon;

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> query;

    string index = to_string(i);

    pokemonByIndex.insert(pair<string, string>{index, query});
    indexByPokemon.insert(pair<string, string>{query, index});
  }

  for (int i = 0; i < M; i++) {
    cin >> query;

    if (indexByPokemon.find(query) != indexByPokemon.end()) {
      cout << indexByPokemon.find(query)->second << "\n";
    } else {
      cout << pokemonByIndex.find(query)->second << "\n";
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}