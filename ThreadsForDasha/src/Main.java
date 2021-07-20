import logic.ThreadVisitors;
import model.VisitorsQueue;
import model.Worker;

public class Main {

    public static final int VISITORS_COUNT = 45;
    public static void main(String[] args){

        VisitorsQueue visitorsQueue = new VisitorsQueue(VISITORS_COUNT);

        Worker worker1 = new Worker(false, 1, 1000);
        Worker worker2 = new Worker(false, 2, 500);
        Worker worker3 = new Worker(false, 3, 800);

        ThreadVisitors thread1 = new ThreadVisitors(visitorsQueue, worker1);
        ThreadVisitors thread2 = new ThreadVisitors(visitorsQueue, worker2);
        ThreadVisitors thread3 = new ThreadVisitors(visitorsQueue, worker3);

        long startTime = System.currentTimeMillis();

        thread1.start();
        thread2.start();
        thread3.start();
        try {
            thread1.join();
            thread2.join();
            thread3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        long endTime = System.currentTimeMillis();
        float totalTime = (endTime - startTime) / 1000F;

        System.out.println("\nTotal execution time is: " + totalTime + " seconds");
        int thread1TotalVisitors = thread1.getTotalVisitors();
        int thread2TotalVisitors = thread2.getTotalVisitors();
        int thread3TotalVisitors = thread3.getTotalVisitors();
        System.out.println("Worker1 managed " + thread1TotalVisitors + " visitors" +
                "\nWorker2 managed " + thread2TotalVisitors + " visitors" +
                "\nWorker3 managed " + thread3TotalVisitors + " visitors" +
                verifyExecution(thread1TotalVisitors, thread2TotalVisitors, thread3TotalVisitors)
        );

    }

    private static String verifyExecution(int thread1TotalVisitors, int thread2TotalVisitors, int thread3TotalVisitors) {
        int sum = thread1TotalVisitors + thread2TotalVisitors + thread3TotalVisitors;
        return "\n------------------------" +
                "\nInitial visitors count: " + VISITORS_COUNT +
                "\nCheck-up: " + thread1TotalVisitors + "+" + thread2TotalVisitors + "+" + thread3TotalVisitors + " = " + sum;
    }
}
