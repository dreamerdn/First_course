package L1;

import java.util.concurrent.locks.ReentrantLock;

public class ThreadClient extends Thread{//создание второго потока
    int totalclients;
    ClientsQueue clientsQueue;
    Registrar registrar;
    private ReentrantLock locker = new ReentrantLock();

    public ThreadClient(ClientsQueue clientsQueue, Registrar registrar){
        this.clientsQueue=clientsQueue;
        this.registrar=registrar;
    }
    public int getTotalclients(){
        return totalclients;
    }
    @Override
    public String toString(){
        return "ThreadClient(" + "Регистратор="+ registrar.getNumber() +") ";
    }
    @Override
    public void run() {
        while (true) {
            locker.lock();
                try {
                    registrar.setOccupied(true);
                    Thread.sleep(registrar.getMinutes());// приостановка одного из потоков для того, чтобы обратиться к другому
                    registrar.setOccupied(false);
                    if(clientsQueue.getSize()>0){
                        totalclients++;
                        System.out.println(this + " clients number is: " + clientsQueue.getSize());
                        clientsQueue.setSize(clientsQueue.getSize()-1);
                    }else break;
                } catch (InterruptedException e) {
                    e.printStackTrace();//показывает, какое исключение и в какой части кода произошло
                }
                finally {
                    locker.unlock();
                }
            }
        }
    }
