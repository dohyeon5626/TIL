# 코드잇_CSS 핵심개념

![Jenna Espezua's Blog | CSS Positioning: Padding vs. Border vs. Margin](https://espezua.github.io/blog/imgs/boxmodel.png)

위와 같은 그림을 **Box Model**이라고 하는데
content는 내용이 들어가는 부분
padding은 요소내의 내부여백
border의 경우에는 테두리
margin은 요소와의 다른요소와의 여백(외부와의)
크기를 설정할때 top-right-bottom-left 순서로 값을 줌

```css
*{
    padding: 1px 2px 3px 4px
}
```



**widht, height**
width는 가로길이, height는 세로길이를 의미
하지만, min은 최소를 설정하고, max는 최대를 설정할 수 있음 (페이지의 크기를 바꿀 때)

``` javascript
*{
    width: 10px;
    height: 20px;
    min-width: 3px;
}
```



**overflow**
넘쳐나는 부분을 어떻게 할 건지 처리하는 부분

```css
p{
    overflow:visible; // 삐져나오게 설정 (기본값)
}
p{
    overflow:hidden; // 숨기기
}
p{
    overflow:scroll; // 스크롤할 수 있도록 설정(위아래로), 스크롤바가 필요 없어도 나옴
    overflow:auto; // 스크롤과 같으나, 넘치지 않을 경우 스크롤바가 안 나옴
}
```



**박스 꾸미기**

``` css
*{
    border-radius: 50px; // 모서리 둥글게
    box-shadow: 50px 10px red; // 그림자
    background-color: blue; // 배경색 (배경 투명은 transparent의 값으로 설정)
}
```



**box-sizing**
모든 box model을 생각하기 힘들어, 계산하기 싶도록 만들기 위해 사용

``` css
box-sizing: border-box; // 크기가 border까지 생각
```



**배경이미지**

```css
background-images: 값;
background-repeat: repeat; // 사진이 반복되도록 설정
background-size: cover; // 원래 비율을 유지하며 꽉 채움
background-position: center center; // 가운데로 위치설정
```



**선택자**

```css
h1{} // 태그이름
#hello{} // 아이디
.world{} // 클래스
부모 자식{} // 부모가 가지고 있는 요소의 자식
부모 > 직속_자식{} // 부모가 가지고 있는 요소의 직속 자식(바로)
.one, .two{} // 복수선택
.one.two{} // 클래스가 one도 있고, two도 둘 다 가지는 태그
```

이외에 가상 클래스는 :을 이용해서 씀

```css
.div1 p:nth-child(3) {} // .div1의 자식인 <p> 태그 중 3번째
.div1 p:first-child {} // .div1의 자식인 <p> 태그 중 첫 번째
.div1 p:last-child {} // .div1의 자식인 <p> 태그 중 마지막
무엇:hover{} // 마우스가 올라갈 때
```



**상속**
부모의 속성이 자식의 속성에 적용되는 것
상속이 되는 속성과 상속이 안되는 속성이 있음



**inline과 block**
inline은 다른 요소들과 같은 줄에 머무르려고 함, 가로길이를 필요한 만큼만 차지 함
block은 새로운 줄로 갈려고 하고, 가로길이를 최대한 많이 차지 함



**inline-block**
inline의 성질을 가지며, block처럼 크기를 조절할 수 있는 성질도 가짐



**vertical-align**
baseline을 바꿀 수 있음
여기서 baseline은 나열하는 기준이라고 생각하면 됨

```css
vertical-align: middle; // 부모의 baseline에 자신의 가운데를 맞춤
```



**positon**
요소의 위치를 변경할 수 있음
기본값은 static으로 되어있음
static이나 relative는 둘다 원래 위치를 나타내나, relative는 위치를 바꿀 수 있음
absolute는 부모의 위치에 따라 변경할 수 있음
fixed는 화면을 기준으로 변경할 수 있음



**float**
다른요소들 위로 붕뜬다고 생각하면 쉬움
하지만, 인라인요소는 떠있는(float)공간에 갈 수 없음, 실제는 다른요소가 공간을 차지하지만, 인라인 요소인 글과 같은 요소들은 그 공간에 가지 없음으로서 붕 떠있는 공간 주변을 인라인 요소가 차지하게 됨



**clear**
다른 요소가 자신의 왼쪽 또는 오른쪽에 없도록 치우는 역할



**리스트 스타일링**
list-style을 이용해 스타일링이 가능함