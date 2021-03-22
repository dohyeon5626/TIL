package codinglaboratory.test.controller;

import codinglaboratory.test.dto.Get;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.extension.ExtendWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.autoconfigure.web.servlet.WebMvcTest;
import org.springframework.test.context.junit.jupiter.SpringExtension;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.MvcResult;
import org.springframework.test.web.servlet.ResultMatcher;

import static org.assertj.core.internal.bytebuddy.matcher.ElementMatchers.is;
import static org.springframework.test.web.servlet.request.MockMvcRequestBuilders.get;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.jsonPath;
import static org.springframework.test.web.servlet.result.MockMvcResultMatchers.status;

@ExtendWith(SpringExtension.class)
@WebMvcTest(controllers = GetController.class)
public class GetControllerTest {

    @Autowired
    protected MockMvc mvc;
    @Autowired
    private ObjectMapper objectMapper;

    @Test
    public void GetControllerRetrunTest() throws Exception {
        MvcResult result = mvc.perform(get("/get")
                .param("value", "hello"))
                .andExpect(status().isOk())
                .andReturn();
        Get response = objectMapper.readValue(result.getResponse().getContentAsString(), Get.class);
        Assertions.assertEquals(response.getContent(), "hello");
    }
}
