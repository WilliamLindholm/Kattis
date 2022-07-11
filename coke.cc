#include <iostream>

using namespace std;

int main() {
  int N, C, n1, n5, n10, i;
  cin >> N;
  while (--N >= 0) {
    cin >> C >> n1 >> n5 >> n10;
    int result = 0;
    
    for (i = C; i > 0; i--) {

      if (n10 > 0) {
        //cout << "- 10x1" << endl;
        result++;
        n10--;
        n1 += 2;
      }
      else if (n5 > i || (n5 > 1 && n1 < 3)) {
        //cout << "- 5x2" << endl;
        result += 2;
        n5 -= 2;
        n1 += 2;
      }
      else if (n5 > 0) {
        //cout << "- 5x1" << endl;
        result += 4;
        n5--;
        n1 -= 3;
      }
      else {
        //cout << "- 8x1" << endl;
        result += 8;
        n1 -= 8;
      }
    }

    cout << result << endl;
  }
  return 0;
}
