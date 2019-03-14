import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int M = in.nextInt();
        int A[] = new int[M];
        int B[] = new int[M];
        for (int i = 0; i < M; i++) {
            A[i] = in.nextInt();
            B[i] = in.nextInt();
        }
        System.out.println(solve(N, M, A, B));
    }
    public static String solve(int N, int M, int[] A, int[] B) {
    }
    public static class Graph {

    }
    public static ArrayList<Integer> bfs(int start, Graph g) {

    }
}
