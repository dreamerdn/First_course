package com.example.rsoi3;

import jakarta.persistence.*;

import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "phone100")
public class Phone {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;

    public Phone(String phoneName, String producer, int phoneMaxPrice, int phoneMinPrice, double screenSize, int rammin, int rammax, String hasSdCardSlot) {
        this.phoneName = phoneName;
        this.producer = producer;
        this.phoneMaxPrice = phoneMaxPrice;
        this.phoneMinPrice = phoneMinPrice;
        this.screenSize = screenSize;
        this.rammin = rammin;
        this.rammax = rammax;
        this.hasSdCardSlot = hasSdCardSlot;
    }
    public Phone(){

    }

    private String phoneName;
    private String producer;
    private int phoneMinPrice;
    private int phoneMaxPrice;
    private double screenSize;
    private int rammin;
    private int rammax;
    private String hasSdCardSlot;

    public void setName(String phoneName) {
        this.phoneName = phoneName;
    }
    public void setProducer(String producer) {
        this.producer = producer;
    }

    public void setMinPrice(int phoneMinPrice) {
        this.phoneMinPrice = phoneMinPrice;
    }
    public void setMaxPrice(int phoneMaxPrice) {
        this.phoneMaxPrice = phoneMaxPrice;
    }

    public void setScreenSize(double screenSize) {
        this.screenSize = screenSize;
    }

    public void setRammin(int rammin) {
        this.rammin = rammin;
    }
    public void setRammax(int rammax) {
        this.rammax = rammax;
    }

    public void setHasSdCardSlot(String hasSdCardSlot) {
        this.hasSdCardSlot = hasSdCardSlot;
    }


    public String getPhoneName(){
        return phoneName;
    }
    public String getProducer(){
        return producer;
    }
    public int getMinPrice() {
        return phoneMinPrice;
    }

    public int getMaxPrice() {
        return phoneMaxPrice;
    }

    public double getScreenSize() {
        return screenSize;
    }

    public int getRammin() {
        return rammin;
    }
    public int getRammax() {
        return rammax;
    }

    public String getHasSdCardSlot() {
        return hasSdCardSlot;
    }
}

