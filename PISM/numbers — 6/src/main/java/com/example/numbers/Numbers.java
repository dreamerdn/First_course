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
        String[] strings = req.getParameter("numbers").trim().split("/");
        ArrayList<Double> numbers = new ArrayList<>();
        String precisionString = req.getParameter("precision").trim();
        int precision = 0;
        try {
            precision = Integer.valueOf(precisionString);
        } catch (Exception ex) {
            PrintWriter pw = resp.getWriter();
            pw.println("ERROR! Check your precision!");
            pw.close();
        }
        for (String s : strings) {
            try {
                double value = Double.valueOf(s.trim());
                double radian = Math.toRadians(value);
                double sin = Math.round(Math.sin(radian) * Math.pow(10, precision)) / Math.pow(10, precision);
                double cos = Math.round(Math.cos(radian) * Math.pow(10, precision)) / Math.pow(10, precision);
                double tan = Math.round(Math.tan(radian) * Math.pow(10, precision)) / Math.pow(10, precision);
                // do something with sin, cos, tan
                numbers.add(sin);
                numbers.add(cos);
                numbers.add(tan);
            } catch (Exception ex) {
                PrintWriter pw = resp.getWriter();
                pw.println("ERROR! Check your numbers!");
                pw.close();
            }
        }


       // Collections.sort(numbers);

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