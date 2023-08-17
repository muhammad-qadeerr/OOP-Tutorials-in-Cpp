#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char a, char b, char c)
{
    if (n > 0)
    {
        TowerOfHanoi(n - 1, a, c, b);
        cout << "Move disk " << n << " from " << a << " to " << c << endl;
        TowerOfHanoi(n - 1, b, a, c);
    }
}
int main()
{
    int N;
    cout << "Enter the no. of disks: ";
    cin >> N;
    char A, B, C;
    TowerOfHanoi(N, 'A', 'B', 'C');
}