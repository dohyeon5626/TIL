# 코드잇_프로그래밍과 데이터 in JavaScript

**객체 (object)**
객체는 중괄호({})를 이용해 만들 수 있음

``` javascript
{
    값의 이름(key):값(value), // 이 한줄을 속성(Property)라고 함
    값의 이름(key):값(value), // key는 문자열이지만, ','나 ","로 감쌀 필요없음 (알아서 형변환 함)
    값의 이름(key):값(value)
}
```

key의 이름을 지을때는 첫 글자는 반드시 문자, 밑줄(_), 달러기호($)로 시작, 띄어쓰기 금지, 하이픈(-)이 금지
만약 어기게 된다면, ','나 ","로 감싸면 가능

value에는 어떤 자료형이든 올 수 있고, 객체를 넣음으로써 객체안에 객체를 넣을 수 있음

객체의 자료형은 객체로 typeof로 출력하면 object가 뜸



**객체에서 데이터 접근**

```javascript
let dohyeon = {
    name : 'dohyeon',
    'born Year': 2004
}
```

- 점 표기법

  ``` javascript
  console.log(dohyeon.name); // 띄어쓰기가 있으면 접근이 안됨
  ```

- 대괄호 표기법

  ```javascript
  console.log(dohyeon['born Year']); // 띄어쓰기가 있어도 가능
  console.log(dohyeon['born '+ 'Year']); // 값을 활용 가능
  ```

객체안의 객체는 계속 이어가면 접근 가능

``` javascript
let dohyeon = {
    name : 'dohyeon',
    'born data': {
        year : 2004,
        month : 3,
        day : 1
    }
}
console.log(dohyeon['born data']['year']);
```



**객체의 다루기**

```javascript
let dohyeon = {
    name : 'dohyeon',
    'born data': {
        year : 2004,
        month : 3,
        day : 1
    }
}
```

- property 값 바꾸기

  ``` javascript
  dohyeon.name = '고도현';
  console.log(dohyeon.name); // 고도현
  ```

- property 추가

  ```javascript
  dohyeon.from = 'jeju'; // 원래 없던 key에 값을 넣으면 생성이 됨
  console.log(dohyeon.from); // jeju
  ```

- property 삭제

  ``` javascript
  delete dohyeon['born data']; // 앞에  delete를 넣으면 삭제 가능
  console.log(dohyeon['born data']); // undefined
  ```

- property 존재 확인

  ``` javascript
  console.log(dohyeon.name !== undefined); // 있으면 true 없으면 false
  console.log('name' in dohyeon) // 있으면 true 없으면 false
  ```



**메서드**
객체가 가지고 있는 동작, 객체 내의 함수를 메서드라고 함

``` javascript
let greetings = {
    sayHello:function(){
        console.log('Hello!');
    },
    sayHi:function(){
        console.log('Hi!');
    },
    sayBye:function(){
        console.log('Bye!');
    }
}
```

- 접근방식

  ```javascript
  greetings.sayHello();
  greetings['sayHello']();
  ```

메서드를 쓰면 이름 중복을 피할 수 있고 객체에 집중해 함수의 동작부분을 짤 수 있음



**for...in 반복문**

``` javascript
for (변수 in 객체){  // 변수가 객체의 key값만 계속 받는다
    코드
}
```

객체는 정수형 property 이름을 오름차순으로 먼저 정렬하고, 나머지들은 추가한 순서대로 정렬하는 특징이 있음
-> 순서대로 for..in 반복문에서 나오지 않는 것을 생각해야 하고, 그에 맞게 이름을 지어야 함



**Date 객체**
내장 객체(자바스크립트가 미리 가지고 있는 객체)

```javascript
let my Date = new Date(); // The May 18 2017 00:00:00 GMT+0900
```

현재 시간을 요일, 월, 일, 년도, 시간, 시간대가 저장됨

```javascript
new Date(특정한 값); // 숫자
```

1970년 1월 1일 00:00:00 UTC를 특정한 값 정도의 밀리초가 지난 시간 객체가 만들어짐

```javascript
new Date('문자열'); // 년도-월-일  (YYYY-MM-DD)
new Date('문자열'); // 년도-월-일T시간:분:초  (YYYY-MM-DDThh:mm:ss)
```

정확한 시간을 주기 위해서는 이런식으로 문자열을 넣으면 가능함
정확한 시간을 설정하지 않으면 00:00:00(자정)으로 설정됨

다른 방법으로는

```javascript
new Date(YYYY, MM, DD, hh, mm, ss, ms);
```

연도와 월을 배고는 생략가능
생략시 DD->1, hh~ms->0으로 기본값이 주어짐

주의할 점은 MM(월)만 0부터 시작하여 우리가 생각하는 1월은 0으로 표현된다는 점

- getTime 메서드

  ``` javascript
  myDate.getTime();
  ```

  1970년 1월 1일 00:00:00 UTC부터 몇 밀리초 지났는지(타임스탬프) 계산해 줌

그밖에도 getDay, get Date 등등 많은 메서드가 존재함



**배열**
중괄호({})대신 대괄호([])을 이용해 만듬
객체지만, 순서가 더 중요할 때

```javascript
let 배열이름 = {
    값,
    값,
    값
}
```

- 접근방식

  ``` javascript
  배열이름[index];
  ```

  인덱스는 0부터 시작함

- 배열을 다루기
  배열도 객체이고, 자바스크립트에서 제공하는 많은 메서드가 있음

  - length

    ``` javascript
    배열이름.length
    배열이름["length"]
    ```

  배열을 추가하는 것도 객체와 같음

  ``` javascript
  배열이름[원래 최대 인덱스+1] = 값; // 중간에 뛰어넘어서 추가하면 undefined가 할당된 공간이 생김
  ```

  배열에서 삭제하는 방법은 제공하는 메서드를 활용해야 함

  - splice

    ``` javascript
    배열이름.splice(인덱스); // 인덱스 뒤에 오는 모든 요소를 삭제
    배열이름.splice(인덱스, 개수); // 인덱스 뒤에 오는 요소를 개수만큼 삭제
    배열이름.splice(인덱스, 개수, 값, 값....); // 인덱스 뒤에 오는 요소를 개수만큼 삭제하고 그자리에 값을 넣음, 개수를 0으로 하면 원하는 위치에 값을 집어 넣을 수 있음
    ```

  배열의 첫 요소를 삭제

  - shift

    ``` javascript
    배열이름.shift();
    ```

  배열의 마지막 요소를 삭제

  - pop

    ``` javascript
    배열이름.pop();
    ```

  배열의 첫 요소로 값 추가

  - unshift

    ``` javascript
    배열이름.unshift(값);
    ```

  배열의 마지막 요소로 값 추가

  - push

    ``` javascript
    배열이름.push(값);
    ```

  배열에서 특정 값을 찾기

  - indexOf

    ``` javascript
    배열이름.indexOf(특정 값)
    ```

    포함되어 있으면, 특정 값이 있는 인덱스가 리턴, 포함되어 있지 않으면 -1이 리턴되며, 여러번 포함되면 처음 발견된 인덱스가 리턴됨

  - includes

    ``` javascript
    배열이름.includes(특정 값)
    ```

    포함되어 있으면 true, 아니면 false가 리턴됨 (여부만 확인)

  배열 뒤집기

  - reverse

    ``` javascript
    배열이름.reverse();
    ```

    배열의 순서를 뒤집음



**for...of 반복문**

``` javascript
for (변수 of 배열){
    코드
}
```

for..in 반복문은 프로퍼티 네임이 할당된 것에 반해
for...of 반복문은 배열의 요소가 할당됨



**다차원배열**
배열안에 배열이 있음

``` javascript
let 배열이름 = [[1,2],[3,4]];
배열이름[인덱스][인덱스]; // 접근 방식
```



**숫자표기**

``` javascript
let a = 1000000000;
let b = 1e9; // 1000000000을 간결하게 표현가능 (지수표기법)
let c= 1e-9; // 소수도 이런식으로 표현 가능
//16진수 0x(16진수)
let hex1 = 0xff; // 255
let hex1 = 0xFF; // 255
//8진수 0o(8진수)
let octal = 0o377 // 255
//2진법 0b(2진수)
let binary = 0b11111111 // 255
```



**숫자형 메서드**
숫자도 객체이므로 메서드가 있음

- toFixed

  ``` javascript
  숫자.toFixed(자리수) // 소수점 밑에 자리수 바로 뒤에 숫자를 반올림하여 자리수 만큼 나타냄
  ```

  자리수를 넘으면 0으로 채워짐 (리턴값은 문자열), 앞에 +를 붙이면 쉽게 number로 만들 수 있음

- toString

  ``` javascript
  숫자.toString(어떤 진수로 바꿀건지);
  ```

  리턴값은 문자열

주의할 점
숫자 바로 뒤에 점을 찍으면 소수점으로 인식해 두개의 점을 찍거나, 괄호로 감싸거나, 변수에 담아서 사용해야 함

숫자형 메서드 말고 Math객체와 같은 것들이 있어서, 숫자를 쉽게 사용할 수 있음



**계산문제**
컴퓨터와 사람이 쓰는 숫자의 차이가 있어 오차가 생김

``` javascript
let sum = 0.1 + 0.2;
console.log(sum); // 0.30000000000000004 (오류)
```

이문제를 해결하기 위해 필요한 자리수에 맞추어 반올림을 시킴



**문자열**
문자열은 하나하나를 접근가능

``` javascript
문자열[숫자];
문자열.chatAt(숫자)
```

- toUpperCase / toLowerCase

  ``` javascript
  문자열.toUpperCase() // 대문자
  문자열.toLowerCase() // 소문자
  ```

- trim

  ``` javascript
  문자열.trim() // 양 끝 공백 제거
  ```

- slice

  ``` javascript
  문자열.slice( 시작 지점, 마지막 지점)
  ```

  문자열을 시작지점부터 마지막 지점까지 잘라내어 새로운 문자열을 반환시켜줌



**자료형**
객체(object)를 제외한 모든 자료형을 기본형(Number, String, Boolean, Null, Undefined)이라고 함



**객체 값 할당**

``` javascript
let x = {객체} // x에는 객체의 주소 저장
let y =x; // y에 x가 받은 객체의 주소 저장
```

이런 상황에서는 y에 x의 값을 전달해 주는데, x에 객체를 주는 과정에서 주소를 주었기에, y도 x와 같이 주소를 받아 y로 객체를 변경한다면, x의 객체도 같으므로 객체가 변경됨



**참조형 복사**
바로 위의 개념처럼 객체에 값을 할당할 때 주소가 복사되어, 값을 바꾸며 둘다 값이 바뀜, 이런 상황이 아닌, 값만 복사하고 싶을때가 있을 수 있음

- 배열의 경우에는 slice를 이용해 값만 전달할 수 있음

  ``` javascript
  배열2 = 배열1.slice(); // 값을 안 넣으면 통째로 들어감
  ```

- 객체의 경우 Object.assign을 쓰면 가능함

  ```javascript
  변수 = Object.assign({},객체)
  ```

- 빈 객체를 만든 후 반복문으로 값을 옮김
  주의할 점은 객체안의 객체도 주의해야 함



