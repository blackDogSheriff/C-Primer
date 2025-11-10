#include <iostream>
class TreeNode
{
  private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};

class BinStrTree
{
  public:
    BinStrTree(const BinStrTree &bst) : root(bst.root)
    {
        root->CopyTree();
    }

  private:
    TreeNode *root;
};
using namespace std;
int main(void)
{
    return 0;
}
