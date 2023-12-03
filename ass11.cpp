import java.util.Scanner;
class CircularQueue {
 int size;
 int f;
 int r;
 int[] arr;
 CircularQueue(int size) {
 this.size = size;
 this.f = -1;
 this.r = -1;
 this.arr = new int[size];
 }
Implement the circular queue.
Name=Darshan Ramesh Jadhav
Code:
 boolean isEmpty() {
 return this.r == this.f;
 }
 boolean isFull() {
 return (this.r + 1) % this.size == this.f;
 }
 void enqueue(int val) {
 if (isFull()) {
 System.out.println("This Queue is full");
 } else {
 this.r = (this.r + 1) % this.size;
 this.arr[this.r] = val;
 System.out.println("Enqueued element: " + val);
 }
 }
 int dequeue() {
 int a = -1;
 if (isEmpty()) {
 System.out.println("This Queue is empty");
 } else {
 this.f = (this.f + 1) % this.size;
 a = this.arr[this.f];
 }
 return a;
 }
 void display() {
 for (int i = 0; i <= this.r; i++) {
 System.out.print(this.arr[i] + " ");
 }
 System.out.println();
 }
}
public class Main {
 public static void main(String[] args) {
 Scanner scanner = new Scanner(System.in);
 int choice, item;
 System.out.print("Enter the size of the Circular Queue: ");
 int size = scanner.nextInt();
 CircularQueue q = new CircularQueue(size);
 do {
 System.out.println("1.Insert");
 System.out.println("2.Delete");
 System.out.println("3.Display");
 System.out.println("4.Quit");
 System.out.print("Enter your choice: ");
 choice = scanner.nextInt();
 switch (choice) {
 case 1:
 System.out.print("Input the element for insertion in queue: ");
 item = scanner.nextInt();
 q.enqueue(item);
 break;
 case 2:
 System.out.println("The Element dequeued is: " + q.dequeue());
 break;
 case 3:
 q.display();
 break;
 case 4:
 break;
 default:
 System.out.println("Wrong choice");
 }
 } while (choice != 4);
 scanner.close();
 }
}