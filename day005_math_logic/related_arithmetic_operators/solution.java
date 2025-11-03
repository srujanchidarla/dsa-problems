import java.util.Scanner;

class Solution {

    // O(1) Time, O(1) Space
    public static void performOperation(int A, int B, char op) {
        long result;

        // Java switch statement handles the logic cleanly
        switch (op) {
            case '+':
                result = (long)A + B;
                break;
            case '-':
                result = (long)A - B;
                break;
            case '*':
                result = (long)A * B;
                break;
            case '/':
                if (B == 0) {
                    System.out.println("Error: Division by zero");
                    return;
                }
                result = (long)A / B;
                break;
            default:
                System.out.println("Error: Invalid operator");
                return;
        }
        System.out.println(result);
    }
    
    // Brute Force using if/else if (O(1))
    public static void performOperation_brute(int A, int B, char op) {
        // Logic is the same, just using an if/else structure.
        performOperation(A, B, op); 
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        if (!scanner.hasNextInt()) return;
        int A = scanner.nextInt();
        
        if (!scanner.hasNextInt()) return;
        int B = scanner.nextInt();

        // Read the operator as a string, then get the first character
        if (!scanner.hasNext()) return;
        char op = scanner.next().charAt(0);
        
        performOperation(A, B, op);
        scanner.close();
    }
}