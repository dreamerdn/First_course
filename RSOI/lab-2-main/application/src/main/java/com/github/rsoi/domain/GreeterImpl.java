package com.github.rsoi.domain;

import com.github.rsoi.service.Greeter;
import org.springframework.stereotype.Service;

@Service
public class GreeterImpl implements Greeter {
    @Override
    public void sayHello() {
        System.out.println("Hello world from Spring Service Bean!");
    }
}
