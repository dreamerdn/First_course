package com.example.lab4rsoimaven;

import com.example.lab4rsoimaven.controller.PhoneController;
import com.example.lab4rsoimaven.domain.Phone;
import com.example.lab4rsoimaven.dto.PhoneDTO;
import com.example.lab4rsoimaven.repository.PhoneRepository;
import com.example.lab4rsoimaven.service.PhoneService;
import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.test.context.junit4.SpringRunner;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

@RunWith(SpringRunner.class)
@SpringBootTest
public class PhoneControllerTest {

    @Autowired
    private PhoneController phoneController;

    @MockBean
    private PhoneService phoneService;

    @MockBean
    private PhoneRepository phoneRepository;

    @Test
    public void testGetInternetShop() {
        ResponseEntity response = phoneController.getInternetShop();
        assertEquals(HttpStatus.OK, response.getStatusCode());
        assertEquals("Сервер работает ура!", response.getBody());
    }

    @Test
    public void testGetPhones() {
        // Given
        List<Phone> phones = new ArrayList<>();
        Phone phone1 = new Phone();
        phone1.setId(1L);
        phone1.setPhoneName("Phone 1");
        Phone phone2 = new Phone();
        phone2.setId(2L);
        phone2.setPhoneName("Phone 2");
        phones.add(phone1);
        phones.add(phone2);

        Mockito.when(phoneService.getPhones()).thenReturn(phones);

        // When
        ResponseEntity<List<Phone>> response = phoneController.getPhones();

        // Then
        assertEquals(HttpStatus.OK, response.getStatusCode());
        assertEquals(phones, response.getBody());
    }

    @Test
    public void testAddPhone() {
        // Given
        PhoneDTO phoneDTO = new PhoneDTO();
        phoneDTO.setPhoneName("Phone 1");
        phoneDTO.setProducer("Producer 1");
        phoneDTO.setPhoneMinPrice(100);
        phoneDTO.setPhoneMaxPrice(200);
        phoneDTO.setScreenSize(5.0);
        phoneDTO.setRammin(2);
        phoneDTO.setRammax(4);
        phoneDTO.setHasSdCardSlot("true");
        phoneDTO.setImageLink("image-link");

        Phone phone = new Phone();
        phone.setId(1L);
        phone.setPhoneName("Phone 1");
        phone.setProducer("Producer 1");
        phone.setPhoneMinPrice(100);
        phone.setPhoneMaxPrice(200);
        phone.setScreenSize(5.0);
        phone.setRammin(2);
        phone.setRammax(4);
        phone.setHasSdCardSlot("true");
        phone.setImageLink("image-link");

        Mockito.when(phoneRepository.save(Mockito.any(Phone.class))).thenReturn(phone);

        // When
        Phone addedPhone = phoneController.addPhone(phoneDTO);

        // Then
        assertEquals(phone, addedPhone);
    }

    @Test
    public void testDeletePhone() {
        // Given
        Long phoneId = 1L;

        // When
        ResponseEntity response = phoneController.deleteGoods(phoneId);

        // Then
        assertEquals(HttpStatus.OK, response.getStatusCode());
        assertEquals("Товар успешно удален!", response.getBody());
    }

}