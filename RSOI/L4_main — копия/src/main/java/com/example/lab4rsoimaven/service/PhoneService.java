package com.example.lab4rsoimaven.service;

import com.example.lab4rsoimaven.domain.Phone;
import com.example.lab4rsoimaven.dto.PhoneDTO;
import com.example.lab4rsoimaven.repository.PhoneRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class PhoneService {
    @Autowired
    private  PhoneRepository phoneRepository;

    public void deletePhone (Long phoneId) {
        phoneRepository.deleteById(phoneId);
    }

    public List<Phone> getPhones() {
        return phoneRepository.findAll();
    }
}
