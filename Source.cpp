// 04/25/2017

#include <iostream>
#include <conio.h>
#include "CQUEUE.h"
using namespace std;


int main()
{
	int choice, item;
	char ch, it;
	cout << "\n**************IMPLEMENTATION OF QUEUE ADT USING EXTENDABLE ARRAY IN CIRCULAR FASHION BY************\nTEAM NAME:ALL STAR TEAM\n";
	Circular_Queue<int> cqi;
	
	QueueEmptyException empty;
	QueueFullException full;

	//----------------------------------Interger Queue---------------------------------
	try {

		cout << "\nPress I to input integer values into the queue\nPress C to input character values into the queue\n";
		cout << "Please note that the characters are case sensitive\n";
		cout << "        \n";
		cin >> ch;
		if (ch == 'I')
		{
			while (1)
			{

				cout << "Please make your choice below:\n1. Insert item\n";
				cout << "2. Delete item\n3. Display items\n4. Front\n5. Size of items\n6. Exit\n";
				cout << "Enter your choice : ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Insert your value into the queue: ";
					cin >> item;
					cqi.enqueue(item);
					break;
				case 2:
					cqi.dequeue();
					break;
				case 3:
					cqi.display();
					break;
				case 4:
					cqi.qfront();
					break;
				case 5:
					cqi.size();
					break;
				case 6:
					exit(0);
					break;
				default:
					cout << "Wrong choice\nPlease select the correct choice\n";
					cout << "  \n";
				}																								// End of switch
			}																									// End of while loop
		}


		//------------------------------CHARACTER QUEUE---------------------------------------------
		else if (ch == 'C') {
			Circular_Queue<char> cqc;
			while (1)
			{
				cout << "Please make your choice below:\n1. Insert item\n";
				cout << "2. Delete item\n3. Display items\n4. Front\n5. Size of items\n6. Exit\n";
				cout << "Enter your choice : ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Input the element for insertion in queue : ";
					cin >> it;
					cqc.enqueue(it);
					break;
				case 2:
					cqc.dequeue();
					break;
				case 3:
					cqc.display();
					break;
				case 4:
					cqc.qfront();
					break;
				case 5:
					cqc.size();
					break;
				case 6:
					exit(0);
					break;
				default:
					cout << "Wrong choice\nPlease select the correct choice\n";
					cout << "  \n";
				}                                                                        // End of switch

			}																			// End of while loop
		}																				
		else
			cout << "please select the correct option";									// End of cascade if statement
	}																					// End of Try Block

	catch (QueueEmptyException) {
		empty.getMessage();
	}
	catch (QueueFullException) {
		full.getMessage();
	}


	system("pause");
	return 0;
}