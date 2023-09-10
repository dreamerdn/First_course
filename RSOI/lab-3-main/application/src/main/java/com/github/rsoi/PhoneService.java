package com.github.rsoi;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class PhoneService {
    private final PhoneRepository phoneRepository;
    public PhoneService(PhoneRepository phoneRepository) {
        this.phoneRepository = phoneRepository;

    }

   public Phone getById(Long id){
        return phoneRepository.getById(id);
   }


    public void addPhone (Phone phone) {
        phoneRepository.save(phone);
    }

    public void deletePhone (Long phoneID) {
        phoneRepository.deleteById(phoneID);
    }

}




