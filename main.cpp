#include <iostream>
#include <fstream>
using namespace std;
ifstream f("preord.in");
const int NMAX = 80;
int inOrd[NMAX+1], postOrd[NMAX+1],preOrd[NMAX+1],n,k;
void divImp(int si, int fi, int sp, int fp)
{
    int r = postOrd[fp],poz ;
    cout << r << " ";
    for(int i = si; i <= fi; i++) ///cautam rad din inordine
        if(inOrd[i] == r)
        {
            poz = i;
            break;
        }
   if(si <= poz-1) divImp(si,poz-1,sp,sp+poz-si-1);
   if(poz+1 <= fi)  divImp(poz+1,fi,sp+poz-si,fp-1);
}
int main()
{
   f >> n;
   for(int i = 1; i <= n; i++)
        f >> inOrd[i];
   for(int i = 1; i <= n; i++)
        f >> postOrd[i];
   divImp(1,n,1,n);
}
