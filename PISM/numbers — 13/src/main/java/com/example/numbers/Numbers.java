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
    public void init() {
    } //используется для инициализации сервлета при его запуске

    //переопределенный метод doGet класса HttpServlet
    //HttpServletRequest - запрос, который отправлен клиентом на сервер
    //HttpServletResponse - ответ, который сервер возвращает клиенту.
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }

    double sum = 0.0;
    double sum2 = 0.0;
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String[] strings = req.getParameter("numbers").trim().split(",");
        ArrayList<Double> numbers = new ArrayList<>();
        for (String s : strings) {
            String word = s.trim();
            if (!word.matches("-?\\d+(\\.\\d+)?")) {
                PrintWriter pw = resp.getWriter();
                pw.println("ERROR! Check your numbers!");
                pw.close();
            } else {
                double number = Double.parseDouble(word);
                numbers.add(number);
                sum += number;
            }
        }

        String[] strings2 = req.getParameter("numbers2").trim().split(",");
        ArrayList<Double> numbers2 = new ArrayList<>();
        for (String s2 : strings2) {
            String word2 = s2.trim();
            if (!word2.matches("-?\\d+(\\.\\d+)?")) {
                PrintWriter pw2 = resp.getWriter();
                pw2.println("ERROR! Check your numbers!");
                pw2.close();
            } else {
                double number2 = Double.parseDouble(word2);
                numbers2.add(number2);
                sum2 += number2;
            }
        }


        PrintWriter out = resp.getWriter();
        resp.setContentType("text/html; charset=UTF-8");
        out.println("<html><head>");
        out.println("<title>Lab 1</title>");
        out.println("</head><body><br>");
        out.println("<table border=1><tr><th> Jumper #1 </th><th> Jumper #2 </th></tr>");
        for (int i = 0; i < numbers.size() || i < numbers2.size(); i++) {
            out.println("<tr><td>");
            if (i < numbers.size()) {
                out.println(numbers.get(i));
            }
            out.println("</td><td>");
            if (i < numbers2.size()) {
                out.println(numbers2.get(i));
            }
            out.println("</td></tr>");
        }
        out.println("</table>");

        out.println("<table border=1><tr><th> Average value #1 </th><th> Average value #2 </th></tr>");
        out.println("<tr><td>" + (sum/ numbers.size()) + "</td><td>" + (sum2/ numbers2.size()) + "</td></tr>");

        double max1 = Collections.max(numbers);
        double min1 = Collections.min(numbers);
        double max2 = Collections.max(numbers2);
        double min2 = Collections.min(numbers2);

        double max=0.0;
        double min=0.0;

        if(max1>max2){
            max=max1;
            out.println("<table border=1><tr><th> Max value belongs to Jumper #1 = Winner! </th></tr>");
            out.println("</table>");
        }
        else {
            max=max2;
        out.println("<table border=1><tr><th> Max value belongs to Jumper #2 = Winner!</th></tr>");
        out.println("</table>");}

        if(min1<min2){
            min=min1;
        }else min=min2;

        out.println("<table border=1><tr><th> Min value </th><th> Max value </th></tr>");
        out.println("<tr><td>" + min + "</td><td>" + max + "</td></tr>");
        out.println("</table>");


        out.println("</table></body></html>");
        out.close();
    }
}


