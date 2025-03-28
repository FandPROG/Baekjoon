# [Platinum IV] 사탕 항아리 - 1829 

[문제 링크](https://www.acmicpc.net/problem/1829) 

### 성능 요약

메모리: 7300 KB, 시간: 72 ms

### 분류

비트마스킹, 해 구성하기, 구현, 수학

### 제출 일자

2025년 3월 27일 15:26:55

### 문제 설명

<p>N개의 항아리에 사탕이 들어 있다. 첫 번째 항아리에는 K개의 사탕, 두 번째 항아리에는 하나 많은 K+1개의 사탕이 들어 있다. 마찬가지로 항아리의 번호가 1만큼 커질 때마다 항아리에 들어 있는 사탕의 개수도 1개씩 증가하여, 마지막 N번째 항아리에는 K+N-1개의 사탕이 들어 있다.</p>

<p>사탕을 꺼내는 방법은 다음과 같다. 먼저 N개의 항아리 중에서 임의로 몇 개의 항아리를 고른다. 이렇게 고른 항아리에서 같은 개수의 사탕을 각각 꺼낸다. 물론 항아리에 들어 있는 사탕의 개수가 꺼내려는 사탕의 개수보다 작아서는 안 된다.</p>

<p>사탕을 좋아하는 순일이는 최대한 빨리 모든 사탕을 꺼내고 싶다. N과 K가 주어지면 주어진 방법을 가능한 적은 횟수로 사용하여 항아리에 들어 있는 모든 사탕을 꺼내는 방법을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N(1 ≤ N ≤ 100,000)과 K(1 ≤ K ≤ 500,000)가 빈 칸을 사이에 두고 주어진다. 모든 항아리에는 순서대로 1번부터 N번까지 번호가 매겨져 있다.</p>

### 출력 

 <p>첫째 줄에는 방법을 사용한 최소 횟수 M을 출력한다. 이어서 사용한 방법에 대한 구체적인 정보를 다음과 같이 한 방법에 대해 두 줄씩 총 2×M개의 줄에 걸쳐 순서대로 출력한다. 각 정보는 다음과 같이 출력한다.</p>

<p>첫째 줄에는 선택한 항아리의 개수와 사탕 몇 개를 꺼낼 건지를 출력한다. 둘째 줄에는 선택한 항아리의 번호를 공백으로 구분하여 출력한다. 예를 들어, 1,3,4,5번 항아리에서 사탕 3개를 꺼낸다면</p>

<pre>4 3
1 3 4 5</pre>

<p>와 같이 출력하면 된다.</p>

