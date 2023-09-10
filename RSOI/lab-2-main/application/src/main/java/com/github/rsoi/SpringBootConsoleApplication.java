package com.github.rsoi;

import com.github.rsoi.service.Greeter;
import com.github.rsoi.domain.PriceRange;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


@SpringBootApplication //объединяет несколько других аннотаций и готовит приложение для запуска
public class SpringBootConsoleApplication implements CommandLineRunner {
    private final Greeter greeter;

    @Autowired //позволяет автоматически связывать зависимости между классами в приложении
    public SpringBootConsoleApplication(Greeter greeter) {
        this.greeter = greeter;
    }

    public static void main(String[] args) {
        SpringApplication.run(SpringBootConsoleApplication.class, args);
	}

    @Override //указывает компилятору, что метод в подклассе является переопределением метода в его суперклассе
    public void run(String... args) {
        greeter.sayHello();

        boolean n=true;
        Scanner scanner = new Scanner(System.in);

        // Create a list of available phones
        List<Phone> phones = new ArrayList<>();
        phones.add(new Phone("Phone_A", new PriceRange(100, 200), 5.5, 4, true));
        phones.add(new Phone("Phone_B", new PriceRange(150, 300), 6.1, 6, true));
        phones.add(new Phone("Phone_C", new PriceRange(200, 400), 6.4, 8, false));
        phones.add(new Phone("Phone_D", new PriceRange(250, 500), 6.0, 8, true));


        // Process the user's request to add or remove a phone
        while (n) {
            // Ask the user if they want to add or remove a phone
            // System.out.println("Do you want to add or remove a phone?");
            System.out.println("1 - Add");
            System.out.println("2 - Delete");
            System.out.println("3 - Enter phone settings");
            System.out.println("4 - Exit");
            String action = scanner.next().toLowerCase();
            switch (action) {
                case "1":
                    System.out.print("Enter phone name: ");
                    String phoneName = scanner.next();
                    System.out.print("Enter minimum price: ");
                    int phoneMinPrice = scanner.nextInt();
                    System.out.print("Enter maximum price: ");
                    int phoneMaxPrice = scanner.nextInt();
                    System.out.print("Enter screen size: ");
                    double phoneScreenSize = scanner.nextDouble();
                    System.out.print("Enter amount of RAM: ");
                    int phoneRamSize = scanner.nextInt();
                    System.out.print("Is there an SD-card slot (true/false): ");
                    boolean phoneHasSdCardSlot = scanner.nextBoolean();
                    if(phoneMinPrice>0 && phoneMaxPrice > phoneMinPrice){
                        Phone newPhone = new Phone(phoneName, new PriceRange(phoneMinPrice, phoneMaxPrice), phoneScreenSize, phoneRamSize, phoneHasSdCardSlot);
                        phones.add(newPhone);
                        System.out.println("Phone " + phoneName + " has been successfully added to the list.");
                        break;
                    }
                    else  System.out.println("Phone didn't added");
                    break;

                case "2":
                    System.out.print("Enter the name of the phone to be removed: ");
                    String phoneName1 = scanner.next();
                    boolean removed = false;
                    for (int i = 0; i < phones.size(); i++) {
                        if (phones.get(i).getName().equals(phoneName1)) {
                            phones.remove(i);
                            removed = true;
                            System.out.println("Phone deleted successfully: " + phoneName1);
                            break;
                        }
                    }
                    if (!removed) {
                        System.out.println("Phone not found: " + phoneName1);
                    }
                    break;

                case "3":
                    System.out.println("Enter phone settings");
                    // Read the criteria from the user
                    System.out.print("Enter minimum price: ");
                    int minPrice = scanner.nextInt();
                    System.out.print("Enter maximum price: ");
                    int maxPrice = scanner.nextInt();
                    System.out.print("Enter minimum screen size: ");
                    double minScreenSize = scanner.nextDouble();
                    System.out.print("Enter the minimum amount of RAM: ");
                    int minRam = scanner.nextInt();
                    System.out.print("Is there an SD-card slot (true/false): ");
                    boolean hasSdCardSlot = scanner.nextBoolean();

                    // Select suitable phones
                    List<Phone> matchingPhones = new ArrayList<>();
                    for (Phone phone : phones) {
                        if (phone.getPriceRange().intersects(new PriceRange(minPrice, maxPrice))
                                && phone.getScreenSize() >= minScreenSize
                                && phone.getRam() >= minRam
                                && phone.hasSdCardSlot() == hasSdCardSlot) {
                            matchingPhones.add(phone);
                        }
                    }

                    // Display search results
                    if (matchingPhones.isEmpty()) {
                        System.out.println("No matching phones found.");
                    } else {
                        System.out.println("Found the following matching phones:");
                        for (Phone phone : matchingPhones) {
                            System.out.println(phone.getName() + ": " + phone.toString());
                        }
                    }
                    break;

                case "4":
                    n = false;

            }
        }

    }

}
