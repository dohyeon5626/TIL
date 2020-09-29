# FLEXBOX FROGGY

#### 단계 1

**justify-content: flex-end** -> 가로상에서 끝으로 정렬

#### 단계 2

**justify-content: center** -> 가로상에서 가운데로 정렬

#### 단계 3

**justify-content: space-around** -> 가로상에서 공간을 적당히 띄워서 위치시킴

#### 단계 4

**justify-content: space-between** -> 가로상에서 공간을 완전 띄워서 위치시킴(around보다 공간이 더 넓음)

#### 단계 5

**align-items: flex-end** -> 세로선 상에서 끝으로 정렬

#### 단계 6

**justify-content: center** -> 가로상에서 중앙으로 정렬

**align-items: center** -> 세로상에서 중앙으로 정렬

#### 단계 7

**align-items: flex-end** -> 세로상에서 끝으로 정렬

**justify-content: space-around** -> 가로상에서 공간을 적당히 띄움

#### 단계 8

**flex-direction: row-reverse** -> 가로(row)로 거꾸로 정렬

#### 단계 9

**flex-direction: column** -> 세로(column)로 정렬

#### 단계 10

**flex-direction: row-reverse** -> 가로로 거꾸로 정렬 (거꾸로 정렬하면 기준도 거꾸로 됨)

**justify-content: flex-end** -> 가로상에서 끝으로 정렬 (기준이 바뀌어 실제는 앞으로 정렬)

#### 단계 11

**flex-direction: column** -> 세로로 정렬 (가로와 세로의 기준도 뒤바뀜) 

**justify-content: flex-end** -> 가로상에서 끝으로 정렬 (가로와 세로가 바뀌어, 실제는 세로상에서 끝으로 정렬)

#### 단계 12

**flex-direction: column-reverse** -> 세로로 거꾸로 정렬 ( 가로와 세로의 기준 거꾸로)

**justify-content: space-between** -> 가로상에서 공간을 완전 띄움 (실제로는 세로)

#### 단계 13

**align-items: flex-end** ->세로상에서 끝으로 정렬

**justify-content: center** -> 가로상에서 가운데로 정렬

**flex-direction: row-reverse** -> 가로상에서 거꾸로 배치

#### 단계 14

**order: 1** -> 기본값 0보다 크므로 맨 오른쪽으로 이동함

#### 단계 15

**order: -1** -> 기본값 0보다 크므로 맨 왼쪽으로 이동함

#### 단계 16

**align-self: flex-end** -> 세로상에서 끝으로 정렬 (개별적으로 적용)

#### 단계 17

**align-self: flex-end** -> 세로상에서 끝으로 이동

**order: 1** -> 기본값보다 크게하여서 오른쪽으로 위치

#### 단계 18

**flex-wrap: wrap** -> 여러 줄에 걸쳐서 정렬 가능

#### 단계 19

**flex-direction: column** -> 세로로 정렬(가로와 세로 기준 바뀜)

**flex-wrap: wrap** -> 여러 줄에 걸쳐서 정렬 가능

#### 단계 20

**flex-flow: column wrap** -> 세로로 정렬, 여러 줄에 걸쳐서 정렬가능

#### 단계 21

**align-content: flex-start** -> 여러 줄들을 제일 위로 위치

#### 단계 22

**align-content: flex-end** -> 여러 줄들을 제일 아래로 위치

#### 단계 23

**flex-direction: column-reverse** -> 세로로 거꾸로 정렬 (가로와 세로 거꾸로)

**align-content: center** -> 가운데로 정렬 (원래는 가로상에서 가운데지만 가로와 세로가 바뀌어 세로에서 가운데)

#### 단계 24

**flex-direction: column-reverse** -> 세로로 거꾸로 정렬 (가로 세로 기준 바뀜)

**flex-wrap: wrap-reverse** -> 여러줄에 걸쳐 정렬, 항목 순서는 역방향

**justify-content: center** -> 가로로 가운데로 정렬 (기준이 바뀌어 실제로는 세로로)

**align-content: space-between** -> 세로로 공간을 완전 띄움 (실제로는 가로로)

# 개념 총정리

#### justify-content:

**(기준선을 기준으로 가로)**

1. flex-start : 기본 설정으로, 플렉스 요소는 플렉스 컨테이너의 앞쪽에서부터 배치
2. flex-end : 플렉스 요소는 플렉스 컨테이너의 뒤쪽에서부터 배치
3. center : 플렉스 요소는 플렉스 컨테이너의 가운데에서부터 배치
4. space-between : 플렉스 요소는 요소들 사이에만 여유 공간을 두고 배치
5. space-around : 플렉스 요소는 앞, 뒤, 그리고 요소들 사이에도 모두 여유 공간을 두고 배치

#### align-items: 

**(기준선을 기준으로 세로)**

1. stretch : 기본 설정으로, 플렉스 요소의 높이가 플렉스 컨테이너의 높이와 같게 변경된 뒤 연이어 배치
2. flex-start : 플렉스 요소는 플렉스 컨테이너의 위쪽에 배치
3. flex-end : 플렉스 요소는 플렉스 컨테이너의 아래쪽에 배치
4. center : 플렉스 요소는 플렉스 컨테이너의 가운데에 배치
5. baseline : 플렉스 요소는 플렉스 컨테이너의 기준선(baseline)에 배치

#### flex-direction: 

**(기준선을 바꿈)**

1. row : 기본 설정으로, 플렉스 요소는 왼쪽에서 오른쪽으로, 그리고 위쪽에서 아래쪽으로 배치 (기준선: →)
2. row-reverse : 만약에 direction 속성값이 ltr(left-to-right)이면, 플렉스 요소는 반대로 오른쪽에서 왼쪽으로 배치 (기준선: ←)
3. column : 만약에 쓰기 방식이 수평이면, 플렉스 요소는 수직 방향으로 위쪽에서 아래쪽으로 배치 (기준선: ↓)
4. column-reverse : 만약에 쓰기 방식이 수평이면, 플렉스 요소는 수직 방향으로 아래쪽에서 위쪽으로 배치 (기준선: ↑)

#### order:
기본값은 0으로 순서를 지정할 때 사용

#### flex-wrap: 

1. nowrap : 기본 설정으로, 플렉스 요소가 다음 줄로 넘어가지 않습니다. 대신에 플렉스 요소의 너비를 줄여서 한 줄에 모두 배치
2. wrap : 플렉스 요소가 여유 공간이 없으면 다음 줄로 넘어가서 배치
3. wrap-reverse : 플렉스 요소가 여유 공간이 없으면 다음 줄로 넘어가서 배치 (단, 아래쪽이 아닌 위쪽으로 넘어감)

#### align-self:
플렉스 컨테이너의 align-items 속성보다 우선 적용 -> 각자 다른 속성 적용 가능