//package company.Servlets;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class Numbers extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {

        String[] strings = req.getParameter("numbers").trim().split(",");
        ArrayList<Integer> numbers = new ArrayList<>();
        for (String s : strings) {
            try {
                numbers.add(Integer.valueOf(s.trim()));
            } catch(Exception ex) {
                PrintWriter pw = resp.getWriter();
                pw.println("ERROR! Check your numbers!");
                pw.close();
            }
        }

        Collections.sort(numbers);

        PrintWriter out = resp.getWriter();
        resp.setContentType("text/html; charset=UTF-8");
        out.println("<html><head>");
        out.println("<title>Lab 1</title>");
        out.println("</head><body><br>");
        out.println("<table border=1><tr><th>Sorted numbers</th></tr>");
        for (Integer i : numbers) {
            out.println("<tr><td>" + i.toString() + "</td></tr>");
        }
        out.println("</table></body></html>");
        out.close();
    }
}