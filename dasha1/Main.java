public class Main {
    public static void main(String[] args) throws InterruptedException{

        Containers count = new Containers(250);

        Worker worker1=new Worker(false, 120, 17);
        Worker worker2=new Worker(false, 150, 17);
        Worker worker3=new Worker(false, 168, 16);

        ThreadWorker threadWorker1 = new ThreadWorker(count, worker1);
        ThreadWorker threadWorker2 = new ThreadWorker(count, worker2);
        ThreadWorker threadWorker3 = new ThreadWorker(count, worker3);

        threadWorker1.run();
        threadWorker2.run();
        threadWorker3.run();

        threadWorker1.join();
        threadWorker2.join();
        threadWorker3.join();

        int totaltime;
        totaltime = (int)(threadWorker1.getTotalTimeOfWork() + threadWorker2.getTotalTimeOfWork() + threadWorker3.getTotalTimeOfWork());

        System.out.println("total time is:" + totaltime);
        System.out.println("total containers of worker 1:" + threadWorker1.getTotalContainers());
        System.out.println("total containers of worker 2:" + threadWorker2.getTotalContainers());
        System.out.println("total containers of worker 3:" + threadWorker3.getTotalContainers());
    }
}
