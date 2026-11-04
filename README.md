# C-Prime-Number-Checker

A prime number checker written in **C** as a college practical. It tests a number by trying only odd divisors up to its square root and stops as soon as it finds one.

## How it works

1. **Negative numbers** are rejected immediately.
2. **0 and 1** are not prime.
3. **2** is the only even prime.
4. **Any other even number** is not prime.
5. **Odd numbers greater than 2** are tested by dividing by 3, 5, 7, ... while `i * i <= num`.
   - If any `i` divides `num`, the program prints "not prime" and exits right away.
   - If no `i` divides `num`, the number is prime.

## Why it's fast

| Idea | Effect |
|---|---|
| Handle even numbers first | Half of all numbers are decided in one check |
| Test only odd divisors (`i += 2`) | Half as many loop steps |
| Stop at `i * i <= num` | If `num` has a divisor larger than its square root, it must also have a smaller one, so checking past the square root is wasted work. This takes the loop from about `n / 2` steps down to about `sqrt(n) / 2` |
| Exit at the first divisor | A composite number is usually caught in a few steps |

## Example

```
Enter The Number :- 7
7 is a Prime Number .
```

```
Enter The Number :- 9
9 is not a Prime Number .
```

## Run it

```bash
gcc prime_checker.c -o prime_checker
./prime_checker
```

## How I improved it

I wrote this one on my own and improved it over several versions:

1. **Version 1:** the loop ran all the way up to `num` and counted every divisor.
2. **Version 2:** the loop stopped at the square root, but the divisor-counting check had to change to match.
3. **Final version:** the loop exits at the first divisor, so the counter isn't needed at all.

The main lesson: after changing the loop, I had to rethink what the rest of the program was checking, instead of only changing numbers until the output looked right.

## Known limitations

- **Overflow near the largest `int`:** `i * i` can overflow for numbers close to 2,147,483,647. I haven't fixed this yet.
- **No input validation:** the return value of `scanf` isn't checked, so typing letters isn't handled.

## What I learned

- Tracing a program by hand on small examples (7, 9, 15, 25, 49) to find bugs.
- Early exit from a loop.
- The square-root bound for prime checking.
- `printf` / `scanf` in C, after learning in C++ first.

---

Part of my learning journey: [github.com/HINDOL-2007](https://github.com/HINDOL-2007)
