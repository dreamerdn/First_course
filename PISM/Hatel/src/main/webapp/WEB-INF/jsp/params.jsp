<%@ page import="java.util.stream.Stream" %>
<%@ page import="java.util.Objects" %>
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
    <title>Params</title>

</head>
<body>


<div class="container">

    <%--    <div class="starter-template">--%>
    <%--        <h1>Spring Boot Web JSP Example</h1>--%>
    <%--        <h2>Flour: ${flour}</h2>--%>
    <%--        <h2>Add this: ${param1}</h2>--%>
    <%--        <h2>Add this: ${param2}</h2>--%>
    <%--        <h2>Add this: ${param3}</h2>--%>
    <%--    </div>--%>

    <%
        boolean blnCheckBoxNameChecked;
        String param1Checked = request.getParameter("firstParam");
        String param2Checked = request.getParameter("secondParam");
        String param3Checked = request.getParameter("thirdParam");
        blnCheckBoxNameChecked = Stream.of(param1Checked, param2Checked, param3Checked)
                .filter(Objects::nonNull).count() > 1 ? true : false;
    %>

    <div class="d-flex aligns-items-center justify-content-center mt-5">
        <form method="post">
            <div>
                <div>
                    <h1>Flour:</h1>
                </div>
                <div>
                    <label for="1">1</label>
                    <input type="radio" id="1" value="1" name="flour"/>
                </div>
                <div>
                    <label for="2">2</label>
                    <input type="radio" id="2" value="2" name="flour"/>
                </div>
                <div>
                    <label for="3">3</label>
                    <input type="radio" id="3" value="3" name="flour"/>
                </div>
                <div>
                    <label for="4">4</label>
                    <input type="radio" id="4" value="4" name="flour"/>
                </div>
            </div>
            <div>
                <div>
                    <h2>Additional parameters:</h2>
                </div>
                <label for="firstParam">Separate water closet</label>
                <input type="checkbox" id="firstParam" value="Separate water closet" name="param1"/>
                <br/>
                <label for="secondParam">Additional TV</label>
                <input type="checkbox" id="secondParam" value="Additional TV" name="param2"/>
                <br/>
                <label for="thirdParam">Breakfast Include</label>
                <input type="checkbox" id="thirdParam" value="Breakfast Include" name="param3"/>
                <br/>
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