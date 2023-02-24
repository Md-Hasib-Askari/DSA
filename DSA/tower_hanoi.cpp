#include<bits/stdc++.h>
using namespace std;

void tower(int n, char A, char B, char C) {
    if (n == 0) return;

    tower(n-1, A, C, B);                          // A -> B
    cout << "Move " << A << " to " << C << endl;  // A -> C
    tower(n-1, B, A, C);                          // B -> C
}

int main() {
    tower(2, 'A', 'B', 'C');
}
