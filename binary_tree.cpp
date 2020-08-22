#include <iostream>
#include <queue>
#include <vector>
#include <string>

struct Node {
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data) { 
        this->data = data;
    }
};

class BinaryTree {
    Node* root;

    void print(const std::vector<int> &output){
        std::string result = "";
        for (int x = 0; x < output.size(); x++){
            if (x == 0){
                result += std::to_string(output[x]);
            }
            else {
                result += ' ' + std::to_string(output[x]);
            }
        }
        std::cout << result << std::endl;
    }

    void printInOrderTraversal(Node* currNode, std::vector<int> &result){
        if (currNode){
            printInOrderTraversal(currNode->left, result);
            result.push_back(currNode->data);
            printInOrderTraversal(currNode->right, result);
        }
    }

    void printPreOrderTraversal(Node* currNode, std::vector<int> &result){
        if (currNode){
            result.push_back(currNode->data);
            printPreOrderTraversal(currNode->left, result);
            printPreOrderTraversal(currNode->right, result);
        }
    }

     void printPostOrderTraversal(Node* currNode, std::vector<int> &result){
        if (currNode){
            printPostOrderTraversal(currNode->left, result);
            printPostOrderTraversal(currNode->right, result);
            result.push_back(currNode->data);
        }
    }

    public:
        BinaryTree(int data){
            root = new Node(data);
        }

        void insertNode(int data){
            std::queue<Node*> nodes;
            nodes.push(root);

            while (!nodes.empty()){
                Node* currNode = nodes.front(); 
                nodes.pop();

                if (currNode->left){
                    nodes.push(currNode->left);
                }
                else {
                    currNode->left = new Node(data);
                    break;
                }

                if (currNode->right){
                    nodes.push(currNode->right);
                }
                else {
                    currNode->right = new Node(data);
                    break;
                }
            }
        }

        void printInOrder(){
            std::vector<int> result = {};
            printInOrderTraversal(root, result);
            print(result);
        }

        void printPreOrder(){
            std::vector<int> result = {};
            printPreOrderTraversal(root, result);
            print(result);
        }

        void printPostOrder(){
            std::vector<int> result = {};
            printPostOrderTraversal(root, result);
            print(result);
        }
};

int main(){

    BinaryTree tree(5);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(8);
    tree.insertNode(10);
    
    tree.printInOrder();
    tree.printPreOrder();
    tree.printPostOrder();

    return 0;
}