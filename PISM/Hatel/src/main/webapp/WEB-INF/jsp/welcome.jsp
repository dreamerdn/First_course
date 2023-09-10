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
    <title>Home</title>

</head>
<body>

<%--<nav class="navbar navbar-inverse">--%>
<%--    <div class="container">--%>
<%--        <div class="navbar-header">--%>
<%--            <a class="navbar-brand" href="#">Spring Boot</a>--%>
<%--        </div>--%>
<%--        <div id="navbar" class="collapse navbar-collapse">--%>
<%--            <ul class="nav navbar-nav">--%>
<%--                <li class="active"><a href="#">Home</a></li>--%>
<%--                <li><a href="#about">About</a></li>--%>
<%--            </ul>--%>
<%--        </div>--%>
<%--    </div>--%>
<%--</nav>--%>

<div class="container">

    <div class="d-flex aligns-items-center justify-content-center mt-5">
        <form method="post">
            <div>
                <h1>Choose your Palace!</h1>
            </div>
            <div>
                <label for="plaza">Plaza</label>
                <input type="radio" id="plaza" value="Plaza" name="name"/>
            </div>
            <div>
                <label for="centre">Centre</label>
                <input type="radio" id="centre" value="Centre" name="name"/>
            </div>
            <input type="submit" value="submit"/>
        </form>
    </div>

</div>

<script type="text/javascript" src="webjars/bootstrap/5.2.3/js/bootstrap.min.js"></script>

</body>

</html>