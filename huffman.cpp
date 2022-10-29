#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    char data;
    int freq;
    Tree *left;
    Tree *right;
    Tree(char c, int f)
    {
        data = c;
        freq = f;
        left = right = NULL;
    }
};

class Compare
{
public:
    bool operator()(Tree *a, Tree *b)
    {
        // define priority base on frequency
        return a->freq > b->freq;
    }
};

Tree *
genTree(priority_queue<Tree *, vector<Tree *>, Compare> pq)
{
    while (pq.size() > 1)
    {
        Tree *left = pq.top();
        pq.pop();
        Tree *right = pq.top();
        pq.pop();

        Tree *node = new Tree('X', left->freq + right->freq); // x means its not a leaf
        node->left = left;
        node->right = right;

        pq.push(node);
    }

    return pq.top();
}

void printCodesToResult(Tree *root, string currentStr, vector<string> &res)
{
    // visit left add '0' to string
    // visit right add '1' to string

    if (root->left)
    {
        printCodesToResult(root->left, currentStr + '0', res);
    }

    if (root->right)
    {
        printCodesToResult(root->right, currentStr + '1', res);
    }

    if (!root->left && !root->right)
    {
        // cout << root->data << " " << currentStr << endl;
        int i = root->data - '0';
        res[i] = currentStr;
    }
}

void huffmanCode(vector<char> datas, vector<int> freq)
{
    int size = datas.size();
    priority_queue<Tree *, vector<Tree *>, Compare> pq;

    for (int i = 0; i < size; i++)
    {
        Tree *node = new Tree(datas[i], freq[i]);
        pq.push(node);
    }

    Tree *root = genTree(pq);
    string curr = "";
    vector<string> res(10, "null");
    printCodesToResult(root, curr, res); // add to variable result all leaves

    // print result
    for (int i = 0; i < 10; i++)
    {
        cout << i << " " << res[i] << endl;
    }
}

void addDatas(string &str, vector<char> &data, vector<int> &freq)
{
    vector<int> dummy(10, 0); // map the data
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        int digit = str[i] - '0';
        dummy[digit]++;
    }
    for (int i = 0; i < 10; i++)
    {
        if (dummy[i] > 0)
        {
            // string s = to_string(i);
            // char d = s[0];
            char d = i + '0';
            data.push_back(d);
            freq.push_back(dummy[i]);
        }
    }
}

void solve()
{
    // solve the problem here

    // string '0' - '9'
    string str;
    cin >> str;
    // count a char and it's freq

    vector<char> datas; // fill all digit exist in input
    vector<int> fDatas; // fill all the frequncy of the digits
    addDatas(str, datas, fDatas);

    if (datas.size() == 1)
    {
        // handle only one digit exist
        vector<string> res(10, "null");
        res[datas[0] - '0'] = "0";
        // print result
        for (int i = 0; i < 10; i++)
        {
            cout << i << " " << res[i] << endl;
        }
    }
    else
    {
        huffmanCode(datas, fDatas);
    }
}

int main()
{
    solve();
    return 0;
}