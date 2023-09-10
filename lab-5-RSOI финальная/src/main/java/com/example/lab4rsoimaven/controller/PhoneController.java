package com.example.lab4rsoimaven.controller;

import com.example.lab4rsoimaven.domain.Phone;
import com.example.lab4rsoimaven.repository.PhoneRepository;
import com.example.lab4rsoimaven.service.PhoneService;
import jakarta.persistence.TypedQuery;
import org.hibernate.Session;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
@ResponseBody
@RequestMapping("/phonecreator")
public class PhoneController {

    @Autowired
    private PhoneService phoneService;
    private Session entityManager;

    @GetMapping()
    public ResponseEntity getInternetShop() {
        try {
            return ResponseEntity.ok("Сервер работает!");
        } catch (Exception e) {
            return ResponseEntity.badRequest().body("Произошла ошибка");
        }
    }

  /*  @GetMapping("/readPhone")
    public ResponseEntity getPhones() {
        try {
            return ResponseEntity.ok(phoneService.getPhones());
        } catch (Exception e) {
            return ResponseEntity.badRequest().body("Произошла ошибка");
        }
    }*/

    @GetMapping("/{id}")
    public Phone getPhone(@PathVariable Long id) {
        // Получить информацию о телефоне с указанным id из базы данных
        TypedQuery<Phone> query = entityManager.createQuery(
                "SELECT p FROM Phone p WHERE p.id = :id",
                Phone.class);
        query.setParameter("id", id);
        Phone phone = query.getSingleResult();

        // Вернуть объект телефона
        return phone;
    }
}
