package com.github.rsoi;

public class PriceRange {
    private final int minPrice;
    private final int maxPrice;

    public PriceRange(int minPrice, int maxPrice) {
        this.minPrice = minPrice;
        this.maxPrice = maxPrice;
    }

    public int getMinPrice() {
        return minPrice;
    }

    public int getMaxPrice() {
        return maxPrice;
    }

    /**
     * Проверяет, пересекается ли данная ценовая категория с другой.
     */
    public boolean intersects(PriceRange other) {
        return !(maxPrice < other.minPrice || other.maxPrice < minPrice);
    }

    @Override
    public String toString() {
        return minPrice + "-" + maxPrice;
    }
}
