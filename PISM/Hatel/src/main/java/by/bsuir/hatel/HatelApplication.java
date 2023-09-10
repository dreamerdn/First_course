package by.bsuir.hatel;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.boot.web.servlet.support.SpringBootServletInitializer;


//запускает встроенный веб-сервер для обслуживания HTTP-запросов
@SpringBootApplication
//метааннотация, включающая несколько других аннотаций,
//обычно используемых в приложениях Spring Boot
public class HatelApplication extends SpringBootServletInitializer {

    @Override
    protected SpringApplicationBuilder configure(SpringApplicationBuilder builder) {
        return builder.sources(HatelApplication.class);
    }

    //Метод run запускает встроенный веб-сервер и инициализирует контекст приложения Spring
    public static void main(String[] args) {
        SpringApplication.run(HatelApplication.class, args);
    }
}
