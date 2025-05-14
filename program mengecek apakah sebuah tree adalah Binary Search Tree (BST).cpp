#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->kiri = node->kanan = nullptr;
    return node;
}

bool cekBSTRekursif(Node* node, int minVal, int maxVal) {
    if (node == nullptr)
        return true;

    if (node->data <= minVal || node->data >= maxVal)
        return false;

    return cekBSTRekursif(node->kiri, minVal, node->data) && cekBSTRekursif(node->kanan, node->data, maxVal);
}

bool apaBST(Node* root) {
    return cekBSTRekursif(root, -1000000, 1000000);
}

int main() {
    /*       20
          /       \
         10       30
        /  \     /  \
       5    15  25   35
                /
               22
    */

    Node* root = newNode(20);
    root->kiri = newNode(10);
    root->kanan = newNode(30);
    root->kiri->kiri = newNode(5);
    root->kiri->kanan = newNode(15);
    root->kanan->kiri = newNode(25);
    root->kanan->kanan = newNode(35);
    root->kanan->kiri->kiri = newNode(22);

    if (apaBST(root))
        cout << "Tree merupakan BST (Binary Search Tree), karena semua node kiri < parent/root dan semua node kanan > parent/root.\n";
    else
        cout << "Tree bukan BST (Binary Search Tree), karena tidak memenuhi kriteria BST\n";

    return 0;
}
