import java.util.Scanner;
public class SortingArray{
 public static void main(String[] args) {
 Scanner scanner = new Scanner(System.in);
 int[] arr = null;
 while (true) {
 System.out.println("\nMenu:");
 System.out.println("1. Accept and Display the Integer Array");
 System.out.println("2. Sort the Array using Quick Sort");
 System.out.println("3. Sort the Array using Merge Sort");
 System.out.println("4. Exit");
 System.out.print("Enter your choice: ");
 int choice = scanner.nextInt();
 switch (choice) {
 case 1:
 arr = acceptAndDisplayArray(scanner);
 break;
 case 2:
 if (arr != null) {
 System.out.println("Sorting using Quick Sort...");
 quickSort(arr, 0, arr.length - 1);
 System.out.println("Sorted Array:");
 displayArray(arr);
 } else {
 System.out.println("Array is not initialized. Please create the array first.");
 }
 break;
 case 3:
 if (arr != null) {
 System.out.println("Sorting using Merge Sort...");
 mergeSort(arr, 0, arr.length - 1);
 System.out.println("Sorted Array:");
 displayArray(arr);
 } else {
 System.out.println("Array is not initialized. Please create the array first.");
 }
 break;
 case 4:
 System.out.println("Exiting the program.");
 scanner.close();
 System.exit(0);
 default:
 System.out.println("Invalid choice. Please enter a valid option.");
 }
 }
 }
 private static int[] acceptAndDisplayArray(Scanner scanner) {
 System.out.print("Enter the number of integers: ");
 int n = scanner.nextInt();
 int[] arr = new int[n];
 for (int i = 0; i < n; i++) {
 System.out.print("Enter integer #" + (i + 1) + ": ");
 arr[i] = scanner.nextInt();
 }
 System.out.println("Entered Integer Array:");
 displayArray(arr);
 return arr;
 }
 public static void quickSort(int[] arr, int low, int high) {
 if (low < high) {
 int pivotIndex = partition(arr, low, high);
 System.out.println("Pass:");
 displayArray(arr);
 quickSort(arr, low, pivotIndex - 1);
 quickSort(arr, pivotIndex + 1, high);
 }
 }
 public static int partition(int[] arr, int low, int high) {
 int pivot = arr[high];
 int i = low - 1;
 for (int j = low; j < high; j++) {
 if (arr[j] < pivot) {
 i++;
 int temp = arr[i];
 arr[i] = arr[j];
 arr[j] = temp;
 }
 }
 int temp = arr[i + 1];
 arr[i + 1] = arr[high];
 arr[high] = temp;
 return i + 1;
 }
 public static void mergeSort(int[] arr, int left, int right) {
 int i=1;
 if (left < right) {
 int mid = (left + right) / 2;
 mergeSort(arr, left, mid);
 mergeSort(arr, mid + 1, right);
 merge(arr, left, mid, right);
 System.out.println("Pass:");
 displayArray(arr);
 }
 }
 public static void merge(int[] arr, int left, int mid, int right) {
 int n1 = mid - left + 1;
 int n2 = right - mid;
 int[] L = new int[n1];
 int[] R = new int[n2];
 for (int i = 0; i < n1; i++) {
 L[i] = arr[left + i];
 }
 for (int i = 0; i < n2; i++) {
 R[i] = arr[mid + i + 1];
 }
 int i = 0, j = 0;
 int k = left;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k] = L[i];
 i++;
 } else {
 arr[k] = R[j];
 j++;
 }
 k++;
 }
 while (i < n1) {
 arr[k] = L[i];
 i++;
 k++;
 }
 while (j < n2) {
 arr[k] = R[j];
 j++;
 k++;
 }
 }
 public static void displayArray(int[] arr) {
 for (int num : arr) {
 System.out.print(num + " ");
 }
 System.out.println();
 }
}