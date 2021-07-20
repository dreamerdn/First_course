package L1_11_;

import java.util.concurrent.locks.ReentrantLock;

public class ThreadVisitors extends Thread {
    private VisitorsQueue visitorsQueue;
    private Workers workers;
    private ReentrantLock locker = new ReentrantLock();

    private int totalvisitors = 0;

    public ThreadVisitors(VisitorsQueue visitorsQueue, Workers workers) {
        this.visitorsQueue = visitorsQueue;
        this.workers = workers;
    }

    public int getTotalvisitors() {
        return totalvisitors;
    }

    @Override
    public String toString() {
        return "ThreadVisitors{" + "worker=" + workers.getNumb() + '}';
    }

    @Override
    public void run() {
        while (true) {
            locker.lock();
            long executionTime = workers.getMin();
            try {
                workers.setBusy(true);
                Thread.sleep(executionTime);
                workers.setBusy(false);
                int queueCount = visitorsQueue.getCnt();
                if (queueCount > 0) {
                    totalvisitors++;
                    System.out.println(this + " clients number is: " + queueCount);
                    visitorsQueue.setCnt(queueCount - 1);
                } else break;
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                locker.unlock();
            }
        }
    }
}
