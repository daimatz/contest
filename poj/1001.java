import java.util.*;

class Main {
  public static void main(String[] args) {
    for (Scanner i = new Scanner(System.in);
         i.hasNext();) {
      System.out.println(i.nextBigDecimal().pow(i.nextInt()).toPlainString().replaceAll("^0|\\.?0*$", ""));
    }
  }
}
