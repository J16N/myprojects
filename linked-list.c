#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
	int value;
	struct record *next;
} NODE;

void append(int data);
void add_begin(int data);
void add_after_node(int pos, int data);
void add_after_value(int num, int data);
void del_begin();
void del_node(int pos);
void del_value(int data);
void del_last();
void search(int data);
void reverse();
void display();
void end();
NODE *start = NULL;

int main(int argc, char const *argv[])
{
	int prompt, data, num, pos;

	do {
		printf("\n *************************************************************");
		printf("\n *************************************************************");
		printf("\n ** <1>  To ADD a new node to the list                      **");
		printf("\n ** <2>  To ADD a new node at the BEGINNING of the list     **");
		printf("\n ** <3>  To ADD a new node AFTER a given NODE in the list   **");
		printf("\n ** <4>  To ADD a new node AFTER a given VALUE in the list  **");
		printf("\n ** <5>  To DELETE a node from the BEGINNING of the list    **");
		printf("\n ** <6>  To DELETE a given NODE in the list                 **");
		printf("\n ** <7>  To DELETE a given VALUE in the list                **");
		printf("\n ** <8>  To DELETE the LAST node in the list                **");
		printf("\n ** <9>  To REVERSE the list                                **");
		printf("\n ** <10> To SEARCH for a VALUE in the list                  **");
		printf("\n ** <11> To DISPLAY the list                                **");
		printf("\n ** <0>  To END the operation                               **");
		printf("\n *************************************************************");
		printf("\n *************************************************************");
		
		printf("\n\n Enter Choice: ");
		scanf("%d", &prompt);

		switch (prompt) {
			case 1:
				printf("\n Enter Data: ");
				scanf("%d", &data);
				append(data);
				break;

			case 2:
				printf("\n Enter Data: ");
				scanf("%d", &data);
				add_begin(data);
				break;

			case 3:
				printf("\n Enter position after which to insert a new node: ");
				scanf("%d", &pos);
				printf("\n Enter Data: ");
				scanf("%d", &data);
				add_after_node(pos, data);
				break;

			case 4:
				printf("\n Enter value after which to insert a new node: ");
				scanf("%d", &num);
				printf("\n Enter Data: ");
				scanf("%d", &data);
				add_after_value(num, data);
				break;

			case 5:
				del_begin();
				break;

			case 6:
				printf("\n Enter position of node to delete: ");
				scanf("%d", &pos);
				del_node(pos);
				break;

			case 7:
				printf("\n Enter value to delete: ");
				scanf("%d", &data);
				del_value(data);
				break;

			case 8:
				del_last();
				break;

			case 9:
				reverse();
				break;

			case 10:
				printf("\n Enter the value to search: ");
				scanf("%d", &data);
				search(data);
				break;

			case 11:
				display();
				break;

			case 0:
				end();
				break;

			default:
				printf("\n Enter a valid choice.\n");
		}

	} while (prompt != 0);

	fflush(stdin);

	getchar();

	return 0;
}

void append(int data)
{
	NODE *temp, *curr;
	temp = (NODE*) malloc(sizeof(NODE));
	temp->value = data;
	temp->next = NULL;

	if (start == NULL) {
		printf("\n ******FIRST NODE OF THE LIST CREATED******\n");
		start = temp;
	}
	else {
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}

void display()
{
	int count = 0;
	NODE *curr = start;
	printf("\n Current list:\n");

	if (curr == NULL)
		printf("\n ***EMPTY LIST***");

	while (curr != NULL) {
		printf(" Data%d = %d\n", ++count, curr->value);
		curr = curr->next;
	}
}

void add_begin(int data)
{
	NODE *temp;
	temp = (NODE*) malloc(sizeof(NODE));
	temp->value = data;
	temp->next = start;
	start = temp;
}

void add_after_node(int pos, int data)
{
	NODE *curr = start, *temp;

	while ((pos > 1) && (curr != NULL)) {
		curr = curr->next;
		pos--;
	}

	if (curr == NULL) {
		printf("\n Position is outside the list");
		return;
	}

	temp = (NODE*) malloc(sizeof(NODE));
	temp->value = data;
	temp->next = curr->next;
	curr->next = temp;
}

void add_after_value(int num, int data)
{
	NODE *curr = start, *temp;

	while ((curr != NULL) && (curr->value != num))
		curr = curr->next;

	if (curr == NULL) {
		printf("\n Value is not present in the list");
		return;
	}

	temp = (NODE*) malloc(sizeof(NODE));
	temp->value = data;
	temp->next = curr->next;
	curr->next = temp;
}

void del_begin()
{
	NODE *temp = start;
	start = start->next;
	free(temp);
}

void del_node(int pos)
{
	NODE *curr = start, *temp;

	while (((pos - 1) > 1) && (curr != NULL)) {
		curr = curr->next;
		pos--;
	}

	if (curr == NULL) {
		printf("\n Position is outside the list");
		return;
	}

	temp = curr->next;
	curr->next = temp->next;
	free(temp);
}

void del_value(int data)
{
	NODE *curr, *temp;

	if (start->value == data) {
		del_begin();
		return;
	}

	curr = start;

	while ((curr->next != NULL) && (curr->next->value != data))
		curr = curr->next;

	if (curr->next != NULL) {
		temp = curr->next;
		curr->next = temp->next;
		free(temp);
	} else
		printf("\n Value not found in list!");
}

void del_last()
{
	NODE *curr = start, *temp;

	while (curr->next->next != NULL)
		curr = curr->next;

	temp = curr->next;
	curr->next = NULL;
	free(temp);
}

void search(int data)
{
	NODE *curr = start;
	int check = 0, count = 0;

	while (curr != NULL) {
		count++;
		
		if (curr->value == data) {
			printf("\n Data %d found in position %d\n", data, count);
			check++;
		}

		curr = curr->next;
	}

	if (check == 0)
		printf("\n Value not found.");
}

void reverse()
{
	NODE *curr = start, *prev = NULL, *sprev = NULL;

	while (curr != NULL) {
		sprev = prev;
		prev = curr;
		curr = curr->next;
		prev->next = sprev;
	}

	start = prev;
}

void end()
{
	while (start != NULL)
		del_begin();
}