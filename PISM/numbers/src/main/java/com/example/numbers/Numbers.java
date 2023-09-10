package com.example.numbers;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

import jakarta.servlet.ServletException;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

//аннотация и определение класса веб-сервлета
@WebServlet(name = "numbers", value = "/numbers") // сервлет будет доступен по адресу "/numbers".
public class Numbers extends HttpServlet { // наследование от HttpServlet
    public void init() {} //используется для инициализации сервлета при его запуске

    //переопределенный метод doGet класса HttpServlet
    //HttpServletRequest - запрос, который отправлен клиентом на сервер
    //HttpServletResponse - ответ, который сервер возвращает клиенту.
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String[] strings = req.getParameter("numbers").trim().split(",");
        ArrayList<String> numbers = new ArrayList<>();
        for (String s : strings) {
            String word = s.trim();
            if (!word.matches("[a-zA-Z]+")) {
                PrintWriter pw = resp.getWriter();
                pw.println("ERROR! Check your words!");
                pw.close();
            } else {
                numbers.add(word);
            }
        }

        Collections.sort(numbers);

        PrintWriter out = resp.getWriter();
        resp.setContentType("text/html; charset=UTF-8"); //генерируется страница html
        out.println("<html><head>");
        out.println("<title>Lab 1</title>");
        out.println("</head><body><br>");
        out.println("<table border=1><tr><th>Sorted numbers</th></tr>"); //генерируется таблица
        numbers.stream().map(i -> "<tr><td>" + i.toString() + "</td></tr>").forEach(out::println);
        out.println("</table></body></html>");
        out.close();
    }

    public void destroy() {}
}