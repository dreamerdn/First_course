package L1_0;

public class ThreadClient extends Thread {
    int totalcliens=0;
    ClientsQueue clientsQueue;
    Kassa kassa;
    public ThreadClient(ClientsQueue clientsQueue,Kassa kassa) {
        this.clientsQueue=clientsQueue;
        this.kassa=kassa;
    }
    public int getTotalcliens() {
        return totalcliens;
    }
    @Override
    public String toString() {
        return "ThreadClient{" + "kassa=" + kassa.getNumber() + '}';
    }
    @Override
    public void run() {
        while(clientsQueue.getSize()>0) {
            System.out.println(this.toString()+ " clients number is: "+clientsQueue.getSize());
            clientsQueue.setSize(clientsQueue.getSize() - 1);
            synchronized (kassa) {
                try {
                    kassa.setOcupied(true);
                    this.sleep(kassa.getMinutes());
                    kassa.setOcupied(false);
                    totalcliens++;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
