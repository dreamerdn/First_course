<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>Lab 1</title>
</head>
<body>
<h1>Введите числа через запятую </h1>
<form method="post" action="${pageContext.request.contextPath}/numbers">
    Поле для ввода: 
    <label>
        <input type="text" name="numbers">
    </label>
    <br>
    <br>
    <button type="submit">Отсортировать</button>
</form>
</body>
</html>