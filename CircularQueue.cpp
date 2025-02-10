#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

struct Queue{
    Node* front;
    Node* rear;
};

void initQueue(Queue* q){
    q->front = q->rear = nullptr;
}

bool isEmpty(Queue* q){
    return q->front == nullptr;
};

void enqueue(Queue* q, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if(isEmpty(q)){
        q->front = q->rear = newNode;
        q->rear->next = q->front;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
        q->rear->next = q->front;
    }

}

int dequeue(Queue* q){
    if(isEmpty(q)){
        cout << "Queue is empty"<<endl;
        return -1;
    }
    int data = q->front->data;
    if(q->front == q->rear){
        delete q->front;
        q->front = q->rear = nullptr;
    }else{
        Node* temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        delete temp;
    }
    return data;
}
void displayQueue(Queue* q){
    if(isEmpty(q)){
        cout << "Que is Empty"<<endl;
        return;
    }
    Node* temp = q->front;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp !=q->front);
    cout << endl;
    
}

int main(){
    Queue q;
    initQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
     
    displayQueue(&q);
    cout << "Dequeued: "<<dequeue(&q)<<endl;
    displayQueue(&q);

    return 0;
}