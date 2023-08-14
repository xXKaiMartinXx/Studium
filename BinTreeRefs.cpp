#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left = NULL;
    Node *right = NULL;
};

class BinTreeRefs  {
private:
    Node *root = NULL;
    void insertNode( Node *root, int keyValue);
    void inorder( Node *root);
    Node *find( Node *root, int key);

    Node *findInOrderPredecessor(Node *root);
    Node *findParent(Node *child, Node *root);
    int istBlatt(Node *root);
    int inTree(Node *root, int key);

public:
    void insert( int key );
    void inorder();

    void remove(int key);
};





Node *BinTreeRefs::find(Node *root, int key) {
    if( root->key == key) {
        return root;
    } else {
        if( root->key < key) {
            return find( root->right, key);
        } else {
            return find( root->left, key);
        }
    }
}

void BinTreeRefs::insertNode( Node *root, int keyValue ) {
    if( root->key >= keyValue ) {
        if( root->left == NULL ) {
            Node* newNode = new Node;
            newNode->key = keyValue;
            root->left = newNode;
        } else {
            insertNode( root->left, keyValue );
        }
    } else {
        if( root->right == NULL ) {
            Node* newNode = new Node;
            newNode->key = keyValue;
            root->right = newNode;
        } else {
            insertNode(root->right, keyValue);
        }
    }
}

void BinTreeRefs::inorder( Node *root) {
    if( root->left != NULL ) {
        inorder(root->left);
    }
    cout << root->key << ",";
    if( root->right != NULL ) {
        inorder(root->right);
    }
}

void BinTreeRefs::insert(int key) {
    if( root == NULL ) {
        root = new Node;
        root->key = key;
    } else {
        insertNode(root, key);
    }
}

void BinTreeRefs::inorder() {
    inorder(root);
}





//schaut ob node ein Blatt ist
int BinTreeRefs::istBlatt(Node *root)
{
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return 0;
}


//sucht key im Baum (vorhanden = 1 | nicht = 0)
int BinTreeRefs::inTree(Node *root, int key)
{
    if(root->key == key)
        return 1;
    else if(!istBlatt(root))
    {
        if(root->key < key)
            return inTree( root->right, key);
        else
            return inTree( root->left, key);
    }
    else
        return 0;
}

//sucht groesste node im linken Teilbaum von root
Node *BinTreeRefs::findInOrderPredecessor(Node *root)
{
    Node* temp = NULL;
    if(root->left != NULL)
    {
        temp = root->left;
        while(temp->right)
            temp = temp->right;
    }
    return temp;
}

//find-funktion - setzt root auf parent von node mit key
Node *BinTreeRefs::findParent(Node *child, Node *root)
{
    if(root->left == child || root->right == child)
        return root;
    else
    {
        if(root->key < child->key)
            return findParent(child, root->right);
        else
            return findParent(child, root->left);
    }
}

//entfernt eine node mit gegebenen key aus dem baum
void BinTreeRefs::remove(int key)
{
    Node* child = new Node;
    Node* temproot = root;

    // Existiert der key im Baum
    if(temproot->key == key || !inTree(temproot, key))
        return;

    child = find(temproot, key);

    temproot = findParent(child, temproot);

    //fall 1
    if(istBlatt(child))
    {
        if(temproot->left == child)
            temproot->left = NULL;
        else
            temproot->right = NULL;
    }

    //fall 2
    else if(child->left != NULL && child->right == NULL)
    {
        if(temproot->left == child)
            temproot->left = child->left;
        else
            temproot->right = child->left;
    }

    //fall 3
    else if(child->right != NULL && child->left == NULL)
    {
        if(temproot->left == child)
            temproot->left = child->right;
        else
            temproot->right = child->right;
    }

    //fall 4
    else if(child->right != NULL && child->left != NULL)
    {
        Node* temp = new Node;
        temp = findInOrderPredecessor(child);
        int tempKey = temp->key;
        remove(temp->key);
        child->key = tempKey;
    }
}

int main() {
    BinTreeRefs tree;

    tree.insert(5);
    tree.insert(15);
    tree.insert(7);
    tree.insert(20);
    tree.insert(70);
    tree.insert(50);
    tree.insert(30);

    tree.inorder();

    cout << endl;

    tree.remove(70);
    tree.remove(20);
    tree.remove(30);

    tree.inorder();

    cout << endl << 5*2.0 << endl;
    return 0;
}
