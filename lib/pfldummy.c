char pfldata[3] = "lx";

asm int pflong()
{
asm {
 leax _pfldata+2,y
 cmpb #'d'
 beq _1
 cmpb #'o'
 beq _1
 cmpb #'x'
 beq _1
 cmpb #'X'
 beq _1
 leax -2,x
 stb 1,x
_1 tfr x,d
 rts
}
}
