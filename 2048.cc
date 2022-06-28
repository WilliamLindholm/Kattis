#include <iostream>
#include <array>
using namespace std;


int shouldMerge(int x, int y) {
  return ((x == 0 && y != 0)|| (x == y && x != 0));
}

void printState(array<array<int, 4>, 4> state) {
  for (array<int, 4> a : state) {
    for (int e : a) {
      cout << e << " ";
    }
    cout << endl;
  }
}

array<array<int, 4>, 4> moveLeft(array<array<int, 4>, 4> state) {
  int i, j, z;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      for (z = j + 1; z < 4; z++) {
        if (shouldMerge(state[i][j], state[i][z])) {
          if (state[i][j] == 0 && state[i][z] != 0) {
            state[i][j] += state[i][z];
            state[i][z] = 0;
            continue;
          }
          state[i][j] += state[i][z];
          state[i][z] = 0;
          break;
        }
        if (state[i][z] != 0) {
          break;
        }
      }
    }
  }
  return state;
}


array<array<int, 4>, 4> moveUp(array<array<int, 4>, 4> state) {
  int i, j, z;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 3; j++) {
      for (z = j + 1; z < 4; z++) {
        if (shouldMerge(state[j][i], state[z][i])) {
          if (state[j][i] == 0 && state[z][i] != 0) {
            state[j][i] += state[z][i];
            state[z][i] = 0;
            continue;
          }
          state[j][i] += state[z][i];
          state[z][i] = 0;
          break;
        }
        if (state[z][i] != 0) {
          break;
        }
      }
    }
  }
  return state;
}


array<array<int, 4>, 4>moveRight(array<array<int, 4>, 4> state) {
  int i, j, z;
  for (i = 0; i < 4; i++) {
    for (j = 3; j > 0; j--) {
      for (z = j - 1; z > -1; z--) {
        if (shouldMerge(state[i][j], state[i][z])) {
          if (state[i][j] == 0 && state[i][z] != 0) {
            state[i][j] += state[i][z];
            state[i][z] = 0;
            continue;
          }
          state[i][j] += state[i][z];
          state[i][z] = 0;
          break;
        }
        if (state[i][z] != 0) {
          break;
        } 
      }
    }
  }
  return state;
}


array<array<int, 4>, 4> moveDown(array<array<int, 4>, 4> state) {
  int i, j, z;
  for (i = 0; i < 4; i++) {
    for (j = 3; j > 0; j--) {
      for (z = j - 1; z > -1; z--) {
        if (shouldMerge(state[j][i], state[z][i])) {
          if (state[j][i] == 0 && state[z][i] != 0) {
            state[j][i] += state[z][i];
            state[z][i] = 0;
            continue;
          }
          state[j][i] += state[z][i];
          state[z][i] = 0;
          break;
        }
        if (state[z][i] != 0) {
          break;
        }
      }
    }
  }
  return state;
}


int main() {
  int i, j, move;
  array<array<int, 4>, 4> state;
  for (i = 0; i < 4; i++) {
    array<int, 4> arr;
    for (j = 0; j < 4; j++) {
       cin >> arr.at(j);
    }
    state.at(i) = arr;
  }

  cin >> move;
  switch(move) {
    case 0: state = moveLeft(state);
            break;
    case 1: state = moveUp(state);
            break;
    case 2: state = moveRight(state);
            break;
    case 3: state = moveDown(state);
            break;
  }

  printState(state);
  return 0;
}
