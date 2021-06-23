#include "Tree/Tree.h"

Tree::Tree() {}

TreeNode * Tree::getRoot() {
  return root;
}

void Tree::printTree() {
  string result = this->printTreeAux(this->root, 2);
  cout << result << "\n";
}

string Tree::printTreeAux(TreeNode * root, int spaces) {
  string result = "";
  result += this->nodeToString(root, spaces) + "\n";
  TreeNode * child = root->child;
  while(child != NULL) {
    result += this->printTreeAux(child, spaces + 4);
    child = child->next;
  }
  return result;
} 

void Tree::orderTransversal() {
  this->orderTransversalAux(this->root);
}

void Tree::orderTransversalAux(TreeNode * root) {
  TreeNode * child = root->child;
  while(child != NULL) {
    this->orderTransversalAux(child);
    child = child->next;
  }
  this->printNode(root);
}

void Tree::preorderTransversal() {
  this->preorderTransversalAux(this->root);
}

void Tree::preorderTransversalAux(TreeNode * root) {
  this->printNode(root);
  TreeNode * child = root->child;
  while(child != NULL) {
    this->preorderTransversalAux(child);
    child = child->next;
  }
}

int Tree::minHeight() {
  return this->minHeightAux(this->root, 1);
}

int Tree::minHeightAux(TreeNode * root, int height) {
  if(root->child == NULL) {
    return height;
  }
  else {
    int minHeight = -1;
    TreeNode * child = root->child;
    while(child != NULL) {
      int newHeight = minHeightAux(child, height + 1);
      if(minHeight == -1) {
        minHeight = newHeight;
      }
      else if(newHeight < minHeight){
        minHeight = newHeight;
      }
      child = child->next;
    }
    return minHeight;
  }
}

int Tree::maxHeight() {
  return this->maxHeightAux(this->root, 1);
}

int Tree::maxHeightAux(TreeNode * root, int height) {
  if(root->child == NULL) {
    return height;
  }
  else {
    int maxHeight = height;
    TreeNode * child = root->child;
    while(child != NULL) {
      int newHeight = maxHeightAux(child, height + 1);
      if(newHeight > maxHeight) {
        maxHeight = newHeight;
      }
      child = child->next;
    }
    return maxHeight;
  }
}

void Tree::onlyOneLeafNode() {
  this->onlyOneLeafNodeAux(this->root);
}

void Tree::onlyOneLeafNodeAux(TreeNode * root) {
  if(root->child != NULL) {
    if(root->child->next == NULL) {
      this->printNode(root);
    }
    TreeNode * child = root->child;
    while(child != NULL) {
      onlyOneLeafNodeAux(child);
      child = child->next;
    }
  }
}

int Tree::maxLeafsNodes() {
  return maxLeafsNodesAux(root);
}

int Tree::maxLeafsNodesAux(TreeNode * root) {
  if(root->child == NULL) {
    return 0;
  }
  else {
    int totalChilds = 0;
    int maxChilds = 0;
    TreeNode * child = root->child;
    while(child != NULL) {
      int childs = maxLeafsNodesAux(child);
      if(childs > maxChilds) {
        maxChilds = childs;
      }
      totalChilds++;
      child = child->next;
    }
    return maxChilds > totalChilds ? maxChilds : totalChilds;
  }
}

int Tree::totalLeafNodes() {
  return this->totalLeafNodesAux(this->root);
}

int Tree::totalLeafNodesAux(TreeNode * root) {
  if(root->child == NULL) {
    return 1;
  }
  else {
    int leafs = 0;
    TreeNode * child = root->child;
    while(child != NULL) {
      leafs += totalLeafNodesAux(child);
      child = child->next;
    }
    return leafs;
  }
}

bool Tree::deleteNode(int id) {
  if(root->id == id) {
    this->root = NULL;
    return true;
  }
  else {
    return deleteNodeAux(id, this->root);
  }
}

bool Tree::deleteNodeAux(int id, TreeNode * root) {
  TreeNode * child = root->child;
  if(child != NULL) {
    TreeNode * temp = child;
    while(temp != NULL) {
      bool res = deleteNodeAux(id, temp);
      if(res) {
        return res;
      }
      temp = temp->next;
    }
    if(child->id == id && child->value >= 0) {
      root->child = child->next;
      return true;
    }
    else {
       while(child->next != NULL) {
         if(child->next->id == id && child->next->value >= 0) {
           child->next = child->next->next;
           return true;
         }
         else {
           child = child->next;
         }
       }
    }
  }
  return false;
}

bool Tree::addNode(int id, string label, string product, int value) {
  TreeNode * newNode = new TreeNode;
  newNode->id = this->actualID;
  newNode->label = label;
  newNode->value = value;
  newNode->product = product;
  bool res = this->addNodeAux(id, this->root, newNode);
  this->actualID++;
  return res;
}

bool Tree::addNode(int id, string product, int value) {
  TreeNode * newNode = new TreeNode;
  newNode->id = this->actualID;
  newNode->value = value;
  newNode->product = product;
  bool res = this->addNodeAux(id, this->root, newNode);
  this->actualID++;
  return res;
}

bool Tree::addNode(int id, string label, string product) {
  TreeNode * newNode = new TreeNode;
  newNode->id = this->actualID;
  newNode->label = label;
  newNode->product = product;
  bool res = this->addNodeAux(id, this->root, newNode);
  this->actualID++;
  return res;
}

bool Tree::addNodeAux(int id, TreeNode * root, TreeNode * newNode) {
  if(root->id == id) {
    TreeNode * child = root->child;
    if(child == NULL) {
      root->child = newNode;
    }
    else {
      while(child->next != NULL) {
        child = child->next;
      }
      child->next = newNode;
    }
    return true;
  }
  else {
    TreeNode * child = root->child;
    while(child != NULL) {
      bool res = addNodeAux(id, child, newNode);
      if(res) {
        return res;
      }
      child = child->next;
    }
  }
  return false;
}

string Tree::convertTree() {
  json jsonRoot = convertNode(this->root);
  return jsonRoot.dump(2);
}

json Tree::convertNode(TreeNode * node) {
  json json;
  json["label"] = node->label;
  json["product"] = node->product;
  json["value"] = node->value;
  auto childs = json::array();
  TreeNode* temp = node->child;
  while(temp != NULL) {
    childs.push_back(convertNode(temp));
    temp = temp->next;
  }
  json["childs"] = childs;
  return json;
}

void Tree::createTree(string text) {
  json json = json::parse(text);
  this->root = createNodeFromJson(json);
}

TreeNode * Tree::createNodeFromJson(json json) {
  TreeNode* node = new TreeNode;
  node->id = this->actualID;
  this->actualID++;
  node->label = json["label"];
  node->product = json["product"];
  node->value = json["value"];
  node->child = iterateChilds(json["childs"]);
  return node;
}

TreeNode * Tree::iterateChilds(json json) { 
  if(json.size() > 0) {
    TreeNode * firstChild = new TreeNode;
    TreeNode * temp = NULL;
    for (auto& it: json) {
      TreeNode * newNode = createNodeFromJson(it);
      if(temp == NULL) {
        temp = newNode;
        firstChild = newNode;
      }
      else {
        temp->next = newNode;
        temp = temp->next;
      }
    }
    return firstChild;
  }
  return NULL;
}

void Tree::printNode(TreeNode * node) {
  cout << "Informacion del Nodo: " << node->id << "\n";
  cout << "Pregunta: " << node->label << "\n";
  cout << "Producto: " << node->product << "\n";
  cout << "Precio: " << node->value << "\n";
}

string Tree::nodeToString(TreeNode * node, int spaces) {
  string resultado = "";
  for(int i = 0; i < spaces; i++) {
    resultado += "-";
  }
  resultado += ">";
  resultado += " Nodo: " + to_string(node->id) + " | Pregunta: " + node->label + " | Producto: " + node->product + " | Valor: " + to_string(node->value);
  return resultado;
}