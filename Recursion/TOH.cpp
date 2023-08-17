#include <iostream>
using namespace std;

void TOH(int n, char beg, char aux, char end)
{
    if (n <= 0)
    {
        cout << "Illegal Entry!\n";
    }
    else if (n == 1)
    {
        cout << "\nMove disc from " << beg << " to " << end;
    }
    else
    {
        TOH(n - 1, beg, end, aux);
        TOH(1, beg, aux, end);
        TOH(n - 1, aux, beg, end);
    }
}
int main()
{
    int N;
    char A, B, C;
    cout << "Enter the number of disc: ";
    cin >> N;
    cout << "Tower of Hanoi of " << N << " discs is: \n\n";
    TOH(N, 'A', 'B', 'C');

    return 0;
}