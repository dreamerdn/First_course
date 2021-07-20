package L1_11_;

import java.util.concurrent.locks.ReentrantLock;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        VisitorsQueue visitorsQueue = new VisitorsQueue(450);

        Workers workers1 = new Workers(false, 1, 100);
        Workers workers2 = new Workers(false, 2, 50);
        Workers workers3 = new Workers(false, 3, 80);


        ThreadVisitors thread1 = new ThreadVisitors(visitorsQueue, workers1);
        ThreadVisitors thread2 = new ThreadVisitors(visitorsQueue, workers2);
        ThreadVisitors thread3 = new ThreadVisitors(visitorsQueue, workers3);

        long startedtime = System.currentTimeMillis();

        thread1.start();
        thread2.start();
        thread3.start();

        thread1.join();
        thread2.join();
        thread3.join();

        long endedtime = System.currentTimeMillis();
        long totaltime = endedtime - startedtime;

        System.out.println("Total time is: " + totaltime);
        System.out.println("total visitors of worker 1 " + thread1.getTotalvisitors() +
                "\ntotal visitors of worker 2 " + thread2.getTotalvisitors()
                + "\ntotal visitors of worker 3 " + thread3.getTotalvisitors()
        );

    }
}
