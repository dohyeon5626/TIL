package codinglaboratory.test.dto;

public class Get {

    private long id;
    private String content;

    public Get(){}

    public Get(long id){
        this.id = id;
    }

    public Get(String content){
        this.content = content;
    }

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
