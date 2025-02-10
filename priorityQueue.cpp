#include <iostream>
#include <string>
using namespace std;

// Student structure
struct Student {
    int code;
    string name;
    int age;
    Student* next;
};

// Priority Queue structure
struct PriorityQueue {
    Student* head;
};

// Initialize priority queue
void initPriorityQueue(PriorityQueue* pq) {
    pq->head = nullptr;
}

// Check if priority queue is empty
bool isEmpty(PriorityQueue* pq) {
    return pq->head == nullptr;
}

// Enqueue operation (based on age as priority)
void enqueue(PriorityQueue* pq, int code, string name, int age) {
    Student* newStudent = new Student();
    newStudent->code = code;
    newStudent->name = name;
    newStudent->age = age;
    newStudent->next = nullptr;

    if (isEmpty(pq) || age < pq->head->age) {
        newStudent->next = pq->head;
        pq->head = newStudent;
    } else {
        Student* temp = pq->head;
        while (temp->next != nullptr && temp->next->age <= age) {
            temp = temp->next;
        }
        newStudent->next = temp->next;
        temp->next = newStudent;
    }
}

// Dequeue operation
Student* dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        cout << "Priority Queue is empty" << endl;
        return nullptr;
    }

    Student* temp = pq->head;
    pq->head = pq->head->next;
    return temp;
}

// Display priority queue
void displayPriorityQueue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        cout << "Priority Queue is empty" << endl;
        return;
    }

    Student* temp = pq->head;
    while (temp != nullptr) {
        cout << "Code: " << temp->code << ", Name: " << temp->name << ", Age: " << temp->age << endl;
        temp = temp->next;
    }
}

int main() {
    PriorityQueue pq;
    initPriorityQueue(&pq);

    enqueue(&pq, 101, "Alice", 20);
    enqueue(&pq, 102, "Bob", 22);
    enqueue(&pq, 103, "Charlie", 19);

    displayPriorityQueue(&pq);

    Student* s = dequeue(&pq);
    if (s != nullptr) {
        cout << "Dequeued: " << s->name << endl;
        delete s;
    }
    displayPriorityQueue(&pq);
     
     Student* f = dequeue(&pq);
    if (f != nullptr) {
        cout << "Dequeued: " << f->name << endl;
        delete f;
    }
    displayPriorityQueue(&pq);


    return 0;
}