package L1_11;

//создание доп потоков
public class ThreadVisitors extends Thread {
    int totalvisitors=0;
    VisitorsQueue visitorsQueue;
    Workers workers;
    public ThreadVisitors(VisitorsQueue visitorsQueue, Workers workers) {
        this.visitorsQueue=visitorsQueue;
        this.workers=workers;
    }
    public int getTotalvisitors() {
        return totalvisitors;
    }
    @Override
    public String toString() {
        return "ThreadVisitirs{" + "worker=" + workers.getNumb() + '}';
    }
    @Override
    public void run() {
        while(visitorsQueue.getCnt()>1) {

            synchronized (workers) {
                try {
                    this.sleep(workers.getMin());
                    if(!visitorsQueue.getBusy()){
                        visitorsQueue.setBusy(true);
                        System.out.println(this.toString()+ " clients number is: "+visitorsQueue.getCnt());
                        visitorsQueue.setCnt(visitorsQueue.getCnt() - 1);
                        visitorsQueue.setBusy(false);
                        totalvisitors++;
                    }

                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

}

