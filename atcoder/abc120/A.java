import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int A = in.nextInt();
        int B = in.nextInt();
        int C = in.nextInt();
        System.out.println(solve(A, B, C));
    }
    public static int solve(int A, int B, int C) {
        return Math.min(B / A, C);
    }
}
