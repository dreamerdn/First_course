public class ThreadClient extends Thread{

    private int totalcliens = 0;
    private ClientsQueue clientsQueue;
    private Kassa kassa;
    private ThreadClient thread;

    public ThreadClient(ClientsQueue clientsQueue, Kassa kassa) {
        this.clientsQueue=clientsQueue;
        this.kassa = kassa;
    }

    public int getTotalcliens() {
        return totalcliens;
    }


    @Override
    public String toString() {
        return currentThread().getName();
    }

    @Override
    public void run() {
        long startedtime = System.currentTimeMillis();
        while (true) {

            synchronized (clientsQueue) {
                if(!kassa.isOcupied()) {
                    System.out.println(currentThread().getName() + " обслуживает " + (clientsQueue.getSize()) + "-го клиента");
                    clientsQueue.setSize(clientsQueue.getSize() + 1);
                    kassa.setOcupied(true);
                    totalcliens++;
                }
            }

            try {
                this.sleep(kassa.getMinutes());
                kassa.setOcupied(false);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            if((System.currentTimeMillis() - startedtime) > 6000){
                break;
            }
        }
    }
}