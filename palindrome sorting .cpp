#include <bits/stdc++.h>
using namespace std;
#define sze 300


/* Utility function to reverse a string */
string reverse(string str)
{
    string rev = str;
    reverse(rev.begin(), rev.end());
    return rev;
}


void printPalin(string str)
{
    int freq[sze];
    memset(freq, 0, sze * sizeof(int));
    int l = str.length();
    for(int i=0; i < l; i++)
        freq[str[i]]++;

    string half = "";
    char c;
    for (int i = 0; i < sze; i++)
    {
        if(freq[i] % 2 == 1)
            c = i ;

        half += string(freq[i] / 2, i );
    }

    string palin;

    do
    {
        palin = half;
        if (l % 2 == 1)
            palin += c;
        palin += reverse(half);
        cout << palin <<"\n";
    }
    while (next_permutation(half.begin(), half.end()));
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string str;
    cin>>str;
    printPalin(str);
    return 0;
}
