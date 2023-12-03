Code
1:Implement stack ADT using linked list
class Node{ int data; Node next; public Node(int
data) {this.data = data; this.next
= null;
}
}
class Stack { private
Node top; public
Stack() {
this.top = null;
}
public void push(int data) {
Node newNode = new Node(data);
newNode.next = top; top =
newNode;
}
public int pop() {
if (isEmpty()) {
throw new IllegalStateException("Stack is empty");
}
int data = top.data;
top = top.next; return
data;
}
public int peek() {
if (isEmpty()) {
throw new IllegalStateException("Stack is empty");
}
return top.data;
}
public boolean isEmpty() {
return top == null;
}
}
Code 2:Write a program for infix to postfix conversion using stack. Also,
evaluate the postfix expression
import java.util.Stack; public class
InfixToPostfixEvaluator {
public static String infixToPostfix(String infixExpression) {
StringBuilder postfix = new StringBuilder();
Stack<Character> stack = new Stack<>(); for
(char c : infixExpression.toCharArray()) {
if (Character.isLetterOrDigit(c)) {
postfix.append(c);
} else if (c == '(') { stack.push(c);
} else if (c == ')') { while (!stack.isEmpty() &&
stack.peek() != '(') {
postfix.append(stack.pop());
}
stack.pop(); // Remove the '('
} else { while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
postfix.append(stack.pop());
}
stack.push(c);
}
}
while (!stack.isEmpty()) {
postfix.append(stack.pop());
}
return postfix.toString();
}
private static int precedence(char operator) {
switch (operator) { case
'+':
case '-':
return 1;
case '*':
case '/':
return 2;
case '^':
return 3;
}
}
public static int evaluatePostfix(String postfixExpression) {
Stack<Integer> stack = new Stack<>(); for (char c :
postfixExpression.toCharArray()) {
if (Character.isDigit(c)) {
stack.push(c - '0');
} else { int operand2 =
stack.pop(); int operand1 =
stack.pop(); switch (c) {
case '+':
stack.push(operand1 + operand2); break;
case '-':
stack.push(operand1 - operand2);
break;
case '*':
stack.push(operand1 * operand2); break;
case '/':
stack.push(operand1 / operand2); break;
}
}
}
return stack.pop();
}
public static void main(String[] args) {
String infixExpression = "3+5*(2-8)/2";
String postfixExpression = infixToPostfix(infixExpression);
System.out.println("Infix Expression: " + infixExpression);
System.out.println("Postfix Expression: " + postfixExpression); int
result = evaluatePostfix(postfixExpression);
System.out.println("Result of postfix expression: " + result);
}
}