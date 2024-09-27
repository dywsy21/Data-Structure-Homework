#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 100;
char a[maxn];
int ne[maxn];
int lena, lenb;
void getnext()
{
    int j = 0, k = -1;
    ne[0] = -1;
    while (j < lena)
    {
        if (k == -1 || a[j] == a[k])
        {
            j++;
            k++;
            ne[j] = k;
        }
        else
        {
            k = ne[k];
        }
        #ifdef DEBUG
        cout << "j: " << j << ", k: " << k << endl;
        #endif
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%s", a);
        #ifdef DEBUG
        cout << "String a: " << a << endl;
        #endif
        lena = strlen(a);
        getnext();
        int ans = 0;
        int m = lena - ne[lena]; // 循环节
        #ifdef DEBUG
        cout << "lena: " << lena << ", m: " << m << ", ne[lena]: " << ne[lena] << endl;
        #endif
        if (lena % m == 0 && lena / m >= 2)
        { // 至少右一个循环节
            cout << 0 << endl;
        }
        else
        {
            cout << m - lena % m << endl;
        }
    }
}
