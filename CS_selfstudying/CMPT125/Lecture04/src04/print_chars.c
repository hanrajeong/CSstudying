/* Printing chars  */
#include <stdio.h>

int main() {
  unsigned char ch;

// 파이썬과 달리 c언어는 chr()라는 함수 호출 상관없이 해당하는 유니코드를 c(character)로 불러들이면 됨.

  for(ch=33; ch<125; ch++)
    printf("numeric = %3d :: char = %c\n", ch, ch);
  return 0;
}

// 코드 run 결과는 다음과 같음.
// numeric =  33 :: char = !
// numeric =  34 :: char = "
// numeric =  35 :: char = #
// numeric =  36 :: char = $
// numeric =  37 :: char = %
// numeric =  38 :: char = &
// numeric =  39 :: char = '
// numeric =  40 :: char = (
// numeric =  41 :: char = )
// numeric =  42 :: char = *
// numeric =  43 :: char = +
// numeric =  44 :: char = ,
// numeric =  45 :: char = -
// numeric =  46 :: char = .
// numeric =  47 :: char = /
// numeric =  48 :: char = 0
// numeric =  49 :: char = 1
// numeric =  50 :: char = 2
// numeric =  51 :: char = 3
// numeric =  52 :: char = 4
// numeric =  53 :: char = 5
// numeric =  54 :: char = 6
// numeric =  55 :: char = 7
// numeric =  56 :: char = 8
// numeric =  57 :: char = 9
// numeric =  58 :: char = :
// numeric =  59 :: char = ;
// numeric =  60 :: char = <
// numeric =  61 :: char = =
// numeric =  62 :: char = >
// numeric =  63 :: char = ?
// numeric =  64 :: char = @
// numeric =  65 :: char = A
// numeric =  66 :: char = B
// numeric =  67 :: char = C
// numeric =  68 :: char = D
// numeric =  69 :: char = E
// numeric =  70 :: char = F
// numeric =  71 :: char = G
// numeric =  72 :: char = H
// numeric =  73 :: char = I
// numeric =  74 :: char = J
// numeric =  75 :: char = K
// numeric =  76 :: char = L
// numeric =  77 :: char = M
// numeric =  78 :: char = N
// numeric =  79 :: char = O
// numeric =  80 :: char = P
// numeric =  81 :: char = Q
// numeric =  82 :: char = R
// numeric =  83 :: char = S
// numeric =  84 :: char = T
// numeric =  85 :: char = U
// numeric =  86 :: char = V
// numeric =  87 :: char = W
// numeric =  88 :: char = X
// numeric =  89 :: char = Y
// numeric =  90 :: char = Z
// numeric =  91 :: char = [
// numeric =  92 :: char = \
// numeric =  93 :: char = ]
// numeric =  94 :: char = ^
// numeric =  95 :: char = _
// numeric =  96 :: char = `
// numeric =  97 :: char = a
// numeric =  98 :: char = b
// numeric =  99 :: char = c
// numeric = 100 :: char = d
// numeric = 101 :: char = e
// numeric = 102 :: char = f
// numeric = 103 :: char = g
// numeric = 104 :: char = h
// numeric = 105 :: char = i
// numeric = 106 :: char = j
// numeric = 107 :: char = k
// numeric = 108 :: char = l
// numeric = 109 :: char = m
// numeric = 110 :: char = n
// numeric = 111 :: char = o
// numeric = 112 :: char = p
// numeric = 113 :: char = q
// numeric = 114 :: char = r
// numeric = 115 :: char = s
// numeric = 116 :: char = t
// numeric = 117 :: char = u
// numeric = 118 :: char = v
// numeric = 119 :: char = w
// numeric = 120 :: char = x
// numeric = 121 :: char = y
// numeric = 122 :: char = z
// numeric = 123 :: char = {
// numeric = 124 :: char = |