package com.github.rsoi.controller;
import com.github.rsoi.domain.Phone;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
public class PhoneTest {

    @Test
    public void testGettersAndSetters() {
        Long id = 1L;
        String phoneName = "iPhone 12";
        String producer = "Apple";
        int phoneMinPrice = 999;
        int phoneMaxPrice = 1299;
        double screenSize = 6.1;
        int ramMax = 6;
        int ramMin = 4;
        String hasSdCardSlot = "no";
        String imageLink = "https://example.com/iphone12.jpg";

        Phone phone = new Phone();
        phone.setId(id);
        phone.setPhoneName(phoneName);
        phone.setProducer(producer);
        phone.setPhoneMinPrice(phoneMinPrice);
        phone.setPhoneMaxPrice(phoneMaxPrice);
        phone.setScreenSize(screenSize);
        phone.setRammax(ramMax);
        phone.setRammin(ramMin);
        phone.setHasSdCardSlot(hasSdCardSlot);
        phone.setImageLink(imageLink);

        Assertions.assertEquals(id, phone.getId());
        Assertions.assertEquals(phoneName, phone.getPhoneName());
        Assertions.assertEquals(producer, phone.getProducer());
        Assertions.assertEquals(phoneMinPrice, phone.getPhoneMinPrice());
        Assertions.assertEquals(phoneMaxPrice, phone.getPhoneMaxPrice());
        Assertions.assertEquals(screenSize, phone.getScreenSize());
        Assertions.assertEquals(ramMax, phone.getRammax());
        Assertions.assertEquals(ramMin, phone.getRammin());
        Assertions.assertEquals(hasSdCardSlot, phone.getHasSdCardSlot());
        Assertions.assertEquals(imageLink, phone.getImageLink());
    }
}

