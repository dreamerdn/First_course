package prog2;
import java.util.Scanner;
public class main {
    public static void main(String[] args) {
        System.out.print("Enter message: ");

        Scanner scanner = new Scanner(System.in);
        String message = scanner.nextLine();

        PrintHelper helper = new PrintHelper();
        helper.print(message);
    }
}
