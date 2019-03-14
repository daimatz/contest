import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println(solve(in.nextLine()));
    }
    public static int solve(String S) {
        return Math.min(count(S, "0"), count(S, "1")) * 2;
    }
    public static int count(String s, String sub) {
        int res = 0;
        String cur = new String(s);
        while (true) {
            int pos = cur.indexOf(sub);
            if (pos == -1) {
                return res;
            }
            res++;
            cur = cur.substring(pos + sub.length());
        }
    }
}
