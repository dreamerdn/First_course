package FUCK;

import FUCK.ConsoleWriter;
    public class Main {

        public static void main(String[] args) {
            System.out.println("Here we go, give me your params, baby:\n");
            ConsoleWriter writer = new ConsoleWriter();
            writer.write(args);
        }
    }