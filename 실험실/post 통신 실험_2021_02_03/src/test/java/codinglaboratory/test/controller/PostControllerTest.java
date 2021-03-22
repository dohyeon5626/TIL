package codinglaboratory.test.controller;

import codinglaboratory.test.dto.Param;
import codinglaboratory.test.dto.Post;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.http.MediaType;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;

import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.post;
import static org.springframework.test.web.servlet.result.MockMvcResultHandlers.print;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;


@ExtendWith(SpringExtension.class)
@WebMvcTest(controllers = PostController.class)
public class PostControllerTest {
    @Autowired
    protected MockMvc mvc;
    @Autowired
    private ObjectMapper objectMapper;

    @Test
    public void PostControllerRetrunTest() throws Exception {
        String content = objectMapper.writeValueAsString(new Param("hello"));
        MvcResult result = mvc.perform(post("/post")
                .content(content)
                .contentType(MediaType.APPLICATION_JSON)
                .accept(MediaType.APPLICATION_JSON)).andDo(print())
                .andExpect(status().isOk())
                .andReturn();

        Post response = objectMapper.readValue(result.getResponse().getContentAsString(), Post.class);

        Assertions.assertEquals(response.getContent(), "hello");
    }
}
