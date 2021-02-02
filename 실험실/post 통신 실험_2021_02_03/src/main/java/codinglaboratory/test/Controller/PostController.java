package codinglaboratory.test.Controller;

import codinglaboratory.test.domain.Param;
import codinglaboratory.test.domain.Post;
import org.springframework.web.bind.annotation.*;

import java.util.concurrent.atomic.AtomicLong;

@CrossOrigin
@RestController
public class PostController {
    private final AtomicLong counter = new AtomicLong();
    @PostMapping("/post")
    public Post post_return (@RequestBody Param param){
        if(param.getData() == "")
            param.setData("현재 입력된 값이 없습니다");
        return new Post(counter.incrementAndGet(), param.getData());
    }
}