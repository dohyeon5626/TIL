package codinglaboratory.test.Controller;

import codinglaboratory.test.domain.Get;
import org.springframework.web.bind.annotation.*;

import java.util.concurrent.atomic.AtomicLong;

@CrossOrigin
@RestController
public class GetController {
    private final AtomicLong counter = new AtomicLong();
    @GetMapping("/get")
    public Get get_return (@RequestParam(value = "value", defaultValue = "현재 서버로 올라온 값이 없음") String value){
        return new Get(counter.incrementAndGet(), value);
    }
}