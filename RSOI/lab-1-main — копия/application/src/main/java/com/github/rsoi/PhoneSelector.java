package com.github.rsoi;




import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PhoneSelector {
    public static void main(String[] args) {
        boolean n=true;
        Scanner scanner = new Scanner(System.in);
        List<Phone> phones = new ArrayList<>();
        phones.add(new Phone("Apple", new PriceRange(500, 1000), 7, 9, true));
        phones.add(new Phone("Samsung", new PriceRange(200, 590), 6, 6, true));
        phones.add(new Phone("Xiaomi", new PriceRange(100, 400), 9, 9, false));
        phones.add(new Phone("Lenovo", new PriceRange(370, 900), 6, 8, true));
        while (n) {

            System.out.println("1 - Add_Phone");
            System.out.println("2 - Delete_Phone");
            System.out.println("3 - Enter Phone settings");
            System.out.println("4 - Exit");
            String action = scanner.next().toLowerCase();
            switch (action) {
                case "1":
                    System.out.print("Enter phone name: ");
                    String phoneName = scanner.next();
                    System.out.print("Enter min price: ");
                    int phoneMinPrice = scanner.nextInt();
                    System.out.print("Enter max price: ");
                    int phoneMaxPrice = scanner.nextInt();
                    System.out.print("Enter screen size: ");
                    double phoneScreenSize = scanner.nextDouble();
                    System.out.print("Enter memory: ");
                    int phoneRamSize = scanner.nextInt();
                    System.out.print("Is there an SDcard (true/false): ");
                    boolean phoneHasSdCardSlot = scanner.nextBoolean();
                    Phone newPhone = new Phone(phoneName, new PriceRange(phoneMinPrice, phoneMaxPrice), phoneScreenSize, phoneRamSize, phoneHasSdCardSlot);
                    phones.add(newPhone);
                    System.out.println("Phone " + phoneName + " has been successfully added to the list.");
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
                    System.out.print("Enter min price: ");
                    int minPrice = scanner.nextInt();
                    System.out.print("Enter max price: ");
                    int maxPrice = scanner.nextInt();
                    System.out.print("Enter min screen size: ");
                    double minScreenSize = scanner.nextDouble();
                    System.out.print("Enter memory: ");
                    int minRam = scanner.nextInt();
                    System.out.print("Is there an SDcard (true/false): ");
                    boolean hasSdCardSlot = scanner.nextBoolean();


                    List<Phone> matchingPhones = new ArrayList<>();
                    for (Phone phone : phones) {
                        if (phone.getPriceRange().intersects(new PriceRange(minPrice, maxPrice))
                                && phone.getScreenSize() >= minScreenSize
                                && phone.getRam() >= minRam
                                && phone.hasSdCardSlot() == hasSdCardSlot) {
                            matchingPhones.add(phone);
                        }
                    }

                    if (matchingPhones.isEmpty()) {
                        System.out.println("No phones found.");
                    } else {
                        System.out.println("Found the following phones:");
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