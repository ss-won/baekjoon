#include <iostream>
#include <string>
#include <vector>
using namespace std;
string S;

vector<int> getFailure()
{
    int n = (int)S.length(), j = 0;
    vector<int> failure(n, 0);
    for (int i = 1; i < n; i++)
    {
        while (j > 0 && S[i] != S[j])
            j = failure[j - 1];
        if (S[i] == S[j])
            failure[i] = ++j;
    }
    return failure;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> failure;
    getline(cin, S, '\n');
    while (S != ".")
    {
        if (S.length() == 0)
            break;
        failure = getFailure();

        if (failure[S.length() - 1] == 0 || S.length() % (S.length() - failure[S.length() - 1]) == 1)
            cout << 1 << "\n";
        else
            cout << S.length() / (S.length() - failure[S.length() - 1]) << "\n";
        getline(cin, S, '\n');
    }
    return 0;
}