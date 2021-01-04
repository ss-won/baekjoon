#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
const int MAX = 100001;
int n, root;
pair<int, int> tree[MAX]; // <left, right>
vector<int> inorder;
vector<int> postorder;

int setTree(int is, int ie, int ps, int pe)
{
    if (ps == pe - 1)
        return postorder[ps];
    int left = 0, right = 0, p = postorder[pe - 1];
    // inorder에서 parent 노드 찾기
    for (int i = is; i < ie; i++)
    {
        if (inorder[i] == p)
        {
            if (is != i)
            {
                left = setTree(is, i, ps, ps + (i - is));
            }
            if (ie - 1 != i)
            {
                right = setTree(i + 1, ie, (pe - 1) - (ie - (i + 1)), pe - 1);
            }
        }
    }
    tree[p] = {left, right};
    return p;
}

void preorder(int root)
{
    cout << root << " ";
    if (tree[root].first != 0)
        preorder(tree[root].first);
    if (tree[root].second != 0)
        preorder(tree[root].second);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        inorder.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        postorder.push_back(num);
    }

    root = postorder[n - 1];
    setTree(0, n, 0, n);
    preorder(root);
    return 0;
}
