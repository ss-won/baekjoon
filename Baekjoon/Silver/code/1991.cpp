#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
int n;
char p, lc, rc;
pair<int, int> tree[26];

void preorder(int root)
{
    // 노드 -> 왼쪽 -> 오른쪽
    char node = 'A' + (root - 1);
    cout << node;
    if (tree[root].first != 0)
        preorder(tree[root].first);
    if (tree[root].second != 0)
        preorder(tree[root].second);
}

void inorder(int root)
{
    // 왼쪽 -> 노드 -> 오른쪽
    char node = 'A' + (root - 1);
    if (tree[root].first != 0)
    {
        inorder(tree[root].first);
    }
    cout << node;
    if (tree[root].second != 0)
    {
        inorder(tree[root].second);
    }
}

void postorder(int root)
{
    // 왼쪽 -> 오른쪽 -> 노드
    char node = 'A' + (root - 1);
    if (tree[root].first != 0)
    {
        postorder(tree[root].first);
    }
    if (tree[root].second != 0)
    {
        postorder(tree[root].second);
    }
    cout << node;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p >> lc >> rc;
        int pi = p - 'A' + 1;
        int lci = (lc != '.') ? lc - 'A' + 1 : 0;
        int rci = (rc != '.') ? rc - 'A' + 1 : 0;
        tree[pi] = {lci, rci};
    }
    preorder(1);
    cout << "\n";
    inorder(1);
    cout << "\n";
    postorder(1);
    return 0;
}
