package com.github.rsoi;

import command.Command;
import command.CommandProvider;
import command.ParameterName;
import controller.CarRentalServlet;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.junit.runner.RunWith;
import org.mockito.Mock;
import org.mockito.MockitoAnnotations;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.io.IOException;
import java.util.Optional;

import static org.junit.jupiter.api.Assertions.assertThrows;
import static org.mockito.Mockito.*;
@RunWith(SpringRunner.class)
@SpringBootTest(classes = CarRentalServlet.class)
class CarRentalServletTest {

    @Mock
    private HttpServletRequest mockRequest;

    @Mock
    private HttpServletResponse mockResponse;

    private CarRentalServlet carRentalServlet;

    @BeforeEach
    void setUp() {
        MockitoAnnotations.initMocks(this);
        carRentalServlet = new CarRentalServlet();
    }

    @Test
    void doGet_ShouldCallProcessRequest() throws ServletException, IOException {
        // Arrange

        // Act
        carRentalServlet.doGet(mockRequest, mockResponse);

        // Assert
        verify(carRentalServlet, times(1)).processRequest(mockRequest, mockResponse);
    }

    @Test
    void doPost_ShouldCallProcessRequest() throws ServletException, IOException {
        // Arrange

        // Act
        carRentalServlet.doPost(mockRequest, mockResponse);

        // Assert
        verify(carRentalServlet, times(1)).processRequest(mockRequest, mockResponse);
    }

    @Test
    void processRequest_ShouldExecuteCommand() throws ServletException {
        // Arrange
        String commandName = "someCommand";
        when(mockRequest.getParameter(ParameterName.COMMAND)).thenReturn(commandName);

        Command mockCommand = mock(Command.class);
        when(CommandProvider.INSTANCE.findCommand(commandName)).thenReturn(Optional.of(mockCommand));

        // Act
        carRentalServlet.processRequest(mockRequest, mockResponse);

        // Assert
        verify(mockCommand, times(1)).execute(mockRequest, mockResponse);
    }

    @Test
    void processRequest_ShouldThrowServletException_WhenCommandNotAvailable() {
        // Arrange
        String commandName = "unavailableCommand";
        when(mockRequest.getParameter(ParameterName.COMMAND)).thenReturn(commandName);
        when(CommandProvider.INSTANCE.findCommand(commandName)).thenReturn(Optional.empty());

        // Act & Assert
        assertThrows(ServletException.class, () -> carRentalServlet.processRequest(mockRequest, mockResponse));
    }
}

