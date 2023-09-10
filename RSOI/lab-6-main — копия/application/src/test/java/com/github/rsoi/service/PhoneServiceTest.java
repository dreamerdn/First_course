package com.github.rsoi.service;

import com.github.rsoi.domain.Phone;
import com.github.rsoi.repository.PhoneRepository;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.junit.jupiter.MockitoExtension;

import java.util.ArrayList;
import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;
import static org.mockito.ArgumentMatchers.anyLong;
import static org.mockito.Mockito.*;

@ExtendWith(MockitoExtension.class)
class PhoneServiceTest {

    @Mock
    private PhoneRepository phoneRepository;

    private PhoneService phoneService;

    private final Long PHONE_ID = 1L;
    private final String PHONE_NAME = "Test Phone";
    private final String PRODUCER = "Test Producer";
    private final int PHONE_MIN_PRICE = 100;
    private final int PHONE_MAX_PRICE = 200;
    private final double SCREEN_SIZE = 5.5;
    private final int RAM_MAX = 4;
    private final int RAM_MIN = 2;
    private final String HAS_SD_CARD_SLOT = "Yes";
    private final String IMAGE_LINK = "http://test.com/image.png";

    @BeforeEach
    void setUp() {
        phoneService = new PhoneService();
    }

    @Test
    void shouldDeletePhoneById() {
        // given
        doNothing().when(phoneRepository).deleteById(anyLong());

        // when
        phoneService.deletePhone(PHONE_ID);

        // then
        verify(phoneRepository, times(1)).deleteById(eq(PHONE_ID));
    }

    @Test
    void shouldGetAllPhones() {
        // given
        List<Phone> phones = new ArrayList<>();
        Phone phone = new Phone(PHONE_ID, PHONE_NAME, PRODUCER, PHONE_MIN_PRICE, PHONE_MAX_PRICE, SCREEN_SIZE, RAM_MAX, RAM_MIN, HAS_SD_CARD_SLOT, IMAGE_LINK);
        phones.add(phone);
        when(phoneRepository.findAll()).thenReturn(phones);

        // when
        List<Phone> result = phoneService.getPhones();


        // then
        assertThat(result).isNotEmpty();
        assertThat(result.get(0).getId()).isEqualTo(phone.getId());
        assertThat(result.get(0).getPhoneName()).isEqualTo(phone.getPhoneName());
        assertThat(result.get(0).getProducer()).isEqualTo(phone.getProducer());
        assertThat(result.get(0).getPhoneMinPrice()).isEqualTo(phone.getPhoneMinPrice());
        assertThat(result.get(0).getPhoneMaxPrice()).isEqualTo(phone.getPhoneMaxPrice());
        assertThat(result.get(0).getScreenSize()).isEqualTo(phone.getScreenSize());
        assertThat(result.get(0).getRammax()).isEqualTo(phone.getRammax());
        assertThat(result.get(0).getRammin()).isEqualTo(phone.getRammin());
        assertThat(result.get(0).getHasSdCardSlot()).isEqualTo(phone.getHasSdCardSlot());
        assertThat(result.get(0).getImageLink()).isEqualTo(phone.getImageLink());
    }
}