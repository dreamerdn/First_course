package com.example.rsoi3;
import org.springframework.stereotype.Service;

@Service
public class PhoneService {
    private final PhoneRepository phoneRepository;
    public PhoneService(PhoneRepository phoneRepository) {
        this.phoneRepository = phoneRepository;
    }


    public void addPhone (Phone phone) {
        phoneRepository.save(phone);
    }

    public void deletePhone (Long phoneID) {
        phoneRepository.deleteById(phoneID);
    }

}




