package LS;

import java.util.Random;

public class Taxi implements Runnable {
    public int workTime;

    public int commonTime;

    String name;

    public Taxi(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    @Override
    public void run() {

        int i = 0;
        Random rnd = new Random();


        while (commonTime < 390) {
            while (workTime < 180) {
                int time = rnd.nextInt(31 - 5); //сделать синхронизированный метод определения времени доставки
// System.out.println("The speed of " + getName() + " is " + time);
                workTime += time;

                try {
                    Thread.sleep(time * 10);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                i++;

                System.out.println(getName() + " has lifted " + i + " passenger");

                if (getName() == "The first taxi" && commonTime <= 360)
// firstTaxi.firstTaxi();
                    System.out.println("The first taxi has lifted " + firstTaxi.firstTaxi());
            }

            try {
                Thread.sleep(15 * 100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            commonTime += workTime + 15;

            workTime = 0;
        }

        if (commonTime >= 390 && commonTime < 420) {
            while (workTime <= 30) {
                int time = rnd.nextInt(31 - 5);
// System.out.println("The speed of " + getName() + " is " + time);
                if (commonTime + time <= 420) {
                    workTime += time;

                    try {
                        Thread.sleep(time * 10);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    i++;
                    System.out.println(getName() + " has lifted " + i + " passenger");

                    if (getName() == "The first taxi" && commonTime <= 360)
// firstTaxi.firstTaxi();
                        System.out.println("The first taxi has lifted " + firstTaxi.firstTaxi());
                }
            }
            commonTime += workTime;

        }

        Main.allClients += i;

    }
}
