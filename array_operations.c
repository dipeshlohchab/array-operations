#include <stdio.h>
#include <stdlib.h>

#define N 10

// Function prototypes
void create(int a[], int size);
void createptr(int *b, int size);
void print(int *a, int size);
int search(int *a, int size, int val);
int delete(int *a, int *size, int val);
int insert(int *a, int *size, int val, int ind);

int main() {
    int a[N], size, *b, val, ind, x;

    // Prompt user to enter the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    b = (int *)malloc(size * sizeof(int));

    // CREATE ARRAY b
    createptr(b, size);
    print(b, size);

    // CREATE ARRAY a
    create(a, N);
    print(a, N);

    // SEARCH for a value in array a
    printf("Enter the value you want to search: ");
    scanf("%d", &val);
    x = search(a, N, val);
    if (x != -1)
        printf("The %d is present at index %d\n", val, x);
    else
        printf("%d is not present in the array.\n", val);

    // DELETE a value from array a
    printf("Enter the value you want to delete: ");
    scanf("%d", &val);
    if (delete(a, &size, val))
        printf("Value %d deleted successfully.\n", val);
    else
        printf("Value %d not found.\n", val);
    print(a, size);

    // INSERT a value into array a
    printf("Enter the value and index you want to insert: ");
    scanf("%d %d", &val, &ind);
    if (insert(a, &size, val, ind))
        printf("Value %d inserted successfully at index %d.\n", val, ind);
    else
        printf("Insertion failed.\n");
    print(a, size);

    // Free allocated memory
    free(b);

    return 0;
}

// Function to create an array with user input
void create(int a[], int s) {
    int i;
    for (i = 0; i < s; i++) {
        scanf("%d", &a[i]);
    }
}

// Function to create an array using pointers with user input
void createptr(int *b, int size) {
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &b[i]);
    }
}

// Function to print the array
void print(int a[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

// Function to search for a value in the array
int search(int arr[], int size, int val) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == val)
            return i;
    }
    return -1;
}

// Function to delete a value from the array
int delete(int a[], int *s, int val) {
    int ind = search(a, *s, val);
    if (ind == -1) {
        printf("No deletion\n");
        return 0;
    }
    for (int i = ind; i < *s - 1; i++) {
        a[i] = a[i + 1];
    }
    (*s)--;
    return 1;
}

// Function to insert a value into the array
int insert(int a[], int *s, int val, int ind) {
    if (ind < 0 || ind > *s) {
        printf("Invalid index\n");
        return 0;
    }
    for (int i = *s; i > ind; i--) {
        a[i] = a[i - 1];
    }
    a[ind] = val;
    (*s)++;
    return 1;
}
