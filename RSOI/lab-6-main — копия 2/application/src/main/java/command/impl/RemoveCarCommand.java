package command.impl;
import command.Command;
import command.CommandException;
import command.PagePath;
import command.ParameterName;
import dbbinding.impl.CarBinding;
import entity.Car;
import repository.RepositoryException;
import repository.impl.SqlRepository;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
public class RemoveCarCommand implements Command {

    @Override
    public void execute(HttpServletRequest request, HttpServletResponse response) throws CommandException {
        int car_id = Integer.parseInt(request.getParameter(ParameterName.CAR_ID));

        try {
            SqlRepository<Car> repository = new SqlRepository<Car>(new CarBinding());
            Car car = repository.getEntityById(car_id);
            repository.removeEntity(car);

            response.sendRedirect(PagePath.SERVLET + "/car_rental?command=to_cars_list");
        } catch (RepositoryException | IOException e) {
            throw new CommandException(e);
        }
    }

    @Override
    public String getCommandName() {
        return "remove_car";
    }
}
