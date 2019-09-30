/**************************************************************/
/*                                                            */
/*   Program to demonstrate the implmentation of a            */
/*   linked list of numbers.								  */
/*                                                            */
/**************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#define bool int
#define false 0
#define true (!false)

//Libraries
#include <stdio.h>
#include <stdlib.h>


//Preprocessor Variable
#define SIZE 10

//Stucture template for data part of a LinearNode
struct book {
	char bookId[9];
	char name[40];
	char author[40];
	int year;
	bool loaned;
	char cusName[40];
	int timesLoaned;
};

//Stucture template for one node
struct LinearNode {
	struct data *element;
	struct LinearNode *next;
};


// Function prototypes
void saveToFile(FILE *);
void getFromFile(FILE *);
void displayStudents();
void linearSearch(int, int, char *);
bool binarySearch(int, int, char *);
void addNodes();  //adding nodes to end of the list
void deleteNode(int); // delete a specific node
void viewAllNodes();
bool isEmpty();
void displaySmallest();
void addSortedNode();


// Global Variables
struct LinearNode *front = NULL;
struct LinearNode *last = NULL;

/**************MAIN FUNCTION*******************/
int main() {

	int delNum;

	FILE *fp;
	int i;

	char delay;

	if ((fp = fopen("books.dat", "rb")) == NULL) {

		//file DOES NOT exist so get user to input students
		printf("Database of books has not been found\nPlease input books\n");
		addNodes();

	}//end if
	else  //file DOES exist
		getFromFile(fp);
	printf("System has been populated with books from file\n");

		int ans;
	do {
		printf("1. Add a new book to the library\n");
		printf("2. Allow customer to take out a book\n");
		printf("3. Allow customer to return a book\n");
		printf("4. Delete an old book from stock\n");
		printf("5. View all books\n");
		printf("6. View a specific book\n");
		printf("7. View details of most popular and least popular books\n");
		printf("8. Who knows\n");
		printf("9. Exit the system\n");
	} while (ans < 1 && ans > 9);
	//viewAllNodes();
	//displaySmallest();
	addSortedNode();
	viewAllNodes();
//	printf("Please enter the number of the node to delete : ");
//	scanf("%d", &delNum);
	
//	deleteNode(delNum);

//	viewAllNodes();

	getchar();
	getchar();
}

void saveToFile(FILE *fp) {

	fp = fopen("students.dat", "wb");

	for (int i = 0; i< MAX; i++)
		fwrite(&listOfBooks[i], sizeof(struct book), 1, fp);

	fclose(fp);
}

void getFromFile(FILE *fp) {
	struct LinearNode current == NULL;

	int i = 0;
	char c;
	printf("Retriving books from file...\n");
	while (fread(&listOfBooks[i], sizeof(struct book), 1, fp) != NULL)
		i++;
	fclose(fp);
}


void displayStudents() {
	int i;
	for (i = 0; i< MAX; i++)
		printf("Student %d is %s\n", i + 1, classOfStudents[i].studentId);
}

void linearSearch(int min, int max, char *target)
{
	int index = min;
	bool found = false;

	while (!found && index <= max)
	{
		if (strcmp(classOfStudents[index].studentId, target) == 0)
			found = true;
		index++;
	}

	if (found)
		printf("%s has been found\n", target);
	else
		printf("%s was not found\n", target);
}


bool binarySearch(int min, int max, char *target)
{
	bool found = false;
	int midpoint = (min + max) / 2;  // determine the midpoint

	if (strcmp(classOfStudents[midpoint].studentId, target) == 0)
		found = true;
	else if (strcmp(classOfStudents[midpoint - 1].studentId, target) == 0)
	{
		if (min <= midpoint - 1)
			found = binarySearch(min, midpoint - 1, target);
	}
	else //if (data[midpoint] < target)
		if (midpoint + 1 <= max)
			found = binarySearch(midpoint + 1, max, target);

	return found;

}


/**********ADD 10 NODES TO THE LIST******************/
// Each new node is added to the end of the list

void addNodes() {

	int aNumber;
	struct LinearNode *aNode;
	struct book *anElement;

	// add SIZE nodes to the list
	for (int i = 0; i<SIZE; i++) {
		//Create space for data part of node
		anElement = (struct book *)malloc(sizeof(struct book));

		if (anElement == NULL)
			printf("Error - no space for the new element\n");
		else
		{
			//Input value into the data part
			int year;
			printf("Enter id for book %d: ", i + 1);
			scanf("%s", &anElement->bookId);
			printf("Enter name for book %d: ", i + 1);
			scanf("%s", &anElement->name);
			printf("Enter author of book %d: ", i + 1);
			scanf("%s", &anElement->author);
			do{
				printf("Enter year(not less than 2008) of publication of book %d: ", i + 1);
				scanf("%s", &anElement->year);
			}while(&anElement->year <= 2008)
			&anElement->loaned = false;
			&anElement->cusName = "";
			&anElement->timesLoaned = 0'

			// create space for new node that will contain data
			aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));

			if (aNode == NULL)
				printf("Error - no space for the new node\n");
			else { // add data part to the node
				aNode->element = anElement;
				aNode->next = NULL;

				//add node to end of the list
				if (isEmpty())
				{
					front = aNode;
					last = aNode;
				}
				else {
					last->next = aNode;
					last = aNode;
				} //end else
			}//end else
		}//end else 
	}//end for
} //end addNodes

void addSortedNode() {
	int aNumber;
	struct LinearNode *aNode, *current, *previous;
	struct data *anElement;

	for (int i = 1; i < 4; i++)
	{


		anElement = (struct data *)malloc(sizeof(struct data));
		aNode = (struct LinearNode *)malloc(sizeof(struct LinearNode));
		aNode->element = anElement;
		aNode->next = NULL;


		printf("Enter a number for node: ");
		scanf("%d", &anElement->num);

		if (isEmpty()) {
			front = last = aNode;
		}
		else {
			current = previous = front;

			while (current != NULL && current->element->num < anElement->num) {

				previous = current;
				current = current->next;

			}

			//if (current != NULL) printf("current = %d\n", current->element->num);

			if (current == front) {
				aNode->next = front;
				front = aNode;
			}
			else if (current == NULL) {
				last->next = aNode;
				last = aNode;
			}
			else {
				previous->next = aNode;
				aNode->next = current;
			}

		}
	}
	
}

  /**********VIEW ALL THREE NODES IN THE LIST******************/
  // Each new node is added to the end of the list
void viewAllNodes() {
	struct LinearNode *current;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = front;
		while (current != NULL) {
			printf("Node value is %d\n", current->element->num);
			current = current->next;
		} //end while
	}//end else
} //end viewAllNodes


void deleteNode(int aNumber) {
	struct LinearNode *current, *previous;
	bool notFound = true;

	printf("\n");
	if (isEmpty())
		printf("Error - there are no nodes in the list\n");
	else {
		current = previous = front;

		while (notFound && current != NULL) {
			if (aNumber == current->element->num)
				notFound = false;
			else {
				previous = current;
				current = current->next;
			}//end else
		} //end while

		if (notFound)
			printf("Error - there is not such node with value %d\n", aNumber);
		else {
			if (current == front) { //delete front node
				front = front->next;
				free(current);
			} //end else
			else if (current == last) {//delete last node
				free(current);
				previous->next = NULL;
				last = previous;
			}
			else {//delete node in middle of list
				previous->next = current->next;
				free(current);
			} //end else
			printf("Node with value %d has been deleted\n", aNumber);
		}//end else
	}//end else
}// end deleteNode

void displaySmallest() {
	struct LinearNode *current, *smallest;
	int num;

	printf("\n");
	if (isEmpty())
		printf("No nodes is list\n");
	else {
		smallest = current = front;

		while (current != NULL) {
			if (smallest->element->num > current->element->num)
				smallest = current;

			    current = current->next;
		}
		num = smallest->element->num;
		printf("\nSmallest node has value of %d\n", num);
	}
}

bool isEmpty() {
	if (front == NULL)
		return true;
	else
		return false;
}