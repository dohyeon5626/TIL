# 코드잇_프로그래밍 핵심 개념 in JavaScript

**숫자형**
거듭제곱 -> ** (거듭제곱이 곱셈보다 우선순위 높음)

``` javascript
var a=1;
var b=2;
console.log(a**b); // 1
```

단항 부정 -> - 

``` javascript
var a=5;
console.log(-a); //-5
```



**문자열**
'와 ', "와 "로 감싸져 있음
'은 무조건 '로 끝나고, "은 무조건"로 끝나야 함

```javascript
console.log('I'm Iron man'); // 오류남 '가 생겨서 문제가 생김
console.log("I'm Iron man"); // "을 이용해서 인식을 할 수 있도록 함
console.log("I\'m Iron man"); // 앞에 \을 이용해서 인식을 할 수 있도록 함
console.log(`I\'m Iron man`); // `을 이용함
```

문자열에서 덧셈은 문자열을 연결하라는 뜻

```javascript
console.log('Hello'+'World'); // HelloWorld로 출력
```



**불린 형**
값은 참과 거짓만 있음
연산은 and, or not만 있음

```javascript
console.log(a>b);
console.log(a<b);
console.log(a>=b);
console.log(a<=b);
console.log(a==b); // 같음 (숫자1과 문자1은 같음)
console.log(a===b); // 정확히 일치 (숫자1와 문자1은 같지 않음)
console.log(a!=b); // 다름 (숫자1과 문자1은 다르지 않음)
console.log(a!==b); // 정확히 다름 (숫자1과 문자1은 다름)
console.log(a&&b);
console.log(a||b);
console.log(!a);
```



**typeof**
자료형을 알려줌, answkduffh flxjs

```javascript
console.log(typeof 101); // number
console.log(typeof 'Hello'); // string
console.log(typeof true); // boolean
```



**형변환**
자바스크립트는 자동으로 형변환을 할때도 있음

``` javascript
console.log('10'+'5'); // 105
console.log(Number('10')+Number('5')); // 15
```

산술 연산자는 Number로 바꾸어 연산(+연산은 두가지 기능이 있어 문자열에서 예외가 나옴)
+연산은 한쪽이 문자열이면 문자열로 변환

```javascript
console.log('4'-true); // 3
```

관계 비교 연산자는 Boolean으로 바꾸어 연산 (일치, 불일치는 형변환이 일어나지 않음)

``` javascript
console.log(1==='1'); // false
console.log(1===true); // false
console.log(1=='1'); // true
console.log(1==true); // true
```



**템플릿 문자열**

```javascript
console.log('생년월일은 ' + year + '년 ' + month + '월 ' + day + '일');
console.log(`생년월일은 ${year}년 ${month}월 ${day}일`);
```

`을 써서 간단히 나타낼 수 있음
${}안에 변수만 아니라 함수도 넣을 수 있음



**null과 undefined**
둘다 '값이 없다'라는 뜻을 가진 자료형 (실제는 서로 다른 자료형임)

- null
  의도적으로 표현할 때 사용하는 값
  코드를 쓰는 사람이 변수에 값이 없다고 표현할 때, null을 집어넣음
- undefined
  값이 없다는 것을 확인하는 값 (처음부터 없음)
  선언 후 값이 없는 변수에는 기본적으로 undefined가 들어있음
  굳이 undefined값을 넣을려 하면 넣을 수는 있으나, 권장하지 않음

==은 true, ===은 false가 됨



**할당 연산자**
오른쪽에 있는 피연산자를 왼쪽에 있는 피연산자의 값을 대입함

``` javascript
x=4;
x=x-2;
```



**복합 할당 연산자**
할당 연산자와 결합해서 자주 쓰이는 표현을 간략하게 쓸 수 있게 해주는 연산자 (C와 유사)

``` javascript
x=x+1;
x+=1;
x++;

x=x*2;
x*=2;
```



**함수**
함수 선언 시 function을 붙여 선언

```javascript
function 함수이름 ( 변수, 변수){
    코드
}
```



**return 문**
값을 반환시킴 (함수가 위치한 자리에), return하는 순간 함수는 끝이 남

``` javascript
function 함수이름 (변수, 변수){
    코드
    return 값;
}
console.log(함수이름(변수, 변수)); // 값
```



**옵셔널 파라미터**
함수에서 미리 값을 할당 (값이 안 들어올 경우를 대비해)

```javascript
function hello(name){
    console.log(name); // 값이 안 들어오면 undefined가 뜸
}
```

```javascript
function hello(name = '홍길동'){
    console.log(name); // 값이 안 들어오면 홍길동이 뜸
}
```

옵셔널 파라미터는 뒤에서부터 선언



**상수**
변하지 않고 값이 일정한 수
변수를 선언할 때 const로 선언하면 상수로 취급됨
재할당이 불가하여, 선언할 때 할당을 해야하며, 값을 보호할 수 있음
이름을 지을때 밑줄과 대문자를 씀(상수인 것을 알기위해)



**if문**

```javascript
if(조건1){
	코드
}
else if(조건2){
    코드 
}
else{
    코드
}
```



**switch문**

```javascript
switch (비교할 값){
    case 조건값_1:
        코드
        break; // break가 없으면 밑에 있는 코드도 실행함
    case 조건값_2:
        코드
        break;
    default: // 모든 조건값에 만족하지 않으면
        코드
}
```

비교할 때 자료형을 엄격히 비교함



**for문**

``` javascript
for(초기화 부분; 조건부분; 추가동작 부분){
    코드
}
```



**while문**

``` javascript
while(조건){
	코드
}
```



**break문**
반복문을 나감



**continue문**
반복문의 다음 작동과정으로 넘어감