<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Lab 1</title>
</head>
<body>
<h1>Введите Число, Средний Балл, Курс</h1>
<form method="post" action="${pageContext.request.contextPath}/student">
    Число:
    <label>
        <input type="text" name="numbers">
    </label>
    <br>
    <br>
    Средний балл:
    <label>
        <input type="text" name="averageScore">
    </label>
    <br>
    <br>
    Курс:
    <label>
        <input type="text" name="course">
    </label>
    <br>
    <br>
    <button type="submit" name="sortOption" value="numbers">Сортировка по числу</button>
    <button type="submit" name="sortOption" value="averageScore">Сортировка по среднему баллу</button>
    <button type="submit" name="sortOption" value="course">Сортировка по курсу</button>
</form>
</body>
</html>



