#include "BST.h"
#include "BTrees.h"
#include "LLRBs.h"
#include "RLRBs.h"

void testBST() {
    BST<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << "BST In-Order Traversal: " << bst.inOrderTraversal() << std::endl;
    std::cout << "BST Pre-Order Traversal: " << bst.preOrderTraversal() << std::endl;
    std::cout << "BST Post-Order Traversal: " << bst.postOrderTraversal() << std::endl;
}

void testBTree() {
    BTree<int> btree(3);
    btree.insert(5);
    btree.insert(3);
    btree.insert(7);
    btree.insert(2);
    btree.insert(4);
    btree.insert(6);
    btree.insert(8);

    std::cout << "BTree In-Order Traversal: " << btree.inOrderTraversal() << std::endl;
    std::cout << "BTree Pre-Order Traversal: " << btree.preOrderTraversal() << std::endl;
    std::cout << "BTree Post-Order Traversal: " << btree.postOrderTraversal() << std::endl;
}

void testLLRB() {
    LLRB<int> llrb;
    llrb.insert(5);
    llrb.insert(3);
    llrb.insert(7);
    llrb.insert(2);
    llrb.insert(4);
    llrb.insert(6);
    llrb.insert(8);

    std::cout << "LLRB In-Order Traversal: " << llrb.inOrderTraversal() << std::endl;
    std::cout << "LLRB Pre-Order Traversal: " << llrb.preOrderTraversal() << std::endl;
    std::cout << "LLRB Post-Order Traversal: " << llrb.postOrderTraversal() << std::endl;
}

void testRLRB() {
    RLRB<int> rlrb;
    rlrb.insert(5);
    rlrb.insert(3);
    rlrb.insert(7);
    rlrb.insert(2);
    rlrb.insert(4);
    rlrb.insert(6);
    rlrb.insert(8);

    std::cout << "RLRB In-Order Traversal: " << rlrb.inOrderTraversal() << std::endl;
    std::cout << "RLRB Pre-Order Traversal: " << rlrb.preOrderTraversal() << std::endl;
    std::cout << "RLRB Post-Order Traversal: " << rlrb.postOrderTraversal() << std::endl;
}

int main() {
    testBST();
    testBTree();
    testLLRB();
    testRLRB();
    return 0;
}
