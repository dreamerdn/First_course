import java.util.concurrent.locks.ReentrantLock;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        TicketsQueue ticketsQueue = new TicketsQueue(250);

        Cashbox cashbox1 = new Cashbox(false, 1, 250);
        Cashbox cashbox2 = new Cashbox(false, 2, 220);
        Cashbox cashbox3 = new Cashbox(false, 3, 190);

        ThreadTickets thread1 = new ThreadTickets(ticketsQueue, cashbox1);
        ThreadTickets thread2 = new ThreadTickets(ticketsQueue, cashbox2);
        ThreadTickets thread3 = new ThreadTickets(ticketsQueue, cashbox3);

        long startedtime = System.currentTimeMillis();

        thread1.start();
        thread2.start();
        thread3.start();

        thread1.join();
        thread2.join();
        thread3.join();

        long endedtime = System.currentTimeMillis();
        long totaltime = endedtime - startedtime;

        System.out.println("Total time is: " + totaltime/100);
        System.out.println("total visitors of worker 1 " + thread1.getTotalvisitors() +
                "\ntotal visitors of worker 2 " + thread2.getTotalvisitors()
                + "\ntotal visitors of worker 3 " + thread3.getTotalvisitors()
        );

    }
}
