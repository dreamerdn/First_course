package validation.impl;

import entity.Car;
import validation.RegExProvider;
import validation.Validator;

public class CarValidator extends Validator<Car> {
    private final static int MIN_SHORT_TEXT_LENGTH = 2;
    private final static int MAX_SHORT_TEXT_LENGTH = 50;
    private final static int MIN_REG_NUMBER_LENGTH = 6;
    private final static int MAX_REG_NUMBER_LENGTH = 10;
    private final static int MIN_MILEAGE = 0;
    private final static int MAX_MILEAGE = 999999;
    private final static float MIN_PRICE = 0f;
    private final static float MAX_PRICE = 9999.99f;

    @Override
    public boolean isValid(Car entity) {

        String model = entity.getModel();
        String registrationNumber = entity.getRegistrationNumber();
        int year = entity.getYear();
        int makeId = entity.getMakeId();
        int mileage = entity.getMileage();
        int gearboxType = entity.getGearboxType();
        float pricePerDay = entity.getPricePerDay();
        float pricePerDay2 = entity.getPricePerDay2();

        if (!validateString(model, MIN_SHORT_TEXT_LENGTH, MAX_SHORT_TEXT_LENGTH, RegExProvider.LETTERS)) {
            setValidationFeedback("Неверный формат модели автомобиля");
            return false;
        }

        if (!validateString(registrationNumber, MIN_REG_NUMBER_LENGTH, MAX_REG_NUMBER_LENGTH, RegExProvider.LETTERS)) {
            setValidationFeedback("Неверный формат номера регистрации автомобиля");
            return false;
        }

        if (year < 1900) {
            setValidationFeedback("Неверный год выпуска автомобиля");
            return false;
        }

        if (makeId <= 0) {
            setValidationFeedback("Неверный id производителя автомобиля");
            return false;
        }

        if (mileage < MIN_MILEAGE || mileage > MAX_MILEAGE) {
            setValidationFeedback("Неверный пробег автомобиля");
            return false;
        }

        if (gearboxType < 1 || gearboxType > 2) {
            setValidationFeedback("Неверный формат коробки передач");
            return false;
        }

        if (pricePerDay < MIN_PRICE || pricePerDay > MAX_PRICE) {
            setValidationFeedback("Неверная цена аренды автомобиля в будние дни");
            return false;
        }

        if (pricePerDay2 < MIN_PRICE || pricePerDay2 > MAX_PRICE) {
            setValidationFeedback("Неверная цена аренды автомобиля в выходные и праздничные дни");
            return false;
        }

        return true;
    }
}