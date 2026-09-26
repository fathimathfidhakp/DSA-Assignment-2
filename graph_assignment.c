#include <stdio.h>
#include <stdlib.h>

#define V 6

char vertices[V] = {'A', 'B', 'C', 'D', 'E', 'F'};

int matrix[V][V] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 0}
};

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *list[V] = {NULL};

struct Node* createNode(int v)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->vertex = v;
    newNode->next = NULL;

    return newNode;
}

void createList()
{
    int i, j;
    struct Node *temp;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (matrix[i][j] == 1)
            {
                struct Node *newNode = createNode(j);

                if (list[i] == NULL)
                {
                    list[i] = newNode;
                }
                else
                {
                    temp = list[i];

                    while (temp->next != NULL)
                        temp = temp->next;

                    temp->next = newNode;
                }
            }
        }
    }
}

void displayMatrix()
{
    int i, j;

    printf("\nAdjacency Matrix:\n");

    printf("  ");

    for (i = 0; i < V; i++)
        printf("%c ", vertices[i]);

    printf("\n");

    for (i = 0; i < V; i++)
    {
        printf("%c ", vertices[i]);

        for (j = 0; j < V; j++)
            printf("%d ", matrix[i][j]);

        printf("\n");
    }
}

void displayList()
{
    int i;
    struct Node *temp;

    printf("\nAdjacency List:\n");

    for (i = 0; i < V; i++)
    {
        printf("%c -> ", vertices[i]);

        temp = list[i];

        while (temp != NULL)
        {
            printf("%c ", vertices[temp->vertex]);
            temp = temp->next;
        }

        printf("\n");
    }
}

void BFS_Matrix(int start)
{
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;
    int current, i;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS using Matrix: ");

    while (front < rear)
    {
        current = queue[front++];

        printf("%c ", vertices[current]);

        for (i = 0; i < V; i++)
        {
            if (matrix[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

void DFS_Matrix(int current, int visited[])
{
    int i;

    visited[current] = 1;

    printf("%c ", vertices[current]);

    for (i = 0; i < V; i++)
    {
        if (matrix[current][i] == 1 && visited[i] == 0)
        {
            DFS_Matrix(i, visited);
        }
    }
}

void BFS_List(int start)
{
    int visited[V] = {0};
    int queue[V];
    int front = 0, rear = 0;
    int current;

    struct Node *temp;

    visited[start] = 1;
    queue[rear++] = start;

    printf("\nBFS using List: ");

    while (front < rear)
    {
        current = queue[front++];

        printf("%c ", vertices[current]);

        temp = list[current];

        while (temp != NULL)
        {
            if (visited[temp->vertex] == 0)
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

void DFS_List(int current, int visited[])
{
    struct Node *temp;

    visited[current] = 1;

    printf("%c ", vertices[current]);

    temp = list[current];

    while (temp != NULL)
    {
        if (visited[temp->vertex] == 0)
        {
            DFS_List(temp->vertex, visited);
        }

        temp = temp->next;
    }
}

void searchMatrix(char key)
{
    int i;
    int operations = 0;

    for (i = 0; i < V; i++)
    {
        operations++;

        if (vertices[i] == key)
        {
            printf("\nMatrix Search: %c found", key);
            printf("\nVertex-label checks = %d\n", operations);
            return;
        }
    }

    printf("\nVertex not found in Matrix\n");
}

void searchList(char key)
{
    int i;
    int operations = 0;

    struct Node *temp;

    for (i = 0; i < V; i++)
    {
        operations++;

        if (vertices[i] == key)
        {
            temp = list[i];

            while (temp != NULL)
            {
                operations++;
                temp = temp->next;
            }

            printf("\nList Search: %c found", key);
            printf("\nVertex/list checks = %d\n", operations);
            return;
        }
    }

    printf("\nVertex not found in List\n");
}

int main()
{
    int visited[V] = {0};
    int i;

    createList();

    displayMatrix();

    displayList();

    BFS_Matrix(0);

    printf("DFS using Matrix: ");
    DFS_Matrix(0, visited);
    printf("\n");

    BFS_List(0);

    for (i = 0; i < V; i++)
        visited[i] = 0;

    printf("DFS using List: ");
    DFS_List(0, visited);
    printf("\n");

    printf("\nSearch for vertex F:\n");

    searchMatrix('F');

    searchList('F');

    return 0;
}
