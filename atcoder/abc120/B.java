import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println(solve(in.nextInt(), in.nextInt(), in.nextInt()));
    }
    public static int solve(int A, int B, int K) {
        int c = 0;
        for (int i = Math.max(A, B); ; i--) {
            if (A % i == 0 && B % i == 0) {
                if (++c == K) {
                    return i;
                }
            }
        }
    }
}
