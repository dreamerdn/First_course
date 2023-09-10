package by.bsuir.hatel;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import java.util.stream.IntStream;
import java.util.stream.Stream;

//класс для контроллера Spring MVC,
// который обрабатывает HTTP-запросы и генерирует HTTP-ответы.
@Controller //это компонент Spring, который обрабатывает веб-запросы
public class HomeController {
    @Value("${welcome.message:test}")
    private String message = "Choose your hotel!";
    private String flour = "1";
    private String param1 = "1";
    private String param2 = "1";
    private String param3 = "1";
    private String addon = "Addon";
    private String errorMessageForFlour = "Select Flour!";
    private String errorMessageForParams = "Choose at least 2 params!";
    private String errorMessageForAddon = "Write something!";

    private final Map<String, String> results = new HashMap<>();//сохраняются введенные данные


    //объект ModelMap, используется для передачи данных в шаблоны представления.
    @GetMapping("/")
    public String home(ModelMap model) {
        model.addAttribute("message", this.message);
        results.clear();
        return "welcome";
    }

    @PostMapping("/")
    public String addFirst(ModelMap model, @RequestParam(required = false) String name) {
        model.addAttribute("message", name);
        results.put("Hotel name", (name == null || name.isBlank()) ? "Plaza" : name);
        return "redirect:/params";
    }

    @GetMapping("/params")
    public String params(ModelMap model) {
        model.addAttribute("flour", this.flour);
        model.addAttribute("param1", this.param1);
        model.addAttribute("param2", this.param2);
        model.addAttribute("param3", this.param3);
        model.addAttribute("errorMessage", "");
        return "params";
    }

    @PostMapping("/params")
    public String addSecond(@RequestParam(required = false) String flour,
                            @RequestParam(required = false) String param1,
                            @RequestParam(required = false) String param2,
                            @RequestParam(required = false) String param3,
                            ModelMap model) {
        model.addAttribute("flour", Objects.requireNonNullElse(flour, ""));
        model.addAttribute("param1", Objects.requireNonNullElse(param1, ""));
        model.addAttribute("param2", Objects.requireNonNullElse(param2, ""));
        model.addAttribute("param3", Objects.requireNonNullElse(param3, ""));

        if (flour == null || flour.isBlank() || flour.isEmpty()) {
            model.addAttribute("errorMessage", this.errorMessageForFlour);
            return "params";
        }

        if (Stream.of(param1, param2, param3)
                .filter(Objects::nonNull)
                .count() < 2) {
            model.addAttribute("errorMessage", this.errorMessageForParams);
            return "params";
        }

        results.put("Flour", flour);

        var params = Stream.of(param1, param2, param3)
                .filter(Objects::nonNull)
                .toList();

        IntStream.range(0, params.size()).forEach(i -> results.put("Additional " + (i + 1), params.get(i)));

        return "redirect:/addons";
    }

    @GetMapping("/addons")
    public String addons(ModelMap model) {
        model.addAttribute("addon", this.addon);
        model.addAttribute("errorMessage", "");
        return "addons";
    }

    @PostMapping("/addons")
    public String AddThird(ModelMap model, @RequestParam String addon) {
        if (addon == null || addon.isBlank() || addon.isEmpty()) {
            model.addAttribute("errorMessage", this.errorMessageForAddon);
            return "addons";
        }

        model.addAttribute("addon", addon);
        results.put("More", addon);
        return "redirect:/result";
    }

    @GetMapping("/result")
    public String result(ModelMap model) {
        model.addAttribute("result", results);
        return "result";
    }
}
