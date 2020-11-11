# 코드잇_CSS 반응형 웹 퍼블리싱

**media queries**

```css
h1{
    font-size: 24px;
}
p{
    font-size:16px;
}
@media(min-width:768px){ // 브라우저의 768이상이면 밑의 속성이 적용됨
    h1{
        font-size: 36px;
    }
    p{
        font-size: 24px;
    }
}
```

만약 조건을 여러게 만들것이면, and를 쓰는데, 띄어쓰기에 유의해야 함(무조건 띄어쓰기 해야함)

```css
@media (조건) and (조건){
}
```