// Team Project
// Implementation of queue ADT using extendable array
// Awani Rotimi
// Coker Oluwaseun
// Paul Eze
// Charles Odunukwe
// 04/25/2017

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;


class QueueEmptyException {
public:
	QueueEmptyException() {}
	~QueueEmptyException() {}
	void getMessage()
	{
		cout << "Cannot delete, Queue is EMPTY!" << endl;
	}
};
class QueueFullException {
public:
	QueueFullException() {}
	~QueueFullException() {}
	void getMessage()
	{
		cout << "Cannot Insert, Queue is FUll!" << endl;
	}
};

//Creating a generic Queue class
template <class Obj>

class Circular_Queue
{
	int MAX;
private:
	Obj *cqueue_arr;
	int front, rear;
public:
	 Circular_Queue()																// Contructor
	{
		cqueue_arr = NULL;
		cout << "\nEnter size of the queue:";
		cin >> MAX;
		cqueue_arr = new Obj[MAX];
		rear = -1, front = -1;
	}

	~Circular_Queue() {															   // destructor
		delete[] cqueue_arr;
	}

	void qfront() {
		if (front == -1)
		{
			cout << "There are no items in the queue\n";
		}
		cout << "Front item is : " << cqueue_arr[front] << endl;
	}
	int size() {
		if (front == -1)
		{
			cout << "There are no items in the queue\n";
		}
		else 
		cout << "Size is: " << ((MAX - front + rear) % MAX + 1) << endl;
		return 0;
	}

	void resize() {
		auto newMAX = 2 * MAX;
		Obj *cqueue_arr2 = new Obj[newMAX];                             // Create a new array of two times the size of old array
		int i = 0;								                        // use this to control new array position
		int j = front;                                                  // use to control old array position
		bool rearReached = false;
		while (!rearReached) {
			rearReached = j % MAX == rear;                              // is true when we reach the rear
			cqueue_arr2[i] = cqueue_arr[j % MAX];                       // copy content from old array into new array.
			i++;
			j++;
		}
		front = 0;
		rear = MAX - 1;
		delete[] cqueue_arr;										// Delete the old array after copying itmes into the new array
		cqueue_arr = cqueue_arr2;
		MAX = newMAX;
	}

	//Insert into Circular Queue
	void enqueue(Obj item)
	{
		char response;
		if ((front == 0 && rear == MAX - 1) || (front == (rear + 1) % MAX))
		{
			//throw QueueFullException();
			cout << "\n**************Please note that CIRCULAR QUEUE is already full and items will be transferred to a bigger QUEUE************" << endl;
			cout << "Press Y. To continue \nPress N. To cancel\n";
			cout << "                                             \n";
			cout << "Enter your choice :";
			cin >> response;
			switch (response) {
			case 'Y':
				resize();                                            // Calls the resize function
				break;
			case 'N':
				exit(0);
				break;
			default:
				cout << "Make press a valid input!" << endl;
			}
			
		}
		if (front == -1)
		{
			front = 0;
			rear = 0;
		}
		else
		{
			if (rear == MAX - 1)
				rear = 0;
			else
				rear = ((rear + 1) % MAX);
		}
		cqueue_arr[rear] = item;
		cout << "Insertion Success!!!\n";

	}

	// Delete from Circular Queue
	Obj dequeue()
	{
		if (front == -1)
		{
			throw QueueEmptyException();
		} 
		cout << "Element deleted from queue is : " << cqueue_arr[front] << endl;
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			if (front == MAX - 1)
				front = 0;
			else
				front = ((front + 1) % MAX);
		}
	}

	//Display Circular Queue

	void display()
	{
		int front_pos = front, rear_pos = rear;
		if (front == -1)
		{
			cout << "Cannot display, Queue is EMPTY!\n";
			return;
		}
		cout << "Circular Queue elements are:\n";
		if (front_pos <= rear_pos)
		{
			while (front_pos <= rear_pos)
			{
				cout << cqueue_arr[front_pos] << "  ";
				front_pos++;
			}
		}
		else
		{
			while (front_pos <= MAX - 1)
			{
				cout << cqueue_arr[front_pos] << "  ";
				front_pos++;
			}
			front_pos = 0;
			while (front_pos <= rear_pos)
			{
				cout << cqueue_arr[front_pos] << "  ";
				front_pos++;
			}
		}
		cout << endl;
	}

};


#endif