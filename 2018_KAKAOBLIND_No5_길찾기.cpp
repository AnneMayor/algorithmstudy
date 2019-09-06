#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int idx;
    int x;
    int y;
};

struct Tree
{
    Node n;
    Tree *left;
    Tree *right;
};

vector<Node> nodeList;
vector<int> nodeNumList;

bool comp(const Node &n1, const Node &n2)
{

    if (n1.y == n2.y)
    {
        return n1.x < n2.x;
    }

    return n1.y > n2.y;
}

void make_Tree(Tree *root, Tree *tmp)
{
    if (root->n.x > tmp->n.x)
    {
        if (root->left == NULL)
        {
            root->left = tmp;
        }
        else
        {
            make_Tree(root->left, tmp);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            root->right = tmp;
        }
        else
        {
            make_Tree(root->right, tmp);
        }
    }
}

void preOrder(Tree *root)
{
    if (root != NULL)
    {
        nodeNumList.push_back(root->n.idx);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Tree *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        nodeNumList.push_back(root->n.idx);
    }
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    vector<vector<int>> ans;

    int len = nodeinfo.size();
    for (int i = 0; i < len; i++)
    {
        Node no;
        no.idx = i + 1;
        no.x = nodeinfo[i][0];
        no.y = nodeinfo[i][1];
        nodeList.push_back(no);
    }

    stable_sort(nodeList.begin(), nodeList.end(), comp);

    Tree *root = new Tree;
    root->n = nodeList[0];
    root->left = NULL;
    root->right = NULL;

    for (int i = 1; i < nodeList.size(); i++)
    {
        Tree *tmp = new Tree;
        tmp->n = nodeList[i];
        tmp->left = NULL;
        tmp->right = NULL;
        make_Tree(root, tmp);
    }

    nodeNumList.clear();
    preOrder(root);
    ans.push_back(nodeNumList);
    nodeNumList.clear();
    postOrder(root);
    ans.push_back(nodeNumList);

    return ans;
}