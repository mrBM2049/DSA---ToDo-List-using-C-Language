#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
int count = 1;
typedef struct Todo
{
    char *workToDO;
    int SrNo;
    struct Todo *next;

} Todo;

void bubble_sort_list(Todo *head)
{
    Todo *current, *next;
    int swapped;
    do
    {
        swapped = 0;
        current = head;
        next = current->next;

        while (next)
        {
            if (current->SrNo > next->SrNo)
            {
                // Swap SrNo values
                int sr = current->SrNo;
                current->SrNo = next->SrNo;
                next->SrNo = sr;

                // Swap workToDO strings
                char *temp;
                temp = current->workToDO;
                current->workToDO = next->workToDO;
                next->workToDO = temp;

                swapped = 1;
            }
            current = next;
            next = current->next;
        }
    } while (swapped);
}

void deleteTodo(Todo **head_ref, int srNo) {
    Todo *current = *head_ref;
    Todo *prev = NULL;

    while (current != NULL && current->SrNo != srNo) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Task with SrNo %d not found\n", srNo);
        return;
    }

    if (prev == NULL) {
        // Node to be deleted is the head
        *head_ref = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Task with SrNo %d deleted successfully\n", srNo);

    // Update SrNo values for the remaining items and sort the list
    Todo *temp = *head_ref;
    count = 1;
    while (temp != NULL) {
        temp->SrNo = count++;
        temp = temp->next;
    }

    bubble_sort_list(*head_ref);
}


void updateTodo(Todo *head, int srNo, char *newWork)
{
    Todo *current = head;

    while (current != NULL && current->SrNo != srNo)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Task with SrNo %d not found\n", srNo);
        return;
    }

    current->workToDO = newWork;
    printf("Task with SrNo %d updated successfully\n", srNo);

    bubble_sort_list(head);
}

void cleanUp(Todo **head)
{
    Todo *current = *head;
    Todo *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("ToDo cleaned");
}

Todo *createTodo(Todo **head_ref, char *work)
{
    Todo *new_node = (Todo *)malloc(sizeof(Todo));
    if (new_node == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }

    new_node->SrNo = count++;
    new_node->workToDO = strdup(work);
    new_node->next = *head_ref;
    *head_ref = new_node;

    // Sort the list based on SrNo
    bubble_sort_list(*head_ref);

    printf("Task added successfully\n");
    return new_node;
}

void printToDos(Todo *ptr)
{
    if (ptr == NULL)
    {
        printf("Empty ToDo list\n");
    }
    printf("ToDo's You created are: \n");
    while (ptr != NULL)
    {
        printf("%d.\t%s\n", ptr->SrNo, ptr->workToDO);
        ptr = ptr->next;
    }
}

int main()
{
    Todo *user = NULL;
    char workget[SIZE];
    int choice;
    int SrNo;

    while (1)
    {
        system("color 3F");
        system("cls");
        printf("\n1.See Your ToDo List");
        printf("\n2.Create Your ToDos");
        printf("\n3.Update Your ToDos");
        printf("\n4.Delete Your ToDos");
        printf("\n5.Clear ToDo List");
        printf("\n6.Exit");
        printf("\n\nEnter your choice..");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printToDos(user);
            system("pause");
            break;
        case 2:
            printf("Enter Your work ToDo: ");
            scanf("%s", workget);
            createTodo(&user, workget);
            system("pause");
            break;
        case 3:
            printf("Enter SrNO(You Need to Update ToDO): ");
            scanf("%d", &SrNo);
            printf("Enter New work ToDo: ");
            scanf("%s", workget);
            updateTodo(user, SrNo, workget);
            system("pause");
            break;
        case 4:
            printf("Enter SrNO(You Need to Delete ToDO): ");
            scanf("%d", &SrNo);
            deleteTodo(&user, SrNo);
            system("pause");
            break;
        case 5:
            cleanUp(&user);
            system("pause");
        case 6:
            exit(0);
        }
    }

    return 0;
}
