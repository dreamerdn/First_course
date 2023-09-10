package com.example.numbers;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet(name = "numbers", value = "/numbers")
public class Numbers extends HttpServlet {
    public void init() {}

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String[] strings = req.getParameter("numbers").trim().split(",");
        ArrayList<Integer> numbers = new ArrayList<>();
        for (String s : strings) {
            try {
                int num = Integer.parseInt(s.trim());
                if (num % 2 == 0 || num % 3 == 0 || num % 5 == 0) {
                    numbers.add(num);
                } else {
                    throw new Exception();
                }
            } catch (Exception ex) {
                PrintWriter pw = resp.getWriter();
                pw.println("ERROR! The input must be a number that is divisible by 2, 3, or 5.");
                pw.close();
                return;
            }
        }

        Collections.sort(numbers);

        PrintWriter out = resp.getWriter();
        resp.setContentType("text/html; charset=UTF-8");
        out.println("<html><head>");
        out.println("<title>Lab 1</title>");
        out.println("</head><body><br>");
        out.println("<table border=1><tr><th>Sorted numbers</th></tr>");
        numbers.stream().map(i -> "<tr><td>" + i.toString() + "</td></tr>").forEach(out::println);
        out.println("</table></body></html>");
        out.close();
    }

    public void destroy() {}
}