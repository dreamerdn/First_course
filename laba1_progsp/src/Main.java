/*
По обслуживанию покупателей в магазине работает три кассы.
У каждого кассира на кассе своя средняя скорость обслуживания одного покупателя (3 мин., 2,5мин. и2,7 мин., соответственно).
 Покупатели выстраиваются в очереди к кассам таким образом, что количество покупателей в каждую кассу одинаковое.
  б) выводится количество покупателей, которое обслужат все кассиры за 60 мин. и выводится количество покупателей,
   которое обслужит каждый кассир за 60 мин.
 */

public class Main {
    public static void main(String[] args) throws InterruptedException {

        ClientsQueue clientsQueue = new ClientsQueue(1);
        Kassa kassa1 = new Kassa(false,1,300);
        Kassa kassa2 = new Kassa(false,2,250);
        Kassa kassa3 = new Kassa(false,3,270);

        ThreadClient thread1 = new ThreadClient(clientsQueue, kassa1);
        ThreadClient thread2 = new ThreadClient(clientsQueue, kassa2);
        ThreadClient thread3 = new ThreadClient(clientsQueue, kassa3);

        thread1.setName("касса 1");
        thread2.setName("касса 2");
        thread3.setName("касса 3");

        thread1.start();
        thread2.start();
        thread3.start();

        thread1.join();
        thread2.join();
        thread3.join();

        System.out.println("Всего обслужено клиентов за 60 минут: " + (thread1.getTotalcliens()+thread2.getTotalcliens() + thread3.getTotalcliens()));
        System.out.println("Количество клиентов обслуженных 1-й кассой за 60 минут: " + thread1.getTotalcliens()+
                "\nКоличество клиентов обслуженных 2-й кассой за 60 минут: "+ thread2.getTotalcliens()
                + "\nКоличество клиентов обслуженных 3-й кассой за 60 минут: "+ thread3.getTotalcliens());

    }
}
