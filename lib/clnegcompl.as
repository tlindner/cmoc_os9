 section code

_flacc EXTERNAL
_ltoacc EXTERNAL

_lneg EXPORT
_lnegx EXPORT
_lcompl EXPORT

_lneg: lbsr  _ltoacc 
_lnegx: ldd   #0 
 subd  2,x 
 std   2,x 
 ldd   #0 
 sbcb  1,x 
 sbca  ,x 
 std   ,x 
 rts    
_lcompl: ldd   ,x 
 coma   
 comb   
 std   _flacc,y 
 ldd   2,x 
 coma   
 comb   
 leax  _flacc,y 
 std   2,x 
 rts    

 endsect  

