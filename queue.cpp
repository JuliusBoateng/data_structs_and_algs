#include <iostream>

class queue {
    int HEAD = 0; 
    int TAIL = 0;
    int COUNT = 0;
    int SIZE;
    int *ARR;

    public:
        queue(){
            SIZE = 10;
            ARR = new int [SIZE];
        }
        queue(int SIZE){
            this->SIZE = SIZE;
            ARR = new int [SIZE];
        }

        void enqueue(int val){
            if (COUNT >= SIZE){
                return;
            }

            ARR[TAIL] = val;
            TAIL = (TAIL + 1) % SIZE;
            COUNT++;
        }

        int dequeue(){
            if (COUNT <= 0){
                throw "Cannot remove element fron empty queue!";
            }

            int result = ARR[HEAD];
            HEAD = (HEAD + 1) % SIZE;
            COUNT--;
            return result;
        }

        int front(){
            if (COUNT > 0){
                throw "Empty queue!";
            }

            return ARR[HEAD];
        }

        int back(){
            if (COUNT > 0){
                throw "Empty queue!";
            }
            
            return ARR[TAIL];
        }
};

int main(){ 
 
    return 0;
}