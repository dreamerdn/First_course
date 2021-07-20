package prog1;
public class main {
    public static void main(String[] args) {
        MyPrinter printer = new MyPrinter();
        String message = String.join(" ", args);
        printer.print(message);
    }
}
