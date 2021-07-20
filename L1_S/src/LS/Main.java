package LS;
public class Main {

    static Thread t1, t2, t3, t4, t5, t6, t7, t8, t9, t10;
    static Taxi car1, car2, car3, car4, car5, car6, car7, car8, car9, car10;
    static int allClients;

    public static void main(String[] args) throws InterruptedException {
        car1 = new Taxi("The first taxi");
        car2 = new Taxi("The second taxi");
        car3 = new Taxi("The third taxi");
        car4 = new Taxi("The fourth taxi");
        car5 = new Taxi("The fifth taxi");
        car6 = new Taxi("The sixth taxi");
        car7 = new Taxi("The seventh taxi");
        car8 = new Taxi("The eighth taxi");
        car9 = new Taxi("The ninth taxi");
        car10 = new Taxi("The tenth taxi");

        t1 = new Thread (car1);
        t2 = new Thread (car2);
        t3 = new Thread (car3);
        t4 = new Thread (car4);
        t5 = new Thread (car5);
        t6 = new Thread (car6);
        t7 = new Thread (car7);
        t8 = new Thread (car8);
        t9 = new Thread (car9);
        t10 = new Thread (car10);

        System.out.println("Taxies have started working!");

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        t6.start();
        t7.start();
        t8.start();
        t9.start();
        t10.start();
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();
        t8.join();
        t9.join();
        t10.join();
        System.out.println("allClients are " + allClients);
        System.out.println("The first taxi has lifted " + (firstTaxi.firstTaxi() - 1 ));
    }

}