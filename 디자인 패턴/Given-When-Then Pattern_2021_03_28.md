# Given-When-Then Pattern

**[준비 - 실행 - 검증] 순서로 이루어지는 테스트 코드를 작성하는 표현 방식**

아주 간단하지만, 테스트 코드를 작성 할때 [준비 - 실행 - 검증] 세 부분으로 나누기만 하면 됨

#### 예

```
기능 : 사용자 주식 트레이드
시나리오 : 트레이드가 마감되기 전에 사용자가 판매를 요청
```

```
"Given"
나는 MSFT 주식을 100 가지고 있다.
그리고 나는 APPL 주식을 150 가지고 있다.
그리고 시간은 트레이드가 종료되기 전이다.

"When"
나는 MSFT 주식 20 팔도록 요청했다.

"Then"
나는 MSFT 주식 80을 가지고 있어야 하며, APPL 주식은 150 가지고 있다.
그리고 MSFT 주식 20이 판매 요청이 실행되었어야 함
```



### 예시

```java
 @Test
public void GetControllerRetrunTest() throws Exception {
    //given
	    /*given은 이 상황에서는 없음*/
    //when
	MvcResult result = mvc.perform(get("/greet") // '/greet'로 get방식으로 요청을 보냄
		.param("value", "hello"))
		.andExpect(status().isOk())
		.andReturn();
    //then
	Get response = objectMapper.readValue(result.getResponse().getContentAsString(), Get.class); // 요청을 다시 받아서 객체에 넣음
	Assertions.assertEquals(response.getContent(), "hello"); // 요청이 기대한 바와 맞는지 비교
}
```

