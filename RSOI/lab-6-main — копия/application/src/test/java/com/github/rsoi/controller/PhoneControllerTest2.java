package com.github.rsoi.controller;

import com.github.rsoi.domain.Phone;
import com.github.rsoi.repository.PhoneRepository;
import com.github.rsoi.service.PhoneService;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.boot.test.mock.mockito.MockBean;
import org.springframework.http.MediaType;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.test.web.servlet.result.MockMvcResultMatchers;

import java.util.ArrayList;
import java.util.List;

@WebMvcTest(PhoneController.class)
public class PhoneControllerTest2 {

    @Autowired
    private MockMvc mockMvc;

    @MockBean
    private PhoneService phoneService;

    @MockBean
    private PhoneRepository phoneRepository;

    @Test
    public void testSearchPhones() throws Exception {
        // arrange
        List<Phone> phones = new ArrayList<>();
        phones.add(new Phone(1L, "iPhone 12", "Apple", 999, 1499, 6.1, 6, 2, "Yes", "https://image.com/iphone"));
        phones.add(new Phone(2L, "Galaxy S21", "Samsung", 799, 1299, 6.2, 8, 4, "Yes", "https://image.com/galaxy"));

        Mockito.when(phoneRepository.findByPhoneNameContainingIgnoreCase(Mockito.anyString())).thenReturn(phones);

        // act and assert
        mockMvc.perform(MockMvcRequestBuilders.get("/phonecreator/getPhoneNames")
                        .param("query", "iPhone")
                        .accept(MediaType.APPLICATION_JSON))
                .andExpect(MockMvcResultMatchers.status().isOk())
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].id").value(1L))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].phoneName").value("iPhone 12"))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].producer").value("Apple"))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].phoneMinPrice").value(999))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].phoneMaxPrice").value(1499))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].screenSize").value(6.1))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].rammax").value(6))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].rammin").value(2))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].hasSdCardSlot").value("Yes"))
                .andExpect(MockMvcResultMatchers.jsonPath("$[0].imageLink").value("https://image.com/iphone"));
    }
}
