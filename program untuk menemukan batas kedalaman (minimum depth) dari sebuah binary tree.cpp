#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *kiri, *kanan;
    Node(int x) : val(x), kiri(nullptr), kanan(nullptr) {}
};

Node* newNode(int x) {
    return new Node(x);
}

int minDepth(Node* root) {
    if (!root) return 0;

    if (!root->kiri) return minDepth(root->kanan) + 1;
    if (!root->kanan) return minDepth(root->kiri) + 1;

    int kiriDepth = minDepth(root->kiri);
    int kananDepth = minDepth(root->kanan);

    if (kiriDepth < kananDepth) {
        return kiriDepth + 1;
    } else {
        return kananDepth + 1;
    }
}

int main() {
    /*            20
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

    cout << "Batas kedalaman (Minimum Depth): " << minDepth(root) << endl;
    return 0;
}
