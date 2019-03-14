import java.util.Scanner
import scala.collection.mutable.ArrayBuffer

object Main {
  def main(args: Array[String]): Unit = {
    val s = new Scanner(System.in)
    val n = s.nextInt()
    val m = s.nextInt()
    val c = s.nextInt()
    val bs = ArrayBuffer[Int]()
    (0 until m).foreach { _ =>
      bs += s.nextInt()
    }
    var res = 0
    (0 until n).foreach { _ =>
      val as = ArrayBuffer[Int]()
      (0 until m).foreach { _ =>
        as += s.nextInt()
      }
      if ((as zip bs).map(t => t._1 * t._2).sum + c > 0) {
        res += 1
      }
    }
    println(res)
  }
}
