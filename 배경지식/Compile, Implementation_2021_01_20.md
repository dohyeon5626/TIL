# Compile

= **api**

프로젝트에 의해 노출된 API의 일부인 프로젝트의 프로덕션 소스를 컴파일하는 데 필요한 종속성
의존 라이브러리 수정시 해당 모듈을 의존하고 있는 모듈들 또한 재빌드



# Implementation

프로젝트에 의해 노출된 API의 일부가 아닌 프로젝트의 프로덕션 소스를 컴파일하는 데 필요한 종속성
의존 라이브러리 수정시 본 모듈까지만 재빌드



# Compile과 Implementation 차이

![img](https://blog.kakaocdn.net/dn/PER9J/btqCckB6KPf/GoPy5z8AKQNknX7iAWRMWk/img.png)

### Compile의 경우

A라는 모듈을 수정하게 되면, 이 모듈을 **직접 혹은 간접 의존**하고 있는 B와 C는 모두 재빌드 되어야 함

### Implementation의 경우

A라는 모듈을 수정하게 되면, 이 모듈을 **직접 의존**하고 있는 B만 재빌드 함

-> 그래서 **Implementation의 장점**은

1. **빠름**
   구조적으로 봐도 연결된 의존이 적고, 수정이 발생하더라도 recompile(=rebuid)을 적게하니 소요시간이 적음
2. **API의 노출**
   유저가 불필요한 행동을 하지 않게 필요한 API만 노출하는 것은 중요함
   compile의 경우에는 연결된 모든 모듈의 API가 노출됨, 하지만 implementation을 사용하게 되면 이런 일은 없음