package L1_0;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        ClientsQueue clientsQueue = new ClientsQueue(21);
        Kassa kassa1 = new Kassa(false, 1, 2000);
        Kassa kassa2 = new Kassa(false, 2, 300);
        Kassa kassa3 = new Kassa(false, 3, 800);
        Kassa kassa4 = new Kassa(false, 4, 100);
        ThreadClient mythread1 = new ThreadClient(clientsQueue, kassa1);
        ThreadClient mythread2 = new ThreadClient(clientsQueue, kassa2);
        ThreadClient mythread3 = new ThreadClient(clientsQueue, kassa3);
        ThreadClient mythread4 = new ThreadClient(clientsQueue, kassa4);
        long startedtime = System.currentTimeMillis();
        mythread1.start();
        mythread2.start();
        mythread3.start();
        mythread4.start();
        mythread1.join();
        mythread2.join();
        mythread3.join();
        mythread4.join();
        long endedtime = System.currentTimeMillis();
        long totaltime = endedtime - startedtime;
        System.out.println("Total time is: " + totaltime);
        System.out.println("total clients of kassa 1 " + mythread1.getTotalcliens() +
                "\ntotal clients of kassa 2 " + mythread2.getTotalcliens() +
                "\ntotal clients of kassa 3 " + mythread3.getTotalcliens() +
                "\ntotal clients of kassa 4 " + mythread4.getTotalcliens());
    }
}
