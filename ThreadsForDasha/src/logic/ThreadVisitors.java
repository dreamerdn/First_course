package logic;

import model.VisitorsQueue;
import model.Worker;

import java.util.concurrent.locks.ReentrantLock;

public class ThreadVisitors extends Thread {
    final Worker worker;
    final VisitorsQueue visitorsQueue;
    final ReentrantLock lock = new ReentrantLock();

    private int totalVisitors = 0;

    public ThreadVisitors(VisitorsQueue visitorsQueue, Worker worker) {
        this.visitorsQueue = visitorsQueue;
        this.worker = worker;
    }

    public int getTotalVisitors() {
        return totalVisitors;
    }

    @Override
    public String toString() {
        return "ThreadVisitors{" + "worker=" + worker.getNumb() + '}';
    }

    @Override
    @SuppressWarnings("BusyWait")
    public void run() {
        while (true) {
            lock.lock();
            long executionTime = worker.getExecutionTime();
            try {
                worker.setBusy(true);
                Thread.sleep(executionTime);
                worker.setBusy(false);
                int queueCount = visitorsQueue.getCount();
                if (queueCount > 0) {
                    totalVisitors++;
                    System.out.println(this + " clients number is: " + queueCount + "; execution time(ms) is: " + executionTime);
                    visitorsQueue.setCount(queueCount - 1);
                } else break;
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
        }
    }
}
