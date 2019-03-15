### Two-dimensional array
A: 3 * 4

|     |  0  |  1  |  2  |  3  |
| --- | --- | --- | --- | --- |
|  0  | 00  | 01  | 02  | 03  |
|  1  | 10  | 11  | 12  | 13  |
|  2  | 20  | 21  | 22  | 23  |  

<br>

Two ways to represent it in memory?
1. `row major`.

`| 00  | 01  | 02  | 03  | 10  | 11  | 12  | 13  |`

If m * n dimensional array then the momory address of A[i][j] would be.<br>
`A[i][j] = ((i * n) + j) * size + base`

2. `column major`

`| 00 | 10 | 20 | 01 | 11 | 21 | `

If m * n dimensional array then the moemory address of A[i][j] would be.<br>
`A[i][j] = ((j * m) + i) * size + base`

<br>

### Binary Addressing

In computer science, everything is in power of two. Because everything is represented by binary.
Here we will calculate how many bits are required to store m * n size of a two-dimensional array.

If array is of size `m * n` then in `A[i][j]`, `j` will always be - `(0 <= j <= n-1)`.
Now suppose `n = 2 ^ k`. This means we need k bits to represent n. Similarly for m `m = 2 ^ l`.


Now if we re-write.

`A[i][j] = ((i * n) + j) * size + base`.

`A[i][j] = ((2 ^ l * 2 ^ k) + j) * 2 ^ x + base`


That means we need `l + k + x` bits to represent this two dimensional array.
