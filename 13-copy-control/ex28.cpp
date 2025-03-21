// Given the following classes, implement a default constructor and the
// necessary copy-control members.

#include <string>

class TreeNode
{
public:
  // constructor
  TreeNode(const std::string &v = "", const int c = 1, TreeNode *l = nullptr,
           TreeNode *r = nullptr)
      : value(v), count(c), left(l), right(r)
  {
  }

  // copy constructor
  TreeNode(const TreeNode &other)
      : value(other.value), count(other.count),
        left(other.left ? new TreeNode(*other.left) : nullptr),
        right(other.right ? new TreeNode(*other.right) : nullptr)
  {
  }

  // copy assignment operator
  TreeNode &operator=(const TreeNode &other)
  {
    TreeNode *newLeft = other.left ? new TreeNode(*other.left) : nullptr;
    TreeNode *newRight = other.right ? new TreeNode(*other.right) : nullptr;

    delete left;
    delete right;

    value = other.value;
    count = other.count;
    left = newLeft;
    right = newRight;

    return *this;
  }

  // destructor
  ~TreeNode()
  {
    delete left;
    delete right;
  }

private:
  std::string value;
  int count;
  TreeNode *left;
  TreeNode *right;
};

class BinStrTree
{
public:
  // default constructor
  BinStrTree() : root(new TreeNode()) {}

  // copy constructor
  BinStrTree(const BinStrTree &other)
      : root(other.root ? new TreeNode(*other.root) : nullptr)
  {
  }

  // copy assignment operator
  BinStrTree &operator=(const BinStrTree &other)
  {
    TreeNode *newRoot = other.root ? new TreeNode(*other.root) : nullptr;
    delete root;
    root = newRoot;
    return *this;
  }

  // destructor
  ~BinStrTree() { delete root; }

private:
  TreeNode *root;
};