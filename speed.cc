#include <iostream>
using namespace std;

int main() {
  int n, i, x, y, lasty, result;
  lasty = 0;
  result = 0;

  while (cin >> n) {
    if (n == -1)
      return 0;

    for (i = 0; i < n; i++) {
      cin >> x >> y;
      result += x * (y - lasty);
      lasty = y;
    }
    cout << result << " miles" << endl;
    result = 0;
    lasty = 0;
  }
  return 0;
}
