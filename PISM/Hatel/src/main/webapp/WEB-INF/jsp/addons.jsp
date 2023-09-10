<!DOCTYPE html>
<%@ taglib prefix="spring" uri="http://www.springframework.org/tags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<html lang="en">
<head>
    <link rel="stylesheet" type="text/css" href="webjars/bootstrap/5.2.3/css/bootstrap.min.css"/>

    <!--
	<spring:url value="/css/main.css" var="springCss" />
	<link href="${springCss}" rel="stylesheet" />
	 -->
    <c:url value="/css/main.css" var="jstlCss"/>
    <link href="${jstlCss}" rel="stylesheet"/>
    <title>Addons</title>

</head>
<body>

<div class="container">

    <%--    <div class="starter-template">--%>
    <%--        <h1>Spring Boot Web JSP Example</h1>--%>
    <%--        <h2>Message: ${addon}</h2>--%>
    <%--    </div>--%>

    <div class="d-flex aligns-items-center justify-content-center mt-5">
        <form method="post">
            <div>
                <h1>Add more what you expect about us</h1>
            </div>
            <div>
                <label for="addon">Addons:</label>
                <input type="text" id="addon" name="addon"/>
            </div>
            <input type="submit" value="submit"/>
        </form>
    </div>

    <div>
        <p>${errorMessage}</p>
    </div>

</div>

<script type="text/javascript" src="webjars/bootstrap/5.2.3/js/bootstrap.min.js"></script>

</body>

</html>