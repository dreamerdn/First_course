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

<div class="container">

    <div class="d-flex aligns-items-center justify-content-center mt-5">

        <div>
            <c:forEach items="${result}" var="entry">
                <label>${entry.key}: ${entry.value}</label>
                <br/>
            </c:forEach>
            <img width="250px" src="${pageContext.request.contextPath}/images/${entry.value eq 'Centre' ? 'pop.jpg' : 'image.jpg'}" alt="Hotel room">
            <%-- src="<c:url value="${image.jpg}"/>"--%>

        </div>
    </div>

</div>

<script type="text/javascript" src="webjars/bootstrap/5.2.3/js/bootstrap.min.js"></script>

</body>
</html>
