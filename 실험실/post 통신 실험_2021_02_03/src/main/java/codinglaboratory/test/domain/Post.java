package codinglaboratory.test.domain;

import org.springframework.web.bind.annotation.ResponseBody;

public class Post {

    private final long id;
    private final String content;

    public Post(long id, String content) {
        this.id = id;
        this.content = content;
    }

    public long getId() {
        return id;
    }

    public String getContent() {
        return content;
    }
}
