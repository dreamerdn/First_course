package command.impl;

import command.CommandException;
import command.EntityBuilder;
import command.PagePath;
import dbbinding.impl.CarBinding;
import entity.Car;
import repository.RepositoryException;
import repository.impl.SqlRepository;
import validation.impl.CarValidator;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Optional;

public class AddCarCommand implements CommandWithValidation {
    @Override
    public void onSuccess(HttpServletRequest request, HttpServletResponse response) throws CommandException {
        try {
            String params = "/car_rental?command=to_cars_list";//стр со списком машин
            response.sendRedirect(PagePath.SERVLET + params);
        } catch (IOException e) {
            throw new CommandException(e);
        }
    }

    @Override
    public void onValidationError(HttpServletRequest request, HttpServletResponse response, String feedback) throws CommandException {
        try {
            request.setAttribute("feedback", feedback);
            request.getRequestDispatcher(PagePath.SERVLET + "/car_rental?command=to_add_car").forward(request, response);
        } catch (ServletException | IOException e) {
            throw new CommandException(e);
        }
    }

    @Override
    public void execute(HttpServletRequest request, HttpServletResponse response) throws CommandException {
        Optional<Car> optionalCar = EntityBuilder.INSTANCE.buildCar(request);
        CarValidator validator = new CarValidator(); //проверка подлинности данных

        if (!optionalCar.isPresent())
        {
            try {
                response.sendError(400);
            } catch (IOException e) {
                throw new CommandException(e);
            }
            return;
        }

        Car car = optionalCar.get();

        if (!validator.isValid(car)) {
            onValidationError(request, response, validator.getValidationFeedback());
            return;
        }

        try {
            new SqlRepository<Car>(new CarBinding()).addEntity(car);//добавление машины в бд
        } catch (RepositoryException e) {
            onValidationError(request, response, "Ошибка добавления машины в базу данных");
            return;
        }

        onSuccess(request, response);
    }

    @Override
    public String getCommandName() {
        return "add_car";
    }
}

