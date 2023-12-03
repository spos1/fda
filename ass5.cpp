#include <stdio.h>
#include <string.h>
// Function to perform Insertion Sort in ascending order
void insertionSortAscending(char arr[][100], int n) {
 int i, j;
 char key[100];
 for (i = 1; i < n; i++) {
 strcpy(key, arr[i]);
 j = i - 1;
 while (j >= 0 && strcmp(arr[j], key) > 0) {
 strcpy(arr[j + 1], arr[j]);
 j = j - 1;
 }
 strcpy(arr[j + 1], key);
 // Display the current state of the array
 printf("Pass %d: ", i);
 for (int k = 0; k < n; k++) {
 printf("%s ", arr[k]);
 }
 printf("\n");
 }
}
// Function to perform Selection Sort in descending order
void selectionSortDescending(char arr[][100], int n) {
 int i, j, minIndex;
 char temp[100];
 for (i = 0; i < n - 1; i++) {
 minIndex = i;
 for (j = i + 1; j < n; j++) {
 if (strcmp(arr[j], arr[minIndex]) > 0) {
 minIndex = j;
 }
 }
 // Swap arr[i] and arr[minIndex]
 strcpy(temp, arr[i]);
 strcpy(arr[i], arr[minIndex]);
 strcpy(arr[minIndex], temp);
 // Display the current state of the array
 printf("Pass %d: ", i + 1);
 for (int k = 0; k < n; k++) {
 printf("%s ", arr[k]);
 }
 printf("\n");
 }
}
// Function to perform Binary Search without recursion
int binarySearchIterative(char arr[][100], int n, char key[100]) {
 int left = 0, right = n - 1;
 while (left <= right) {
 int mid = left + (right - left) / 2;
 int cmp = strcmp(arr[mid], key);
 if (cmp == 0) {
 return mid; // Element found
 } else if (cmp < 0) {
 left = mid + 1;
 } else {
 right = mid - 1;
 }
 }
 return -1; // Element not found
}
// Function to display the menu and perform operations based on user choice
int main() {
 int n, i;
 char arr[100][100];
 char key[100];
 int choice;
 printf("Enter the number of strings: ");
 scanf("%d", &n);
 printf("Enter the strings:\n");
 for (i = 0; i < n; i++) {
 scanf("%s", arr[i]);
 }
 do {
 printf("\nMenu:\n");
 printf("1. Sort in Ascending Order using Insertion Sort\n");
 printf("2. Sort in Descending Order using Selection Sort\n");
 printf("3. Search a String using Binary Search (Iterative)\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 insertionSortAscending(arr, n);
 break;
 case 2:
 selectionSortDescending(arr, n);
 break;
 case 3:
 printf("Enter the string to search: ");
 scanf("%s", key);
 i = binarySearchIterative(arr, n, key);
 if (i != -1) {
 printf("String found at index %d\n", i);
 } else {
 printf("String not found\n");
 }
 break;
 case 4:
 printf("Exiting...\n");
 break;
 default:
 printf("Invalid choice! Please enter a valid option.\n");
 }
 } while (choice != 4);
 return 0;
}