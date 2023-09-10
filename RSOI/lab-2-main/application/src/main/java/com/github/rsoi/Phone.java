package com.github.rsoi;

import com.github.rsoi.domain.PriceRange;


public class Phone {
    private final String name;
    private final PriceRange priceRange;
    private final double screenSize;
    private final int ram;
    private final boolean hasSdCardSlot;

    public Phone(String name, PriceRange priceRange, double screenSize, int ram, boolean hasSdCardSlot) {
        this.name = name;
        this.priceRange = priceRange;
        this.screenSize = screenSize;
        this.ram = ram;
        this.hasSdCardSlot = hasSdCardSlot;
    }

    public String getName() {
        return name;
    }

    public PriceRange getPriceRange() {
        return priceRange;
    }

    public double getScreenSize() {
        return screenSize;
    }

    public int getRam() {
        return ram;
    }

    public boolean hasSdCardSlot() {
        return hasSdCardSlot;
    }

    @Override
    public String toString() {
        return "Price: " + priceRange.toString()
                + ", screen size: " + screenSize
                + ", RAM: " + ram
                + ", SD-card slot presence: " + (hasSdCardSlot ? "yes" : "no");
    }
}
