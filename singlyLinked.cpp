#include <iostream>

struct Node {
    int data;
    Node *next = NULL;

    Node(){
        data = 0;
    }

    Node(int data){
        this->data = data;
    }
};

class Linkedlist { 
    Node *headPtr;
    int length = 1;
    
    public:
        Linkedlist(){
            headPtr = new Node();
        }

        Linkedlist(int data){
            headPtr = new Node(data);
        }

        Node *getHeadPtr(){
            return headPtr;
        }

        void appendNode(int data){
            Node *node = headPtr;
            Node *tail = new Node(data);
            length++;

            while (node->next != NULL){
                node = node->next;
            }

            node->next = tail;
        }

        Node *findNode(int key){
            Node *node = headPtr;

            if (headPtr->data == key){
                return headPtr;
            }
       
            while (node->next != NULL){
                node = node->next;
                if (node->data == key){
                    return node;
                }
            }
            
            return NULL;
        }

        bool deleteNode(Node *nodeKey) {
            Node *node = headPtr;

            if (headPtr == nodeKey){
                 if(node->next != NULL){
                    headPtr = node->next;

                    delete nodeKey;
                    length--;
                    return true;
                }
                else {
                    return false;
                }
            }
       
            while (node->next != NULL){
                if (node->next == nodeKey){
                    Node *temp = node->next;
                    node->next = (node->next)->next;

                    delete temp;
                    length--;
                    return true;
                }
                node = node->next;
            } 
            return false;
        }

        bool insertNodeAtPos(int data, int pos){
            Node *newNode = new Node(data);
            Node *node = headPtr;
            int index = pos - 1;

            if (index > (length + 1) || index < 0){
                return false;
            }

            if (index == 0){
                newNode->next = headPtr;
                headPtr = newNode;
                length++;
                return true;
            }
            else {
                int prevNodeIndex = 0;
                while (prevNodeIndex < (index - 1)){
                    node = node->next;
                    prevNodeIndex++;
                }

                newNode->next = node->next;
                node->next = newNode;
                length++;
                return true;
            }
        }

        bool deleteNodeAtPos(int pos){
            Node *node = headPtr;
            int index = pos - 1;

            if (index >= length || length < 2 || index < 0){
                return false;
            }

            if (index == 0){
                Node *temp = headPtr;
                headPtr = headPtr->next;

                delete temp;
                length--;
                return true;
            }
            else {
                int prevNodeIndex = 0;
                while (prevNodeIndex < (index - 1)){
                    node = node->next;
                    prevNodeIndex++;
                }

                Node *temp = node->next;
                node->next = temp->next;

                delete temp;
                length--;
                return true;
            }
        }

        int getLength(){
            return length;
        }

        void printList(){
            Node *node = headPtr;
        
            std::cout << headPtr->data << std::endl;
            while (node->next != NULL){
                node = node->next;                
                std::cout << node->data << std::endl;

            }
        }
};

void deleteLinkedList(Linkedlist linkedlist){
    Node *node = linkedlist.getHeadPtr();

    while (node->next != NULL){
        node = node->next;
        delete node;
    }

   delete linkedlist.getHeadPtr();
}


int main() {
    
    Linkedlist linkedlist;
    linkedlist.appendNode(2);
    linkedlist.appendNode(3);
    linkedlist.printList();

    std::cout << std::endl;

    linkedlist.insertNodeAtPos(4,1);
    linkedlist.printList();
    // std::cout << linkedlist.getLength() << std::endl;


    std::cout << std::endl;

    linkedlist.deleteNodeAtPos(1);
    linkedlist.deleteNodeAtPos(2);
        linkedlist.deleteNodeAtPos(3);
    linkedlist.printList();

    std::cout << std::endl;
    std::cout << linkedlist.getLength() << std::endl;
    // linkedlist.deleteNodeAtPos(3);

    // std::cout << std::endl;
    // linkedlist.printList();


    // linkedlist.deleteNodeAtPos(3);
    // linkedlist.printList();



    // std::cout << linkedlist.getLength() << std::endl;

    return 0; 
}