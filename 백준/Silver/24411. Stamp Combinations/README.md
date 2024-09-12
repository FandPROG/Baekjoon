# [Silver I] Stamp Combinations - 24411 

[문제 링크](https://www.acmicpc.net/problem/24411) 

### 성능 요약

메모리: 11612 KB, 시간: 304 ms

### 분류

이분 탐색, 브루트포스 알고리즘, 자료 구조, 해시를 사용한 집합과 맵, 누적 합, 트리를 사용한 집합과 맵

### 제출 일자

2024년 9월 12일 11:05:10

### 문제 설명

<p>You’re on your way to pick up a package from the store, wrap it, and mail it. You want to bring a certain number of stamps to mail it, and you have a long roll of stamps that you can use. Now, over time, you’ve occasionally pulled off a stamp from somewhere in the middle of the roll, and now you’re left with a strip where stamps are clustered in groups, separated by empty spaces.</p>

<p>Being practical, you don’t want to tear individual stamps, and so you’ll only tear the roll in between the clusters of stamps. And, you don’t want to be left with multiple rolls of stamps, so you can only pull these groups off of the beginning or end of the roll. Is it possible to do this with the roll of stamps you have?</p>

### 입력 

 <p>The first line of input consists of two integers, $m$ and $n$, $1 ≤ m, n ≤ 10^6$, $1 ≤ m \cdot n ≤ 10^7$, giving the number of clusters of stamps and the number of queries you will have.</p>

<p>The second line contains $m$ integers, $a_i$, $1 ≤ a_i ≤ 100$, separated by spaces. These give the number of stamps in each cluster, in order from the beginning to the end of the roll.</p>

<p>The next $n$ lines each contain one integer, $q$, $0 ≤ q ≤ 10^8$, giving a query, where a query is the number of stamps needed to mail a package.</p>

### 출력 

 <p>For each query, output one line containing “<code>Yes</code>” if it is possible to bring that number of stamps, or ‘<code>No</code>” if it is not possible to bring that number of stamps.</p>

