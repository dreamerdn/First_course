import java.util.concurrent.locks.ReentrantLock;

public class ThreadContainer extends Thread {
        private ContQueue contQueue;
        private Ship ship;
        private ReentrantLock locker = new ReentrantLock();

        private int totalvisitors = 0;

    public ThreadContainer(ContQueue contQueue, Ship ship) {
            this.contQueue = contQueue;
            this.ship = ship;
        }

        public int getTotalvisitors() {
            return totalvisitors;
        }

        @Override
        public String toString() {
            return "ThreadVisitors{" + "worker=" + ship.getNumb() + '}';
        }

        @Override
        public void run() {
            while (true) {
                locker.lock();
                long executionTime = ship.getMin();
                int threadk = ship.getK();
                try {
                    ship.setBusy(true);
                    Thread.sleep(executionTime);
                    ship.setBusy(false);
                    int queueCount = contQueue.getCnt();
                    if (queueCount > 0) {
                        totalvisitors+=threadk;
                        System.out.println(this + " clients number is: " + queueCount);
                        contQueue.setCnt(queueCount - threadk);
                    } else
                        break;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    locker.unlock();
                }
            }
        }
}
