package command.impl;

import command.Command;
import command.CommandException;
import command.PagePath;
import command.ParameterName;
import dbbinding.impl.CarBinding;
import entity.Car;
import repository.RepositoryException;
import repository.impl.SqlRepository;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
public class ToCarProfileCommand implements Command{
    @Override
    public void execute(HttpServletRequest request, HttpServletResponse response) throws CommandException {
        String stringId = request.getParameter(ParameterName.CAR_ID);
        int id = Integer.parseInt(stringId);

        try {
            Car car = new SqlRepository<>(new CarBinding()).getEntityById(id);
            request.setAttribute(ParameterName.CAR, car);
            request.getRequestDispatcher(PagePath.CAR_PROFILE).forward(request, response);
        } catch (RepositoryException | ServletException | IOException e) {
            throw new CommandException(e);
        }
    }

    @Override
    public String getCommandName() {
        return "to_car_profile";
    }
}
