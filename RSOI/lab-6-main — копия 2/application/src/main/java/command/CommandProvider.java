package command;

import command.impl.*;
import command.impl.decorator.RequiredLoginDecorator;

import java.util.List;
import java.util.Optional;

public enum CommandProvider {
    INSTANCE;

    private List<Command> commands;

    CommandProvider() {
        commands = List.of(new ToLoginCommand(), new LoginCommand(), new LogoutCommand(),
                new RequiredLoginDecorator(new ToClientsList()),
                new RequiredLoginDecorator(new ToAddClientCommand()),
                new RequiredLoginDecorator(new AddClientCommand()),
                new RequiredLoginDecorator(new ToClientProfileCommand()),
                new RequiredLoginDecorator(new UpdateClientProfileCommand()),

                new RequiredLoginDecorator(new ToAddOrderCommand()),
                new RequiredLoginDecorator(new AddOrderCommand()),
                new RequiredLoginDecorator(new ToOrdersList()),
                new RequiredLoginDecorator(new RemoveOrderCommand()),

                new RequiredLoginDecorator(new ToPrintCommand()),

                new RequiredLoginDecorator(new ToCarsList()),
                new RequiredLoginDecorator(new ToAddCarCommand()),
                new RequiredLoginDecorator(new AddCarCommand()),
                new RequiredLoginDecorator(new ToCarProfileCommand()),
                new RequiredLoginDecorator(new UpdateCarProfileCommand()),
                new RequiredLoginDecorator(new RemoveCarCommand())
        );
    }

    public Optional<Command> findCommand(String commandName) {
        return commands.stream().filter(x -> x.getCommandName().equals(commandName)).findFirst();
    }
}
