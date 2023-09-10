package validation;

public abstract class Validator<T> {
    private String validationFeedback;

    public abstract boolean isValid(T entity);

    //исп для устан сообщения обратн связи при проверке, если проверка не пройдена
    protected void setValidationFeedback(String feedback)
    {
        validationFeedback = feedback;
    }

    //метод возвращает логическое значение, указывающее, является ли строка допустимой или нет
    protected boolean validateString(String str, int minLength, int maxLength, String regex) {
        return str != null && str.length() <= maxLength && str.length() >= minLength &&
                str.matches(regex);
    }

    public String getValidationFeedback()
    {
        return validationFeedback;
    }
}
