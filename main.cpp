#include <bits/stdc++.h>
#include <chrono>
using namespace std;

long long vr[1000000], b[1000000], fr[1000000];

void BubbleSort(long long vr[],long long n)
{
    long long i,j,aux;
    long long ok;
    do
    {
        ok=1;
        for(i=0; i<n-1; i++)
            if(vr[i]>vr[i+1])
            {
                aux=vr[i];
                vr[i]=vr[i+1];
                vr[i+1]=aux;
                ok=0;
            }
    }
    while(ok==0);
}
void CountSort(long long a[],long long n)
{
    long long max1 = 0;
    for(long long i=0; i<=n-1; i++)
        if (a[i] > max1)
            max1 = a[i];
    for(long long i=0; i<=n-1; i++)
        fr[a[i]]++;
    long long idx = 0;
    for(long long i=0; i<= max1; i++)
        for (long long j=1; j<=fr[i]; j++)
            a[idx++] = i;
}
void InsertionSort(long long vr[],long long n)
{
    long long i,j,piv;
    for(j=1; j<n; j++)
    {
        piv=vr[j];
        i=j-1;
        while(i>=0 && vr[i]>piv)
        {
            vr[i+1]=vr[i];
            i--;
        }
        vr[i+1]=piv;
    }

}
void interclasare(long long vr[], long long left, long long m, long long right)
{
    long long i, j, k, l=m-left+1, r=right-m;
    long long lft[l], rgh[r];
    for(i = 0; i<l; i++)
        lft[i] = vr[left+i];
    for(j = 0; j<r; j++)
        rgh[j] = vr[m+1+j];
    i = 0;
    j = 0;
    k = left;
    while(i < l && j<r)
    {
        if(lft[i] <= rgh[j])
        {
            vr[k] = lft[i];
            i++;
        }
        else
        {
            vr[k] = rgh[j];
            j++;
        }
        k++;
    }
    while(i<l)
    {
        vr[k] = lft[i];
        i++;
        k++;
    }
    while(j<r)
    {
        vr[k] = rgh[j];
        j++;
        k++;
    }
}
void MergeSort(long long vr[], long long left, long long right)
{
    if(left < right)
    {
        long long m = left+(right-left )/2;
        MergeSort(vr, left, m);
        MergeSort(vr, m+1, right);
        interclasare(vr, left, m, right);
    }
}
int poz(long long vr[],long long lft, long long rgh)
{
    long long x = vr[rgh], i = lft, j;
    for (j = lft; j <= rgh - 1; j++)
        if (vr[j] <= x)
        {
            swap(vr[i], vr[j]);
            i++;
        }
    swap(vr[i], vr[rgh]);
    return i;
}
void QuickSort(long long vr[],long long lft, long long rgh)
{
    if (lft<rgh)
    {
        long long i=poz(vr,lft,rgh);
        QuickSort(vr,lft, i-1);
        QuickSort(vr,i+1, rgh);
    }
}
void generare ( long long n, long long nmax, long long vr[])
{
    for ( long long i = 0; i < n; i ++ )
        vr[i] = rand()%nmax;
}
void copie( long long vr[], long long n, long long b[])
{
    for ( long long i = 0; i < n; i ++)
        b[i] = vr[i];
}
void sortare( long long vr[], long long n)
{
    for ( long long i = 0; i< n - 1; i ++ )
        if ( vr[i] > vr[i +  1])
        {
            cout << "Vectorul nu e sortat" << "\n";
            return;
        }
    cout << "Vectorul e sortat"  << "\n";
}
int main()
{
    long long ntest;
    cout<<"Numar teste: ";
    cin >> ntest;
    for ( long long i = 1; i <= ntest; i ++ )
    {

        clock_t start,end;
        long long n, nmax;
        cout<<"Marime vector: ";
        cin >> n;
        cout<<"Valoare maxima: ";
        cin>>nmax;
        generare(n,nmax,vr);
        cout << "Testul "<< i << "\n" << "\n";
        if ( n <= 20000)
        {
            copie(vr, n, b);
            start = clock();
            BubbleSort(b, n);
            end = clock();
            double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            cout << "BubbleSort a sortat in  : " << fixed << time_taken << setprecision(5) << " secunde " << "\n";
            sortare(b, n);
        }
        else
            cout << "Sunt prea multe numere pentru a fi sortate cu BubbleSort" << "\n";
        cout << "\n";

        if ( n <= 20000)
        {
            copie(vr, n, b);
            start = clock();
            InsertionSort(b, n);
            end = clock();
            double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            cout << "InsertionSort a sortat in  : " << fixed << time_taken << setprecision(5) << " secunde " << "\n";
            sortare(b, n);
        }
        else
            cout << "Sunt prea multe numere pentru a fi sortate cu InsertionSort" << "\n";
        cout << "\n";

        if ( nmax <= 1000000)
        {
            copie(vr, n, b);
            start = clock();
            CountSort(b,n);
            end = clock();
            double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
            cout << "CountSort a sortat in  : " << fixed << time_taken << setprecision(5) << " secunde " << "\n";
            sortare(b, n);
        }
        else
            cout << "Sunt numere prea mari pentru a le sorta cu CountSort" << "\n";
        cout <<"\n";

        copie(vr, n, b);
        start = clock();
        QuickSort(b,0, n);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "QuickSort a sortat in  : " << fixed << time_taken << setprecision(5) << " secunde " << "\n";
        sortare(b, n);
        cout <<"\n";

        copie(vr, n, b);
        start = clock();
        MergeSort(b,0,n);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "MergeSort a sortat in  : " << fixed << time_taken << setprecision(5) << " secunde " << "\n";
        sortare(b, n);
        cout <<"\n";

        copie(vr, n, b);
        start = clock();
        sort(b,b + n);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << "Sortarea implicita a sortat in  : " << fixed << time_taken << setprecision(5) << " secunde " << "\n";
        sortare(b, n);
        cout <<"\n";

    }
    return 0;
}
