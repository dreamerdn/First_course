import java.util.concurrent.locks.ReentrantLock;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        ContQueue contQueue = new ContQueue(300);

        Ship workers1 = new Ship(false, 1, 700,15);//70 мин
        Ship workers2 = new Ship(false, 2, 680,14);//68 мин
        Ship workers3 = new Ship(false, 3, 660,13);//66 мин
        Ship workers4 = new Ship(false, 4, 600,10);//60 мин

        ThreadContainer thread1 = new ThreadContainer(contQueue, workers1);
        ThreadContainer thread2 = new ThreadContainer(contQueue, workers2);
        ThreadContainer thread3 = new ThreadContainer(contQueue, workers3);
        ThreadContainer thread4 = new ThreadContainer(contQueue, workers4);

        long startedtime = System.currentTimeMillis();

        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();

        thread1.join();
        thread2.join();
        thread3.join();
        thread4.join();

        long endedtime = System.currentTimeMillis();
        long totaltime = endedtime - startedtime;

        System.out.println("Total time is: " + totaltime);
        System.out.println("total visitors of worker 1 " + thread1.getTotalvisitors() +
                "\ntotal visitors of worker 2 " + thread2.getTotalvisitors()
                + "\ntotal visitors of worker 3 " + thread3.getTotalvisitors()
                + "\ntotal visitors of worker 4 " + thread4.getTotalvisitors()
        );

    }
}
