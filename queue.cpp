#include <iostream>
using namespace std;
//int queue[100], n = 100, front = - 1, rear = - 1;
struct Queue{
int front, rear, n;
int *queue;
//constructor
Queue(int c){
front=rear=-1;
n=c;
queue=new int[n];
};
void enqueue() {
   int val;
   if (rear == n - 1)
   cout<<"Queue Overflow/Full"<<endl;
   else {
      if (front == - 1)
      front = 0;
      cout<<"Insert the element in queue : "<<endl;
      cin>>val;
      rear++;
      queue[rear] = val;
   }
}
void dequeue() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow/Empty ";
      return ;
   }
      cout<<"Element deleted from queue is : "<< queue[front] <<endl;
      // No need of shifting left , but this is not a better implementation
      front++;
}
};