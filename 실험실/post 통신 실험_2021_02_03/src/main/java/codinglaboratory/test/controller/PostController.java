package codinglaboratory.test.controller;

import codinglaboratory.test.dto.Param;
import codinglaboratory.test.dto.Post;
import org.springframework.web.bind.annotation.*;

import java.util.concurrent.atomic.AtomicLong;

@RestController
public class PostController {
    private final AtomicLong counter = new AtomicLong();
    @PostMapping("/post")
    public Post post_return (@RequestBody Param param){
        System.out.println(param.getData());
        if(param.getData() == "")
            param.setData("현재 입력된 값이 없습니다");
        return new Post(counter.incrementAndGet(), param.getData());
    }
}