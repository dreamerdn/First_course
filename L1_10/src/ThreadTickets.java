import java.util.concurrent.locks.ReentrantLock;

public class ThreadTickets extends Thread {
    private TicketsQueue ticketsQueue;
    private Cashbox cashbox;
    private ReentrantLock locker = new ReentrantLock();

    private int totalvisitors = 0;

    public ThreadTickets (TicketsQueue ticketsQueue, Cashbox cashbox) {
        this.ticketsQueue = ticketsQueue;
        this.cashbox = cashbox;
    }

    public int getTotalvisitors() {
        return totalvisitors;
    }

    @Override
    public String toString() {
        return "ThreadVisitors{" + "worker=" + cashbox.getNumb() + '}';
    }

    @Override
    public void run() {
        while (true) {
            locker.lock();
            long executionTime = cashbox.getMin();
            try {
                cashbox.setBusy(true);
                Thread.sleep(executionTime);
                cashbox.setBusy(false);
                int queueCount = ticketsQueue.getCnt();
                if (queueCount > 0) {
                    totalvisitors++;
                    System.out.println(this + " clients number is: " + queueCount);
                    ticketsQueue.setCnt(queueCount - 1);
                } else break;
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                locker.unlock();
            }
        }
    }
}
