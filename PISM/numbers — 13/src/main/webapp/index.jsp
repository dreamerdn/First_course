<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Lab 1</title>
</head>
<body>
<h1>Введите показатели через запятую </h1>
<form method="post" action="${pageContext.request.contextPath}/numbers">
    Поле для ввода 1:
    <label>
        <input type="text" name="numbers">
    </label>
    <br>
    <form method="post" action="${pageContext.request.contextPath}/numbers2">
    Поле для ввода 2:
    <label>
        <input type="text" name="numbers2">
    </label>
    <br>
    <br>
    <button type="submit">Отсортировать</button>
</form>
</form>
</body>
</html>


