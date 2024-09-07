# [Gold III] Candy Cane Feast - 31063 

[문제 링크](https://www.acmicpc.net/problem/31063) 

### 성능 요약

메모리: 11480 KB, 시간: 96 ms

### 분류

애드 혹, 구현, 시뮬레이션

### 제출 일자

2024년 9월 7일 11:51:45

### 문제 설명

<p>Farmer John's cows have quite the sweet tooth, and they especially enjoy eating candy canes! FJ has $N$ total cows, each with a certain initial height and he wants to feed them $M$ candy canes, each also of varying height ($1\le N,M\le 2\cdot 10^5$).</p>

<p>FJ plans to feed the candy canes one by one to the cows, in the order they are given in the input. To feed a candy cane to his cows, he will hang the candy cane so that initially the candy cane is just touching the ground. The cows will then line up one by one, in the order given by the input, and go up to the candy cane, each eating up to their height (since they cannot reach any higher). The candy cane stays suspended in place where it is initially set up and is not lowered to the ground, even after cows eat the bottom of the candy cane. It is possible a cow may eat nothing during her turn, if the base of the candy cane is already above that cow's height. After every cow has had their turn, the cows grow in height by how many units of candy cane they ate, and Farmer John hangs the next candy cane and the cows repeat the process again (with cow 1 again being the first to start eating the next candy cane).</p>

### 입력 

 <p>The first line contains $N$ and $M$.</p>

<p>The next line contains the initial heights of the $N$ cows, each in the range $[1,10^9]$.</p>

<p>The next line contains the heights of the $M$ candy canes, each in the range $[1,10^9]$.</p>

### 출력 

 <p>The final heights of each of the $N$ cows on separate lines.</p>

<p><strong>Note that the large size of integers involved in this problem may require the use of 64-bit integer data types (e.g., a "long long" in C/C++).</strong></p>

