#include <iostream>
#include <map>
#include <string>
using namespace std;

#define LENGTH 32

int idx(int i) {
  return LENGTH - i - 1;
}

array<char, LENGTH> clear(array<char, LENGTH> arr) {
  int i;
  cin >> i;
  arr.at(idx(i)) = '0';
  return arr;
}

array<char, LENGTH> set(array<char, LENGTH> arr) {
  int i;
  cin >> i;
  arr.at(idx(i)) = '1';
  return arr;
}

array<char, LENGTH> ors(array<char, LENGTH> arr) {
  int i, j;
  cin >> i >> j;
  if (arr[idx(i)] == '1' || arr[idx(j)] == '1')
    arr[idx(i)] = '1';
  else if (arr[idx(i)] == '?' || arr[idx(j)] == '?')
    arr[idx(i)] = '?';
  else
    arr[idx(i)] = '0';
  return arr;
}

array<char, LENGTH> ands(array<char, LENGTH> arr) {
  int i, j;
  cin >> i >> j;
  if (arr[idx(i)] == '1' && arr[idx(j)] == '1')
    arr[idx(i)] = '1';
  else if (arr[idx(i)] == '?' || arr[idx(j) == '?'])
    arr[idx(i)] = '?';
  else
    arr[idx(i)] = '0';
  return arr;
}

void printBits(array<char, LENGTH> arr) {
  for (char c : arr) {
    cout << c;
  }
}

int main() {
  int n, i;
  map<string, int> convert {
    {"CLEAR", 0},
    {"SET", 1},
    {"OR", 2},
    {"AND", 3}
  };
  int flag = 0;
  string cmd;
  while (cin >> n) {
    if (n == 0)
      break;
    if (flag)
      cout << endl;
    flag = 1;
    array<char, LENGTH> arr;
    arr.fill('?');
    for (i = 0; i < n; i++) {
      cin >> cmd;
      switch(convert[cmd]) {
        case 0: arr = clear(arr);
                break;
        case 1: arr = set(arr);
                break;
        case 2: arr = ors(arr);
                break;
        case 3: arr = ands(arr);
                break;
      }
    }
    printBits(arr);
  }
  return 0;
}
