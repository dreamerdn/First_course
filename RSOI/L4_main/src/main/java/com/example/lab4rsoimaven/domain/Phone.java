package com.example.lab4rsoimaven.domain;

import jakarta.persistence.*;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@Entity
@NoArgsConstructor
@AllArgsConstructor
@Table(name = "phone12345")
public class Phone {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    Long id;
    String phoneName;
    String producer;
    int phoneMinPrice;
    int phoneMaxPrice;
    double screenSize;
    int rammax;
    int rammin;
    String hasSdCardSlot;
}
