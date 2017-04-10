// Ex0502.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

//initializes a container
void Initialize(const string* container[], int capacity);

//tests filled status of a container
bool isFull(const string* const container[], int capacity);

//tests empty status of a container
bool isEmpty(const string* const container[], int capacity);

//tests if an item is in a container
bool Contains(const string* const pItem,
	const string* container[], int capacity);

//displays the items in a container
void Display(const string* const container[], int capacity);

//adds an item to a container
void Add(const string* const pItem,
	const string* container[], int capacity);

//removes an item from a container
void Remove(const string* const pItem,
	const string* container[], int capacity);

int main()
{
	cout << "\tWelcome to Inventory!" << endl;

	//items
	const int NUM_ITEMS = 5;
	const string items[NUM_ITEMS] = { "sword",
		"axe",
		"shield",
		"gold",
		"potion" };

	//inventory
	const int INVENTORY_CAPACITY = 3;
	const string* inventory[INVENTORY_CAPACITY];
	Initialize(inventory, INVENTORY_CAPACITY);

	int choice;         //menu choice
	int itemNumber;     //number of item to add or remove

	do
	{
		cout << endl << "Inventory" << endl;
		cout << "---------" << endl << endl;
		cout << "0 - Quit" << endl;
		cout << "1 - Display items in the inventory";
		cout << endl;
		cout << "2 - Add an item to the inventory";
		cout << endl;
		cout << "3 - Remove an item from the inventory";
		cout << endl;
		cout << endl << "Choice: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 0:
			cout << "Good-bye." << endl;
			break;
		case 1:
			cout << "Inventory:" << endl;
			Display(inventory, INVENTORY_CAPACITY);
			break;
		case 2:
			for (int i = 0; i<NUM_ITEMS; ++i)
			{
				cout << i << " - " << items[i] << endl;
			}

			do
			{
				cout << "Enter the number of the item to add: ";
				cin >> itemNumber;
			} while (itemNumber < 0 || itemNumber >= NUM_ITEMS);

			//pass address of element items[itemNumber]
			Add(&items[itemNumber],
				inventory,
				INVENTORY_CAPACITY);
			break;
		case 3:
			for (int i = 0; i<NUM_ITEMS; ++i)
			{
				cout << i << " - " << items[i] << endl;
			}

			do
			{
				cout << "Enter the number of the item to remove: ";
				cin >> itemNumber;
			} while (itemNumber < 0 || itemNumber >= NUM_ITEMS);

			//pass address of element items[itemNumber]
			Remove(&items[itemNumber], inventory, INVENTORY_CAPACITY);
			break;
		default:
			cout << "Sorry, " << choice;
			cout << " isn't a valid choice." << endl;
		}
	} while (choice != 0);

	return 0;
}

void Initialize(const string* container[], int capacity)
{
	//set all elements to NULL
	for (int i = 0; i<capacity; ++i)
	{
		//	TODO: add code
#pragma message ("Add code, location 1.")

	}
}

bool isFull(const string* const container[], int capacity)
{
	bool full = true;
	int i = 0;

	while (full && i<capacity)
	{
		//if there's at least one empty slot...

		//	TODO: add code
#pragma message ("Add code, location 2.")

		++i;
	}

	return full;
}

bool isEmpty(const string* const container[],
	int capacity)
{
	bool empty = true;
	int i = 0;

	while (empty && i<capacity)
	{
		//if a slot isn't empty

		//	TODO: add code

		++i;
	}

	return empty;
}

bool Contains(const string* const pItem,
	const string* container[], int capacity)
{
	bool has = false;
	int i = 0;

	while (!has && i<capacity)
	{
		//	TODO: add code
#pragma message ("Add code, location 3.")

		++i;
	}

	return has;
}

void Display(const string* const container[],
	int capacity)
{
	//if container is empty, display message saying so and return
	if (isEmpty(container, capacity))
	{
		//	TODO: add code
#pragma message ("Add code, location 4.")

	}

	//otherwise, send all strings pointed to by elements of container to cout
	for (int i = 0; i<capacity; ++i)
	{
		//	TODO: add code
#pragma message ("Add code, location 5.")

	}
}

void Add(const string* const pItem,
	const string* container[], int capacity)
{
	if (pItem == NULL)
	{
		//	TODO: add code
#pragma message ("Add code, location 6.")

	}

	if (Contains(pItem, container, capacity))
	{
		//	TODO: add code
#pragma message ("Add code, location 7.")

	}

	if (isFull(container, capacity))
	{
		//	TODO: add code
#pragma message ("Add code, location 8.")

	}

	//find first null pointer in container, point it to string pItem points to
	bool found = false;
	int i = 0;

	while (!found && i<capacity)
	{
		//	TODO: add code
#pragma message ("Add code, location 9.")

		++i;
	}

}

void Remove(const string* const pItem,
	const string* container[], int capacity)
{
	if (pItem == NULL)
	{
		//	TODO: add code
#pragma message ("Add code, location 10.")

	}

	//set element that is equal to pItem to NULL
	bool found = false;
	int i = 0;

	while (!found && i<capacity)
	{
		//	TODO: add code
#pragma message ("Add code, location 11.")

		++i;
	}

	//if item wasn't found, say so
	if (!found)
	{
		//	TODO: add code
#pragma message ("Add code, location 12.")

	}

}
