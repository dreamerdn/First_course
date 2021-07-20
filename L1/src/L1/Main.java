package L1;

public class Main {
    public static void main(String[] args) throws InterruptedException{
        ClientsQueue clientsQueue = new ClientsQueue(100);
        Registrar registrar1=new Registrar(false, 1, 200);
        Registrar registrar2=new Registrar(false, 2, 150);

        ThreadClient mythread1 = new ThreadClient(clientsQueue, registrar1);
        ThreadClient mythread2 = new ThreadClient(clientsQueue, registrar2);


        long startedtime=System.currentTimeMillis();// устанавливаем счетчик времени
        mythread1.start();//запускает выполнение потока
        mythread2.start();

        mythread1.join();//ожидает завершение потока
        mythread2.join();


        long endedtime=System.currentTimeMillis();
        long totaltime=endedtime-startedtime;

        System.out.println("Общее время:" + totaltime/100 + " мин");
        System.out.println("Количество талонов, выданных первым регистратором:" + mythread1.getTotalclients());
        System.out.println("Количество талонов, выданных вторым регистратором:" + mythread2.getTotalclients());
    }
}


