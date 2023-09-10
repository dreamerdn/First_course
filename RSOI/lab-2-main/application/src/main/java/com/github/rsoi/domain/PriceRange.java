package com.github.rsoi.domain;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.stereotype.Component;

@Configuration //использует этот класс для создания bean-компонентов
 class AppConfig {
    @Bean //создание и настройка bean-компонентов
    public Integer myInteger() {
        return 0;
    }
}

@Component //оздает экземпляр этого класса и регистрирует его как bean-компонент в контейнере Spring
public class PriceRange {

   public Integer minPrice;
   public Integer maxPrice;

   @Autowired //Spring Framework автоматически связывает с другими bean-компонентами
   public PriceRange(Integer minPrice, Integer maxPrice) {
        this.minPrice = minPrice;
        this.maxPrice = maxPrice;
    }

    public boolean intersects(PriceRange other) {
       return !(maxPrice < other.minPrice || other.maxPrice < minPrice);
    }

    @Override
    public String toString() {
        return minPrice + "-" + maxPrice;
    }
}
