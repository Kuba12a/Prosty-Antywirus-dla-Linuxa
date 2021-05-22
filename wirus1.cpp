#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
   
    int i;
    double n, b=0, a, A[ 3];
    do{
    cout << "Podaj Tekst:"; cin >> n;
    }      
    while(n<2 || n>10);
   
    for(i=0; i < n; i++){
    cout << "Podaj tekst na pozycje" << i << " : "; cin >> a;
    A[ i]= a;
    cout << "A[" << i << "] = " << A [i] << endl;
    }
    cout << "\n\nTablica A :\n";
    for(i=0; i < n; i++){
    cout << "A[" << i << "] = " << A [i] << endl;
    b += A [i];
    }
    cout << "\nSrednia arytmetyczna wynosi: " << b/n << "\n\n";
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
