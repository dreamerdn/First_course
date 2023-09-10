package com.example.rsoi3;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;
import java.sql.*;
@SpringBootApplication
public class SpringBootConsoleApplication {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(SpringBootConsoleApplication.class, args);
        PhoneService phoneService = context.getBean(PhoneService.class);
        boolean n = true;
        Scanner scanner = new Scanner(System.in);

        while (n) {
            System.out.println("1 - Add");
            System.out.println("2 - Delete");
            System.out.println("3 - Enter phone settings");
            System.out.println("4 - Exit");
            String action = scanner.next().toLowerCase();
            switch (action) {
                case "1":
                    Phone phone = new Phone();
                    System.out.print("Enter phone name: ");
                    scanner.nextLine();
                    phone.setName(scanner.nextLine());
                    System.out.print("Enter producer name: ");
                    phone.setProducer(scanner.nextLine());
                    System.out.print("Enter minimum price: ");
                    phone.setMinPrice(scanner.nextInt());
                    System.out.print("Enter maximum price: ");
                    phone.setMaxPrice(scanner.nextInt());;
                    System.out.print("Enter screen size: ");
                    phone.setScreenSize(scanner.nextDouble());
                    System.out.print("Enter amount of RAMmin: ");
                    phone.setRammin(scanner.nextInt());
                    System.out.print("Enter amount of RAMmax: ");
                    phone.setRammax(scanner.nextInt());
                    System.out.print("Is there an SD-card slot (true/false): ");
                    scanner.nextLine();
                    phone.setHasSdCardSlot(scanner.nextLine());
                    phoneService.addPhone(phone);
                    System.out.println("Phone has been successfully added to the list.");
                    System.out.println(phone.getPhoneName());
                    break;

                case "2":
                    System.out.println("Введите id телефона, который нужно удалить:");
                    Long phoneId = scanner.nextLong();
                    scanner.nextLine();
                    phoneService.deletePhone(phoneId);
                    break;

                case "3":
                    String url = "jdbc:mysql://localhost:3306/phonecreator";
                    String user = "root";
                    String password = "new_password";
                    List <Phone> allPhones = new ArrayList<>();
                    try{
                        Connection connection = DriverManager.getConnection(url, user, password);
                        Statement statement = connection.createStatement();
                        ResultSet resultSet = statement.executeQuery("SELECT * FROM phone1");
                        while (resultSet.next()) {
                            int id = resultSet.getInt("id");
                            System.out.println(id);
                            String name = resultSet.getString("phone_name");
                            System.out.println(name);
                            String producer = resultSet.getString("producer");
                            System.out.println(producer);
                            int min = resultSet.getInt("phone_min_price");
                            System.out.println(min);
                            int max = resultSet.getInt("phone_max_price");
                            System.out.println(max);
                            Double screen = resultSet.getDouble("screen_size");
                            System.out.println(screen);
                            int phone_rammin = resultSet.getInt("rammin");
                            System.out.println(phone_rammin);
                            int phone_rammax = resultSet.getInt("rammax");
                            System.out.println(phone_rammax);
                            String card = resultSet.getString("has_sd_card_slot");
                            System.out.println(card);

                            //Phone allPhone = new Phone(name, max, min, screen, phone_ram, card);
                            allPhones.add(new Phone(name, producer, max, min, screen, phone_rammin, phone_rammax, card));
                        }
                        System.out.println("Enter phone settings");
                        // Read the criteria from the user
                        System.out.print("Enter minimum price: ");
                        int minPrice = scanner.nextInt();
                        System.out.print("Enter maximum price: ");
                        int maxPrice = scanner.nextInt();
                        System.out.print("Enter minimum screen size: ");
                        double minScreenSize = scanner.nextDouble();
                        System.out.print("Enter the minimum amount of minRAM: ");
                        int minRam = scanner.nextInt();
                        System.out.print("Enter the minimum amount of maxRAM: ");
                        int maxRam = scanner.nextInt();
                        System.out.print("Is there an SD-card slot (true/false): ");
                        scanner.nextLine();
                        String hasSdCardSlot = scanner.nextLine();

                        List <Phone> matchingPhones = new ArrayList<>();
                        for (Phone phone_ : allPhones) {
                        if (phone_.getMinPrice() <= minPrice
                                && phone_.getMaxPrice() <= maxPrice
                                && phone_.getScreenSize() >= minScreenSize
                                && phone_.getRammin() >= minRam
                                && phone_.getRammax() >= maxRam
                                && Objects.equals(phone_.getHasSdCardSlot(), hasSdCardSlot)) {
                            matchingPhones.add(phone_);
                        }
                    }

                        if (matchingPhones.isEmpty()) {
                        System.out.println("No matching phones found.");
                    } else {
                        System.out.println("Found the following matching phones:");
                        for (Phone phone_ : matchingPhones) {
                            System.out.println(phone_.getPhoneName() + ": " + phone_.getMinPrice()+ "| " + phone_.getMaxPrice()+ "| " + phone_.getHasSdCardSlot()+ "| " + phone_.getRammin()+ "| " + "| " + phone_.getRammax()+ "| "+ phone_.getScreenSize());
                        }
                    }
                    break;

                    }
                    catch (Exception e){
                        System.out.println(e.getMessage());
                    }

                case "4":
                    n = false;

            }
        }
    }
}