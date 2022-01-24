#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <iomanip>
#include <ios>
#include <sstream>
#include <stack>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
#include <iosfwd>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <queue>
#include <set>
#include <cwchar>
#include <cwctype>
#include <complex.h>
#include <fenv.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
#include <regex>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* helper(queue<TreeNode*>& nodes) {
    if(nodes.empty()) return nullptr;
    TreeNode* root = nodes.front();
    nodes.pop();
    if(!root) return nullptr;
    root->left = helper(nodes);
    root->right = helper(nodes);
    return root;
}

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(!root) return "#";
    return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    queue<TreeNode*> nodes;
    regex ws_re(",");
    vector<string> v(sregex_token_iterator(data.begin(), data.end(), ws_re, -1), sregex_token_iterator());
    for(auto a : v) {
        TreeNode* root = nullptr;
        if(a != "#") root = new TreeNode(atoi(a.c_str()));
        nodes.push(root);
    }
    return helper(nodes);
}




int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    string s = serialize(root);
    cout << s << endl;
    TreeNode* res_root = deserialize(s);
    cout << serialize(res_root) << endl;
}
