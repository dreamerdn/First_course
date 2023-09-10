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
   /* protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {

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
        }*/

        protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        String surname = req.getParameter("surname").trim();
        String averageScoreString = req.getParameter("averageScore").trim();
        String courseString = req.getParameter("course").trim();
        double averageScore = 0;
        int course = 0;
        try {
            averageScore = Double.valueOf(averageScoreString);
            course = Integer.valueOf(courseString);
        } catch (Exception ex) {
            PrintWriter pw = resp.getWriter();
            pw.println("ERROR! Check your data!");
            pw.close();
        }

        String sortBy = req.getParameter("sortBy");
        if (sortBy != null) {
            switch (sortBy) {
                case "surname":
                    Collections.sort(surname);
                    break;
                case "averageScore":
                    List<Student> students = new ArrayList<>();
                    students.add(new Student(surname, averageScore, course));
                    students.sort(Comparator.comparing(Student::getAverageScore).reversed());
                    break;
                case "course":
                    students = new ArrayList<>();
                    students.add(new Student(surname, averageScore, course));
                    students.sort(Comparator.comparingInt(Student::getCourse));
                    break;
            }
        }

        PrintWriter out = resp.getWriter();
        resp.setContentType("text/html; charset=UTF-8");
        out.println("<html><head>");
        out.println("<title>Lab 1</title>");
        out.println("</head><body><br>");
        out.println("<table border=1><tr><th>Sorted Students</th></tr>");
        students.stream().map(i -> "<tr><td>" + i.toString() + "</td></tr>").forEach(out::println);
        out.println("</table></body></html>");
        out.close();
    }

    public void destroy() {}
}