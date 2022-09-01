#include <fstream>
#include <NTL/LLL.h>

using namespace std;
using namespace NTL;

int main () {
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    out << "LLL algorithm (NTL)\n\n";
    long m, n;
    in >> m >> n;
    mat_ZZ X;
    X.SetDims(m, n);
    out << "A matrix " << m << "x" << n << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            in >> X(i, j);
    }
    out << "Input matrix:\n" << X << endl;
    ZZ det(1);
    LLL(det, X);
    out << "\nReduced matrix:\n" << X << endl;
    in.close();
    out.close();
}
