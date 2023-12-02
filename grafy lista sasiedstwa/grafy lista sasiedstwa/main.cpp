#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

struct slistEl
{
  slistEl *next;
  int data;
};

int main()
{
    int i, j, vs, ve, n, m;
    slistEl **A;
    slistEl *p;

    setlocale(LC_CTYPE, "Polish");

    // Dane zaszyte w kodzie
    int K[7][2] = {{0, 1}, {1, 2}, {2, 1}, {2, 3}, {4, 0}, {4, 1}, {4, 3}};
    n = 5; // Liczba wierzchołków
    m = sizeof(K) / sizeof(K[0]);
    
    for (i=0; i<7; i++) {
        cout << "Podaj liczbe wierzcholkow i liczbe sasiaow:" << endl;
        for (j=0; j<2; j++) {
            cout<<K[i][j]<<endl;
        }
    }
    cout << "Podaj liczbe wierzcholkow i liczbe sasiaow:" << endl;

    A = new slistEl *[n];

    for (i = 0; i < n; i++)
        A[i] = NULL;

    for (i = 0; i < m; i++)
    {
        vs = K[i][0];
        ve = K[i][1];

        p = new slistEl;
        p->data = ve;
        p->next = A[vs];
        A[vs] = p;
    }

    for (i = 0; i < n; i++)
    {
        cout << "Sąsiedzi " << i << ": ";
        p = A[i];
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    
    int *outDegree = new int[n]();
    int *inDegree = new int[n]();

    for (i = 0; i < n; i++)
    {
        p = A[i];
        while (p != NULL)
        {
            outDegree[i]++;
            inDegree[p->data]++;
            p = p->next;
        }
    }

    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Stopień wychodzący wierzchołka " << i << ": " << outDegree[i] << endl;
        cout << "Stopień wchodzący wierzchołka " << i << ": " << inDegree[i] << endl;
        
        cout<<endl;
    }

    delete[] A;

    return 0;
}
