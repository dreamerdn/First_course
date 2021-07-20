public class ThreadWorker extends Thread {
    int totalContainers;
    int totalTimeOfWork;
    Containers containers;
    Worker worker;

    public ThreadWorker(Containers containers, Worker worker) {
        this.containers = containers;
        this.worker = worker;
    }

    public int getTotalContainers() {
        return totalContainers;
    }

    public long getTotalTimeOfWork() {
        return totalTimeOfWork;
    }
    @Override
    public String toString(){
        return "ThreadWorker(" + "worker is working)";
    }

    @Override
    public void run() {
        while (containers.getCount() > 0) {
            System.out.println(this.toString() + "container count is:" + containers.getCount());
            containers.setCount(containers.getCount() - worker.getNumber());
            this.totalTimeOfWork += worker.getMinutesOfWork();
            synchronized (worker) {
                try {
                    worker.setWorking(true);
                    this.sleep(worker.getMinutesOfWork());
                    worker.setWorking(false);
                    totalContainers += worker.getNumber();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

            }
        }
    }
}
