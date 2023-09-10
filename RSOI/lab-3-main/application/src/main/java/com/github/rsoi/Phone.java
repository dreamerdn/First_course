package com.github.rsoi;

import jakarta.persistence.*;

import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "phone_")
public class Phone {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;

    private String name;

  /*  public Phone(String name, PriceRange priceRange, double screenSize, int ram, boolean hasSdCardSlot) {
        this.name = name;
        this.priceRange = priceRange;
        this.screenSize = screenSize;
        this.ram = ram;
        this.hasSdCardSlot = hasSdCardSlot;
    }*/
    private double screenSize;

    private int ram;

    private boolean hasSdCardSlot;


    public Phone() {
    }

    public String getName() {
        return name;
    }
    public void setName(String phoneName) {
    }

    public void setMinPrice(int phoneMinPrice) {
    }
    public void setMaxPrice(int phoneMaxPrice) {
    }

    public void setScreenSize(double phoneScreenSize) {
    }

    public void setRam(int phoneRamSize) {
    }

    public void setHasSdCardSlot(boolean phoneHasSdCardSlot) {
    }


    public double getScreenSize() {
        return screenSize;
    }

    public int getRam() {
        return ram;
    }

    public boolean hasSdCardSlot() {
        return false;
    }

}

