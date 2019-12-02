/*
 * capter 6 homework
 */

/*
 * 6.22 
 * the length of inline circle is : 
 * 2*r*x*pi
 * assume it can store length * k(k is a parameter)
 * the remain of r is : r - r*x
 * the data that can save equal : 
 *  (r-r*x)(k*2*r*x*pi) =
 *  M * (r-rx)*rx =
 *  N * (x - x^2) 
 *  if x = 0.5 , the value come to the maxnum
 *
 */

/* 
 * 6.23
 * t1 = 60 * 1000 / 15000 / 2
 *    = 2ms
 * t2 = 4 / 800 * 1/2 = 2ms(we assume that will get 1/2 data)
 * so total = 4 + 2 + 2 = 8ms
 *
 */

/*
 * 6.24
 * Tseek = 4ms
 * Taverage_rotation = 60000 / 15000 * 1/2 = 2ms
 * 2 * 2^20 / 2^9 = 2 ^ 12
 * Tread = 2 ^ 12 * 4/1000 = 16.384
 * T = 16.384 + 4 + 2 = 26.384
 * Trandom = (4 + 2) * 2 ^ 12 = 24576ms
 */

/* 6.25

| cache |  m |  c |  b |  e |  s |  t |  s |  b |
| - | - | - | - |
...
*
*/


