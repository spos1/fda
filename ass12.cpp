class Patient { String name; int severity;
public Patient(String name, int severity) {
this.name = name;
this.severity = severity;
}
@Override public String 
toString() {
return "Patient{" +
"name='" + name + '\'' +
", severity=" + severity +
'}';
}
}
class Node {
Patient patient;
Node next;
Node(Patient patient) {
this.patient = patient; this.next 
= null;
public
}
}
public class PriorityQueueLinkedList { 
private Node front; public 
PriorityQueueLinkedList() {
this.front = null;
}
public void enqueue(Patient patient) { Node 
newNode = new Node(patient);
if (front == null || patient.severity < front.patient.severity) {
newNode.next = front; front 
= newNode;
} else {
Node current = front;
while (current.next != null && patient.severity >= current.next.patient.severity) {
current = current.next;
}
newNode.next = current.next; current.next = 
newNode;
}
System.out.println("Enqueued: " + patient);
}
Patient dequeue() {
if (isEmpty()) {
public
System.out.println("Queue is empty. Cannot dequeue."); 
return null;
}
Patient removedPatient = front.patient; front = 
front.next;
System.out.println("Dequeued: " + removedPatient); return 
removedPatient;
}
public boolean isEmpty() {
return front == null;
}
public void display() {
if (isEmpty()) {
System.out.println("Queue is empty."); return;
}
Node current = front; while 
(current != null) {
System.out.print(current.patient + " "); current = 
current.next;
}
System.out.println();
}
static void main(String[] args) {
PriorityQueueLinkedList priorityQueue = new PriorityQueueLinkedList(); 
priorityQueue.enqueue(new Patient("John", 3)); priorityQueue.enqueue(new 
Patient("Alice", 1)); priorityQueue.enqueue(new Patient("Bob", 2)); 
priorityQueue.display(); priorityQueue.dequeue(); priorityQueue.display();
}