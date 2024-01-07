#include <iostream>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	int data;

	Node(int data) {
		left = right = nullptr;
		this->data = data;
	}
};

class BST {
private:
	Node* root;

	Node* insert(Node* root, int data) {
		if (root == nullptr) {
			Node* node = new Node(data);
			return node;
		}
		if (root->data > data) {
			root->left = insert(root->left, data);
		}
		else {
			root->right = insert(root->right, data);
		}
		return root;
	}
	void preOrder(Node* root) {
		if (root == nullptr)
			return;
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
	Node* findMin(Node* root) {
		if (root == nullptr)
			return root;
		Node* curr = root;

		while (curr->left != nullptr)
			curr = curr->left;
		return curr;
	}
	Node* deleteNode(Node* root, int data) {
		if (root == nullptr)
			return root;

		else if (root->data > data)
			root->left = deleteNode(root->left, data);

		else if (root->data < data)
			root->right = deleteNode(root->right, data);

		else {
			if (root->left == nullptr && root->right == nullptr) {
				delete root;
				root = nullptr;
			}
			else if (root->left == nullptr && root->right != nullptr) {
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->left != nullptr && root->right == nullptr) {
				Node* temp = root;
				root = root->left;
				delete temp;
			}
			else {
				Node* temp = findMin(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		return root;
	}
public:
	BST() {
		root = nullptr;
	}
	void insert(int data) {
		root = insert(root, data);
	}
	void preOrder() {
		preOrder(root);
	}
	void deleteNode(int data) {
		root = deleteNode(root, data);
	}
};

int main() {
	BST bst;

	bst.insert(12);
	bst.insert(5);
	bst.insert(15);
	bst.insert(3);
	bst.insert(7);
	bst.insert(13);
	bst.insert(17);
	bst.insert(1);
	bst.insert(9);

	bst.preOrder();
	cout << endl;

	bst.deleteNode(3);

	bst.preOrder();
	cout << endl;

	return 0;
}
