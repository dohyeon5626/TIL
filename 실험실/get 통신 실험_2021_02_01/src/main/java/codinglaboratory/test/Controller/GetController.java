package codinglaboratory.test.Controller;

import com.google.gson.Gson;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.concurrent.atomic.AtomicLong;

@CrossOrigin
@RestController
public class GetController {
    private final AtomicLong counter = new AtomicLong();
    Gson gson = new Gson();
    @GetMapping("/get")
    public String get_return (@RequestParam(value = "value", defaultValue = "현재 서버로 올라온 값이 없음") String value){
        return  gson.toJson(new Get(counter.incrementAndGet(), value));
    }
}
