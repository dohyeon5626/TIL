# HTML

- 텍스트 문서
- 태그(꺾쇠 괄호 안에 있는 문자)를 사용, 태그는 쌍을 이룸(열고 닫기)
- 태그를 요소라고도 함
- 열기 태그에는 속성이 있으며, 속성은 요소의 콘텐츠에 대한 설명을 제공, 속성은 이름과 값 필요

# HTML 구조

### <body>

: 요소안에 있는 모든 콘텐츠는 메인 브라우저 창에 표시한다

### <head>

: 페이지에 대한 정보가 포함되어 있다

### <title>

: 브라우저 상단 또는 탭을 제공하는 경우 해당 페이지 탭에 표시 됨



# 워드문서 구조

``` c
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>프론트테스트용</title>
</head>
<body>
    <h1>메인제목</h1>
    <p>전체 페이지를 소개하는 내용을 작성한다. 메인 제목이 긴 경우에는 여러 개의 부 제목으로 나눈다</p>
    <h2>부제목</h2> 
    <p>부제목 내용</p>
    <h3>부제목의 부제목</h3> 
    <p>부제목의 부제목 내용</p>
    <h4>부제목의 부제목의 부제목</h4> 
    <p>부제목의 부제목의 부제목 내용</p>
    <h5>부제목의 부제목의 부제목의 부제목</h5> 
    <p>부제목의 부제목의 부제목의 부제목 내용</p>
    <h6>부제목의 부제목의 부제목의 부제목의 부제목</h6> 
    <p>부제목의 부제목의 부제목의 부제목의 부제목 내용</p>
</body>
</html>
```

![image-20200909170345328](C:\Users\user\AppData\Roaming\Typora\typora-user-images\image-20200909170345328.png)



# 제목

### <h1> <h2> ~ <h6> 

: 여섯 단계의 레벨 제목이 있음 (위에 워드문서 예시를 보면 됨)



# 굵게& 기울임& 위 첨자& 아래 첨자

### <b>

: 굵게

### <i>

: 기울임

### <sup>

: 위첨자로 표시 (수학의 거듭제곱처럼)

### <sub>

: 아래첨자로 표시 (과학의 화학식처럼)



# 공백병합

공백은 두 개 이상이 연속해서 입력되면 하나의 공백으로 처리한다



# 줄바꿈& 가로줄

### <br />

: 줄바꿈

### <hr />

: 가로줄



# 강한 강조& 강조

### <strong>

: 강한 강조 (굵게 표시)

### <em>

: 강조 (기울임꼴 표시)



# 인용

### <blockquote>

: 전체 단락을 차지하는 긴 인용에 사용 (들여써서 표시)

### <q>

: 짧은 인용에 사용



# 약어& 머리글자

### <abbr>

: 약어 및 머리글자

``` html
<p><aabr title="abbreviation">abbr</abbr>의 사전적 의미는 축약어</p>
```



# 인용(참조)& 정의

### <cite>

: 인용 (기울임꼴 표시)

### <dfn>

: 정의 (기울임꼴 표시)



# 작성자 상세정보

### <address>

``` html
<address>
    <p><a href="mailto:homer@example.org">
        homer@example.org</a></p>
    <p>서울특별시 종로구 새문안로 79 (신문로1가)</p>
</address>
```



# 콘텐츠 변경

### <ins>

: 삽입된 콘텐츠 (밑줄)

### <del>

: 삭제된 텍스트 (가운데 줄)

### <s>

: 현재 유효하지 않으나 삭제해서는 안 되는 내용 (가운데 줄)



# 목록

### <li>

: 각 항목은 <li>태그 사이에 배치한다

목록안에 또다른 중첩 목록을 만들 수 있다

## 순서 있는 목록

### <ol>

: 순서 있는 목록

``` html
<ol>
    <li>감자를 강원도에서 가지고 온다</li>
    <li>돈을 까먹었다</li>
    <li>돈을 내러 강원도로 가기 위해 버스를 탄다</li>
    <li>버스비를 까먹었다</li>
</ol>
```

## 순서 없는 목록

### <ul>

: 순서 없는 목록

```html
<ul>
    <li>강원도에 가서 줄 돈</li>
    <li>버스비</li>
    <li>정신줄</li>
</ul>
```



# 정의 목록

```html
<dl>
    <dt>정의할 용어</dt>
    <dd>정의할 용어 설명</dd>
</dl>
```



# 링크 작성

### <a>

: 링크 작성

``` html
<a href="링크페이지">사용자가 클릭할 텍스트</a>
```

### href 속성의 값

**절대 URL**이라고 알려진 사이트의 전체 웹 주소이어야 함

**상대URL**은 웹 주소가 아닌 것을 불러들인다.

### 상대 URL

- 동일한 폴더

  ``` html
  <a href="reviews.html">Reviews</a>
  ```

  파일 명만 작성

- 자식 폴더

  ``` html
  <a href="music/listings.html">Reviews</a>
  ```

  music이라는 폴더안에 listings.html이라는 파일

- 손자 폴더

  ``` html
  <a href="movies/dvd/reviews.html">Reviews</a>
  ```

- 부모 폴더

  ``` html
  <a href="../index.html">Reviews</a>
  ```

  ../는 상위 폴더를 가리킴

- 할아버지 폴더

  ``` html
  <a href="../../index.html">Reviews</a>
  ```



### 이메일 링크

mailto: 를 href 속성의 값으로 시작한다

``` html
<a href="mailto:jon@example.org">존에게 이메일 보내기</a>
```



### 새 창에서 링크 열기

<a>태그에 target 속성을 사용한다. target 속성의 값은 _blank로 설정해야 한다

``` html
<a href="http://www.imdb.com" target="_blank">인터넷 영화 데이터베이스</a> (새창에서 열기)
```



### 동일한 페이지의 특정 부분 링크

이동할 부분에 대해 id 속성을 사용하고, #을 이용해 href에 #이름을 주어 링크한다

``` html
<h1 id="top">영화 제작 용어</h1>
<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />				<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />
<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />				<br /><br /><br /><br /><br /><br /><br /><br /><br /><br /><br />
<p><a href="#top">위로</p>
```



### 다른 페이지의 특정 부분 링크

이동할 부분에 대해 id 속성을 사용하고, #을 이용해 href에 #이름을 주어 링크한다. .다른 파일에 URL은 입력한다

``` html
<h1 id="top">영화 제작 용어</h1>
```

``` html
<p><a href="영화제작용어.html#top">위로</p>
```



# 이미지

### 추가

### <img>

이미지 추가를 위한 요소

- src

  이미지 파일의 위치를 알려줌

- alt

  이미지를 볼 수 없는 경우에 이미지 설명을 위해 이미지에 대한 텍스트 설명

- title

  이미지에 대한 추가 정보 (마우스를 가져가면 titile 속성의 콘텐츠를 말풍선으로 보여줌)

``` html
<img src="images/quokka.jpg" alt="Quokka (Setonix brachyurs)" title="Quokka는 호주에 사는 유대류(marsupial)로 크기는 애완용 정도다" />
```



### 세로& 가로

- height

  이미지의 세로폭을 픽셀 단위로 지정

- width

  이미지의 가로폭을 픽셀 단위로 지정

``` html
<img src="images/quokka.jpg" alt="Quokka (Setonix brachyurus)" width="600" height="450" />
```



### 정렬

- align

  가로는 left와 right를 이용해 정렬, 세로는 top, middle, bottom을 이용함

``` html
<img src="file:///C:/Users/user/Desktop/html_test/quokka.jpg" alt="Quokka (Setonix brachyurus)" title="Quokka는 호주에 사는 유대류(marsupial)로 크기는 애완용 정도다" align="left" />
```



### 이미지 형식

**JPEG** -> 다양한 색상으로 구성된 사진

**GIF, PNG** -> 넓은 영역이 동일한 색상으로 구성돼 있는 사진



### 이미지 해상도

72ppi의 해상도로 저장해야 함

72ppi로 해상도가 제한되어 있고, 해상도가 높아질수록 파일을 로딩하는 시간이 늘어난다



### 벡터 이미지

그리드에 점을 배치하고 이들 점 간에 선을 그려서 만듬

이미지의 크기를 키워도 품질에는 영향이 없음



### 이미지와 캡션

### <figure>

: 하나 이상의 이미지를 포함시켜 동일한 캡션 공유 가능

### <figcaption>

: 캡션 추가

``` html
<figure>
    <img src="images/otters.jpg" alt="물위에 떠 있는 두마리의 수달 사진"/>
    <br />
    <figcaption>바다 수달은 서로 떨어지지 않도록 잠잘 때 손을 잡는다.
    </figcaption>
</figure>
```



# 테이블

### <table>

: 테이블 생성

### <tr>

: 각 행 열기

### <td>

: 각 열 열기

``` html
<table>
    <tr>
        <td>15</td>
        <td>16</td>
        <td>17</td>
    </tr>
</table>
```

결과 -> 15 16 17



### <th>

: 머리말 생성, scope 속성을 사용해 머리말이 열, 행에 대한 것인지 나타낼 수 있다(행은 row, 열은 col)

``` html
<table>
    <tr>
        <th></th>
        <th scope="col">토요일</th>
        <th scope="col">일요일</th>
    </tr>
    <tr>
        <th scope="row">티켓 판매:</th>
        <td>120</td>
        <td>135</td>
    </tr>
    <tr>
        <th scope="row">총 판매:</th>
        <td>$600</td>
        <td>$675</td>
    </tr>
</table>
```

결과 -> 				**토요일**	**일요일**

​			**티켓판매:**   120          135

​			**총 매출:**    $600		 $675

- colspan

  : 열 병합

- rowspan

  : 행 병합

``` html
<table>
    <tr>
        <th></th>
        <th colspan=2>열병합</th>
        <th></th>
    </tr>
    <tr>
        <th rowspan=2>열병합</th>
        <th></th>
        <th></th>
    </tr>
    <tr>
        <th></th>
        <th></th>
    </tr>
</table>
```

### 긴 테이블

### <thead>

: 테이블의 머리말은 <thead> 요소안에 배치해야 함

### <tbody>

: 본문은 <tbody> 요소 안에 배치해야 함

### <tfoot>

: 꼬미말은 <tfoot> 요소안에 배치해야 함

- width

  너비를 지정

- cellpading

  각 셀 내부에 여백 추가

- cellspacing

  각 셀 사이에 여백 추가

- border

  테두리의 두께 지정

- bgcolor

  색깔 지정

# 폼

정보를 기입하는 부분이 있는 인쇄된 문서를 의미

### <form>

: 폼 컨트롤은 <form> 요소 내부에 위치

- action

  정보를 수신할 서버 페이지의 URL

- method

  : 정보 수신 방식을 정해서 폼을 전달

  - get

    동일한 연산을 여러 번 수행하더라도 동일한 결과

  - post

    서버에게 동일한 요청을 여러 번 전송해도 응답은 항상 다를 수 있습니다

``` html
<form action="http://www.example.com/subscibe.php" method="get">
    <p>여기에 폼 컨트롤이 위치함</p>
</form>
```



### <input>

: 폼 컨트롤을 만드는데 사용

- type

  속성의 값으로 입력의 종류를 결정

  - password, text, radio, checkbox, file, submit, image, hidden, date, email, url, search .....등등
    - 참고로 placeholder를 통해 사용자가 해당영역을 클릭할 때까지 텍스트 박스에 설정한 텍스트를 표시할 수 있다

- name

  서버가 어떤 폼 컨트롤에 해당하는지 알기위해 이름을 설정

- size

  입력창의 크기

- maxlength

  사용자가 텍스트 필드에 입력하는 문자의 수를 제한하는 데 사용

<form action="http://www.example.com/subscibe.php">
    <p>사용자명:
        <input type="text" name="username" size="15" maxlength="30">
    </p>
</form>

### <textarea>

: 여러 줄의 텍스트 입력을 만드는 데 사용

### <select>

: 드롭다운 리스트 박스

### <option>

: 사용자가 선택할 수 있는 옵션을 지정하는 데 사용

- value

  컨트롤의 이름과 함께 서버에 전송되는 값

- selected

  기본으로 선택되는 옵션 (사용하지 않으면 첫번째 옵션이 선택됨)

- multiple

  다수의 옵션을 선택 가능

### <button>

: 버튼 생성

### 폼 컨트롤에 레이블 붙이기

### <label>

- for

  id속성값을 이용해 레이블의 크기를 늘림

### 폼 요소 그룹화

### <fieldset>

: 폼 컨트롤들을 그룹화 할 수 있음

### <legend>

: <fieldset> 태그 바로 뒤에 위치하며폼 컨트롤 그룹의 목적을 나타내는 제목을 포함

``` html
<fieldset>
    <legend>연락처</legend>
    <label>이메일:<br />
    <input type="text" name="email" /></label><br />
    <label>휴대전화:<br />
    <input type="text" name="mobile" /></label><br />
    <label>전화:<br />
    <input type="text" name="telephone" /></label><br />
</fieldset>
```

### 폼 유효성 검증

- required

  이 required에 값을 안 주면 값을 넣으라고 뜬다.