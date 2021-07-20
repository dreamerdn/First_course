package FUCK;

public class ConsoleWriter {
    public void write(String[] args) {
        for(String line : args) {
            System.out.println("Command line param - " + line);
        }
    }

}
