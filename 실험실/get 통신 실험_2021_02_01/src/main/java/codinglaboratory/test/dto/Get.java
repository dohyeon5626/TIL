package codinglaboratory.test.dto;

public class Get {

    private final long id;
    private final String content;

    public Get(long id, String content) {
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
