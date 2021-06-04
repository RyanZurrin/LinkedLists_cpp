/**
 * @Program ZurrinRyanTW.java
 * @author Ryan Zurrin
 * @Description build a menu based list testing application that lets a user
 * load and unload both sorted and unsorted linked lists.
 * @Assignment Sorted & Unsorted List Loader
 * @DueBy 2/18/2021
 */
 #include "UnsortedList.h"
#include "SortedList.h"
#include <fstream>
#include <sstream>

void displayMenu();
void validatePickLoop(UnsortedList&, SortedList&);
void menuOptions(int,UnsortedList&, SortedList&);
void listLoader(UnsortedList&, SortedList&);
void displayListsContents(UnsortedList&, SortedList&);
void deleteItemFromLists(UnsortedList&, SortedList&);
void emptyUnsorted(UnsortedList&);
void emptySorted(SortedList&);
bool quit();
void run(UnsortedList&, SortedList&);
static bool endProgram = false;

int main()
{
	SortedList sl;
	UnsortedList ul;

	run(ul, sl);

	return 0;
}//end main method

/// <summary>
/// Displays the menu.
/// </summary>
void displayMenu() {
	cout << "\n/============================================\\" << endl;
	cout << "||   Unsorted and Sorted Linked List test   ||" << endl;
	cout << "||   Choose an option from the Menu below   ||" << endl;
	cout << "|| ---------------------------------------- ||" << endl;
	cout << "||      1.)  Load both List                 ||" << endl;
	cout << "||      2.)  Display Both Lists and qty's   ||" << endl;
	cout << "||      3.)  Delete Items From both lists   ||" << endl;
	cout << "||      4.)  Empty unsorted linked list     ||" << endl;
	cout << "||      5.)  Empty sorted linked list       ||" << endl;
	cout << "||      6.)  Exit program                   ||" << endl;
	cout << "\\============================================/" << endl;
}//end method displayMenu

/// <summary>
/// returns the value of the quit flag, false until user
/// chooses to quit program then becomes true.
/// </summary>
 bool quit()
{
	return endProgram;
}//end method quit

/// <summary>
/// public run method that instantiates  the UnitTest methods that
/// control the test application
/// </summary>
void run(UnsortedList& usll, SortedList& sll)
{
	displayMenu();
	validatePickLoop(usll,sll);
}//end method run

/// <summary>
/// takes as an argument the users pick from the option menu, which is
/// already validated for proper range and type.
/// </summary>
/// <param name="choice">the option picked by user.</param>
void menuOptions(int choice, UnsortedList& usll, SortedList& sll)
{
	switch (choice)
	{
		case 1:
			listLoader(usll, sll);
			break;
		case 2:
			displayListsContents(usll, sll);
			displayMenu();
			break;
		case 3:
			deleteItemFromLists(usll, sll);
			displayMenu();
			break;
		case 4:
			emptyUnsorted(usll);
			break;
		case 5:
			emptySorted(sll);
			break;
		case 6:
			cout << "\n\tTesting has been completed\n\t\tGood Bye" << endl;
			endProgram = true;
			break;
		default:
			displayMenu();
			break;
	}
}//end method menuOptions

/// <summary>
/// loads a list from an external file.
/// </summary>
void listLoader(UnsortedList& usll, SortedList& sll)
{
	ifstream inFile;
	string fileName = "numbers.dat";
	int toList;
	bool fileNotFoundError = false;
	do
	{
		if (fileNotFoundError)
		{
			cout << "enter the name of the file to load from: "
				 <<"then press return.\n>>";
			cin >> fileName;
			if (fileName == "exit")
			{
				menuOptions(6,usll,sll);
				exit(0);
			}
		}

		inFile.open(fileName.c_str());
		if (!inFile)
		{
			cout << "file not found, type 'exit' to end program, or" << endl;
			fileNotFoundError = true;
		}
	} while (!inFile);

	while (!inFile.eof())
	{
		inFile >> toList;
		usll.add(toList);
		sll.add(toList);
	}

	cout << "Lists have been successfully loaded." << endl;
	inFile.close();
}//end method listLoader

/// <summary>
/// method to display the contents and quantities of both lists
/// </summary>
void displayListsContents(UnsortedList& usll, SortedList& sll)
{
	usll.printList();
	cout << "Unsorted List length: " << usll.getLength() << endl;
	sll.printList();
	cout << "Sorted List length: " << sll.getLength() << endl;
}//end method displayListContents


/// <summary>
/// method to let user enter items to delete from list
/// </summary>
void deleteItemFromLists(UnsortedList& usll, SortedList& sll)
{
	int itemToDelete;
	char moreToDelete;
	bool toDeleteFlag = true;
	do
	{
		do
		{
			cout << "\nEnter an Item to delete from both lists,"
				 <<" then press enter\n>>";
			try {
				cin >> itemToDelete;
				if (cin) {
					if(usll.find(itemToDelete))
					{
						cout << itemToDelete
							 << " has been removed from the Usorted list"
							 <<endl;
					}
					else if(!usll.find(itemToDelete))
					{
						cout << itemToDelete
						<< " was not found in the unsorted list"<< endl;
					}

					if(sll.find(itemToDelete))
					{
						cout << itemToDelete
							 << " has been removed from the Sorted list"
							 <<endl;
					}
					else if(!sll.find(itemToDelete))
					{
						cout << itemToDelete
							 << " was not found in the sorted list"<< endl;
					}
					usll.deleteItem(itemToDelete);
					sll.deleteItem(itemToDelete);
					cin.clear();
					cin.ignore(100, '\n');
					toDeleteFlag = true;
				}
				while (!cin)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Lists contain integers only, please try again";
					toDeleteFlag = false;
				}
			}
			catch (...) {
				cout << "unknown error, please try again";
				cin.clear();
				cin.ignore(100, '\n');
				toDeleteFlag = false;
			}
		} while (!toDeleteFlag);
		cout << "press [Y/y] to delete another item from the lists, "
			 << " anything else returns to menu\n>>";
		cin >> moreToDelete;
		cin.clear();
		cin.ignore(100, '\n');
	}while (std::toupper(moreToDelete) == 'Y');
}//end method delete items from list

/// <summary>
/// method that empties the Unsorted list
/// </summary>
void emptyUnsorted(UnsortedList& usll)
{
	if(usll.isEmpty())
		cout << "Unsorted list is already empty" << endl;
	else
		cout << "Unsorted list has been emptied"<< endl;
	usll.makeEmpty();
}//end emptyUnsortedList
//
/// <summary>
/// method that empties the Sorted list
/// </summary>
void emptySorted(SortedList& sll)
{
		if(sll.isEmpty())
		cout << "Sorted list is already empty" << endl;
	else
		cout << "Sorted list has been emptied"<< endl;
	sll.makeEmpty();
}//end method emptySorted


/// <summary>
/// Validates the users input and loops until a proper menu option
/// is picked.
/// </summary>
void validatePickLoop(UnsortedList& usll, SortedList& sll){

		int pick;
		while (!quit())
		{
			cout << "\nEnter Menu Option\n>>";
				cin >> pick;
				if (pick >= 1 && pick <= 6) {
					menuOptions(pick, usll,sll);
				}
				else
				{
					cout << "Invalid choice\n" << endl;
					cin.clear();
					cin.ignore(100, '\n');
				}

	 }
}//end method validatePickLoop


