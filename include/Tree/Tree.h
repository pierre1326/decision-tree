#ifndef TREE_H
#define TREE_H

#include <nlohmann/json.hpp>

#include <iostream>
#include <streambuf>
#include <fstream>
#include <string>

using json = nlohmann::json;
using namespace std;

struct TreeNode {
  int id = -1;
  string label = "";
  string product = "";
  int value = 0;
  TreeNode *next = NULL;
  TreeNode *child = NULL;
};

class Tree {
  
  public:
    Tree();
    bool addNode(int id, string label, string product, int value);
    bool addNode(int id, string label, string product);
    bool addNode(int id, string product, int value);
    bool deleteNode(int id);
    void createTree(string json);
    string convertTree();
    int totalLeafNodes();
    int maxLeafsNodes();
    void onlyOneLeafNode();
    int minHeight();
    int maxHeight();
    void preorderTransversal();
    void orderTransversal();
    void printTree();

  private:
    TreeNode *root;
    int actualID = 0;
    
    TreeNode * createNodeFromJson(json json);
    TreeNode * iterateChilds(json json);
    json convertNode(TreeNode * node);
    bool addNodeAux(int id, TreeNode * root, TreeNode * newNode);
    bool deleteNodeAux(int id, TreeNode * root);
    void printNode(TreeNode * node);
    string nodeToString(TreeNode * node, int spaces);
    int totalLeafNodesAux(TreeNode * root);
    int maxLeafsNodesAux(TreeNode * root);
    void onlyOneLeafNodeAux(TreeNode * root);
    int minHeightAux(TreeNode * root, int height);
    int maxHeightAux(TreeNode * root, int height);
    void preorderTransversalAux(TreeNode * root);
    void orderTransversalAux(TreeNode * root);
    string printTreeAux(TreeNode * root, int spaces);

};

#endif