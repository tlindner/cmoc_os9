* Disassembly by Os9disasm of syscommon.r


 section bss
_os9err EXPORT
_sysret EXPORT
_errno  EXTERNAL
 endsect

 section code

_os9err: clra   
 std   _errno,y 
* ldd   #-1 
 rts    
_sysret: bcs   _os9err 
 clra   
 clrb   
 rts    

 endsect  

